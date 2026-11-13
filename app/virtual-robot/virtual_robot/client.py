"""/ws/bridge에 클라이언트로 접속해 서버와 같은 메시지 규약(PRD 7.4)으로 통신한다.
연결이 끊기면 계속 재접속을 시도한다."""

from __future__ import annotations

import asyncio
import json
import logging

import websockets

from virtual_robot.config import Settings, load_phase_times
from virtual_robot.protocol import make_envelope
from virtual_robot.state import RobotRuntimeState
from virtual_robot.task_executor import TaskExecutor

logger = logging.getLogger(__name__)


class BridgeClient:
    def __init__(self, settings: Settings, state: RobotRuntimeState | None = None):
        self._settings = settings
        self._state = state or RobotRuntimeState(physical_board_count=settings.physical_board_initial_count)
        self._executor = TaskExecutor(load_phase_times(), self._state)
        self._ws: websockets.ClientConnection | None = None

    async def run_forever(self) -> None:
        while True:
            try:
                await self._run_once()
            except Exception:
                logger.exception("bridge connection lost, retrying in %.1fs", self._settings.reconnect_delay_sec)
            await asyncio.sleep(self._settings.reconnect_delay_sec)

    async def _run_once(self) -> None:
        headers = {"X-Bridge-Token": self._settings.bridge_token}
        async with websockets.connect(self._settings.bridge_url, additional_headers=headers) as ws:
            self._ws = ws
            logger.info("connected to %s", self._settings.bridge_url)
            await self._send_hello()

            heartbeat_task = asyncio.create_task(self._heartbeat_loop())
            try:
                async for raw in ws:
                    await self._handle_message(json.loads(raw))
            finally:
                heartbeat_task.cancel()
                self._ws = None

    async def _send(self, event_type: str, data: dict) -> None:
        if self._ws is None:
            return
        await self._ws.send(json.dumps(make_envelope(event_type, data)))

    async def _send_hello(self) -> None:
        await self._send(
            "bridge.hello",
            {
                "mode": "SIM",
                "robot_state": self._state.robot_state,
                "current_task_id": self._state.current_task_id,
            },
        )

    async def _send_robot_state(self) -> None:
        await self._send(
            "robot.state",
            {
                "state": self._state.robot_state,
                "current_task_id": self._state.current_task_id,
                "last_error": self._state.last_error,
            },
        )

    async def _heartbeat_loop(self) -> None:
        try:
            while True:
                await asyncio.sleep(self._settings.heartbeat_interval_sec)
                await self._send_robot_state()
        except asyncio.CancelledError:
            return

    async def _handle_message(self, envelope: dict) -> None:
        msg_type = envelope.get("type")
        data = envelope.get("data") or {}

        if msg_type == "task.dispatch":
            await self._handle_task_dispatch(data)
        elif msg_type == "robot.fault":
            self._handle_fault(data)
        elif msg_type == "robot.board_count":
            count = data.get("count")
            if isinstance(count, int):
                self._state.physical_board_count = count
                logger.info("physical board count synced to %d", count)
        else:
            logger.debug("ignoring message type=%s", msg_type)

    def _handle_fault(self, data: dict) -> None:
        kind = data.get("kind")
        if kind == "NO_BOARD":
            self._state.fault_no_board_once = True
        elif kind == "GRIP_FAIL":
            self._state.fault_grip_fail_once = True

    async def _handle_task_dispatch(self, data: dict) -> None:
        if self._state.busy_lock.locked():
            await self._send("task.rejected", {"task_id": data.get("task_id"), "reason": "BUSY"})
            return

        task_id = data["task_id"]
        task_type = data["type"]
        slot = data["slot"]
        time_scale = float(data.get("time_scale", 1.0))

        async with self._state.busy_lock:
            self._state.robot_state = "BUSY"
            self._state.current_task_id = task_id
            await self._send("task.accepted", {"task_id": task_id})
            await self._send_robot_state()

            async def send_feedback(phase: str, progress: float) -> None:
                await self._send(
                    "task.feedback",
                    {"task_id": task_id, "type": task_type, "slot": slot, "phase": phase, "progress": progress},
                )

            result = await self._executor.execute(task_type, slot, time_scale, send_feedback)

            await self._send(
                "task.result",
                {
                    "task_id": task_id,
                    "success": result.success,
                    "error_code": result.error_code,
                    "message": result.message,
                },
            )

            self._state.current_task_id = None
            self._state.robot_state = "IDLE"
            self._state.last_error = result.error_code or ""
            await self._send_robot_state()
