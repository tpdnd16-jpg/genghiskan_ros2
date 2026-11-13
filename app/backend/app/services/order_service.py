import random
from datetime import datetime

from sqlalchemy.ext.asyncio import AsyncSession

from app.core.events import broadcast_to_web
from app.enums import SHAPE_PRINT_DURATION_SEC, OrderSource, OrderStatus, Shape
from app.models import Order
from app.repositories.order_repository import OrderRepository
from app.repositories.user_repository import UserRepository
from app.schemas import OrderOut
from app.services.dispatcher_service import DispatcherService

_SHAPE_CHOICES = list(Shape)


class OrderService:
    @staticmethod
    async def create_order(
        session: AsyncSession,
        shape: Shape | None,
        source: OrderSource,
        customer_name: str | None = None,
    ) -> Order:
        chosen_shape = shape or random.choice(_SHAPE_CHOICES)
        now = datetime.utcnow()

        name = customer_name or f"손님-{random.randint(0, 9999):04d}"
        user = await UserRepository.add(session, name=name, created_at=now)

        order = Order(
            user_id=user.id,
            shape=chosen_shape,
            print_duration_sec=SHAPE_PRINT_DURATION_SEC[chosen_shape],
            status=OrderStatus.WAITING,
            source=source,
            created_at=now,
            updated_at=now,
        )
        OrderRepository.add(session, order)
        await session.flush()

        await broadcast_to_web(session, "order.created", OrderOut.model_validate(order).model_dump(mode="json"))
        await session.commit()

        await DispatcherService.run_cycle()
        # 디스패처가 다른 세션으로 이 주문을 즉시 LOAD 디스패치했을 수 있으므로 최신 상태로 갱신한다.
        await session.refresh(order)
        return order

    @staticmethod
    async def list_orders(session: AsyncSession, status: OrderStatus | None, limit: int) -> list[Order]:
        return await OrderRepository.list_recent(session, status, limit)
