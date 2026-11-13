# app/

`assets/docs/prd.md`의 M1(서버 기반) + M2(가상 로봇) 범위를 구현했습니다. 백엔드는 레이어드
아키텍처(`api → services → repositories → models/core`), 프론트는 아토믹 디자인
(`atoms → molecules → organisms → templates → pages`)으로 구성했습니다 (10.4장 참고).

```
app/
  backend/        FastAPI 서버 (주문·재고 API, 디스패처, 타이머, 시뮬레이터, /ws/client, /ws/bridge)
  frontend/       Vite + React + TS 대시보드 (상태 조회·수동 주문·보충 알럿·이벤트 로그)
  virtual-robot/  /ws/bridge에 접속하는 가상 로봇 프로세스 (LOAD/UNLOAD 단계 시간 재현, 장애 주입)
  docker-compose.yml  MySQL 8.0 + backend + virtual-robot
```

## 스크립트로 실행 (권장)

처음 클론받은 뒤 한 번만:

```bash
cd app
./scripts/setup.sh   # venv 생성 + pip/npm install + .env 생성 + MySQL(Docker) 기동 + alembic upgrade head
```

그 이후로는 매번:

```bash
cd app
./scripts/run.sh     # MySQL 컨테이너 안 떠있으면 기동 + 백엔드·가상로봇·프론트엔드 실행
```

- 백엔드: http://localhost:8000, 프론트엔드: http://localhost:5173
- 백엔드·가상로봇 로그는 `app/.run/*.log`에 쌓입니다.
- 종료는 프론트가 실행 중인 터미널에서 `Ctrl+C` (백엔드·가상로봇도 함께 정리됩니다).
- 자세한 동작/옵션은 `scripts/setup.sh`, `scripts/run.sh` 주석 참고. Docker가 꺼져 있으면
  Docker Desktop을 먼저 켜야 합니다.

아래 "전체 실행 (Docker)" / "로컬에서 하나씩 실행"은 스크립트 없이 수동으로 실행하는 방법입니다.

## 전체 실행 (Docker)

```bash
cd app
docker compose up --build
```

- 서버: http://localhost:8000 (최초 기동 시 `alembic upgrade head`로 스키마 생성 후 기동)
- virtual-robot은 backend가 뜨면 자동으로 `/ws/bridge`에 접속해 작업을 처리합니다.
- 프론트는 별도로 `cd frontend && npm install && npm run dev` 로 띄웁니다 (http://localhost:5173, `/api`·`/ws`를 8000번으로 proxy).

## 로컬에서 하나씩 실행 (Docker 없이, 스크립트 미사용)

```bash
# 1) 백엔드 (SQLite로 빠르게 — 운영은 MySQL)
cd app/backend
python3 -m venv .venv && source .venv/bin/activate
pip install -r requirements-dev.txt
export DATABASE_URL="sqlite+aiosqlite:///./dev.db" BRIDGE_TOKEN="dev-token"
python - <<'EOF'   # SQLite는 이 스크립트로 스키마 생성 (MySQL이면 alembic upgrade head)
import asyncio
from app import models
from app.core.database import Base, engine

async def main():
    async with engine.begin() as conn:
        await conn.run_sync(Base.metadata.create_all)
    await engine.dispose()

asyncio.run(main())
EOF
uvicorn app.main:app --reload

# 2) 가상 로봇 (다른 터미널)
cd app/virtual-robot
python3 -m venv .venv && source .venv/bin/activate
pip install -r requirements-dev.txt
export BRIDGE_URL="ws://localhost:8000/ws/bridge" BRIDGE_TOKEN="dev-token"
python -m virtual_robot.main

# 3) 프론트 (다른 터미널)
cd app/frontend
npm install && npm run dev
```

브라우저에서 http://localhost:5173 을 열면 주문 생성 → LOAD → PRINTING → UNLOAD → 수령까지
전체 흐름이 실시간으로 보입니다.

테스트: `pytest` (backend, virtual-robot 각 디렉터리에서), `npm run build` (frontend 타입체크 겸 빌드).

## 가상 로봇 동작 요약 (PRD 7.7)

- `/ws/bridge`에 `bridge.hello(mode=SIM)`로 접속 → `task.dispatch`를 받으면 LOAD/UNLOAD 단계를
  순서대로 밟으며 `task.feedback`을 보내고, 끝나면 `task.result`를 보낸다.
- 단계 시간은 `virtual-robot/config/phase_times.yaml`에서 바꿀 수 있고, 서버가 보내는
  `time_scale`(현재 배율, FR-20)이 곱해진다.
- DB와 별개로 "실물 보드 수"를 들고 있다가 0이면 LOAD의 CHECK_GRIP에서 NO_BOARD로 실패한다.
  `POST /api/inventory/refill`의 `fill_physical`(기본 true)로 실물 수도 같이 채울지 결정한다.
- 웹 디버그 패널 → `PATCH /api/debug/faults`로 NO_BOARD·GRIP_FAIL을 1회성으로 강제할 수 있다.
- 연결이 끊기면 계속 재접속을 시도한다 (`RECONNECT_DELAY_SEC`). 서버는 10초 무응답이면
  연결을 끊긴 것으로 보므로, 가상 로봇은 유휴 중에도 `robot.state`를 주기적으로(기본 5초) 보낸다.

## 가상 로봇 없이 디스패처만 확인하기

`/ws/bridge`에 아래 순서로 메시지를 직접 보내면 가상 로봇 없이도 디스패치 흐름을 확인할 수 있습니다
(헤더 `X-Bridge-Token: <BRIDGE_TOKEN>` 필요).

1. `bridge.hello` (`robot_state: IDLE`) → 서버가 LOAD/UNLOAD `task.dispatch`를 보냄
2. `task.accepted` → `task.feedback`(옵션) → `task.result`(`success: true`)
3. `robot.state`(`state: IDLE`) → 다음 작업이 있으면 다시 디스패치

## 구현 범위

- 포함: FR-01~21 (서버+가상 로봇+웹), 주문/재고/시뮬레이터/통계 REST API,
  `/ws/client` 스냅샷·브로드캐스트, `/ws/bridge` 전체 프로토콜(재접속 복구, 하트비트, 작업 타임아웃 포함),
  가상 로봇 프로세스(LOAD/UNLOAD 단계 재현, 장애 주입, 재접속),
  2D 업장 레이아웃 + 로봇팔 애니메이션(FR-13, FR-14, `WorkshopStage` 컴포넌트).
- 제외(다음 단계 또는 추가 요청 시): ROS 2 브릿지, PRD 9장 시나리오 통합 테스트.
