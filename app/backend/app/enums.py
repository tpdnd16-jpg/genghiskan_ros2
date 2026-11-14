from enum import Enum


class Shape(str, Enum):
    TRIANGLE = "TRIANGLE"
    SQUARE = "SQUARE"
    STAR = "STAR"
    CIRCLE = "CIRCLE"


SHAPE_PRINT_DURATION_SEC: dict[Shape, int] = {
    Shape.TRIANGLE: 30,
    Shape.SQUARE: 40,
    Shape.STAR: 50,
    Shape.CIRCLE: 70,
}


class OrderStatus(str, Enum):
    WAITING = "WAITING"
    # 작업요청(SQS) 경로 전용: LOAD 명령 발행 성공 ~ pick_complete 수신 전까지 ("투입중").
    # PRD: assets/docs/prd-work-request-sqs.md 5장.
    DISPATCHING = "DISPATCHING"
    LOADING = "LOADING"
    PRINTING = "PRINTING"
    PRINT_DONE = "PRINT_DONE"
    UNLOADING = "UNLOADING"
    READY_FOR_PICKUP = "READY_FOR_PICKUP"
    PICKED_UP = "PICKED_UP"


class OrderSource(str, Enum):
    AUTO = "AUTO"
    MANUAL = "MANUAL"


class PrinterStatus(str, Enum):
    EMPTY = "EMPTY"
    RESERVED = "RESERVED"
    PRINTING = "PRINTING"
    DONE = "DONE"
    UNLOADING = "UNLOADING"


class TaskType(str, Enum):
    LOAD = "LOAD"
    UNLOAD = "UNLOAD"


class TaskStatus(str, Enum):
    DISPATCHED = "DISPATCHED"
    RUNNING = "RUNNING"
    SUCCEEDED = "SUCCEEDED"
    FAILED = "FAILED"
    CANCELED = "CANCELED"


ACTIVE_TASK_STATUSES = (TaskStatus.DISPATCHED, TaskStatus.RUNNING)
ACTIVE_ORDER_STATUSES = (OrderStatus.LOADING, OrderStatus.PRINTING, OrderStatus.PRINT_DONE, OrderStatus.UNLOADING)


class RobotState(str, Enum):
    IDLE = "IDLE"
    BUSY = "BUSY"
    ERROR = "ERROR"
    DISCONNECTED = "DISCONNECTED"


class EventDirection(str, Enum):
    SERVER_TO_WEB = "SERVER_TO_WEB"
    SERVER_TO_BRIDGE = "SERVER_TO_BRIDGE"
    BRIDGE_TO_SERVER = "BRIDGE_TO_SERVER"


class AlertReason(str, Enum):
    # 작업요청(SQS) 경로 전용 (PRD: assets/docs/prd-work-request-sqs.md 5장 "채우기 완료" 버튼).
    BOARD_STOCK_EMPTY = "BOARD_STOCK_EMPTY"


class BoardStockStatus(str, Enum):
    """적재대 층(1~3)별 상태 (PRD: assets/docs/prd-work-request-sqs.md 5장)."""

    EMPTY = "EMPTY"
    RESERVED = "RESERVED"
    OCCUPIED = "OCCUPIED"
