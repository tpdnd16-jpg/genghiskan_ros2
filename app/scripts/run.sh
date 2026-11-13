#!/usr/bin/env bash
# 클론 이후 매번 쓰는 실행 스크립트.
# - Docker 컨테이너(MySQL)가 안 떠있으면 띄움
# - 백엔드(FastAPI), 가상로봇, 프론트엔드(Vite)를 모두 실행
# 처음 실행하기 전에는 ./scripts/setup.sh 를 먼저 실행해야 합니다.
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
APP_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
RUN_DIR="$APP_DIR/.run"
mkdir -p "$RUN_DIR"

log() { printf '\n\033[1;34m[run]\033[0m %s\n' "$1"; }
err() { printf '\n\033[1;31m[run][ERROR]\033[0m %s\n' "$1" >&2; }

if [ ! -d "$APP_DIR/backend/.venv" ] || [ ! -d "$APP_DIR/virtual-robot/.venv" ] || [ ! -d "$APP_DIR/frontend/node_modules" ]; then
  err "아직 설정이 안 된 것 같습니다. 먼저 ./scripts/setup.sh 를 실행해 주세요."
  exit 1
fi

# --- Docker (MySQL) 기동 확인 ---
if ! docker info >/dev/null 2>&1; then
  err "Docker가 실행 중이지 않습니다. Docker Desktop을 먼저 켜 주세요."
  exit 1
fi

mysql_running() {
  (cd "$APP_DIR" && docker compose ps mysql --status running --format '{{.Name}}' 2>/dev/null | grep -q .)
}

if mysql_running; then
  log "MySQL 컨테이너가 이미 떠있습니다."
else
  log "MySQL 컨테이너가 안 떠있어서 기동합니다 (docker compose up -d mysql)"
  (cd "$APP_DIR" && docker compose up -d mysql)
  tries=0
  until (cd "$APP_DIR" && docker compose exec -T mysql mysqladmin ping -h localhost -u root -proot >/dev/null 2>&1); do
    tries=$((tries + 1))
    if [ "$tries" -gt 60 ]; then
      err "MySQL이 60초 내에 준비되지 않았습니다. 'docker compose logs mysql'로 확인해 주세요."
      exit 1
    fi
    sleep 1
  done
  log "MySQL 준비 완료"
fi

# --- 백엔드 / 가상로봇을 백그라운드로, 프론트엔드를 포그라운드로 실행 ---
PIDS=()

cleanup() {
  log "종료 중... 백엔드/가상로봇 프로세스를 정리합니다."
  for pid in "${PIDS[@]:-}"; do
    kill "$pid" >/dev/null 2>&1 || true
  done
}
trap cleanup EXIT INT TERM

log "백엔드를 실행합니다 (http://localhost:8000, 로그: .run/backend.log)"
(
  cd "$APP_DIR/backend"
  # shellcheck disable=SC1091
  source .venv/bin/activate
  alembic upgrade head
  exec uvicorn app.main:app --reload --port 8000
) >"$RUN_DIR/backend.log" 2>&1 &
PIDS+=("$!")

log "가상로봇을 실행합니다 (로그: .run/virtual-robot.log)"
(
  cd "$APP_DIR/virtual-robot"
  # shellcheck disable=SC1091
  source .venv/bin/activate
  exec python -m virtual_robot.main
) >"$RUN_DIR/virtual-robot.log" 2>&1 &
PIDS+=("$!")

log "프론트엔드를 실행합니다 (http://localhost:5173)"
log "종료하려면 Ctrl+C 를 누르세요 (백엔드/가상로봇도 함께 종료됩니다)"
cd "$APP_DIR/frontend"
npm run dev
