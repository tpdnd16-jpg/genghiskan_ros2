from fastapi import APIRouter, Depends
from sqlalchemy.ext.asyncio import AsyncSession

from app.core.database import get_session
from app.models import BoardStock
from app.repositories.board_stock_repository import BoardStockRepository
from app.schemas import BoardStockOut
from app.services.board_stock_service import BoardStockService

router = APIRouter(prefix="/api/board-stock", tags=["board-stock"])


@router.get("", response_model=list[BoardStockOut])
async def list_board_stock(session: AsyncSession = Depends(get_session)) -> list[BoardStock]:
    return await BoardStockRepository.list_all(session)


@router.post("/refill-complete", response_model=list[BoardStockOut])
async def refill_complete(session: AsyncSession = Depends(get_session)) -> list[BoardStock]:
    return await BoardStockService.refill_complete(session)
