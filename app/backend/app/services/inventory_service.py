from datetime import datetime

from sqlalchemy.ext.asyncio import AsyncSession

from app.core.events import broadcast_to_web, send_to_bridge
from app.models import BoardInventory
from app.repositories.inventory_repository import InventoryRepository
from app.schemas import BoardInventoryOut
from app.services.dispatcher_service import DispatcherService


class InventoryService:
    @staticmethod
    async def refill(session: AsyncSession, count: int, fill_physical: bool = True) -> BoardInventory:
        inventory = await InventoryRepository.get(session)
        inventory.remaining_count = count
        inventory.refill_required = False
        inventory.updated_at = datetime.utcnow()

        await broadcast_to_web(
            session, "inventory.updated", BoardInventoryOut.model_validate(inventory).model_dump(mode="json")
        )
        await broadcast_to_web(session, "alert.cleared", {})

        if fill_physical:
            # 가상 로봇(/ws/bridge 전용)의 실물 보드 수도 함께 채운다. fill_physical=False면
            # DB만 올리고 실물은 그대로 둬서 요구사항 12 상황(DB만 보충, 실물은 없음)을 재현한다.
            await send_to_bridge(session, "robot.board_count", {"count": count})

        await session.commit()

        await DispatcherService.run_cycle()
        return inventory
