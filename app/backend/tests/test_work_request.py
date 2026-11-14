from datetime import datetime

import pytest
from sqlalchemy import select

from app.core.database import AsyncSessionLocal
from app.enums import BoardStockStatus, OrderStatus, PrinterStatus, TaskStatus, TaskType
from app.models import BoardStock, Order, Printer, RobotTask
from app.repositories.board_stock_repository import BoardStockRepository
from app.services.board_stock_service import BoardStockService
from app.services.sqs_producer_service import SqsProducerService
from app.services.work_request_service import BoardEmptyError, SqsProduceError, WorkRequestService

pytestmark = pytest.mark.asyncio


async def _occupy(slot: int) -> None:
    async with AsyncSessionLocal() as session:
        board = await session.get(BoardStock, slot)
        board.status = BoardStockStatus.OCCUPIED
        board.updated_at = datetime.utcnow()
        await session.commit()


async def _fill_all_printers() -> None:
    async with AsyncSessionLocal() as session:
        for slot in (1, 2, 3):
            printer = await session.get(Printer, slot)
            printer.status = PrinterStatus.PRINTING
            printer.updated_at = datetime.utcnow()
        await session.commit()


async def test_board_empty_returns_error_but_keeps_order_waiting():
    async with AsyncSessionLocal() as session:
        with pytest.raises(BoardEmptyError):
            await WorkRequestService.create(session, shape=None)

    async with AsyncSessionLocal() as session:
        order = (await session.execute(select(Order))).scalars().one()
        assert order.status == OrderStatus.WAITING

        tasks = (await session.execute(select(RobotTask))).scalars().all()
        assert tasks == []


async def test_no_empty_printer_keeps_order_waiting_as_success():
    await _occupy(2)
    await _fill_all_printers()

    async with AsyncSessionLocal() as session:
        order = await WorkRequestService.create(session, shape=None)
        assert order.status == OrderStatus.WAITING

    async with AsyncSessionLocal() as session:
        tasks = (await session.execute(select(RobotTask))).scalars().all()
        assert tasks == []

        board = await session.get(BoardStock, 2)
        assert board.status == BoardStockStatus.OCCUPIED  # 그대로, RESERVED로 넘어가지 않음


async def test_successful_dispatch_sets_dispatching_and_reserves_slots(monkeypatch):
    await _occupy(2)
    monkeypatch.setattr(SqsProducerService, "produce_load_command", _fake_produce(True))

    async with AsyncSessionLocal() as session:
        order = await WorkRequestService.create(session, shape=None)
        assert order.status == OrderStatus.DISPATCHING
        assert order.printer_slot == 1  # 가장 작은 번호의 빈 프린터

    async with AsyncSessionLocal() as session:
        board = await session.get(BoardStock, 2)
        assert board.status == BoardStockStatus.RESERVED

        printer = await session.get(Printer, 1)
        assert printer.status == PrinterStatus.RESERVED
        assert printer.current_order_id == order.id

        task = (await session.execute(select(RobotTask))).scalars().one()
        assert task.type == TaskType.LOAD
        assert task.status == TaskStatus.DISPATCHED
        assert task.start_pos_id == 2
        assert task.sd_pos_id == 1


async def test_sqs_produce_failure_rolls_back_reservation(monkeypatch):
    await _occupy(2)
    monkeypatch.setattr(SqsProducerService, "produce_load_command", _fake_produce(False))

    async with AsyncSessionLocal() as session:
        with pytest.raises(SqsProduceError):
            await WorkRequestService.create(session, shape=None)

    async with AsyncSessionLocal() as session:
        order = (await session.execute(select(Order))).scalars().one()
        assert order.status == OrderStatus.WAITING
        assert order.printer_slot is None

        board = await session.get(BoardStock, 2)
        assert board.status == BoardStockStatus.OCCUPIED  # RESERVED에서 원복

        printer = await session.get(Printer, 1)
        assert printer.status == PrinterStatus.EMPTY
        assert printer.current_order_id is None

        tasks = (await session.execute(select(RobotTask))).scalars().all()
        assert tasks == []


async def test_pick_complete_moves_order_to_loading_and_frees_slot(monkeypatch):
    await _occupy(2)
    monkeypatch.setattr(SqsProducerService, "produce_load_command", _fake_produce(True))

    async with AsyncSessionLocal() as session:
        order = await WorkRequestService.create(session, shape=None)

    await WorkRequestService.handle_pick_complete(order.id)

    async with AsyncSessionLocal() as session:
        refreshed = await session.get(Order, order.id)
        assert refreshed.status == OrderStatus.LOADING

        board = await session.get(BoardStock, 2)
        assert board.status == BoardStockStatus.EMPTY

        task = (await session.execute(select(RobotTask))).scalars().one()
        assert task.status == TaskStatus.RUNNING
        assert task.started_at is not None


async def test_pick_complete_ignores_unknown_work_id():
    await WorkRequestService.handle_pick_complete(999999)  # 예외 없이 조용히 무시


async def test_refill_complete_fills_only_empty_slots():
    await _occupy(1)

    async with AsyncSessionLocal() as session:
        rows = await BoardStockService.refill_complete(session)
        by_slot = {r.slot: r.status for r in rows}
        assert by_slot[1] == BoardStockStatus.OCCUPIED  # 이미 채워져 있던 슬롯은 그대로
        assert by_slot[2] == BoardStockStatus.OCCUPIED
        assert by_slot[3] == BoardStockStatus.OCCUPIED

    async with AsyncSessionLocal() as session:
        rows = await BoardStockRepository.list_all(session)
        assert all(r.status == BoardStockStatus.OCCUPIED for r in rows)


def _fake_produce(result: bool):
    async def _produce(*args, **kwargs) -> bool:
        return result

    return _produce
