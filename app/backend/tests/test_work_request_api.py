import pytest
from fastapi.testclient import TestClient

from app.main import app
from app.services.sqs_producer_service import SqsProducerService

pytestmark = pytest.mark.asyncio


async def test_work_request_board_empty_returns_409(monkeypatch):
    with TestClient(app) as client:
        resp = client.post("/api/work-requests", json={"shape": "TRIANGLE"})
        assert resp.status_code == 409
        detail = resp.json()["detail"]
        assert detail["error_code"] == "BOARD_EMPTY"


async def test_work_request_dispatches_when_board_and_printer_available(monkeypatch):
    async def fake_produce(*args, **kwargs) -> bool:
        return True

    monkeypatch.setattr(SqsProducerService, "produce_load_command", fake_produce)

    with TestClient(app) as client:
        board = client.post("/api/board-stock/refill-complete")
        assert board.status_code == 200
        assert all(slot["status"] == "OCCUPIED" for slot in board.json())

        created = client.post("/api/work-requests", json={"shape": "STAR"})
        assert created.status_code == 201
        body = created.json()
        assert body["status"] == "DISPATCHING"
        assert body["printer_slot"] == 1
