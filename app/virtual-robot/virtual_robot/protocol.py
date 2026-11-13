"""서버 ↔ 가상 로봇 메시지 봉투 (PRD 7.2, 7.4). 서버 쪽 app/backend/app/core/events.py의
make_envelope와 같은 형식을 쓴다."""

import uuid
from datetime import datetime, timezone
from typing import Any


def now_iso() -> str:
    return datetime.now(timezone.utc).strftime("%Y-%m-%dT%H:%M:%S.%f")[:-3] + "Z"


def make_envelope(event_type: str, data: dict[str, Any]) -> dict[str, Any]:
    return {
        "type": event_type,
        "event_id": str(uuid.uuid4()),
        "ts": now_iso(),
        "data": data,
    }
