from fastapi import APIRouter, WebSocket, WebSocketDisconnect

from app.core.database import AsyncSessionLocal
from app.core.events import send_envelope_to
from app.core.runtime import runtime
from app.enums import EventDirection
from app.services.state_service import StateService

router = APIRouter()


@router.websocket("/ws/client")
async def client_websocket(websocket: WebSocket) -> None:
    await websocket.accept()
    runtime.client_connections.add(websocket)
    try:
        async with AsyncSessionLocal() as session:
            snapshot = await StateService.build_snapshot(session)
            await send_envelope_to(
                session,
                websocket,
                "state.snapshot",
                snapshot.model_dump(mode="json"),
                EventDirection.SERVER_TO_WEB,
            )
            await session.commit()

        while True:
            # 웹은 이 소켓으로 명령을 보내지 않는다 (REST만 사용). 연결 유지를 위해 수신만 한다.
            await websocket.receive_text()
    except WebSocketDisconnect:
        pass
    finally:
        runtime.client_connections.discard(websocket)
