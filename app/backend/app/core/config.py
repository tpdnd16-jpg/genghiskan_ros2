from dotenv import load_dotenv
from pydantic_settings import BaseSettings, SettingsConfigDict

# pydantic-settings의 env_file 로딩은 .env 값을 Settings 필드에만 채워주고
# os.environ 자체는 바꾸지 않는다. boto3는 AWS_ACCESS_KEY_ID 등 자격증명을
# os.environ에서 직접 찾으므로(Settings에 선언하지 않은 키), SQS를 쓰려면
# .env를 실제 프로세스 환경변수로도 로드해 둬야 한다.
load_dotenv()


class Settings(BaseSettings):
    model_config = SettingsConfigDict(env_file=".env", extra="ignore")

    database_url: str = "mysql+aiomysql://printshop:printshop@localhost:3306/printshop"
    bridge_token: str = "change-me-dev-token"
    cors_origins: str = "http://localhost:5173"

    task_timeout_sec: int = 120
    default_auto_order_interval_sec: int = 45
    default_time_scale: float = 1.0
    default_auto_order_running: bool = True

    timer_sweep_interval_sec: float = 0.5
    bridge_heartbeat_timeout_sec: float = 10.0

    # 작업요청(SQS) 경로 전용 (PRD: assets/docs/prd-work-request-sqs.md 7장).
    # 기본값은 빈 문자열 — 설정하지 않으면 produce/consume 모두 조용히 비활성화된다.
    # (ROS 2 쪽 sfarm_bridge.py처럼 실제 AWS 큐 URL을 코드에 기본값으로 박아두지 않기 위함.)
    aws_region: str = "ap-northeast-2"
    command_queue_url: str = ""
    event_queue_url: str = ""
    sqs_poll_wait_sec: int = 20

    @property
    def cors_origin_list(self) -> list[str]:
        return [o.strip() for o in self.cors_origins.split(",") if o.strip()]


settings = Settings()
