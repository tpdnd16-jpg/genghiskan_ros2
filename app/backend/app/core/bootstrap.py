from datetime import datetime

from sqlalchemy.ext.asyncio import AsyncSession

from app.repositories.board_stock_repository import BoardStockRepository
from app.repositories.printer_repository import PrinterRepository


async def ensure_seed_data(session: AsyncSession) -> None:
    """프린터 3대(빈 상태), 적재대 층 3개(빈 상태)가 없으면 만든다 (최초 기동 1회,
    PRD: assets/docs/prd-work-request-sqs.md 5장)."""
    now = datetime.utcnow()
    await PrinterRepository.ensure_slots(session, slots=(1, 2, 3), now=now)
    await BoardStockRepository.ensure_slots(session, slots=(1, 2, 3), now=now)
    await session.commit()
