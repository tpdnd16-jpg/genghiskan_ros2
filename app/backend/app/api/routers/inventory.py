from fastapi import APIRouter, Depends
from sqlalchemy.ext.asyncio import AsyncSession

from app.core.database import get_session
from app.models import BoardInventory
from app.schemas import BoardInventoryOut, InventoryRefillRequest
from app.services.inventory_service import InventoryService

router = APIRouter(prefix="/api/inventory", tags=["inventory"])


@router.post("/refill", response_model=BoardInventoryOut)
async def refill_inventory(
    req: InventoryRefillRequest, session: AsyncSession = Depends(get_session)
) -> BoardInventory:
    return await InventoryService.refill(session, req.count, req.fill_physical)
