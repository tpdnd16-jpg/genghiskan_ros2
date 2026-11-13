# Copyright 2026 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""Unit tests for sfarm_bridge SQS event payload formatting."""

from datetime import datetime

from sfarm_bridge.sfarm_bridge import (
    build_robot_event,
    DEFAULT_EVENT_QUEUE_URL,
)


def test_default_event_queue_url():
    """Verify default robot-events SQS queue URL."""
    assert DEFAULT_EVENT_QUEUE_URL == (
        'https://sqs.ap-northeast-2.amazonaws.com/135135392043/robot-events'
    )


def test_build_robot_event_load_format():
    """Verify LOAD command produces the expected robot-events payload."""
    command = {
        'type': 'LOAD',
        'command_id': 'test-load-001',
        'job_id': 'job-001',
        'printer_id': 2,
    }
    event = build_robot_event(command, 'robot-arm-1')

    assert set(event.keys()) == {
        'event_id',
        'event_type',
        'command_id',
        'job_id',
        'robot_id',
        'printer_id',
        'reason',
        'occurred_at',
    }
    assert event['event_id'].startswith('evt-')
    assert event['event_type'] == 'LOAD_COMPLETED'
    assert event['command_id'] == 'test-load-001'
    assert event['job_id'] == 'job-001'
    assert event['robot_id'] == 'robot-arm-1'
    assert event['printer_id'] == 2
    assert isinstance(event['printer_id'], int)
    assert event['reason'] is None
    assert event['occurred_at'].endswith('+00:00')
    parsed_dt = datetime.fromisoformat(event['occurred_at'])
    assert parsed_dt.tzinfo is not None


def test_build_robot_event_variants():
    """Verify command_type fallback, string printer_id, and REJECTED."""
    unload_cmd = {
        'command_type': 'unload',
        'command_id': 'cmd-002',
        'job_id': 'job-002',
        'printer_id': '3',
        'robot_id': 'robot-arm-2',
    }
    unload_evt = build_robot_event(unload_cmd, 'robot-arm-1')
    assert unload_evt['event_type'] == 'UNLOAD_COMPLETED'
    assert unload_evt['printer_id'] == 3
    assert unload_evt['robot_id'] == 'robot-arm-2'
    assert unload_evt['reason'] is None

    bad_cmd = {'type': 'UNKNOWN', 'command_id': 'cmd-003'}
    bad_evt = build_robot_event(bad_cmd, 'robot-arm-1')
    assert bad_evt['event_type'] == 'REJECTED'
    assert bad_evt['reason'] == 'unknown type'
