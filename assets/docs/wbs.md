# WBS — 소규모 3D 프린트 업장 관리 로봇

작성일: 2026-11-12 · 기준 문서: [PRD](prd.md) · 작성자: 류병옥

이 문서는 PRD 10.8 마일스톤(M1~M4, 다음 단계)을 기준으로 `app/` 디렉터리의 실제 구현 상태를 점검하고,
다음에 이어서 작업할 항목을 정리한 것이다. `app/README.md`는 작성 당시 기준으로 "가상 로봇·애니메이션 제외"라고
적혀 있으나, 이후 가상 로봇이 추가 구현되어 **내용이 최신 상태와 다르다** — 이 WBS가 최신 기준이다.

## 0. 현재 상태 한 줄 요약 (2026-11-12 갱신)

- `app/` 전체가 아직 git에 커밋되지 않은 미추적(untracked) 상태다. 작업 내용을 잃지 않으려면 커밋이 필요하다.
- M1(서버), M2(가상 로봇), M3(웹 화면)는 기능 구현 + 단위 테스트 통과까지 완료됐다. M3의 마지막 공백이던 2D 업장 레이아웃·로봇팔 애니메이션(FR-13, FR-14)을 `WorkshopStage` 컴포넌트로 구현해 마무리했다.
- M4(시나리오 테스트·시연)와 "다음 단계"(ROS 2 브릿지, `ros2_ws/`)는 손대지 않았다.

## 1. 마일스톤별 진행 상태

### M1 — 서버 기반 ✅ 완료

| 항목 | 상태 | 위치 |
| --- | --- | --- |
| 스키마·시드 (alembic) | 완료 | `app/backend/migrations/versions/0001_initial.py`, `app/backend/app/core/bootstrap.py` |
| 주문 API (FR-02, FR-03) | 완료 | `app/backend/app/api/routers/orders.py`, `services/order_service.py` |
| 재고 API + 보충 알럿 (FR-09, FR-10) | 완료 | `api/routers/inventory.py`, `services/inventory_service.py` |
| 디스패처 (FR-04, UNLOAD>LOAD 우선순위) | 완료 | `services/dispatcher_service.py` (단위 테스트 통과) |
| 프린터 타이머 + 재시작 복원 (FR-06) | 완료 | `services/timer_service.py` |
| 자동 주문 시뮬레이터 + 시간 배율 (FR-01, FR-20) | 완료 | `services/simulator_service.py` |
| 상태 스냅샷 (FR-15) | 완료 | `services/state_service.py`, `api/routers/state.py` |
| 통계 (FR-21) | 완료 | `services/stats_service.py`, `api/routers/stats.py` |
| `/ws/client` 브로드캐스트 | 완료 | `api/ws/client_ws.py` |
| `/ws/bridge` 프로토콜 (하트비트, 작업 타임아웃, 재접속 복구) | 완료 | `api/ws/bridge_ws.py`, `services/bridge_protocol_service.py` |
| 백엔드 단위 테스트 | 통과 (5 passed) | `app/backend/tests/` |

### M2 — 가상 로봇 ✅ 완료

| 항목 | 상태 | 위치 |
| --- | --- | --- |
| `/ws/bridge` 클라이언트 접속 + 재접속 (FR-18) | 완료 | `virtual-robot/virtual_robot/client.py` |
| LOAD/UNLOAD phase 진행 (FR-05, FR-07, PRD 7.7 단계표) | 완료 | `virtual_robot/task_executor.py` |
| 장애 주입 NO_BOARD / GRIP_FAIL (FR-19) | 완료 | `task_executor.py`, `state.py` |
| 단계 시간 설정 파일 | 완료 | `virtual-robot/config/phase_times.yaml` |
| 가상 로봇 단위 테스트 | 통과 (5 passed) | `virtual-robot/tests/test_task_executor.py` |

### M3 — 웹 화면 ✅ 완료

| 항목 | 상태 | 위치 / 비고 |
| --- | --- | --- |
| REST/WS 연동, 실시간 상태 수신 | 완료 | `frontend/src/hooks/useLiveState.ts` |
| 수동 주문 폼 (FR-02 웹 쪽) | 완료 | `components/organisms/OrderForm.tsx` |
| 보충 알럿 모달 (FR-10 웹 쪽) | 완료 | `components/organisms/RefillModal.tsx` |
| 디버그 패널 (FR-19 웹 쪽 트리거) | 완료 | `components/organisms/DebugPanel.tsx` |
| 이벤트 로그 패널 (FR-17) | 완료 | `components/organisms/EventLogPanel.tsx` |
| 연결 상태 표시 (FR-16) | 완료 | `components/molecules/ConnectionStatus.tsx` |
| 재고·대기열 상태 표시 | 완료 (텍스트·목록 수준) | `InventoryPanel.tsx`, `OrderQueuePanel.tsx` |
| **2D 업장 레이아웃 (PRD 8.1~8.2)** | **완료 (2026-11-12)** | `components/organisms/WorkshopStage.tsx` — 프린터 3층, 로봇팔, 보드 적재대, 수령대, 손님(주문 중인 전체 건수)을 SVG로 배치. 기존 텍스트 전용 `PrinterPanel`/`PrinterSlotRow`는 중복이라 제거 |
| **로봇팔 애니메이션 동기화 (FR-13, FR-14, PRD 8.3)** | **완료 (2026-11-12)** | `hooks/useRobotArm.ts` + `lib/robotArm.ts` — `robot.feedback`의 phase/type/slot로 목표 자세(HOME/STOCK/PICKUP/PRINTER_1~3)를 정하고, `virtual-robot/config/phase_times.yaml`과 맞춘 단계 시간(시간배율 반영)으로 requestAnimationFrame 보간. 2관절 IK로 베이스→팔꿈치→그리퍼를 그리고, 보드를 쥔 상태도 표시. framer-motion 등 새 의존성은 추가하지 않음(PRD 8.3이 언급한 requestAnimationFrame 방식 채택) |

의도적으로 단순화한 부분: 손님 캐릭터는 "주문 시 입장 → 대기 줄 → 수령 시 퇴장" 개념을 개별 애니메이션 없이 "현재 미완료 주문 수만큼 아이콘 표시"로 구현했다(대기+작업중+수령대기 합계 = PICKED_UP 전까지의 모든 주문과 정확히 일치). 더 정교한 입장/퇴장 모션이 필요하면 추가 작업이 필요하다.

### M4 — 시나리오 테스트·시연 ⬜ 미착수

- PRD 9장 시퀀스(정상 흐름, 작업 중 이벤트, 재고 0, 실물 보드 없음, 기타 예외) 통합 테스트 없음.
- 30분 연속 운전 점검 없음.
- `docker compose up` 전체 스택을 엔드투엔드로 띄워본 기록 없음 (가상 로봇이 docker-compose 서비스로 아직 연결되어 있는지도 확인 필요).

### 다음 단계 (ROS 2) ⬜ 미착수

- `ros2_ws/` 디렉터리 자체가 아직 없음. `printshop_interfaces`, `printshop_bridge`, `printshop_executor` 전부 미착수.
- PRD 7.5의 Action/Topic 정의는 문서로만 존재.

## 2. 다음에 이어서 할 작업 (우선순위 순)

1. **`app/` 커밋** — 현재 전부 untracked라 작업물이 로컬에만 있음. 가장 먼저 커밋해서 안전하게 보관한다. (주의: `app/.gitignore`가 `virtual-robot/.venv`, `virtual-robot/__pycache__`, `virtual-robot/.pytest_cache`, `backend/dev.db`, `backend/e2e.db`를 빠뜨리고 있어 그대로 `git add app/` 하면 같이 커밋된다 — 커밋 전에 `.gitignore`부터 보완할 것.)
2. **M4: 시나리오 통합 테스트** — PRD 9.1~9.5 시퀀스를 최소 하나씩 커버하는 통합 테스트(백엔드 `tests/`에 e2e 성격 테스트 추가, 또는 docker compose로 수동 시연 체크리스트 작성).
3. **docker compose 풀스택 점검** — `virtual-robot`이 compose 서비스로 등록되어 있는지 확인하고, `docker compose up --build`로 MySQL+backend+virtual-robot+frontend가 함께 돌아가는지 1회 검증.
4. **다음 단계 착수 여부 논의** — ROS 2 브릿지(`ros2_ws/`)는 PRD상 "다음 단계"이므로, 위 1~3이 끝난 뒤 착수 여부를 다시 확인.

## 3. PRD 10.7 미결 사항 (여전히 열려 있음)

- [ ] 7.7 단계 시간 기본값을 그대로 쓸지, ROS 2 담당자에게 예상 시간을 받아 맞출지
- [ ] 웹 화면을 여러 대에서 동시에 볼지, 조작 권한을 나눌지
- [ ] UNLOAD 파지 실패 시 자동 재시도 횟수
- [ ] (다음 단계) 로봇 모델·그리퍼 모델, ROS 2 배포판과 DSR 패키지 버전
- [ ] (다음 단계) 실물 수령대 칸 수, 가득 찼을 때 UNLOAD를 멈출지 여부
