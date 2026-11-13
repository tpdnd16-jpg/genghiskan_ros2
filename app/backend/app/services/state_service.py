from sqlalchemy.ext.asyncio import AsyncSession

from app.core.runtime import runtime
from app.repositories.inventory_repository import InventoryRepository
from app.repositories.order_repository import OrderRepository
from app.repositories.printer_repository import PrinterRepository
from app.schemas import (
    BoardInventoryOut,
    OrderOut,
    PrinterOut,
    RobotStatusOut,
    SimulatorSettingsOut,
    StateSnapshot,
)


class StateService:
    @staticmethod
    async def build_snapshot(session: AsyncSession) -> StateSnapshot:
        printers = await PrinterRepository.list_all(session)
        inventory = await InventoryRepository.get(session)
        waiting = await OrderRepository.get_waiting(session)
        active = await OrderRepository.get_active(session)
        pickup = await OrderRepository.get_pickup(session)

        return StateSnapshot(
            printers=[PrinterOut.model_validate(p) for p in printers],
            inventory=BoardInventoryOut.model_validate(inventory),
            robot=RobotStatusOut(
                state=runtime.robot_state,
                current_task_id=runtime.current_task_id,
                bridge_connected=runtime.bridge_connected(),
            ),
            waiting_orders=[OrderOut.model_validate(o) for o in waiting],
            active_orders=[OrderOut.model_validate(o) for o in active],
            pickup_orders=[OrderOut.model_validate(o) for o in pickup],
            simulator=SimulatorSettingsOut(
                running=runtime.simulator_running,
                interval_sec=runtime.simulator_interval_sec,
                time_scale=runtime.simulator_time_scale,
            ),
        )
