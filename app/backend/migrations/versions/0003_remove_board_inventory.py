"""remove board_inventory (manual refill UI/API and dispatch gating removed)

Revision ID: 0003_remove_board_inventory
Revises: 0002_work_request_sqs
Create Date: 2026-11-14

"""
from typing import Sequence, Union

import sqlalchemy as sa
from alembic import op

revision: str = "0003_remove_board_inventory"
down_revision: Union[str, None] = "0002_work_request_sqs"
branch_labels: Union[str, Sequence[str], None] = None
depends_on: Union[str, Sequence[str], None] = None


def upgrade() -> None:
    op.drop_table("board_inventory")


def downgrade() -> None:
    op.create_table(
        "board_inventory",
        sa.Column("id", sa.SmallInteger, primary_key=True),
        sa.Column("remaining_count", sa.Integer, nullable=False),
        sa.Column("capacity", sa.Integer, nullable=False),
        sa.Column("refill_required", sa.Boolean, nullable=False, server_default=sa.false()),
        sa.Column("updated_at", sa.DateTime(), nullable=False),
    )
