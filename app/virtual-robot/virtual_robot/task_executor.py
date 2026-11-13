"""PRD 7.7 단계 진행. LOAD/UNLOAD 각각 정해진 순서로 단계를 밟으며, CHECK_GRIP에서
실패하면 중간 단계를 건너뛰고 RETURN_HOME으로 바로 간다 (9.4)."""

import asyncio
from collections.abc import Awaitable, Callable
from dataclasses import dataclass

from virtual_robot.config import PhaseTimes
from virtual_robot.state import RobotRuntimeState

LOAD_PHASES = ["MOVE_TO_STOCK", "PICK_BOARD", "CHECK_GRIP", "MOVE_TO_PRINTER", "PLACE_IN_PRINTER", "RETURN_HOME"]
UNLOAD_PHASES = ["MOVE_TO_PRINTER", "PICK_FROM_PRINTER", "CHECK_GRIP", "MOVE_TO_PICKUP", "PLACE_AT_PICKUP", "RETURN_HOME"]

FeedbackFn = Callable[[str, float], Awaitable[None]]


@dataclass
class TaskResult:
    success: bool
    error_code: str | None
    message: str


class TaskExecutor:
    def __init__(self, phase_times: PhaseTimes, state: RobotRuntimeState):
        self._phase_times = phase_times
        self._state = state

    def _durations(self, task_type: str, slot: int, time_scale: float) -> dict[str, float]:
        base = self._phase_times.for_type(task_type)
        floor_offset = self._phase_times.floor_offset_sec.get(slot, 0.0)
        durations = dict(base)
        if "MOVE_TO_PRINTER" in durations:
            durations["MOVE_TO_PRINTER"] = durations["MOVE_TO_PRINTER"] + floor_offset
        return {phase: sec * time_scale for phase, sec in durations.items()}

    async def execute(
        self, task_type: str, slot: int, time_scale: float, send_feedback: FeedbackFn
    ) -> TaskResult:
        phases = LOAD_PHASES if task_type == "LOAD" else UNLOAD_PHASES
        durations = self._durations(task_type, slot, time_scale)
        total = sum(durations[p] for p in phases)

        elapsed = 0.0
        for phase in phases:
            if phase == "CHECK_GRIP":
                await send_feedback(phase, elapsed / total if total else 1.0)
                await asyncio.sleep(durations[phase])
                elapsed += durations[phase]

                failure = self._check_grip(task_type)
                if failure is not None:
                    await send_feedback("RETURN_HOME", elapsed / total if total else 1.0)
                    await asyncio.sleep(durations["RETURN_HOME"])
                    return TaskResult(success=False, error_code=failure, message=f"{failure} at CHECK_GRIP")
                continue

            await send_feedback(phase, elapsed / total if total else 1.0)
            await asyncio.sleep(durations[phase])
            elapsed += durations[phase]

        if task_type == "LOAD":
            self._state.physical_board_count = max(0, self._state.physical_board_count - 1)

        return TaskResult(success=True, error_code=None, message="ok")

    def _check_grip(self, task_type: str) -> str | None:
        if task_type == "LOAD":
            if self._state.physical_board_count <= 0:
                return "NO_BOARD"
            if self._state.consume_no_board_fault():
                return "NO_BOARD"
            return None

        if self._state.consume_grip_fail_fault():
            return "GRIP_FAIL"
        return None
