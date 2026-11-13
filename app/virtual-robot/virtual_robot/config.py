from functools import lru_cache
from pathlib import Path

import yaml
from pydantic_settings import BaseSettings, SettingsConfigDict


class Settings(BaseSettings):
    model_config = SettingsConfigDict(env_file=".env", extra="ignore")

    bridge_url: str = "ws://localhost:8000/ws/bridge"
    bridge_token: str = "change-me-dev-token"
    phase_times_path: str = "config/phase_times.yaml"
    physical_board_initial_count: int = 10
    reconnect_delay_sec: float = 3.0
    heartbeat_interval_sec: float = 5.0


settings = Settings()


class PhaseTimes:
    def __init__(self, load: dict[str, float], unload: dict[str, float], floor_offset_sec: dict[int, float]):
        self.load = load
        self.unload = unload
        self.floor_offset_sec = floor_offset_sec

    def for_type(self, task_type: str) -> dict[str, float]:
        return self.load if task_type == "LOAD" else self.unload


@lru_cache
def load_phase_times() -> PhaseTimes:
    path = Path(settings.phase_times_path)
    with path.open("r", encoding="utf-8") as f:
        raw = yaml.safe_load(f)
    floor_offset = {int(k): float(v) for k, v in raw["floor_offset_sec"].items()}
    return PhaseTimes(load=raw["load"], unload=raw["unload"], floor_offset_sec=floor_offset)
