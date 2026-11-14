from datetime import datetime

from sqlalchemy.ext.asyncio import AsyncSession

from app.core.events import broadcast_to_web
from app.enums import BoardStockStatus
from app.models import BoardStock
from app.repositories.board_stock_repository import BoardStockRepository


class BoardStockService:
    @staticmethod
    async def refill_complete(session: AsyncSession) -> list[BoardStock]:
        """"채우기 완료" 버튼: 사람이 적재대를 물리적으로 다 채운 뒤 누르면,
        그 시점에 EMPTY인 층을 모두 OCCUPIED로 바꾼다. 수량 입력은 받지 않는다
        (PRD: assets/docs/prd-work-request-sqs.md 5장 — 사용자 확정)."""
        rows = await BoardStockRepository.list_all_locked(session)
        now = datetime.utcnow()
        for row in rows:
            if row.status == BoardStockStatus.EMPTY:
                row.status = BoardStockStatus.OCCUPIED
                row.updated_at = now

        await broadcast_to_web(
            session,
            "board_stock.updated",
            {"slots": [{"slot": r.slot, "status": r.status.value} for r in rows]},
        )
        await broadcast_to_web(session, "alert.cleared", {})
        await session.commit()
        return rows
