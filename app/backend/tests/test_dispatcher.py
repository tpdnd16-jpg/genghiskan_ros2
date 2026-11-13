import pytest
from sqlalchemy import select

from app.core.database import AsyncSessionLocal
from app.enums import OrderSource, OrderStatus, PrinterStatus, TaskStatus, TaskType
from app.models import BoardInventory, Order, Printer, RobotTask
from app.services.bridge_protocol_service import BridgeProtocolService
from app.services.dispatcher_service import DispatcherService
from app.services.order_service import OrderService

pytestmark = pytest.mark.asyncio


async def test_load_dispatched_to_lowest_empty_slot():
    async with AsyncSessionLocal() as session:
        await OrderService.create_order(session, shape=None, source=OrderSource.MANUAL)

    async with AsyncSessionLocal() as session:
        order = (await session.execute(select(Order))).scalars().one()
        assert order.status == OrderStatus.LOADING
        assert order.printer_slot == 1

        task = (await session.execute(select(RobotTask))).scalars().one()
        assert task.type == TaskType.LOAD
        assert task.status == TaskStatus.DISPATCHED


async def test_unload_takes_priority_over_load():
    from datetime import datetime

    async with AsyncSessionLocal() as session:
        await OrderService.create_order(session, shape=None, source=OrderSource.MANUAL)  # slot 1 LOADING

    async with AsyncSessionLocal() as session:
        task1 = (await session.execute(select(RobotTask))).scalars().one()

    # LOAD 1 성공 처리 -> 로봇 다시 IDLE, 활성 작업 없음
    await BridgeProtocolService.handle_task_result({"task_id": task1.id, "success": True})

    # 프린터 2를 출력 완료(DONE) 상태로 미리 만들어 둔다.
    async with AsyncSessionLocal() as session:
        printer2 = await session.get(Printer, 2)
        done_order = Order(
            user_id=1,
            shape="SQUARE",
            print_duration_sec=40,
            status=OrderStatus.PRINT_DONE,
            source=OrderSource.MANUAL,
            printer_slot=2,
            created_at=datetime.utcnow(),
            print_completed_at=datetime.utcnow(),
            updated_at=datetime.utcnow(),
        )
        session.add(done_order)
        await session.flush()
        printer2.status = PrinterStatus.DONE
        printer2.current_order_id = done_order.id
        printer2.updated_at = datetime.utcnow()
        await session.commit()

        # 새 대기 주문도 함께 존재 -> UNLOAD(프린터2)가 LOAD보다 먼저 디스패치돼야 한다.
        await OrderService.create_order(session, shape=None, source=OrderSource.MANUAL)

    async with AsyncSessionLocal() as session:
        active = (
            await session.execute(select(RobotTask).where(RobotTask.status == TaskStatus.DISPATCHED))
        ).scalars().all()
        assert len(active) == 1
        assert active[0].type == TaskType.UNLOAD
        assert active[0].printer_slot == 2


async def test_refill_alert_when_inventory_empty():
    async with AsyncSessionLocal() as session:
        inventory = await session.get(BoardInventory, 1)
        inventory.remaining_count = 0
        await session.commit()

        await OrderService.create_order(session, shape=None, source=OrderSource.MANUAL)

    async with AsyncSessionLocal() as session:
        order = (await session.execute(select(Order))).scalars().one()
        assert order.status == OrderStatus.WAITING  # LOAD로 넘어가지 못하고 대기 유지

        inventory = await session.get(BoardInventory, 1)
        assert inventory.refill_required is True

        tasks = (await session.execute(select(RobotTask))).scalars().all()
        assert tasks == []


async def test_at_most_one_active_task_blocks_new_dispatch():
    async with AsyncSessionLocal() as session:
        await OrderService.create_order(session, shape=None, source=OrderSource.MANUAL)
        await OrderService.create_order(session, shape=None, source=OrderSource.MANUAL)

    await DispatcherService.run_cycle()

    async with AsyncSessionLocal() as session:
        active_tasks = (
            await session.execute(select(RobotTask).where(RobotTask.status == TaskStatus.DISPATCHED))
        ).scalars().all()
        assert len(active_tasks) == 1

        waiting = (
            await session.execute(select(Order).where(Order.status == OrderStatus.WAITING))
        ).scalars().all()
        assert len(waiting) == 1
