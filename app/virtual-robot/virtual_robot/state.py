import asyncio
from dataclasses import dataclass, field


@dataclass
class RobotRuntimeState:
    """가상 로봇 프로세스 내부 상태. DB에는 없고 이 프로세스 메모리에만 있다."""

    robot_state: str = "IDLE"  # IDLE | BUSY | ERROR
    current_task_id: int | None = None
    last_error: str = ""

    physical_board_count: int = 10
    fault_no_board_once: bool = False
    fault_grip_fail_once: bool = False

    busy_lock: asyncio.Lock = field(default_factory=asyncio.Lock)

    def consume_no_board_fault(self) -> bool:
        if self.fault_no_board_once:
            self.fault_no_board_once = False
            return True
        return False

    def consume_grip_fail_fault(self) -> bool:
        if self.fault_grip_fail_once:
            self.fault_grip_fail_once = False
            return True
        return False
