#!/usr/bin/env bash
# 최초 1회 설정 스크립트.
# - 백엔드/가상로봇 Python venv 생성 + 패키지 설치
# - 프론트엔드 npm 패키지 설치
# - .env 파일 생성 (.env.example 복사)
# - MySQL(Docker) 기동 + alembic upgrade head 로 스키마 생성
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
APP_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

log() { printf '\n\033[1;34m[setup]\033[0m %s\n' "$1"; }
err() { printf '\n\033[1;31m[setup][ERROR]\033[0m %s\n' "$1" >&2; }

require_cmd() {
  if ! command -v "$1" >/dev/null 2>&1; then
    err "'$1' 명령을 찾을 수 없습니다. 설치 후 다시 실행해 주세요."
    exit 1
  fi
}

require_cmd python3
require_cmd npm
require_cmd docker

if ! docker compose version >/dev/null 2>&1; then
  err "'docker compose' 플러그인을 찾을 수 없습니다. Docker Desktop을 업데이트해 주세요."
  exit 1
fi

ensure_env_file() {
  local dir="$1"
  if [ ! -f "$dir/.env" ]; then
    cp "$dir/.env.example" "$dir/.env"
    log "$(basename "$dir")/.env 생성 (.env.example 복사)"
  fi
}

setup_python_component() {
  local dir="$1"
  log "${dir##*/} 설정 중..."
  (
    cd "$dir"
    if [ ! -d ".venv" ]; then
      python3 -m venv .venv
    fi
    # shellcheck disable=SC1091
    source .venv/bin/activate
    pip install --upgrade pip >/dev/null
    pip install -r requirements-dev.txt
  )
  ensure_env_file "$dir"
}

log "백엔드/가상로봇 Python 환경을 준비합니다 (처음 실행 시 몇 분 걸릴 수 있습니다)"
setup_python_component "$APP_DIR/backend"
setup_python_component "$APP_DIR/virtual-robot"

log "프론트엔드 패키지를 설치합니다 (npm install)"
(cd "$APP_DIR/frontend" && npm install)
ensure_env_file "$APP_DIR/frontend"

log "MySQL 컨테이너를 기동합니다 (docker compose up -d mysql)"
(cd "$APP_DIR" && docker compose up -d mysql)

log "MySQL이 준비될 때까지 대기합니다..."
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

log "DB 스키마를 생성합니다 (alembic upgrade head)"
(
  cd "$APP_DIR/backend"
  # shellcheck disable=SC1091
  source .venv/bin/activate
  alembic upgrade head
)

log "설정이 완료되었습니다. 이제 ./scripts/run.sh 로 전체 앱을 실행할 수 있습니다."
