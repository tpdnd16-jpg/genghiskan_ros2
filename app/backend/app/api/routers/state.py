from fastapi import APIRouter, Depends
from sqlalchemy.ext.asyncio import AsyncSession

from app.core.database import get_session
from app.schemas import StateSnapshot
from app.services.state_service import StateService

router = APIRouter(prefix="/api/state", tags=["state"])


@router.get("", response_model=StateSnapshot)
async def get_state(session: AsyncSession = Depends(get_session)) -> StateSnapshot:
    return await StateService.build_snapshot(session)
