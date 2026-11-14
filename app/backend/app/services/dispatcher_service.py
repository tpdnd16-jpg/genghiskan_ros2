"""디스패처: 로봇이 IDLE일 때마다 UNLOAD > LOAD 우선순위로 작업을 하나 고르고
로봇 쪽(/ws/bridge)으로 내려보낸다 (PRD 3장). 여러 리포지토리를 넘나드는
유스케이스 orchestration이므로 서비스 계층에 둔다."""

from dataclasses import dataclass
from datetime import datetime

from sqlalchemy.ext.asyncio import AsyncSession

from app.core.database import AsyncSessionLocal
from app.core.events import broadcast_to_web, send_to_bridge
from app.core.runtime import runtime
from app.enums import ACTIVE_TASK_STATUSES, OrderStatus, PrinterStatus, RobotState, TaskStatus, TaskType
from app.models import Order, Printer, RobotTask
from app.repositories.order_repository import OrderRepository
from app.repositories.printer_repository import PrinterRepository
from app.repositories.robot_task_repository import RobotTaskRepository
from app.schemas import OrderOut, PrinterOut


@dataclass
class _ReservedTask:
    task: RobotTask
    order: Order
    printer: Printer


class DispatcherService:
    @staticmethod
    async def run_cycle() -> None:
        async with runtime.dispatcher_lock:
            await DispatcherService._run_cycle_locked()

    @staticmethod
    async def _run_cycle_locked() -> None:
        if runtime.robot_state != RobotState.IDLE:
            return

        async with AsyncSessionLocal() as session:
            active = await RobotTaskRepository.get_active_locked(session)
            if active is not None:
                await session.rollback()
                return

            reserved = await DispatcherService._try_reserve_unload(session)
            if reserved is None:
                reserved = await DispatcherService._try_reserve_load(session)
                if reserved is None:
                    await session.rollback()
                    return

            await broadcast_to_web(
                session, "order.updated", OrderOut.model_validate(reserved.order).model_dump(mode="json")
            )
            await broadcast_to_web(
                session, "printer.updated", PrinterOut.model_validate(reserved.printer).model_dump(mode="json")
            )
            await session.commit()

            task_id = reserved.task.id
            sent = await send_to_bridge(
                session,
                "task.dispatch",
                {
                    "task_id": task_id,
                    "type": reserved.task.type.value,
                    "slot": reserved.task.printer_slot,
                    "order_id": reserved.task.order_id,
                    # 가상 로봇이 7.7 단계 시간에 곱할 현재 시간 배율 (FR-20).
                    "time_scale": runtime.simulator_time_scale,
                },
            )
            await session.commit()

            if sent:
                runtime.current_task_id = task_id
            else:
                await DispatcherService._revert_unsent_task(task_id)

    @staticmethod
    async def _try_reserve_unload(session: AsyncSession) -> _ReservedTask | None:
        found = await PrinterRepository.get_done_with_order_locked(session)
        if found is None:
            return None
        printer, order = found

        now = datetime.utcnow()
        task = RobotTask(
            order_id=order.id,
            type=TaskType.UNLOAD,
            printer_slot=printer.slot,
            status=TaskStatus.DISPATCHED,
            dispatched_at=now,
        )
        RobotTaskRepository.add(session, task)
        order.status = OrderStatus.UNLOADING
        order.updated_at = now
        printer.status = PrinterStatus.UNLOADING
        printer.updated_at = now
        await session.flush()
        return _ReservedTask(task=task, order=order, printer=printer)

    @staticmethod
    async def _try_reserve_load(session: AsyncSession) -> _ReservedTask | None:
        """LOAD 작업을 예약한다."""
        order = await OrderRepository.oldest_waiting_locked(session)
        if order is None:
            return None

        printer = await PrinterRepository.first_empty_locked(session)
        if printer is None:
            return None

        now = datetime.utcnow()
        task = RobotTask(
            order_id=order.id,
            type=TaskType.LOAD,
            printer_slot=printer.slot,
            status=TaskStatus.DISPATCHED,
            dispatched_at=now,
        )
        RobotTaskRepository.add(session, task)
        order.status = OrderStatus.LOADING
        order.printer_slot = printer.slot
        order.updated_at = now
        printer.status = PrinterStatus.RESERVED
        printer.current_order_id = order.id
        printer.updated_at = now
        await session.flush()
        return _ReservedTask(task=task, order=order, printer=printer)

    @staticmethod
    async def _revert_unsent_task(task_id: int) -> None:
        """디스패치 직후 브릿지 전송에 실패하면 작업을 취소하고 원래 상태로 되돌린다."""
        async with AsyncSessionLocal() as session:
            task = await RobotTaskRepository.get(session, task_id)
            if task is None or task.status not in ACTIVE_TASK_STATUSES:
                return
            order = await OrderRepository.get(session, task.order_id)
            printer = await PrinterRepository.get(session, task.printer_slot)
            now = datetime.utcnow()

            task.status = TaskStatus.CANCELED
            task.finished_at = now

            if task.type == TaskType.LOAD:
                order.status = OrderStatus.WAITING
                order.printer_slot = None
                order.updated_at = now
                printer.status = PrinterStatus.EMPTY
                printer.current_order_id = None
                printer.updated_at = now
            else:
                order.status = OrderStatus.PRINT_DONE
                order.updated_at = now
                printer.status = PrinterStatus.DONE
                printer.updated_at = now

            await broadcast_to_web(session, "order.updated", OrderOut.model_validate(order).model_dump(mode="json"))
            await broadcast_to_web(
                session, "printer.updated", PrinterOut.model_validate(printer).model_dump(mode="json")
            )
            await broadcast_to_web(session, "bridge.connection", {"connected": False})
            await session.commit()

        runtime.robot_state = RobotState.DISCONNECTED
        runtime.bridge_ws = None
        runtime.current_task_id = None
