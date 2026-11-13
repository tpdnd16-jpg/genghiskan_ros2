from fastapi import APIRouter, Depends
from pydantic import BaseModel
from sqlalchemy.ext.asyncio import AsyncSession

from app.core.database import get_session
from app.schemas import DebugFaultRequest
from app.services.debug_service import DebugService

router = APIRouter(prefix="/api/debug", tags=["debug"])


class DebugFaultResult(BaseModel):
    relayed: bool


@router.patch("/faults", response_model=DebugFaultResult)
async def set_debug_fault(
    req: DebugFaultRequest, session: AsyncSession = Depends(get_session)
) -> DebugFaultResult:
    relayed = await DebugService.inject_fault(session, req.kind, req.once)
    return DebugFaultResult(relayed=relayed)
