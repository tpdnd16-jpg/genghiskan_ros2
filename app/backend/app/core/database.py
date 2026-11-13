from collections.abc import AsyncIterator

from sqlalchemy import event
from sqlalchemy.ext.asyncio import AsyncSession, async_sessionmaker, create_async_engine
from sqlalchemy.orm import DeclarativeBase
from sqlalchemy.pool import StaticPool

from app.core.config import settings


class Base(DeclarativeBase):
    pass


if settings.database_url.startswith("sqlite"):
    # 테스트용 인메모리 SQLite: 커넥션을 하나로 고정해 데이터가 유지되게 한다.
    engine = create_async_engine(
        settings.database_url, poolclass=StaticPool, connect_args={"check_same_thread": False}
    )
else:
    engine = create_async_engine(settings.database_url, pool_pre_ping=True)

# DB·서버·컨테이너 중 서버 한 곳에서만 시간대를 다루도록 세션 time_zone을 UTC로 고정한다.
if engine.sync_engine.dialect.name == "mysql":

    @event.listens_for(engine.sync_engine, "connect")
    def _set_mysql_session_timezone(dbapi_connection, connection_record) -> None:
        cursor = dbapi_connection.cursor()
        cursor.execute("SET time_zone = '+00:00'")
        cursor.close()


AsyncSessionLocal = async_sessionmaker(engine, expire_on_commit=False, class_=AsyncSession)


async def get_session() -> AsyncIterator[AsyncSession]:
    async with AsyncSessionLocal() as session:
        yield session
