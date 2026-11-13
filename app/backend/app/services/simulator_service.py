import asyncio

from app.core.database import AsyncSessionLocal
from app.core.runtime import runtime
from app.enums import OrderSource
from app.schemas import SimulatorSettingsOut, SimulatorSettingsPatch
from app.services.order_service import OrderService


class SimulatorService:
    @staticmethod
    def get_settings() -> SimulatorSettingsOut:
        return SimulatorSettingsOut(
            running=runtime.simulator_running,
            interval_sec=runtime.simulator_interval_sec,
            time_scale=runtime.simulator_time_scale,
        )

    @staticmethod
    def patch_settings(patch: SimulatorSettingsPatch) -> SimulatorSettingsOut:
        if patch.running is not None:
            runtime.simulator_running = patch.running
        if patch.interval_sec is not None:
            runtime.simulator_interval_sec = patch.interval_sec
        if patch.time_scale is not None:
            runtime.simulator_time_scale = patch.time_scale
        runtime.simulator_wakeup.set()
        return SimulatorService.get_settings()

    @staticmethod
    async def auto_order_loop() -> None:
        """45초(기본) 간격으로 자동 주문을 생성한다. 실행 여부·간격·시간 배율이
        바뀌면 simulator_wakeup 이벤트로 즉시 재평가한다."""
        while True:
            if not runtime.simulator_running:
                runtime.simulator_wakeup.clear()
                await runtime.simulator_wakeup.wait()
                continue

            effective_interval = runtime.simulator_interval_sec * runtime.simulator_time_scale
            try:
                await asyncio.wait_for(runtime.simulator_wakeup.wait(), timeout=effective_interval)
                runtime.simulator_wakeup.clear()
                continue  # 설정이 바뀌어 깨어남 → 다음 루프에서 새 간격으로 재평가
            except asyncio.TimeoutError:
                pass

            if not runtime.simulator_running:
                continue

            async with AsyncSessionLocal() as session:
                await OrderService.create_order(session, shape=None, source=OrderSource.AUTO)
