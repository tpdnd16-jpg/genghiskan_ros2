from sqlalchemy import func, select
from sqlalchemy.ext.asyncio import AsyncSession

from app.enums import ACTIVE_ORDER_STATUSES, OrderStatus
from app.models import Order
from app.repositories.base import lock_for_update


class OrderRepository:
    """orders 테이블 접근을 전담한다. 상태 변경(mutation)은 서비스 계층이
    엔티티 속성을 직접 바꾸고 트랜잭션을 커밋하는 방식으로 처리한다."""

    @staticmethod
    def add(session: AsyncSession, order: Order) -> None:
        session.add(order)

    @staticmethod
    async def get(session: AsyncSession, order_id: int) -> Order | None:
        return await session.get(Order, order_id)

    @staticmethod
    async def list_recent(
        session: AsyncSession, status: OrderStatus | None, limit: int
    ) -> list[Order]:
        stmt = select(Order).order_by(Order.created_at.desc()).limit(limit)
        if status is not None:
            stmt = stmt.where(Order.status == status)
        return list((await session.execute(stmt)).scalars().all())

    @staticmethod
    async def get_waiting(session: AsyncSession) -> list[Order]:
        stmt = select(Order).where(Order.status == OrderStatus.WAITING).order_by(Order.created_at)
        return list((await session.execute(stmt)).scalars().all())

    @staticmethod
    async def get_active(session: AsyncSession) -> list[Order]:
        stmt = (
            select(Order).where(Order.status.in_(ACTIVE_ORDER_STATUSES)).order_by(Order.created_at)
        )
        return list((await session.execute(stmt)).scalars().all())

    @staticmethod
    async def get_pickup(session: AsyncSession) -> list[Order]:
        stmt = (
            select(Order)
            .where(Order.status == OrderStatus.READY_FOR_PICKUP)
            .order_by(Order.ready_at)
        )
        return list((await session.execute(stmt)).scalars().all())

    @staticmethod
    async def oldest_waiting_locked(session: AsyncSession) -> Order | None:
        stmt = select(Order).where(Order.status == OrderStatus.WAITING).order_by(Order.created_at)
        return (await session.execute(lock_for_update(stmt, session))).scalars().first()

    @staticmethod
    async def count_by_status(session: AsyncSession, status: OrderStatus) -> int:
        stmt = select(func.count()).where(Order.status == status)
        return (await session.execute(stmt)).scalar_one()

    @staticmethod
    async def wait_duration_rows(session: AsyncSession) -> list[tuple]:
        stmt = select(Order.created_at, Order.started_at).where(Order.started_at.isnot(None))
        return list((await session.execute(stmt)).all())

    @staticmethod
    async def print_duration_rows(session: AsyncSession) -> list[tuple]:
        stmt = select(Order.started_at, Order.print_completed_at).where(
            Order.started_at.isnot(None), Order.print_completed_at.isnot(None)
        )
        return list((await session.execute(stmt)).all())

    @staticmethod
    async def pickup_duration_rows(session: AsyncSession) -> list[tuple]:
        stmt = select(Order.ready_at, Order.picked_up_at).where(Order.picked_up_at.isnot(None))
        return list((await session.execute(stmt)).all())
