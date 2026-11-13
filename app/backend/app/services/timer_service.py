import asyncio
import logging
from datetime import datetime, timedelta

from app.core.config import settings
from app.core.database import AsyncSessionLocal
from app.core.events import broadcast_to_web
from app.core.runtime import runtime
from app.enums import OrderStatus, PrinterStatus, RobotState, TaskStatus
from app.repositories.order_repository import OrderRepository
from app.repositories.printer_repository import PrinterRepository
from app.repositories.robot_task_repository import RobotTaskRepository
from app.schemas import OrderOut, PrinterOut
from app.services.dispatcher_service import DispatcherService

logger = logging.getLogger(__name__)


class TimerService:
    """출력 타이머·수령 타이머·작업 타임아웃을 주기적으로 점검한다 (PRD 3장, 9.5).

    DB의 timer_ends_at을 매 틱마다 그대로 읽어 판정하므로, 서버가 재시작돼도
    별도 복원 로직 없이 자연히 복구된다."""

    @staticmethod
    async def _sweep_print_timers() -> bool:
        now = datetime.utcnow()
        changed = False
        async with AsyncSessionLocal() as session:
            printers = await PrinterRepository.get_expired_printing(session, now)
            for printer in printers:
                order = await OrderRepository.get(session, printer.current_order_id)
                if order is None:
                    continue
                order.status = OrderStatus.PRINT_DONE
                order.print_completed_at = now
                order.updated_at = now
                printer.status = PrinterStatus.DONE
                printer.updated_at = now
                await broadcast_to_web(
                    session, "order.updated", OrderOut.model_validate(order).model_dump(mode="json")
                )
                await broadcast_to_web(
                    session, "printer.updated", PrinterOut.model_validate(printer).model_dump(mode="json")
                )
                changed = True
            await session.commit()
        return changed

    @staticmethod
    async def _sweep_pickup_timers() -> None:
        now = datetime.utcnow()
        async with AsyncSessionLocal() as session:
            for order in await OrderRepository.get_pickup(session):
                due_at = order.ready_at + timedelta(seconds=order.pickup_delay_sec)
                if due_at <= now:
                    order.status = OrderStatus.PICKED_UP
                    order.picked_up_at = now
                    order.updated_at = now
                    await broadcast_to_web(
                        session, "order.updated", OrderOut.model_validate(order).model_dump(mode="json")
                    )
            await session.commit()

    @staticmethod
    async def _sweep_task_timeouts() -> None:
        """디스패치 후 응답 없는 작업을 타임아웃 처리한다 (운영자 확인 후 수동 복구)."""
        now = datetime.utcnow()
        deadline = now - timedelta(seconds=settings.task_timeout_sec)
        async with AsyncSessionLocal() as session:
            tasks = await RobotTaskRepository.get_timed_out(session, deadline)
            for task in tasks:
                task.status = TaskStatus.FAILED
                task.error_code = "TIMEOUT"
                task.finished_at = now
                await broadcast_to_web(
                    session, "robot.state", {"state": RobotState.ERROR.value, "current_task_id": task.id}
                )
            if tasks:
                await session.commit()
                runtime.robot_state = RobotState.ERROR

    @staticmethod
    async def sweep_loop() -> None:
        while True:
            await asyncio.sleep(settings.timer_sweep_interval_sec)
            try:
                print_changed = await TimerService._sweep_print_timers()
                await TimerService._sweep_pickup_timers()
                await TimerService._sweep_task_timeouts()
                if print_changed:
                    await DispatcherService.run_cycle()
            except Exception:
                # 한 사이클의 오류가 스윕 루프 전체를 멈추지 않도록 한다.
                logger.exception("timer sweep cycle failed")
