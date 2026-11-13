from datetime import datetime

from sqlalchemy import select
from sqlalchemy.ext.asyncio import AsyncSession

from app.enums import ACTIVE_TASK_STATUSES
from app.models import RobotTask
from app.repositories.base import lock_for_update


class RobotTaskRepository:
    """robot_tasks 테이블 접근을 전담한다."""

    @staticmethod
    def add(session: AsyncSession, task: RobotTask) -> None:
        session.add(task)

    @staticmethod
    async def get(session: AsyncSession, task_id: int) -> RobotTask | None:
        return await session.get(RobotTask, task_id)

    @staticmethod
    async def get_active_locked(session: AsyncSession) -> RobotTask | None:
        stmt = select(RobotTask).where(RobotTask.status.in_(ACTIVE_TASK_STATUSES))
        return (await session.execute(lock_for_update(stmt, session))).scalars().first()

    @staticmethod
    async def get_timed_out(session: AsyncSession, deadline: datetime) -> list[RobotTask]:
        stmt = select(RobotTask).where(
            RobotTask.status.in_(ACTIVE_TASK_STATUSES), RobotTask.dispatched_at <= deadline
        )
        return list((await session.execute(stmt)).scalars().all())
