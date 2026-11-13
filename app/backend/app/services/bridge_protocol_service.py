"""서버 ↔ 로봇 쪽 프로세스(/ws/bridge) 메시지의 업무 로직 (PRD 7.4, 9.4, 9.5).

전송 계층(app.api.ws.bridge_ws)은 소켓 수명주기(인증·수신 루프·하트비트)만
담당하고, 각 메시지 타입에 대한 실제 처리는 이 서비스에 위임한다."""

import random
from datetime import datetime, timedelta

from sqlalchemy.ext.asyncio import AsyncSession

from app.core.database import AsyncSessionLocal
from app.core.events import broadcast_to_web
from app.core.runtime import runtime
from app.enums import ACTIVE_TASK_STATUSES, OrderStatus, PrinterStatus, RobotState, TaskStatus, TaskType
from app.models import RobotTask
from app.repositories.inventory_repository import InventoryRepository
from app.repositories.order_repository import OrderRepository
from app.repositories.printer_repository import PrinterRepository
from app.repositories.robot_task_repository import RobotTaskRepository
from app.schemas import BoardInventoryOut, OrderOut, PrinterOut
from app.services.dispatcher_service import DispatcherService


class BridgeProtocolService:
    @staticmethod
    async def handle_message(msg_type: str, data: dict) -> None:
        handler = _HANDLERS.get(msg_type)
        if handler is None:
            return
        await handler(data)

    @staticmethod
    async def handle_hello(data: dict) -> None:
        raw_state = data.get("robot_state", "IDLE")
        try:
            runtime.robot_state = RobotState(raw_state)
        except ValueError:
            runtime.robot_state = RobotState.IDLE
        runtime.current_task_id = data.get("current_task_id")

        async with AsyncSessionLocal() as session:
            active = await RobotTaskRepository.get_active_locked(session)
            if active is not None and active.id != runtime.current_task_id:
                # 서버 DB에는 진행 중인 작업이 있는데 로봇은 모른다 → 로봇 기준으로 되돌린다.
                await BridgeProtocolService._revert_task(session, active, error_code="RECONNECT_MISMATCH")

            await broadcast_to_web(session, "bridge.connection", {"connected": True})
            await broadcast_to_web(
                session,
                "robot.state",
                {"state": runtime.robot_state.value, "current_task_id": runtime.current_task_id},
            )
            await session.commit()

        await DispatcherService.run_cycle()

    @staticmethod
    async def handle_task_accepted(data: dict) -> None:
        task_id = data.get("task_id")
        async with AsyncSessionLocal() as session:
            task = await RobotTaskRepository.get(session, task_id)
            if task is None or task.status != TaskStatus.DISPATCHED:
                return
            task.status = TaskStatus.RUNNING
            task.started_at = datetime.utcnow()
            await session.commit()
        runtime.current_task_id = task_id

    @staticmethod
    async def handle_task_rejected(data: dict) -> None:
        task_id = data.get("task_id")
        reason = data.get("reason", "BUSY")
        async with AsyncSessionLocal() as session:
            task = await RobotTaskRepository.get(session, task_id)
            if task is None or task.status not in ACTIVE_TASK_STATUSES:
                return
            await BridgeProtocolService._revert_task(session, task, error_code=reason)
            await session.commit()
        runtime.current_task_id = None
        await DispatcherService.run_cycle()

    @staticmethod
    async def _revert_task(session: AsyncSession, task: RobotTask, error_code: str) -> None:
        """작업을 취소하고 주문·프린터를 디스패치 이전 상태로 되돌린다."""
        order = await OrderRepository.get(session, task.order_id)
        printer = await PrinterRepository.get(session, task.printer_slot)
        now = datetime.utcnow()

        task.status = TaskStatus.CANCELED
        task.error_code = error_code
        task.finished_at = now

        if task.type == TaskType.LOAD:
            order.status = OrderStatus.WAITING
            order.printer_slot = None
            printer.status = PrinterStatus.EMPTY
            printer.current_order_id = None
        else:
            order.status = OrderStatus.PRINT_DONE
            printer.status = PrinterStatus.DONE

        order.updated_at = now
        printer.updated_at = now

        await broadcast_to_web(session, "order.updated", OrderOut.model_validate(order).model_dump(mode="json"))
        await broadcast_to_web(session, "printer.updated", PrinterOut.model_validate(printer).model_dump(mode="json"))

    @staticmethod
    async def handle_task_feedback(data: dict) -> None:
        task_id = data.get("task_id")
        async with AsyncSessionLocal() as session:
            task = await RobotTaskRepository.get(session, task_id)
            if task is None:
                return
            task.last_phase = data.get("phase")
            await broadcast_to_web(session, "robot.feedback", data)
            await session.commit()

    @staticmethod
    async def handle_task_result(data: dict) -> None:
        task_id = data.get("task_id")
        success = bool(data.get("success"))
        error_code = data.get("error_code")

        async with AsyncSessionLocal() as session:
            task = await RobotTaskRepository.get(session, task_id)
            if task is None or task.status not in ACTIVE_TASK_STATUSES:
                return  # 이미 종료된 작업의 중복 결과는 무시 (요구사항 9.5)

            order = await OrderRepository.get(session, task.order_id)
            printer = await PrinterRepository.get(session, task.printer_slot)
            now = datetime.utcnow()
            task.finished_at = now

            if success:
                task.status = TaskStatus.SUCCEEDED
                if task.type == TaskType.LOAD:
                    await BridgeProtocolService._apply_load_success(session, order, printer, now)
                else:
                    await BridgeProtocolService._apply_unload_success(order, printer, now)
                order.updated_at = now
                printer.updated_at = now
            else:
                task.status = TaskStatus.FAILED
                task.error_code = error_code
                if task.type == TaskType.LOAD and error_code == "NO_BOARD":
                    await BridgeProtocolService._apply_no_board(session, order, printer, now)
                else:
                    # GRIP_FAIL/MOTION_FAIL 등: 주문·슬롯은 현재 단계에 유지하고 로봇 ERROR로
                    # 넘겨 운영자 확인을 기다린다 (robot.state 메시지가 뒤이어 ERROR를 알린다).
                    order.updated_at = now
                    printer.updated_at = now

            await broadcast_to_web(session, "order.updated", OrderOut.model_validate(order).model_dump(mode="json"))
            await broadcast_to_web(
                session, "printer.updated", PrinterOut.model_validate(printer).model_dump(mode="json")
            )
            await session.commit()

        runtime.current_task_id = None
        await DispatcherService.run_cycle()

    @staticmethod
    async def _apply_load_success(session: AsyncSession, order, printer, now: datetime) -> None:
        inventory = await InventoryRepository.get(session)
        inventory.remaining_count = max(0, inventory.remaining_count - 1)
        inventory.updated_at = now
        order.status = OrderStatus.PRINTING
        order.started_at = now
        printer.status = PrinterStatus.PRINTING
        printer.timer_ends_at = now + timedelta(seconds=order.print_duration_sec * runtime.simulator_time_scale)
        await broadcast_to_web(
            session, "inventory.updated", BoardInventoryOut.model_validate(inventory).model_dump(mode="json")
        )

    @staticmethod
    async def _apply_unload_success(order, printer, now: datetime) -> None:
        order.status = OrderStatus.READY_FOR_PICKUP
        order.ready_at = now
        order.pickup_delay_sec = max(1, round(random.randint(1, 10) * runtime.simulator_time_scale))
        printer.status = PrinterStatus.EMPTY
        printer.current_order_id = None

    @staticmethod
    async def _apply_no_board(session: AsyncSession, order, printer, now: datetime) -> None:
        """실물과 DB가 어긋났다는 뜻이므로 실물(보드 없음) 기준으로 맞춘다 (요구사항 12)."""
        order.status = OrderStatus.WAITING
        order.printer_slot = None
        printer.status = PrinterStatus.EMPTY
        printer.current_order_id = None
        order.updated_at = now
        printer.updated_at = now

        inventory = await InventoryRepository.get(session)
        inventory.remaining_count = 0
        inventory.refill_required = True
        inventory.updated_at = now
        await broadcast_to_web(
            session, "inventory.updated", BoardInventoryOut.model_validate(inventory).model_dump(mode="json")
        )
        await broadcast_to_web(session, "alert.refill_required", {"reason": "ROBOT_NO_BOARD"})

    @staticmethod
    async def handle_robot_state(data: dict) -> None:
        raw_state = data.get("state")
        try:
            runtime.robot_state = RobotState(raw_state)
        except (TypeError, ValueError):
            return
        runtime.current_task_id = data.get("current_task_id")

        async with AsyncSessionLocal() as session:
            await broadcast_to_web(
                session,
                "robot.state",
                {"state": runtime.robot_state.value, "current_task_id": runtime.current_task_id},
            )
            await session.commit()

        if runtime.robot_state == RobotState.IDLE:
            await DispatcherService.run_cycle()

    @staticmethod
    async def on_bridge_disconnected() -> None:
        runtime.bridge_ws = None
        runtime.robot_state = RobotState.DISCONNECTED
        runtime.current_task_id = None
        async with AsyncSessionLocal() as session:
            await broadcast_to_web(session, "bridge.connection", {"connected": False})
            await broadcast_to_web(
                session, "robot.state", {"state": RobotState.DISCONNECTED.value, "current_task_id": None}
            )
            await session.commit()


_HANDLERS = {
    "bridge.hello": BridgeProtocolService.handle_hello,
    "task.accepted": BridgeProtocolService.handle_task_accepted,
    "task.rejected": BridgeProtocolService.handle_task_rejected,
    "task.feedback": BridgeProtocolService.handle_task_feedback,
    "task.result": BridgeProtocolService.handle_task_result,
    "robot.state": BridgeProtocolService.handle_robot_state,
}
