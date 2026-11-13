import pytest

from virtual_robot.config import PhaseTimes
from virtual_robot.state import RobotRuntimeState
from virtual_robot.task_executor import TaskExecutor

pytestmark = pytest.mark.asyncio

# 테스트가 빠르게 끝나도록 매우 작은 단계 시간을 쓴다 (비율/순서 로직만 검증).
_PHASE_TIMES = PhaseTimes(
    load={
        "MOVE_TO_STOCK": 0.01,
        "PICK_BOARD": 0.01,
        "CHECK_GRIP": 0.01,
        "MOVE_TO_PRINTER": 0.01,
        "PLACE_IN_PRINTER": 0.01,
        "RETURN_HOME": 0.01,
    },
    unload={
        "MOVE_TO_PRINTER": 0.01,
        "PICK_FROM_PRINTER": 0.01,
        "CHECK_GRIP": 0.01,
        "MOVE_TO_PICKUP": 0.01,
        "PLACE_AT_PICKUP": 0.01,
        "RETURN_HOME": 0.01,
    },
    floor_offset_sec={1: 0, 2: 0.01, 3: 0.02},
)


async def _collect_feedback(executor: TaskExecutor, task_type: str, slot: int):
    phases: list[tuple[str, float]] = []

    async def send_feedback(phase: str, progress: float) -> None:
        phases.append((phase, progress))

    result = await executor.execute(task_type, slot, time_scale=1.0, send_feedback=send_feedback)
    return result, phases


async def test_load_success_decrements_physical_board_count():
    state = RobotRuntimeState(physical_board_count=3)
    executor = TaskExecutor(_PHASE_TIMES, state)

    result, phases = await _collect_feedback(executor, "LOAD", slot=1)

    assert result.success is True
    assert state.physical_board_count == 2
    assert [p for p, _ in phases] == [
        "MOVE_TO_STOCK",
        "PICK_BOARD",
        "CHECK_GRIP",
        "MOVE_TO_PRINTER",
        "PLACE_IN_PRINTER",
        "RETURN_HOME",
    ]
    assert phases[0][1] == 0.0  # 첫 단계는 진행률 0에서 시작


async def test_load_no_board_skips_to_return_home():
    state = RobotRuntimeState(physical_board_count=0)
    executor = TaskExecutor(_PHASE_TIMES, state)

    result, phases = await _collect_feedback(executor, "LOAD", slot=1)

    assert result.success is False
    assert result.error_code == "NO_BOARD"
    assert [p for p, _ in phases] == ["MOVE_TO_STOCK", "PICK_BOARD", "CHECK_GRIP", "RETURN_HOME"]
    assert state.physical_board_count == 0  # 실패 시 소비되지 않음


async def test_load_forced_no_board_fault_is_one_shot():
    state = RobotRuntimeState(physical_board_count=5, fault_no_board_once=True)
    executor = TaskExecutor(_PHASE_TIMES, state)

    result, _ = await _collect_feedback(executor, "LOAD", slot=1)
    assert result.success is False
    assert result.error_code == "NO_BOARD"
    assert state.fault_no_board_once is False  # 소비됨

    result2, _ = await _collect_feedback(executor, "LOAD", slot=1)
    assert result2.success is True  # 두 번째는 정상 진행


async def test_unload_grip_fail_skips_to_return_home():
    state = RobotRuntimeState(fault_grip_fail_once=True)
    executor = TaskExecutor(_PHASE_TIMES, state)

    result, phases = await _collect_feedback(executor, "UNLOAD", slot=3)

    assert result.success is False
    assert result.error_code == "GRIP_FAIL"
    assert [p for p, _ in phases] == ["MOVE_TO_PRINTER", "PICK_FROM_PRINTER", "CHECK_GRIP", "RETURN_HOME"]


async def test_unload_success_does_not_touch_board_count():
    state = RobotRuntimeState(physical_board_count=7)
    executor = TaskExecutor(_PHASE_TIMES, state)

    result, _ = await _collect_feedback(executor, "UNLOAD", slot=1)

    assert result.success is True
    assert state.physical_board_count == 7
