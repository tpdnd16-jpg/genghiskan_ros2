import asyncio
import os

os.environ["DATABASE_URL"] = "sqlite+aiosqlite:///:memory:"
os.environ["BRIDGE_TOKEN"] = "test-token"

import pytest
import pytest_asyncio

from app.core.bootstrap import ensure_seed_data
from app.core.database import AsyncSessionLocal, Base, engine
from app.core.runtime import runtime
from app.enums import RobotState


@pytest_asyncio.fixture(autouse=True)
async def _fresh_database():
    async with engine.begin() as conn:
        await conn.run_sync(Base.metadata.drop_all)
        await conn.run_sync(Base.metadata.create_all)

    async with AsyncSessionLocal() as session:
        await ensure_seed_data(session)

    runtime.robot_state = RobotState.IDLE
    runtime.current_task_id = None
    runtime.bridge_ws = _FakeBridge()
    runtime.client_connections.clear()
    runtime.simulator_running = False
    runtime.simulator_time_scale = 1.0

    yield


class _FakeBridge:
    """실제 소켓 없이도 dispatcher가 'bridge 연결됨'으로 보고 task.dispatch를 보내게 한다."""

    def __init__(self):
        self.sent: list[dict] = []

    async def send_json(self, envelope: dict) -> None:
        self.sent.append(envelope)
