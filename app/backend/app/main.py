import asyncio
from contextlib import asynccontextmanager

from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware

from app.api.routers import debug, health, inventory, orders, simulator, state, stats
from app.api.ws import bridge_ws, client_ws
from app.core.bootstrap import ensure_seed_data
from app.core.config import settings
from app.core.database import AsyncSessionLocal
from app.services.dispatcher_service import DispatcherService
from app.services.simulator_service import SimulatorService
from app.services.timer_service import TimerService

_background_tasks: list[asyncio.Task] = []


@asynccontextmanager
async def lifespan(app: FastAPI):
    async with AsyncSessionLocal() as session:
        await ensure_seed_data(session)

    _background_tasks.append(asyncio.create_task(TimerService.sweep_loop()))
    _background_tasks.append(asyncio.create_task(SimulatorService.auto_order_loop()))

    # 서버 재시작 복구: DB 상태 기준으로 즉시 한 번 평가한다 (로봇이 아직 연결 전이면 no-op).
    await DispatcherService.run_cycle()

    yield

    for task in _background_tasks:
        task.cancel()
    await asyncio.gather(*_background_tasks, return_exceptions=True)


app = FastAPI(title="소규모 3D 프린트 업장 관리 로봇 - 서버", lifespan=lifespan)

app.add_middleware(
    CORSMiddleware,
    allow_origins=settings.cors_origin_list,
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

app.include_router(orders.router)
app.include_router(state.router)
app.include_router(inventory.router)
app.include_router(simulator.router)
app.include_router(debug.router)
app.include_router(stats.router)
app.include_router(health.router)

app.include_router(client_ws.router)
app.include_router(bridge_ws.router)
