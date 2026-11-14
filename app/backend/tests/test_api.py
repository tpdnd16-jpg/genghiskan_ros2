import pytest
from fastapi.testclient import TestClient

from app.main import app

pytestmark = pytest.mark.asyncio


async def test_health_and_order_flow():
    with TestClient(app) as client:
        health = client.get("/api/health")
        assert health.status_code == 200
        assert health.json()["db"] is True

        created = client.post("/api/orders", json={"shape": "TRIANGLE"})
        assert created.status_code == 201
        body = created.json()
        assert body["shape"] == "TRIANGLE"
        assert body["status"] == "LOADING"  # 빈 프린터가 있으므로 즉시 LOAD 디스패치

        state = client.get("/api/state")
        assert state.status_code == 200
        snapshot = state.json()
        assert snapshot["printers"][0]["slot"] == 1
