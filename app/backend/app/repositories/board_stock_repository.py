from datetime import datetime

from sqlalchemy import select
from sqlalchemy.ext.asyncio import AsyncSession

from app.enums import BoardStockStatus
from app.models import BoardStock
from app.repositories.base import lock_for_update


class BoardStockRepository:
    """board_stock(적재대 층별 상태) 테이블 접근을 전담한다. board_inventory와는
    독립적으로 관리한다 (PRD: assets/docs/prd-work-request-sqs.md 5장)."""

    @staticmethod
    async def get(session: AsyncSession, slot: int) -> BoardStock | None:
        return await session.get(BoardStock, slot)

    @staticmethod
    async def list_all(session: AsyncSession) -> list[BoardStock]:
        stmt = select(BoardStock).order_by(BoardStock.slot)
        return list((await session.execute(stmt)).scalars().all())

    @staticmethod
    async def list_all_locked(session: AsyncSession) -> list[BoardStock]:
        stmt = select(BoardStock).order_by(BoardStock.slot)
        return list((await session.execute(lock_for_update(stmt, session))).scalars().all())

    @staticmethod
    async def ensure_slots(session: AsyncSession, slots: tuple[int, ...], now: datetime) -> None:
        existing = {s.slot for s in (await session.execute(select(BoardStock))).scalars().all()}
        for slot in slots:
            if slot not in existing:
                session.add(BoardStock(slot=slot, status=BoardStockStatus.EMPTY, updated_at=now))

    @staticmethod
    async def get_locked(session: AsyncSession, slot: int) -> BoardStock | None:
        stmt = select(BoardStock).where(BoardStock.slot == slot)
        return (await session.execute(lock_for_update(stmt, session))).scalars().first()

    @staticmethod
    async def top_occupied_locked(session: AsyncSession) -> BoardStock | None:
        """status='OCCUPIED'인 가장 큰 slot(맨 위 층)을 잠금과 함께 가져온다."""
        stmt = (
            select(BoardStock)
            .where(BoardStock.status == BoardStockStatus.OCCUPIED)
            .order_by(BoardStock.slot.desc())
            .limit(1)
        )
        return (await session.execute(lock_for_update(stmt, session))).scalars().first()
