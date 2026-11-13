"""/ws/bridge 전송 계층. 인증·연결 수명주기·하트비트만 다루고, 메시지의 실제
업무 처리는 서비스 계층(BridgeProtocolService)에 위임한다."""

import asyncio
import logging
import time

from fastapi import APIRouter, WebSocket, WebSocketDisconnect

from app.core.config import settings
from app.core.database import AsyncSessionLocal
from app.core.runtime import runtime
from app.enums import EventDirection
from app.repositories.event_log_repository import EventLogRepository
from app.services.bridge_protocol_service import BridgeProtocolService

router = APIRouter()
logger = logging.getLogger(__name__)


@router.websocket("/ws/bridge")
async def bridge_websocket(websocket: WebSocket) -> None:
    token = websocket.headers.get("x-bridge-token") or websocket.query_params.get("token")
    if token != settings.bridge_token:
        await websocket.close(code=4401)
        return

    await websocket.accept()

    if runtime.bridge_ws is not None:
        try:
            await runtime.bridge_ws.close(code=4409)
        except Exception:
            pass

    runtime.bridge_ws = websocket
    runtime.mark_bridge_seen()
    heartbeat_task = asyncio.create_task(_heartbeat_watchdog(websocket))

    try:
        while True:
            envelope = await websocket.receive_json()
            runtime.mark_bridge_seen()
            await _dispatch_incoming(envelope)
    except WebSocketDisconnect:
        pass
    finally:
        heartbeat_task.cancel()
        if runtime.bridge_ws is websocket:
            await BridgeProtocolService.on_bridge_disconnected()


async def _heartbeat_watchdog(websocket: WebSocket) -> None:
    try:
        while True:
            await asyncio.sleep(2)
            if runtime.bridge_ws is not websocket:
                return
            if time.monotonic() - runtime.bridge_last_seen_monotonic > settings.bridge_heartbeat_timeout_sec:
                try:
                    await websocket.close(code=4408)
                except Exception:
                    pass
                return
    except asyncio.CancelledError:
        return


async def _dispatch_incoming(envelope: dict) -> None:
    msg_type = envelope.get("type")
    data = envelope.get("data") or {}
    event_id = envelope.get("event_id")

    async with AsyncSessionLocal() as session:
        is_new = await EventLogRepository.try_add_unique(session, envelope, EventDirection.BRIDGE_TO_SERVER)
        if not is_new:
            return  # event_id 중복 수신 - 무시 (요구사항 9.5)
        await session.commit()

    if msg_type not in _KNOWN_TYPES:
        logger.warning("unknown bridge message type=%s event_id=%s", msg_type, event_id)
        return
    await BridgeProtocolService.handle_message(msg_type, data)


_KNOWN_TYPES = {
    "bridge.hello",
    "task.accepted",
    "task.rejected",
    "task.feedback",
    "task.result",
    "robot.state",
}
