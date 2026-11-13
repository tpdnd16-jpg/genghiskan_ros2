import asyncio
import time
from dataclasses import dataclass, field

from fastapi import WebSocket

from app.core.config import settings
from app.enums import RobotState


@dataclass
class RuntimeState:
    """서버 프로세스 메모리에만 두는 런타임 상태.

    DB가 단일 진실 원천인 주문·프린터·재고와 달리, 이 값들은 재시작 시
    초기화돼도 무방하다 (로봇 연결 상태, 소켓 핸들, 시뮬레이터 설정 등).
    """

    robot_state: RobotState = RobotState.DISCONNECTED
    current_task_id: int | None = None
    bridge_ws: WebSocket | None = None
    bridge_last_seen_monotonic: float = 0.0

    client_connections: set[WebSocket] = field(default_factory=set)

    simulator_running: bool = settings.default_auto_order_running
    simulator_interval_sec: int = settings.default_auto_order_interval_sec
    simulator_time_scale: float = settings.default_time_scale
    simulator_wakeup: asyncio.Event = field(default_factory=asyncio.Event)

    dispatcher_lock: asyncio.Lock = field(default_factory=asyncio.Lock)

    def mark_bridge_seen(self) -> None:
        self.bridge_last_seen_monotonic = time.monotonic()

    def bridge_connected(self) -> bool:
        return self.bridge_ws is not None and self.robot_state != RobotState.DISCONNECTED


runtime = RuntimeState()
