from datetime import datetime

from sqlalchemy.ext.asyncio import AsyncSession

from app.models import User


class UserRepository:
    """users 테이블 접근을 전담한다. 세션/트랜잭션 관리는 호출한 서비스가 책임진다."""

    @staticmethod
    async def add(session: AsyncSession, name: str, created_at: datetime) -> User:
        user = User(name=name, created_at=created_at)
        session.add(user)
        await session.flush()
        return user
