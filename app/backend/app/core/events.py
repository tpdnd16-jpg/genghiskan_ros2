"""서버 → 웹 / 서버 ↔ 로봇 메시지 봉투를 만들고 내보내는 인프라 계층.

비즈니스 로직(서비스 계층)은 이 모듈을 통해서만 WebSocket으로 이벤트를 내보내며,
실제 event_logs 테이블 기록은 레포지토리 계층(EventLogRepository)에 위임한다.
"""

import uuid
from datetime import datetime, timezone
from typing import Any

from sqlalchemy.ext.asyncio import AsyncSession

from app.core.runtime import runtime
from app.enums import EventDirection
from app.repositories.event_log_repository import EventLogRepository


def _now_iso() -> str:
    return datetime.now(timezone.utc).strftime("%Y-%m-%dT%H:%M:%S.%f")[:-3] + "Z"


def make_envelope(event_type: str, data: dict[str, Any]) -> dict[str, Any]:
    return {
        "type": event_type,
        "event_id": str(uuid.uuid4()),
        "ts": _now_iso(),
        "data": data,
    }


async def broadcast_to_web(session: AsyncSession, event_type: str, data: dict[str, Any]) -> None:
    envelope = make_envelope(event_type, data)
    EventLogRepository.add(session, envelope, EventDirection.SERVER_TO_WEB)
    dead: list = []
    for ws in runtime.client_connections:
        try:
            await ws.send_json(envelope)
        except Exception:
            dead.append(ws)
    for ws in dead:
        runtime.client_connections.discard(ws)


async def send_envelope_to(
    session: AsyncSession, ws, event_type: str, data: dict[str, Any], direction: EventDirection
) -> None:
    envelope = make_envelope(event_type, data)
    EventLogRepository.add(session, envelope, direction)
    await ws.send_json(envelope)


async def send_to_bridge(session: AsyncSession, event_type: str, data: dict[str, Any]) -> bool:
    envelope = make_envelope(event_type, data)
    EventLogRepository.add(session, envelope, EventDirection.SERVER_TO_BRIDGE)
    if runtime.bridge_ws is None:
        return False
    try:
        await runtime.bridge_ws.send_json(envelope)
        return True
    except Exception:
        return False
