"""서버 → robot-commands(SQS) 메시지 발행. PRD: assets/docs/prd-work-request-sqs.md 7장.

boto3는 동기(blocking) 클라이언트이므로 asyncio 이벤트 루프를 막지 않도록
asyncio.to_thread로 감싸서 호출한다."""

import asyncio
import json
import logging
from functools import lru_cache

import boto3
from botocore.exceptions import BotoCoreError, ClientError

from app.core.config import settings

logger = logging.getLogger(__name__)

_LOAD_MESSAGE_GROUP_ID = "load"


@lru_cache(maxsize=1)
def _client():
    return boto3.client("sqs", region_name=settings.aws_region)


class SqsProducerService:
    @staticmethod
    async def produce_load_command(work_id: int, start_pos_id: int, sd_pos_id: int) -> bool:
        """robot-commands.fifo에 LOAD 명령을 보낸다. 성공하면 True, 큐 미설정이거나
        전송에 실패하면 False를 반환한다 (호출 측이 트랜잭션을 롤백한다)."""
        if not settings.command_queue_url:
            return False

        body = {"work_id": work_id, "start_pos_id": start_pos_id, "sd_pos_id": sd_pos_id}
        params: dict = {
            "QueueUrl": settings.command_queue_url,
            "MessageBody": json.dumps(body, ensure_ascii=False),
        }
        if settings.command_queue_url.endswith(".fifo"):
            params["MessageGroupId"] = _LOAD_MESSAGE_GROUP_ID
            params["MessageDeduplicationId"] = f"load-{work_id}"

        try:
            await asyncio.to_thread(_client().send_message, **params)
            return True
        except (BotoCoreError, ClientError) as exc:
            logger.error("robot-commands produce 실패 (work_id=%s): %s", work_id, exc)
            return False
