from fastapi import APIRouter, Depends
from sqlalchemy.ext.asyncio import AsyncSession

from app.core.database import get_session
from app.schemas import HealthOut
from app.services.health_service import HealthService

router = APIRouter(prefix="/api/health", tags=["health"])


@router.get("", response_model=HealthOut)
async def health(session: AsyncSession = Depends(get_session)) -> HealthOut:
    return await HealthService.check(session)
