from fastapi import APIRouter, Depends, Query
from sqlalchemy.ext.asyncio import AsyncSession

from app.core.database import get_session
from app.enums import OrderSource, OrderStatus
from app.models import Order
from app.schemas import OrderCreateRequest, OrderOut
from app.services.order_service import OrderService

router = APIRouter(prefix="/api/orders", tags=["orders"])


@router.post("", response_model=OrderOut, status_code=201)
async def create_manual_order(
    req: OrderCreateRequest, session: AsyncSession = Depends(get_session)
) -> Order:
    return await OrderService.create_order(
        session, req.shape, OrderSource.MANUAL, customer_name=req.customer_name
    )


@router.get("", response_model=list[OrderOut])
async def list_orders(
    status: OrderStatus | None = Query(default=None),
    limit: int = Query(default=50, ge=1, le=500),
    session: AsyncSession = Depends(get_session),
) -> list[Order]:
    return await OrderService.list_orders(session, status, limit)
