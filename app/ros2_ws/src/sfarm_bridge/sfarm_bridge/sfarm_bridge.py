"""
SQS 연결 확인용 단순 브리지 노드.

robot-commands 큐에서 메시지를 받아 출력(print)하고,
3초 뒤 로봇이 동작한 것처럼 완료 이벤트를 robot-events 큐로 발행(produce)한 뒤 삭제한다.
로봇·액션 서버 없이 서버 ↔ SQS ↔ ROS 2 통신이 되는지 확인할 때 쓴다.

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
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node

COMPLETED_EVENT = {'LOAD': 'LOAD_COMPLETED', 'UNLOAD': 'UNLOAD_COMPLETED'}
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
    def __init__(self) -> None:
        super().__init__('sqs_echo_node')
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
        self.delay_sec = float(self.declare_parameter('delay_sec', 3.0).value)

        if not self.command_queue_url or not self.event_queue_url:
            raise ValueError('command_queue_url and event_queue_url are required')

        self.sqs = boto3.client('sqs', region_name=region)
        self.stop = threading.Event()
        # long polling은 최대 20초 블로킹하므로 executor와 분리된 스레드에서 실행
        self.worker = threading.Thread(target=self.consume_loop, daemon=True)
        self.worker.start()
        self.get_logger().info(f'listening on {self.command_queue_url}')

    # ---------------------------------------------------------------- consume
    def consume_loop(self) -> None:
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
        body = message['Body']
        print(f'[RECEIVED] message_id={message["MessageId"]}')
        print(f'           body={body}', flush=True)

        try:
            command = json.loads(body)
        except json.JSONDecodeError:
            self.get_logger().error('body is not JSON; deleting message')
            self.delete(message)
            return

        # 로봇 동작 시뮬레이션: 3초 대기 후 완료 이벤트 발행
        if self.stop.wait(self.delay_sec):
            return

        event = self.build_event(command)
        if self.produce(event):
            self.delete(message)  # 이벤트 발행에 성공한 뒤에만 삭제

    # ---------------------------------------------------------------- produce
    def build_event(self, command: dict) -> dict:
        """Build an SQS event dictionary from an incoming command."""
        return build_robot_event(command, self.robot_id)

    def produce(self, event: dict) -> bool:
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
            f'event_type={event["event_type"]} job_id={event["job_id"]}',
            flush=True,
        )
        return True

    def delete(self, message: dict) -> None:
        try:
            self.sqs.delete_message(
                QueueUrl=self.command_queue_url,
                ReceiptHandle=message['ReceiptHandle'],
            )
        except (BotoCoreError, ClientError) as e:
            self.get_logger().error(f'delete failed: {e}')


def main(args=None) -> None:
    rclpy.init(args=args)
    node = SqsEchoNode()
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        node.stop.set()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
