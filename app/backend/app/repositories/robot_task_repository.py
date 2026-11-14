from datetime import datetime

from sqlalchemy import select
from sqlalchemy.ext.asyncio import AsyncSession

from app.enums import ACTIVE_TASK_STATUSES, TaskType
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
    async def get_active_load_for_order_locked(session: AsyncSession, order_id: int) -> RobotTask | None:
        """작업요청(SQS) 경로의 pick_complete 처리용: 해당 주문의 활성 LOAD 작업을 찾는다."""
        stmt = (
            select(RobotTask)
            .where(
                RobotTask.order_id == order_id,
                RobotTask.type == TaskType.LOAD,
                RobotTask.status.in_(ACTIVE_TASK_STATUSES),
            )
            .order_by(RobotTask.id.desc())
            .limit(1)
        )
        return (await session.execute(lock_for_update(stmt, session))).scalars().first()

    @staticmethod
    async def get_timed_out(session: AsyncSession, deadline: datetime) -> list[RobotTask]:
        stmt = select(RobotTask).where(
            RobotTask.status.in_(ACTIVE_TASK_STATUSES), RobotTask.dispatched_at <= deadline
        )
        return list((await session.execute(stmt)).scalars().all())
