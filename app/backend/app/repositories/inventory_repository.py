from datetime import datetime

from sqlalchemy import select
from sqlalchemy.ext.asyncio import AsyncSession

from app.models import BoardInventory
from app.repositories.base import lock_for_update

_SINGLETON_ID = 1


class InventoryRepository:
    """board_inventory 테이블(단일 행) 접근을 전담한다."""

    @staticmethod
    async def get(session: AsyncSession) -> BoardInventory:
        return (await session.get(BoardInventory, _SINGLETON_ID)) or _missing()

    @staticmethod
    async def get_locked(session: AsyncSession) -> BoardInventory:
        stmt = select(BoardInventory).where(BoardInventory.id == _SINGLETON_ID)
        return (await session.execute(lock_for_update(stmt, session))).scalar_one()

    @staticmethod
    async def ensure_default(session: AsyncSession, initial_count: int, capacity: int, now: datetime) -> None:
        existing = await session.get(BoardInventory, _SINGLETON_ID)
        if existing is None:
            session.add(
                BoardInventory(
                    id=_SINGLETON_ID,
                    remaining_count=initial_count,
                    capacity=capacity,
                    refill_required=False,
                    updated_at=now,
                )
            )


def _missing() -> BoardInventory:
    raise RuntimeError("board_inventory 시드 데이터가 없습니다 (ensure_default 미실행)")
