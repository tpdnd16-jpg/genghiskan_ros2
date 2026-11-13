from pydantic_settings import BaseSettings, SettingsConfigDict


class Settings(BaseSettings):
    model_config = SettingsConfigDict(env_file=".env", extra="ignore")

    database_url: str = "mysql+aiomysql://printshop:printshop@localhost:3306/printshop"
    bridge_token: str = "change-me-dev-token"
    cors_origins: str = "http://localhost:5173"

    task_timeout_sec: int = 120
    default_auto_order_interval_sec: int = 45
    default_time_scale: float = 1.0
    default_auto_order_running: bool = True

    board_initial_count: int = 6
    board_capacity: int = 6

    timer_sweep_interval_sec: float = 0.5
    bridge_heartbeat_timeout_sec: float = 10.0

    @property
    def cors_origin_list(self) -> list[str]:
        return [o.strip() for o in self.cors_origins.split(",") if o.strip()]


settings = Settings()
