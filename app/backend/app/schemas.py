from datetime import datetime

from pydantic import BaseModel, ConfigDict, Field

from app.enums import (
    AlertReason,
    BoardStockStatus,
    OrderSource,
    OrderStatus,
    PrinterStatus,
    RobotState,
    Shape,
    TaskStatus,
    TaskType,
)


class OrderCreateRequest(BaseModel):
    shape: Shape | None = None
    customer_name: str | None = None


class OrderOut(BaseModel):
    model_config = ConfigDict(from_attributes=True)

    id: int
    user_id: int
    shape: Shape
    print_duration_sec: int
    status: OrderStatus
    source: OrderSource
    printer_slot: int | None
    created_at: datetime
    started_at: datetime | None
    print_completed_at: datetime | None
    ready_at: datetime | None
    pickup_delay_sec: int | None
    picked_up_at: datetime | None
    updated_at: datetime


class PrinterOut(BaseModel):
    model_config = ConfigDict(from_attributes=True)

    slot: int
    status: PrinterStatus
    current_order_id: int | None
    timer_ends_at: datetime | None
    updated_at: datetime


class BoardStockOut(BaseModel):
    """적재대 층(1~3)별 상태 (PRD: assets/docs/prd-work-request-sqs.md 5장)."""

    model_config = ConfigDict(from_attributes=True)

    slot: int
    status: BoardStockStatus
    updated_at: datetime


class RobotTaskOut(BaseModel):
    model_config = ConfigDict(from_attributes=True)

    id: int
    order_id: int
    type: TaskType
    printer_slot: int
    status: TaskStatus
    last_phase: str | None
    error_code: str | None


class RobotStatusOut(BaseModel):
    state: RobotState
    current_task_id: int | None
    bridge_connected: bool


class SimulatorSettingsOut(BaseModel):
    running: bool
    interval_sec: int
    time_scale: float


class SimulatorSettingsPatch(BaseModel):
    running: bool | None = None
    interval_sec: int | None = Field(default=None, gt=0)
    time_scale: float | None = Field(default=None, gt=0)


class DebugFaultRequest(BaseModel):
    kind: str  # NO_BOARD | GRIP_FAIL
    once: bool = True


class StateSnapshot(BaseModel):
    printers: list[PrinterOut]
    robot: RobotStatusOut
    waiting_orders: list[OrderOut]
    active_orders: list[OrderOut]
    pickup_orders: list[OrderOut]
    simulator: SimulatorSettingsOut


class StatsOut(BaseModel):
    picked_up_count: int
    avg_wait_sec: float | None
    avg_print_sec: float | None
    avg_pickup_wait_sec: float | None


class HealthOut(BaseModel):
    db: bool
    bridge_connected: bool
    robot_state: RobotState
