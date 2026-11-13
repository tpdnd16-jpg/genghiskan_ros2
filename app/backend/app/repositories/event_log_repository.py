from datetime import datetime, timezone
from typing import Any

from sqlalchemy.exc import IntegrityError
from sqlalchemy.ext.asyncio import AsyncSession

from app.enums import EventDirection
from app.models import EventLog


class EventLogRepository:
    """event_logs 테이블 접근을 전담한다 (요구사항 10.1 관측성: 모든 WS 메시지 저장)."""

    @staticmethod
    def add(session: AsyncSession, envelope: dict[str, Any], direction: EventDirection) -> None:
        session.add(
            EventLog(
                event_id=envelope["event_id"],
                type=envelope["type"],
                direction=direction,
                payload=envelope,
                created_at=datetime.now(timezone.utc).replace(tzinfo=None),
            )
        )

    @staticmethod
    async def try_add_unique(
        session: AsyncSession, envelope: dict[str, Any], direction: EventDirection
    ) -> bool:
        """event_id가 이미 존재하면(중복 수신) False를 반환하고 세션을 롤백한다."""
        EventLogRepository.add(session, envelope, direction)
        try:
            await session.flush()
            return True
        except IntegrityError:
            await session.rollback()
            return False
