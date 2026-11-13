"""initial schema

Revision ID: 0001_initial
Revises:
Create Date: 2026-11-12

"""
from typing import Sequence, Union

import sqlalchemy as sa
from alembic import op

revision: str = "0001_initial"
down_revision: Union[str, None] = None
branch_labels: Union[str, Sequence[str], None] = None
depends_on: Union[str, Sequence[str], None] = None


def upgrade() -> None:
    op.create_table(
        "users",
        sa.Column("id", sa.BigInteger, primary_key=True, autoincrement=True),
        sa.Column("name", sa.String(50), nullable=False),
        sa.Column("created_at", sa.DateTime(), nullable=False),
    )

    op.create_table(
        "orders",
        sa.Column("id", sa.BigInteger, primary_key=True, autoincrement=True),
        sa.Column("user_id", sa.BigInteger, sa.ForeignKey("users.id"), nullable=False),
        sa.Column(
            "shape", sa.Enum("TRIANGLE", "SQUARE", "STAR", "CIRCLE", name="shape"), nullable=False
        ),
        sa.Column("print_duration_sec", sa.Integer, nullable=False),
        sa.Column(
            "status",
            sa.Enum(
                "WAITING",
                "LOADING",
                "PRINTING",
                "PRINT_DONE",
                "UNLOADING",
                "READY_FOR_PICKUP",
                "PICKED_UP",
                name="order_status",
            ),
            nullable=False,
            server_default="WAITING",
        ),
        sa.Column("source", sa.Enum("AUTO", "MANUAL", name="order_source"), nullable=False),
        sa.Column("printer_slot", sa.SmallInteger, nullable=True),
        sa.Column("created_at", sa.DateTime(), nullable=False),
        sa.Column("started_at", sa.DateTime(), nullable=True),
        sa.Column("print_completed_at", sa.DateTime(), nullable=True),
        sa.Column("ready_at", sa.DateTime(), nullable=True),
        sa.Column("pickup_delay_sec", sa.SmallInteger, nullable=True),
        sa.Column("picked_up_at", sa.DateTime(), nullable=True),
        sa.Column("updated_at", sa.DateTime(), nullable=False),
    )
    op.create_index("ix_orders_status_created_at", "orders", ["status", "created_at"])

    op.create_table(
        "printers",
        sa.Column("slot", sa.SmallInteger, primary_key=True),
        sa.Column(
            "status",
            sa.Enum("EMPTY", "RESERVED", "PRINTING", "DONE", "UNLOADING", name="printer_status"),
            nullable=False,
            server_default="EMPTY",
        ),
        sa.Column("current_order_id", sa.BigInteger, sa.ForeignKey("orders.id"), nullable=True),
        sa.Column("timer_ends_at", sa.DateTime(), nullable=True),
        sa.Column("updated_at", sa.DateTime(), nullable=False),
    )

    op.create_table(
        "board_inventory",
        sa.Column("id", sa.SmallInteger, primary_key=True),
        sa.Column("remaining_count", sa.Integer, nullable=False),
        sa.Column("capacity", sa.Integer, nullable=False),
        sa.Column("refill_required", sa.Boolean, nullable=False, server_default=sa.false()),
        sa.Column("updated_at", sa.DateTime(), nullable=False),
    )

    op.create_table(
        "robot_tasks",
        sa.Column("id", sa.BigInteger, primary_key=True, autoincrement=True),
        sa.Column("order_id", sa.BigInteger, sa.ForeignKey("orders.id"), nullable=False),
        sa.Column("type", sa.Enum("LOAD", "UNLOAD", name="task_type"), nullable=False),
        sa.Column("printer_slot", sa.SmallInteger, nullable=False),
        sa.Column(
            "status",
            sa.Enum("DISPATCHED", "RUNNING", "SUCCEEDED", "FAILED", "CANCELED", name="task_status"),
            nullable=False,
            server_default="DISPATCHED",
        ),
        sa.Column("last_phase", sa.String(32), nullable=True),
        sa.Column("error_code", sa.String(32), nullable=True),
        sa.Column("dispatched_at", sa.DateTime(), nullable=True),
        sa.Column("started_at", sa.DateTime(), nullable=True),
        sa.Column("finished_at", sa.DateTime(), nullable=True),
    )

    op.create_table(
        "event_logs",
        sa.Column("id", sa.BigInteger, primary_key=True, autoincrement=True),
        sa.Column("event_id", sa.String(36), nullable=False),
        sa.Column("type", sa.String(64), nullable=False),
        sa.Column(
            "direction",
            sa.Enum(
                "SERVER_TO_WEB", "SERVER_TO_BRIDGE", "BRIDGE_TO_SERVER", name="event_direction"
            ),
            nullable=False,
        ),
        sa.Column("payload", sa.JSON, nullable=False),
        sa.Column("created_at", sa.DateTime(), nullable=False),
    )
    op.create_unique_constraint("uq_event_logs_event_id", "event_logs", ["event_id"])


def downgrade() -> None:
    op.drop_table("event_logs")
    op.drop_table("robot_tasks")
    op.drop_table("board_inventory")
    op.drop_table("printers")
    op.drop_index("ix_orders_status_created_at", table_name="orders")
    op.drop_table("orders")
    op.drop_table("users")
