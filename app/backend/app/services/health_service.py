from sqlalchemy import text
from sqlalchemy.ext.asyncio import AsyncSession

from app.core.runtime import runtime
from app.schemas import HealthOut


class HealthService:
    @staticmethod
    async def check(session: AsyncSession) -> HealthOut:
        db_ok = True
        try:
            await session.execute(text("SELECT 1"))
        except Exception:
            db_ok = False

        return HealthOut(db=db_ok, bridge_connected=runtime.bridge_connected(), robot_state=runtime.robot_state)
