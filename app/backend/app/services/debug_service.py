from sqlalchemy.ext.asyncio import AsyncSession

from app.core.events import send_to_bridge


class DebugService:
    @staticmethod
    async def inject_fault(session: AsyncSession, kind: str, once: bool) -> bool:
        """가상 로봇(/ws/bridge) 전용 장애 주입. 로봇이 연결돼 있지 않으면 전달할 대상이 없다."""
        relayed = await send_to_bridge(session, "robot.fault", {"kind": kind, "once": once})
        await session.commit()
        return relayed
