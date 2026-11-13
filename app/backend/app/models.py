from datetime import datetime

from sqlalchemy import JSON, BigInteger, Boolean, DateTime, Enum as SAEnum, ForeignKey, Index, Integer, SmallInteger, String
from sqlalchemy.orm import Mapped, mapped_column

from app.core.database import Base
from app.enums import EventDirection, OrderSource, OrderStatus, PrinterStatus, Shape, TaskStatus, TaskType

# SQLite는 ROWID 별칭(AUTOINCREMENT)으로 쓰려면 정확히 INTEGER 타입이 필요하다.
# 운영 DB(MySQL)에서는 그대로 BIGINT를 쓰고, 테스트용 SQLite에서만 INTEGER로 내린다.
BigIntPK = BigInteger().with_variant(Integer, "sqlite")


class User(Base):
    __tablename__ = "users"

    id: Mapped[int] = mapped_column(BigIntPK, primary_key=True, autoincrement=True)
    name: Mapped[str] = mapped_column(String(50))
    created_at: Mapped[datetime] = mapped_column(DateTime(timezone=False))


class Order(Base):
    __tablename__ = "orders"
    __table_args__ = (Index("ix_orders_status_created_at", "status", "created_at"),)

    id: Mapped[int] = mapped_column(BigIntPK, primary_key=True, autoincrement=True)
    user_id: Mapped[int] = mapped_column(BigInteger, ForeignKey("users.id"))
    shape: Mapped[Shape] = mapped_column(SAEnum(Shape, native_enum=True, length=16))
    print_duration_sec: Mapped[int] = mapped_column(Integer)
    status: Mapped[OrderStatus] = mapped_column(
        SAEnum(OrderStatus, native_enum=True, length=20), default=OrderStatus.WAITING
    )
    source: Mapped[OrderSource] = mapped_column(SAEnum(OrderSource, native_enum=True, length=8))
    printer_slot: Mapped[int | None] = mapped_column(SmallInteger, nullable=True)
    created_at: Mapped[datetime] = mapped_column(DateTime(timezone=False))
    started_at: Mapped[datetime | None] = mapped_column(DateTime(timezone=False), nullable=True)
    print_completed_at: Mapped[datetime | None] = mapped_column(DateTime(timezone=False), nullable=True)
    ready_at: Mapped[datetime | None] = mapped_column(DateTime(timezone=False), nullable=True)
    pickup_delay_sec: Mapped[int | None] = mapped_column(SmallInteger, nullable=True)
    picked_up_at: Mapped[datetime | None] = mapped_column(DateTime(timezone=False), nullable=True)
    updated_at: Mapped[datetime] = mapped_column(DateTime(timezone=False))


class Printer(Base):
    __tablename__ = "printers"

    slot: Mapped[int] = mapped_column(SmallInteger, primary_key=True)
    status: Mapped[PrinterStatus] = mapped_column(
        SAEnum(PrinterStatus, native_enum=True, length=16), default=PrinterStatus.EMPTY
    )
    current_order_id: Mapped[int | None] = mapped_column(
        BigInteger, ForeignKey("orders.id"), nullable=True
    )
    timer_ends_at: Mapped[datetime | None] = mapped_column(DateTime(timezone=False), nullable=True)
    updated_at: Mapped[datetime] = mapped_column(DateTime(timezone=False))


class BoardInventory(Base):
    __tablename__ = "board_inventory"

    id: Mapped[int] = mapped_column(SmallInteger, primary_key=True)
    remaining_count: Mapped[int] = mapped_column(Integer)
    capacity: Mapped[int] = mapped_column(Integer)
    refill_required: Mapped[bool] = mapped_column(Boolean, default=False)
    updated_at: Mapped[datetime] = mapped_column(DateTime(timezone=False))


class RobotTask(Base):
    __tablename__ = "robot_tasks"

    id: Mapped[int] = mapped_column(BigIntPK, primary_key=True, autoincrement=True)
    order_id: Mapped[int] = mapped_column(BigInteger, ForeignKey("orders.id"))
    type: Mapped[TaskType] = mapped_column(SAEnum(TaskType, native_enum=True, length=8))
    printer_slot: Mapped[int] = mapped_column(SmallInteger)
    status: Mapped[TaskStatus] = mapped_column(
        SAEnum(TaskStatus, native_enum=True, length=16), default=TaskStatus.DISPATCHED
    )
    last_phase: Mapped[str | None] = mapped_column(String(32), nullable=True)
    error_code: Mapped[str | None] = mapped_column(String(32), nullable=True)
    dispatched_at: Mapped[datetime | None] = mapped_column(DateTime(timezone=False), nullable=True)
    started_at: Mapped[datetime | None] = mapped_column(DateTime(timezone=False), nullable=True)
    finished_at: Mapped[datetime | None] = mapped_column(DateTime(timezone=False), nullable=True)


class EventLog(Base):
    __tablename__ = "event_logs"

    id: Mapped[int] = mapped_column(BigIntPK, primary_key=True, autoincrement=True)
    event_id: Mapped[str] = mapped_column(String(36), unique=True)
    type: Mapped[str] = mapped_column(String(64))
    direction: Mapped[EventDirection] = mapped_column(SAEnum(EventDirection, native_enum=True, length=20))
    payload: Mapped[dict] = mapped_column(JSON)
    created_at: Mapped[datetime] = mapped_column(DateTime(timezone=False))
