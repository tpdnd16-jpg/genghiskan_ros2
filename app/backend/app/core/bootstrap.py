from datetime import datetime

from sqlalchemy.ext.asyncio import AsyncSession

from app.core.config import settings
from app.repositories.inventory_repository import InventoryRepository
from app.repositories.printer_repository import PrinterRepository


async def ensure_seed_data(session: AsyncSession) -> None:
    """프린터 3대(빈 상태)와 보드 재고 초기 행이 없으면 만든다 (최초 기동 1회)."""
    now = datetime.utcnow()
    await PrinterRepository.ensure_slots(session, slots=(1, 2, 3), now=now)
    await InventoryRepository.ensure_default(
        session, initial_count=settings.board_initial_count, capacity=settings.board_capacity, now=now
    )
    await session.commit()
