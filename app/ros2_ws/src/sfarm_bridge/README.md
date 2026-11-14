# `sfarm_bridge` 실행 및 테스트 가이드

웹(AWS SQS)과 ROS 2 로봇 제어 노드 사이를 연결하는 브릿지 패키지(`sfarm_bridge`) 실행 및 테스트 방법입니다.

---

## 1. 사전 준비 (`.env` 설정)

`sfarm_bridge`는 실행 시 `.env` 파일에서 AWS SQS 접속 정보를 자동으로 불러옵니다. (`.env`는 `.gitignore`에 포함되어 있으므로 팀원 각자 생성해야 합니다.)

`app/ros2_ws/src/sfarm_bridge/.env` 파일을 만들고 아래 값을 채우세요:

```dotenv
AWS_ACCESS_KEY_ID=<YOUR_ACCESS_KEY>
AWS_SECRET_ACCESS_KEY=<YOUR_SECRET_KEY>
AWS_REGION=ap-northeast-2
COMMAND_QUEUE_URL=https://sqs.ap-northeast-2.amazonaws.com/<ACCOUNT_ID>/robot-commands.fifo
EVENT_QUEUE_URL=https://sqs.ap-northeast-2.amazonaws.com/<ACCOUNT_ID>/robot-events
```

---

## 2. 빌드 및 환경 로드

> **주의**: 반드시 `app/ros2_ws` **루트**에서 빌드하세요 (`src/` 내부에서 `colcon build` 실행 금지).

```bash
source /opt/ros/jazzy/setup.bash
cd /home/rokey/workspace/genghiskan_ros2/app/ros2_ws

colcon build --symlink-install --packages-select sfarm_interfaces sfarm_bridge
source install/setup.bash
```

---

## 3. 브릿지 노드 실행

```bash
# 기본 실행 (.env 자동 로드)
ros2 run sfarm_bridge sfarm_bridge

# ROS 파라미터로 직접 지정해 실행할 때
ros2 run sfarm_bridge sfarm_bridge --ros-args \
  -p robot_id:=robot-arm-1 \
  -p action_timeout_sec:=120.0
```

정상 실행 시 다음과 같은 로그가 출력됩니다:
```text
[INFO] [...][sfarm_bridge_node]: listening on https://sqs.ap-northeast-2.amazonaws.com/.../robot-commands.fifo
```

---

## 4. 통신 규격 및 테스트

### 4.1 연결되는 ROS 2 인터페이스 (`sfarm_interfaces`)

| 종류 | 채널 주소 | 인터페이스 타입 | 방향 |
| :--- | :--- | :--- | :--- |
| Action | `/sfarm/insert` | `sfarm_interfaces/action/Insert` | `sfarm_bridge`(Client) → 로봇 팔 노드(Server) |
| Action | `/sfarm/eject` | `sfarm_interfaces/action/Eject` | `sfarm_bridge`(Client) → 로봇 팔 노드(Server) |
| Service | `/sfarm/error` | `sfarm_interfaces/srv/Error` | 로봇 팔 노드(Client) → `sfarm_bridge`(Server) |

### 4.2 웹(SQS `robot-commands.fifo`) 수신 메시지 예시

- **Insert (적재대 → 3D 프린터)**:
  ```json
  {"work_id": 16, "start_pos_id": 3, "sd_pos_id": 2}
  ```
- **Eject (3D 프린터 → 수령대)**:
  ```json
  {"work_id": 17, "sd_pos_id": 2, "receive_pos_id": 1}
  ```

> **참고**: `/sfarm/insert` 또는 `/sfarm/eject` Action Server 노드가 실행 중이 아니면 `action server is not available` 로그가 출력되며, SQS 메시지는 유실 방지를 위해 삭제되지 않고 큐에 유지됩니다.

### 4.3 CLI 단독 테스트

새 터미널에서 환경을 소싱한 뒤 아래 명령으로 동작을 확인할 수 있습니다:

```bash
source /opt/ros/jazzy/setup.bash
source /home/rokey/workspace/genghiskan_ros2/app/ros2_ws/install/setup.bash

# 1. 노드 및 서비스 확인
ros2 node list
ros2 service list | grep sfarm

# 2. /sfarm/error 서비스 호출 테스트 (robot-events SQS로 ERROR 이벤트 발행 확인)
ros2 service call /sfarm/error sfarm_interfaces/srv/Error "{message: 'test error from cli'}"

# 3. 인터페이스 정의 확인
ros2 interface show sfarm_interfaces/action/Insert
ros2 interface show sfarm_interfaces/action/Eject
```

---

## 5. 단위 테스트 및 린트 검증

```bash
source /opt/ros/jazzy/setup.bash
cd /home/rokey/workspace/genghiskan_ros2/app/ros2_ws
source install/setup.bash

colcon test --packages-select sfarm_interfaces sfarm_bridge
colcon test-result --verbose
```

---

## 6. 자주 겪는 문제

- **`Package 'sfarm_interfaces' not found` / `No module named 'sfarm_interfaces'`**:
  `sfarm_interfaces`를 포함해 다시 빌드하고 `source app/ros2_ws/install/setup.bash`를 실행하세요.
- **코드 수정이 반영되지 않을 때**:
  `app/ros2_ws/src/` 안에 실수로 생성된 `build/`, `install/` 폴더가 없는지 확인하세요. 있다면 삭제한 뒤 `app/ros2_ws/`에서 다시 빌드해야 합니다.
