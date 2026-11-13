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
    STOCK_EMPTY = "STOCK_EMPTY"
    ROBOT_NO_BOARD = "ROBOT_NO_BOARD"
