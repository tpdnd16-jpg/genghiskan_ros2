"""
Web(AWS SQS) <-> ROS 2 브릿지 노드 (sfarm_bridge).

robot-commands.fifo 큐에서 작업 명령을 수신해 ROS 2 액션(/sfarm/insert, /sfarm/eject)으로
전달하고, 실행 결과 및 /sfarm/error 서비스 호출을 robot-events 큐로 발행한다.

ros2 run sfarm_bridge sfarm_bridge --ros-args \
  -p command_queue_url:=https://sqs.ap-northeast-2.amazonaws.com/<ACCOUNT>/robot-commands.fifo \
  -p event_queue_url:=https://sqs.ap-northeast-2.amazonaws.com/<ACCOUNT>/robot-events
"""
from __future__ import annotations

from datetime import datetime, timezone
import json
import os
from pathlib import Path
import threading
import uuid

import boto3
from botocore.exceptions import BotoCoreError, ClientError
import rclpy
from rclpy.action import ActionClient
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import ExternalShutdownException, MultiThreadedExecutor
from rclpy.node import Node

from sfarm_interfaces.action import Eject, Insert
from sfarm_interfaces.srv import Error

COMPLETED_EVENT = {'LOAD': 'LOAD_COMPLETED', 'UNLOAD': 'UNLOAD_COMPLETED'}
ACTION_COMPLETED_EVENT = {'INSERT': 'INSERT_COMPLETED', 'EJECT': 'EJECT_COMPLETED'}
DEFAULT_COMMAND_QUEUE_URL = (
    'https://sqs.ap-northeast-2.amazonaws.com/135135392043/robot-commands.fifo'
)
DEFAULT_EVENT_QUEUE_URL = (
    'https://sqs.ap-northeast-2.amazonaws.com/135135392043/robot-events'
)


def _parse_printer_id(value):
    """Normalize printer_id to int when possible."""
    if isinstance(value, bool) or value is None:
        return value
    if isinstance(value, int):
        return value
    if isinstance(value, str):
        stripped = value.strip()
        if stripped.isdigit():
            return int(stripped)
    return value


def _to_int(value) -> int | None:
    """Convert numeric field to int, returning None if invalid."""
    if isinstance(value, bool) or value is None:
        return None
    try:
        return int(value)
    except (TypeError, ValueError):
        return None


def parse_task_command(command: dict) -> tuple[str | None, dict | None]:
    """Parse an SQS command payload into ('INSERT' | 'EJECT', goal_fields)."""
    if not isinstance(command, dict):
        return None, None

    work_id = _to_int(command.get('work_id'))
    pos_3d_id = _to_int(
        command.get('sd_pos_id')
        if command.get('sd_pos_id') is not None
        else (
            command.get('pos_3d_id')
            if command.get('pos_3d_id') is not None
            else command.get('3d_pos_id')
        )
    )
    start_pos_id = _to_int(command.get('start_pos_id'))
    receive_pos_id = _to_int(command.get('receive_pos_id'))

    raw_type = str(
        command.get('type') or command.get('command_type') or ''
    ).strip().upper()

    is_insert = raw_type in {'INSERT', 'LOAD'} or (
        start_pos_id is not None and receive_pos_id is None
    )
    if is_insert and work_id is not None and start_pos_id is not None and pos_3d_id is not None:
        return 'INSERT', {
            'work_id': work_id,
            'start_pos_id': start_pos_id,
            'pos_3d_id': pos_3d_id,
        }

    is_eject = raw_type in {'EJECT', 'UNLOAD'} or (
        receive_pos_id is not None and start_pos_id is None
    )
    if is_eject and work_id is not None and pos_3d_id is not None and receive_pos_id is not None:
        return 'EJECT', {
            'work_id': work_id,
            'pos_3d_id': pos_3d_id,
            'receive_pos_id': receive_pos_id,
        }

    return None, None


def build_robot_event(command: dict, default_robot_id: str) -> dict:
    """Build a robot-events SQS payload matching the backend contract."""
    raw_type = command.get('type') or command.get('command_type') or ''
    cmd_type = str(raw_type).strip().upper()
    event_type = COMPLETED_EVENT.get(cmd_type, 'REJECTED')
    return {
        'event_id': f'evt-{uuid.uuid4()}',
        'event_type': event_type,
        'command_id': command.get('command_id'),
        'job_id': command.get('job_id'),
        'robot_id': command.get('robot_id') or default_robot_id,
        'printer_id': _parse_printer_id(command.get('printer_id')),
        'reason': None if event_type != 'REJECTED' else 'unknown type',
        'occurred_at': datetime.now(timezone.utc).isoformat(timespec='seconds'),
    }


def build_action_result_event(
    action_kind: str,
    work_id: int,
    success: bool,
    message: str,
    work_type: int,
    robot_id: str,
) -> dict:
    """Build a robot-events SQS payload from a ROS 2 action result."""
    event_type = (
        ACTION_COMPLETED_EVENT[action_kind]
        if success
        else f'{action_kind}_FAILED'
    )
    work_type_str = 'insert' if work_type == Insert.Result.WORK_TYPE_INSERT else 'eject'
    return {
        'event_id': f'evt-{uuid.uuid4()}',
        'event_type': event_type,
        'work_id': work_id,
        'work_type': work_type_str,
        'success': success,
        'message': message,
        'robot_id': robot_id,
        'occurred_at': datetime.now(timezone.utc).isoformat(timespec='seconds'),
    }


def load_dotenv() -> None:
    """Load key=value pairs from the first available .env file into os.environ."""
    candidates = [Path.cwd() / '.env']
    for parent in Path(__file__).resolve().parents:
        candidates.append(parent / '.env')
        candidates.append(parent / 'src' / 'sfarm_bridge' / '.env')

    for env_path in candidates:
        if not env_path.is_file():
            continue
        for raw_line in env_path.read_text(encoding='utf-8').splitlines():
            line = raw_line.strip()
            if not line or line.startswith('#') or '=' not in line:
                continue
            key, value = line.split('=', 1)
            key = key.strip()
            value = value.strip().strip('"').strip("'")
            if key:
                os.environ.setdefault(key, value)
        break


class SqsEchoNode(Node):
    """Bridge node connecting AWS SQS queues and 3Farm ROS 2 actions/services."""

    def __init__(self) -> None:
        super().__init__('sfarm_bridge_node')
        load_dotenv()
        default_region = (
            os.getenv('AWS_REGION')
            or os.getenv('AWS_DEFAULT_REGION')
            or 'ap-northeast-2'
        )
        default_cmd_url = os.getenv(
            'COMMAND_QUEUE_URL',
            DEFAULT_COMMAND_QUEUE_URL,
        )
        default_event_url = os.getenv(
            'EVENT_QUEUE_URL',
            DEFAULT_EVENT_QUEUE_URL,
        )

        self.robot_id = self.declare_parameter('robot_id', 'robot-arm-1').value
        region = self.declare_parameter('aws_region', default_region).value
        self.command_queue_url = self.declare_parameter(
            'command_queue_url', default_cmd_url
        ).value
        self.event_queue_url = self.declare_parameter(
            'event_queue_url', default_event_url
        ).value
        self.action_timeout_sec = float(
            self.declare_parameter('action_timeout_sec', 120.0).value
        )

        if not self.command_queue_url or not self.event_queue_url:
            raise ValueError('command_queue_url and event_queue_url are required')

        self.cb_group = ReentrantCallbackGroup()
        self.insert_client = ActionClient(
            self, Insert, '/sfarm/insert', callback_group=self.cb_group
        )
        self.eject_client = ActionClient(
            self, Eject, '/sfarm/eject', callback_group=self.cb_group
        )
        self.error_srv = self.create_service(
            Error, '/sfarm/error', self.handle_error_service, callback_group=self.cb_group
        )

        self.sqs = boto3.client('sqs', region_name=region)
        self.stop = threading.Event()
        # long polling은 최대 20초 블로킹하므로 executor와 분리된 스레드에서 실행
        self.worker = threading.Thread(target=self.consume_loop, daemon=True)
        self.worker.start()
        self.get_logger().info(f'listening on {self.command_queue_url}')

    # ---------------------------------------------------------------- service
    def handle_error_service(self, request: Error.Request, response: Error.Response):
        """Forward robot error service calls to the robot-events SQS queue."""
        self.get_logger().error(f'[/sfarm/error] {request.message}')
        event = {
            'event_id': f'evt-{uuid.uuid4()}',
            'event_type': 'ERROR',
            'message': request.message,
            'robot_id': self.robot_id,
            'occurred_at': datetime.now(timezone.utc).isoformat(timespec='seconds'),
        }
        self.produce(event)
        return response

    # ---------------------------------------------------------------- consume
    def consume_loop(self) -> None:
        """Poll robot-commands.fifo in a background thread."""
        while not self.stop.is_set() and rclpy.ok():
            try:
                resp = self.sqs.receive_message(
                    QueueUrl=self.command_queue_url,
                    MaxNumberOfMessages=1,
                    WaitTimeSeconds=20,  # long polling
                    VisibilityTimeout=60,
                )
            except (BotoCoreError, ClientError) as e:
                self.get_logger().error(f'receive failed: {e}')
                self.stop.wait(3.0)
                continue

            messages = resp.get('Messages', [])
            if not messages:
                self.get_logger().info('대기중...')
                continue

            for message in messages:
                self.handle_message(message)

    def handle_message(self, message: dict) -> None:
        """Parse an SQS message, dispatch ROS 2 action, and report result."""
        body = message['Body']
        print(f'[RECEIVED] message_id={message["MessageId"]}')
        print(f'           body={body}', flush=True)

        try:
            command = json.loads(body)
        except json.JSONDecodeError:
            self.get_logger().error('body is not JSON; deleting message')
            self.delete(message)
            return

        action_kind, goal_fields = parse_task_command(command)
        if action_kind is None or goal_fields is None:
            event = self.build_event(command)
            if self.produce(event):
                self.delete(message)
            return

        result = self.execute_ros_action(action_kind, goal_fields)
        if result is None:
            self.get_logger().warning(
                f'{action_kind} action did not complete; keeping SQS message for retry'
            )
            return

        event = build_action_result_event(
            action_kind=action_kind,
            work_id=result.work_id,
            success=result.success,
            message=result.message,
            work_type=result.work_type,
            robot_id=self.robot_id,
        )
        if self.produce(event):
            self.delete(message)

    # ---------------------------------------------------------------- ros2 action
    def execute_ros_action(self, action_kind: str, goal_fields: dict):
        """Send an Insert or Eject goal to ROS 2 and wait for the result."""
        if action_kind == 'INSERT':
            client = self.insert_client
            action_name = '/sfarm/insert'
            goal_msg = Insert.Goal()
            goal_msg.work_id = goal_fields['work_id']
            goal_msg.start_pos_id = goal_fields['start_pos_id']
            goal_msg.pos_3d_id = goal_fields['pos_3d_id']
        else:
            client = self.eject_client
            action_name = '/sfarm/eject'
            goal_msg = Eject.Goal()
            goal_msg.work_id = goal_fields['work_id']
            goal_msg.pos_3d_id = goal_fields['pos_3d_id']
            goal_msg.receive_pos_id = goal_fields['receive_pos_id']

        if not client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error(f'{action_name} action server is not available')
            return None

        self.get_logger().info(f'Sending goal to {action_name}: {goal_fields}')

        done_event = threading.Event()
        holder: dict = {'result': None}

        def on_feedback(feedback_msg) -> None:
            fb = feedback_msg.feedback
            self.get_logger().info(
                f'[{action_name} feedback] work_id={fb.work_id} '
                f'start_at={fb.start_at.sec}.{fb.start_at.nanosec:09d} '
                f'end_at={fb.end_at.sec}.{fb.end_at.nanosec:09d}'
            )

        def on_result(future) -> None:
            try:
                holder['result'] = future.result().result
            except Exception as exc:  # noqa: BLE001
                self.get_logger().error(f'{action_name} result error: {exc}')
            finally:
                done_event.set()

        def on_goal_response(future) -> None:
            try:
                goal_handle = future.result()
            except Exception as exc:  # noqa: BLE001
                self.get_logger().error(f'{action_name} goal error: {exc}')
                done_event.set()
                return

            if not goal_handle.accepted:
                self.get_logger().warning(f'{action_name} goal was rejected')
                done_event.set()
                return

            self.get_logger().info(f'{action_name} goal accepted')
            result_future = goal_handle.get_result_async()
            result_future.add_done_callback(on_result)

        goal_future = client.send_goal_async(goal_msg, feedback_callback=on_feedback)
        goal_future.add_done_callback(on_goal_response)

        deadline = self.action_timeout_sec
        waited = 0.0
        while not done_event.is_set() and not self.stop.is_set() and rclpy.ok():
            if done_event.wait(timeout=0.5):
                break
            waited += 0.5
            if waited >= deadline:
                self.get_logger().error(f'{action_name} timed out after {deadline}s')
                return None

        return holder['result']

    # ---------------------------------------------------------------- produce
    def build_event(self, command: dict) -> dict:
        """Build an SQS event dictionary from an incoming command."""
        return build_robot_event(command, self.robot_id)

    def produce(self, event: dict) -> bool:
        """Publish an event JSON payload to the robot-events SQS queue."""
        params = {
            'QueueUrl': self.event_queue_url,
            'MessageBody': json.dumps(event, ensure_ascii=False),
        }
        if self.event_queue_url.endswith('.fifo'):
            params['MessageGroupId'] = self.robot_id
            params['MessageDeduplicationId'] = event['event_id']
        try:
            resp = self.sqs.send_message(**params)
        except (BotoCoreError, ClientError) as e:
            self.get_logger().error(f'produce failed: {e}')
            return False
        print(
            f'[PRODUCED] message_id={resp["MessageId"]} '
            f'event_type={event["event_type"]} '
            f'work_id={event.get("work_id")} job_id={event.get("job_id")}',
            flush=True,
        )
        return True

    def delete(self, message: dict) -> None:
        """Delete a processed message from robot-commands.fifo."""
        try:
            self.sqs.delete_message(
                QueueUrl=self.command_queue_url,
                ReceiptHandle=message['ReceiptHandle'],
            )
        except (BotoCoreError, ClientError) as e:
            self.get_logger().error(f'delete failed: {e}')


def main(args=None) -> None:
    """Entry point for sfarm_bridge node."""
    rclpy.init(args=args)
    node = SqsEchoNode()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    try:
        executor.spin()
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        node.stop.set()
        executor.shutdown()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
