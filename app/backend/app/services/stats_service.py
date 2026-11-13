from sqlalchemy.ext.asyncio import AsyncSession

from app.enums import OrderStatus
from app.repositories.order_repository import OrderRepository
from app.schemas import StatsOut


def _avg(rows: list[tuple]) -> float | None:
    if not rows:
        return None
    deltas = [(b - a).total_seconds() for a, b in rows]
    return sum(deltas) / len(deltas)


class StatsService:
    @staticmethod
    async def get_stats(session: AsyncSession) -> StatsOut:
        picked_up_count = await OrderRepository.count_by_status(session, OrderStatus.PICKED_UP)
        wait_rows = await OrderRepository.wait_duration_rows(session)
        print_rows = await OrderRepository.print_duration_rows(session)
        pickup_rows = await OrderRepository.pickup_duration_rows(session)

        return StatsOut(
            picked_up_count=picked_up_count,
            avg_wait_sec=_avg(wait_rows),
            avg_print_sec=_avg(print_rows),
            avg_pickup_wait_sec=_avg(pickup_rows),
        )
