from sqlalchemy import Select
from sqlalchemy.ext.asyncio import AsyncSession


def lock_for_update(stmt: Select, session: AsyncSession) -> Select:
    """레포지토리 전용 헬퍼. MySQL에서만 SELECT ... FOR UPDATE를 적용한다
    (SQLite는 단위 테스트에서만 쓰며 FOR UPDATE 문법을 지원하지 않는다)."""
    if session.bind is not None and session.bind.dialect.name == "mysql":
        return stmt.with_for_update()
    return stmt
