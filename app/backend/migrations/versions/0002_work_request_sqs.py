"""work request (SQS) feature: orders.DISPATCHING, robot_tasks snapshot columns, board_stock table

PRD: assets/docs/prd-work-request-sqs.md (5장)

Revision ID: 0002_work_request_sqs
Revises: 0001_initial
Create Date: 2026-11-14

"""
from typing import Sequence, Union

import sqlalchemy as sa
from alembic import op

revision: str = "0002_work_request_sqs"
down_revision: Union[str, None] = "0001_initial"
branch_labels: Union[str, Sequence[str], None] = None
depends_on: Union[str, Sequence[str], None] = None

_OLD_ORDER_STATUS = sa.Enum(
    "WAITING",
    "LOADING",
    "PRINTING",
    "PRINT_DONE",
    "UNLOADING",
    "READY_FOR_PICKUP",
    "PICKED_UP",
    name="order_status",
)

_NEW_ORDER_STATUS = sa.Enum(
    "WAITING",
    "DISPATCHING",
    "LOADING",
    "PRINTING",
    "PRINT_DONE",
    "UNLOADING",
    "READY_FOR_PICKUP",
    "PICKED_UP",
    name="order_status",
)


def upgrade() -> None:
    op.alter_column(
        "orders",
        "status",
        existing_type=_OLD_ORDER_STATUS,
        type_=_NEW_ORDER_STATUS,
        existing_nullable=False,
        existing_server_default="WAITING",
    )

    op.add_column("robot_tasks", sa.Column("start_pos_id", sa.SmallInteger, nullable=True))
    op.add_column("robot_tasks", sa.Column("sd_pos_id", sa.SmallInteger, nullable=True))

    op.create_table(
        "board_stock",
        sa.Column("slot", sa.SmallInteger, primary_key=True),
        sa.Column(
            "status",
            sa.Enum("EMPTY", "RESERVED", "OCCUPIED", name="board_stock_status"),
            nullable=False,
            server_default="EMPTY",
        ),
        sa.Column("updated_at", sa.DateTime(), nullable=False),
    )


def downgrade() -> None:
    op.drop_table("board_stock")
    op.drop_column("robot_tasks", "sd_pos_id")
    op.drop_column("robot_tasks", "start_pos_id")
    op.alter_column(
        "orders",
        "status",
        existing_type=_NEW_ORDER_STATUS,
        type_=_OLD_ORDER_STATUS,
        existing_nullable=False,
        existing_server_default="WAITING",
    )
