"""작업요청(SQS 디스패치) 1건 처리. 기존 가상 로봇 경로(OrderService,
DispatcherService, board_inventory)와는 완전히 분리된 신규 경로다
(PRD: assets/docs/prd-work-request-sqs.md). 이 경로는 요청 하나를 받을 때마다
그 자리에서 즉시 베드·프린터를 확인해 판정한다 — 기존 DispatcherService처럼
로봇이 IDLE이 될 때마다 재평가하는 루프가 아니다."""

import random
from datetime import datetime

from sqlalchemy.ext.asyncio import AsyncSession

from app.core.database import AsyncSessionLocal
from app.core.events import broadcast_to_web
from app.enums import (
    SHAPE_PRINT_DURATION_SEC,
    AlertReason,
    BoardStockStatus,
    OrderSource,
    OrderStatus,
    PrinterStatus,
    Shape,
    TaskStatus,
    TaskType,
)
from app.models import Order, RobotTask
from app.repositories.board_stock_repository import BoardStockRepository
from app.repositories.order_repository import OrderRepository
from app.repositories.printer_repository import PrinterRepository
from app.repositories.robot_task_repository import RobotTaskRepository
from app.repositories.user_repository import UserRepository
from app.schemas import OrderOut, PrinterOut
from app.services.sqs_producer_service import SqsProducerService

_SHAPE_CHOICES = list(Shape)


class BoardEmptyError(Exception):
    """적재대에 베드가 비어있어 작업요청을 디스패치할 수 없을 때. 주문 행 자체는
    이미 WAITING으로 저장돼 있다 (PRD 3장 2단계)."""

    def __init__(self, order_id: int):
        self.order_id = order_id
        super().__init__(f"board empty for order {order_id}")


class SqsProduceError(Exception):
    """SQS robot-commands 전송에 실패해 작업요청을 디스패치하지 못했을 때
    (PRD 3장 4단계 — 트랜잭션은 이미 롤백된 상태)."""

    def __init__(self, order_id: int):
        self.order_id = order_id
        super().__init__(f"SQS produce failed for order {order_id}")


class WorkRequestService:
    @staticmethod
    async def create(
        session: AsyncSession,
        shape: Shape | None,
        customer_name: str | None = None,
    ) -> Order:
        order = await WorkRequestService._insert_order(session, shape, customer_name)

        async with AsyncSessionLocal() as session2:
            board = await BoardStockRepository.top_occupied_locked(session2)
            if board is None:
                await broadcast_to_web(
                    session2, "alert.refill_required", {"reason": AlertReason.BOARD_STOCK_EMPTY.value}
                )
                await session2.commit()
                raise BoardEmptyError(order.id)

            printer = await PrinterRepository.first_empty_locked(session2)
            if printer is None:
                # 베드는 있지만 빈 프린터가 없음 -> 추가 조치 없이 WAITING으로 대기.
                await session2.rollback()
                return order

            now = datetime.utcnow()
            board.status = BoardStockStatus.RESERVED
            board.updated_at = now

            printer.status = PrinterStatus.RESERVED
            printer.current_order_id = order.id
            printer.updated_at = now

            task = RobotTask(
                order_id=order.id,
                type=TaskType.LOAD,
                printer_slot=printer.slot,
                status=TaskStatus.DISPATCHED,
                start_pos_id=board.slot,
                sd_pos_id=printer.slot,
                dispatched_at=now,
            )
            RobotTaskRepository.add(session2, task)

            order_db = await OrderRepository.get_locked(session2, order.id)
            order_db.status = OrderStatus.DISPATCHING
            order_db.printer_slot = printer.slot
            order_db.updated_at = now
            await session2.flush()

            produced = await SqsProducerService.produce_load_command(
                work_id=order.id, start_pos_id=board.slot, sd_pos_id=printer.slot
            )
            if not produced:
                await session2.rollback()
                raise SqsProduceError(order.id)

            await broadcast_to_web(
                session2, "order.updated", OrderOut.model_validate(order_db).model_dump(mode="json")
            )
            await broadcast_to_web(
                session2, "printer.updated", PrinterOut.model_validate(printer).model_dump(mode="json")
            )
            await broadcast_to_web(
                session2, "board_stock.updated", await WorkRequestService._board_stock_snapshot(session2)
            )
            await session2.commit()
            return order_db

    @staticmethod
    async def handle_pick_complete(work_id: int) -> None:
        """robot-events의 pick_complete 수신 처리 (PRD 5장): board_stock을
        RESERVED→EMPTY로, 주문을 DISPATCHING→LOADING으로 바꾼다. 알 수 없는
        work_id이거나 이미 처리된 경우(중복 수신)는 조용히 무시한다."""
        async with AsyncSessionLocal() as session:
            order = await OrderRepository.get_locked(session, work_id)
            if order is None or order.status != OrderStatus.DISPATCHING:
                await session.rollback()
                return

            task = await RobotTaskRepository.get_active_load_for_order_locked(session, work_id)
            if task is None or task.start_pos_id is None:
                await session.rollback()
                return

            now = datetime.utcnow()
            board = await BoardStockRepository.get_locked(session, task.start_pos_id)
            if board is not None and board.status == BoardStockStatus.RESERVED:
                board.status = BoardStockStatus.EMPTY
                board.updated_at = now

            order.status = OrderStatus.LOADING
            order.updated_at = now
            task.status = TaskStatus.RUNNING
            task.started_at = task.started_at or now
            await session.flush()

            await broadcast_to_web(
                session, "order.updated", OrderOut.model_validate(order).model_dump(mode="json")
            )
            await broadcast_to_web(
                session, "board_stock.updated", await WorkRequestService._board_stock_snapshot(session)
            )
            await session.commit()

    @staticmethod
    async def _insert_order(
        session: AsyncSession, shape: Shape | None, customer_name: str | None
    ) -> Order:
        chosen_shape = shape or random.choice(_SHAPE_CHOICES)
        now = datetime.utcnow()
        name = customer_name or f"손님-{random.randint(0, 9999):04d}"
        user = await UserRepository.add(session, name=name, created_at=now)

        order = Order(
            user_id=user.id,
            shape=chosen_shape,
            print_duration_sec=SHAPE_PRINT_DURATION_SEC[chosen_shape],
            status=OrderStatus.WAITING,
            source=OrderSource.MANUAL,
            created_at=now,
            updated_at=now,
        )
        OrderRepository.add(session, order)
        await session.flush()
        await broadcast_to_web(session, "order.created", OrderOut.model_validate(order).model_dump(mode="json"))
        await session.commit()
        return order

    @staticmethod
    async def _board_stock_snapshot(session: AsyncSession) -> dict:
        rows = await BoardStockRepository.list_all(session)
        return {"slots": [{"slot": r.slot, "status": r.status.value} for r in rows]}
