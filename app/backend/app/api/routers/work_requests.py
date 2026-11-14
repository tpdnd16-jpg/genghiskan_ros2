from fastapi import APIRouter, Depends, HTTPException
from sqlalchemy.ext.asyncio import AsyncSession

from app.core.database import get_session
from app.models import Order
from app.schemas import OrderCreateRequest, OrderOut
from app.services.work_request_service import BoardEmptyError, SqsProduceError, WorkRequestService

router = APIRouter(prefix="/api/work-requests", tags=["work-requests"])


@router.post("", response_model=OrderOut, status_code=201)
async def create_work_request(
    req: OrderCreateRequest, session: AsyncSession = Depends(get_session)
) -> Order:
    try:
        return await WorkRequestService.create(session, req.shape, customer_name=req.customer_name)
    except BoardEmptyError as exc:
        raise HTTPException(
            status_code=409,
            detail={
                "error_code": "BOARD_EMPTY",
                "message": "적재대에 베드가 비어있습니다",
                "order_id": exc.order_id,
            },
        ) from exc
    except SqsProduceError as exc:
        raise HTTPException(
            status_code=502,
            detail={
                "error_code": "SQS_PRODUCE_FAILED",
                "message": "로봇에 작업을 전달하지 못했습니다. 운영자 확인이 필요합니다.",
                "order_id": exc.order_id,
            },
        ) from exc
