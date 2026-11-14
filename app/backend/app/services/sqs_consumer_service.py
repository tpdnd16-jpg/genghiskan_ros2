"""robot-events(SQS) <- pick_complete 메시지 소비. PRD: assets/docs/prd-work-request-sqs.md 5장.

이번 PRD 범위는 pick_complete 처리(board_stock 갱신 + 주문 LOADING 전이)뿐이다.
robot-events의 다른 이벤트(LOAD_COMPLETED/UNLOAD_COMPLETED/REJECTED 등 주문 상태를
더 진행시키는 것)는 범위 밖이라 여기서는 무시한다."""

import asyncio
import json
import logging
from functools import lru_cache

import boto3
from botocore.exceptions import BotoCoreError, ClientError

from app.core.config import settings
from app.services.work_request_service import WorkRequestService

logger = logging.getLogger(__name__)

_PICK_COMPLETE_STATUS = "pick_complete"
_ERROR_BACKOFF_SEC = 3.0


@lru_cache(maxsize=1)
def _client():
    return boto3.client("sqs", region_name=settings.aws_region)


class SqsConsumerService:
    @staticmethod
    async def robot_events_loop() -> None:
        """event_queue_url이 설정되지 않으면 바로 종료한다 (로컬 개발 등에서 안전한
        기본값). 큐가 설정됐을 때만 long polling으로 계속 수신한다."""
        if not settings.event_queue_url:
            logger.info("event_queue_url 미설정 — robot-events 컨슈머를 시작하지 않습니다.")
            return

        client = _client()
        while True:
            try:
                response = await asyncio.to_thread(
                    client.receive_message,
                    QueueUrl=settings.event_queue_url,
                    MaxNumberOfMessages=10,
                    WaitTimeSeconds=settings.sqs_poll_wait_sec,
                )
            except asyncio.CancelledError:
                raise
            except (BotoCoreError, ClientError) as exc:
                logger.error("robot-events 수신 실패: %s", exc)
                await asyncio.sleep(_ERROR_BACKOFF_SEC)
                continue

            for message in response.get("Messages", []):
                await SqsConsumerService._handle_message(client, message)

    @staticmethod
    async def _handle_message(client, message: dict) -> None:
        try:
            body = json.loads(message["Body"])
        except (json.JSONDecodeError, KeyError):
            logger.error("robot-events 메시지 파싱 실패: %s", message.get("Body"))
            await SqsConsumerService._delete(client, message)
            return

        if body.get("status") == _PICK_COMPLETE_STATUS and "work_id" in body:
            try:
                await WorkRequestService.handle_pick_complete(int(body["work_id"]))
            except (TypeError, ValueError):
                logger.error("pick_complete work_id가 올바르지 않습니다: %s", body)
            except Exception:
                # 예상 못한 오류(DB 등)는 메시지를 지우지 않고 가시성 타임아웃이 지난 뒤
                # 재시도되게 둔다. 알 수 없는 work_id/중복 수신은 여기서 예외가 나지
                # 않으므로(handle_pick_complete가 조용히 무시) 영향 없다.
                logger.exception("pick_complete 처리 실패, 재시도를 위해 메시지를 남겨둡니다: %s", body)
                return

        await SqsConsumerService._delete(client, message)

    @staticmethod
    async def _delete(client, message: dict) -> None:
        try:
            await asyncio.to_thread(
                client.delete_message,
                QueueUrl=settings.event_queue_url,
                ReceiptHandle=message["ReceiptHandle"],
            )
        except (BotoCoreError, ClientError) as exc:
            logger.error("robot-events 메시지 삭제 실패: %s", exc)
