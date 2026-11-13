from fastapi import APIRouter

from app.schemas import SimulatorSettingsOut, SimulatorSettingsPatch
from app.services.simulator_service import SimulatorService

router = APIRouter(prefix="/api/simulator", tags=["simulator"])


@router.get("", response_model=SimulatorSettingsOut)
async def get_simulator_settings() -> SimulatorSettingsOut:
    return SimulatorService.get_settings()


@router.patch("", response_model=SimulatorSettingsOut)
async def patch_simulator_settings(req: SimulatorSettingsPatch) -> SimulatorSettingsOut:
    return SimulatorService.patch_settings(req)
