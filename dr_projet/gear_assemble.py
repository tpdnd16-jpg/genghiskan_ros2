
"""m0609_gear_assemble

Doosan Teaching Pendant에서 작성된 DRL 프로그램(m0609_gear_assemble)을 ROS2 +
DSR_ROBOT2 python API로 옮긴 버전이다. LG_x / RG_x 포인트에서 기어를 집어
반대쪽(RG_x / LG_x)에 놓는 동작을 3회 반복하고, 마지막으로 center 포인트에
기어를 끼우면서 힘 제어(force control)로 삽입 완료 여부를 확인한다.
"""

import rclpy
import DR_init

ROBOT_ID = "dsr01"
ROBOT_MODEL = "m0609"

VELJ, ACCJ = 60.0, 100.0
VELX1, VELX2 = 250.0, 80.625
ACCX1, ACCX2 = 1000.0, 322.5

# 전체 pick & place 시퀀스(gear1 -> gear2 -> gear3 -> center)를 반복할 횟수.
# 원본 DRL 프로그램은 1회만 실행한다.
CYCLE = 1

DR_init.__dsr__id = ROBOT_ID
DR_init.__dsr__model = ROBOT_MODEL

GLOBAL_HEIGHT = 424.31

# 아래 posx 좌표들은 원본 DRL 프로그램의 Global_* 변수와 1:1 대응되며,
# teaching pendant 쪽 값과 비교/점검하기 쉽도록 이름과 값을 그대로 유지했다.
HOME = [367.39, 6.87, 424.06, 146.04, 179.96, 145.97]

LG_1 = [517.52, -10.10, 274.01, 163.86, 178.89, 165.58]
LG_2 = [610.71, -56.20, 274.64, 158.81, 179.07, 160.10]
LG_3 = [604.12, 46.83, 274.44, 162.74, 179.05, 164.57]
LG_CENTER = [575.08, -7.98, 274.04, 146.42, 179.32, 148.29]

RG_1 = [217.28, -11.64, 272.66, 146.57, 178.60, 148.72]
RG_2 = [310.09, -56.53, 272.92, 150.76, 179.09, 153.11]
RG_3 = [307.98, 45.54, 272.98, 152.52, 178.24, 154.59]
RG_CENTER = [278.89, -9.36, 272.69, 142.33, 177.98, 144.22]

# "_UP" : 같은 XY/방향에서 Z만 GLOBAL_HEIGHT로 올린 접근/후퇴 포인트
# (원본의 Global_*_1 변수에 대응)
LG_1_UP = [517.52, -10.10, GLOBAL_HEIGHT, 163.86, 178.89, 165.58]
LG_2_UP = [610.71, -56.20, GLOBAL_HEIGHT, 158.81, 179.07, 160.10]
LG_3_UP = [604.12, 46.83, GLOBAL_HEIGHT, 162.74, 179.05, 164.57]
LG_CENTER_UP = [575.08, -7.98, GLOBAL_HEIGHT, 146.42, 179.32, 148.29]

RG_1_UP = [217.28, -11.64, GLOBAL_HEIGHT, 146.57, 178.60, 148.72]
RG_2_UP = [310.09, -56.53, GLOBAL_HEIGHT, 150.76, 179.09, 153.11]
RG_3_UP = [307.98, 45.54, GLOBAL_HEIGHT, 152.52, 178.24, 154.59]
RG_CENTER_UP = [278.89, -9.36, GLOBAL_HEIGHT, 142.33, 177.98, 144.22]

CENTERPOINT = [274.90, -2.24, 305.69, 2.44, -179.50, 2.23]


def main(args=None):
    rclpy.init(args=args)
    node = rclpy.create_node("gear_assemble", namespace=ROBOT_ID)

    DR_init.__dsr__node = node

    try:
        from DSR_ROBOT2 import (
            DR_AXIS_Z,
            DR_BASE,
            DR_AVOID,
            DR_FC_MOD_REL,
            DR_MV_MOD_ABS,
            DR_MV_RA_DUPLICATE,
            DR_QSTOP,
            DR_TOOL,
            ON,
            OFF,
            check_force_condition,
            check_position_condition,
            move_periodic,
            movel,
            release_compliance_ctrl,
            release_force,
            set_accj,
            set_accx,
            set_desired_force,
            set_digital_output,
            set_singular_handling,
            set_stiffnessx,
            set_velj,
            set_velx,
            task_compliance_ctrl,
            wait,
        )
        from DR_common2 import posx

        import DSR_ROBOT2
        from dsr_msgs2.srv import MoveStop

    except ImportError as e:
        node.get_logger().info(f"Error importing DSR_ROBOT2 : {e}")
        return

    # 원본 DRL 프로그램에는 Tool/TCP 설정 노드가 없으므로, 여기서도 별도로
    # set_tool()/set_tcp()를 호출하지 않고 컨트롤러에 이미 지정된 Tool
    # Weight/TCP를 그대로 사용한다. 실행 전 teaching pendant에서 설정된
    # Tool/TCP가 이 프로그램의 좌표들과 맞는지 반드시 확인한다.

    # DSR_ROBOT2.py에는 DRL의 stop()에 대응하는 python wrapper가 없어
    # "motion/move_stop" 서비스를 직접 호출한다. movel/movej 등 내부에서
    # 쓰는 것과 동일한 서비스 이름 prefix를 사용해 실제 배포된 서비스 이름과
    # 어긋나지 않도록 한다.
    move_stop_client = node.create_client(
        MoveStop, DSR_ROBOT2._srv_name_prefix + "motion/move_stop"
    )
    while not move_stop_client.wait_for_service(timeout_sec=1.0):
        node.get_logger().info("Waiting for service motion/move_stop ...")

    def move_stop(stop_mode):
        req = MoveStop.Request()
        req.stop_mode = stop_mode
        future = move_stop_client.call_async(req)
        rclpy.spin_until_future_complete(node, future)
        return future.result()

    home = posx(HOME)

    lg_1, lg_2, lg_3, lg_center = posx(LG_1), posx(LG_2), posx(LG_3), posx(LG_CENTER)
    rg_1, rg_2, rg_3, rg_center = posx(RG_1), posx(RG_2), posx(RG_3), posx(RG_CENTER)

    lg_1_up, lg_2_up, lg_3_up, lg_center_up = (
        posx(LG_1_UP),
        posx(LG_2_UP),
        posx(LG_3_UP),
        posx(LG_CENTER_UP),
    )
    rg_1_up, rg_2_up, rg_3_up, rg_center_up = (
        posx(RG_1_UP),
        posx(RG_2_UP),
        posx(RG_3_UP),
        posx(RG_CENTER_UP),
    )

    centerpoint = posx(CENTERPOINT)

    def move_abs(pos):
        movel(pos, radius=0.0, ref=0, mod=DR_MV_MOD_ABS, ra=DR_MV_RA_DUPLICATE)

    def grip_close():
        set_digital_output(1, OFF)
        set_digital_output(2, ON)
        wait(0.5)

    def grip_open():
        set_digital_output(1, ON)
        set_digital_output(2, OFF)
        wait(0.5)

    def pick_and_place(lg_up, lg_down, rg_up, rg_down):
        move_abs(lg_up)
        move_abs(lg_down)
        grip_close()
        move_abs(lg_up)
        move_abs(rg_up)
        move_abs(rg_down)
        grip_open()
        move_abs(rg_up)

    def gear1():
        pick_and_place(lg_1_up, lg_1, rg_1_up, rg_1)

    def gear2():
        pick_and_place(lg_2_up, lg_2, rg_2_up, rg_2)

    def gear3():
        pick_and_place(lg_3_up, lg_3, rg_3_up, rg_3)

    def checkforce():
        task_compliance_ctrl()
        set_stiffnessx([3000.0, 3000.0, 3000.0, 200.0, 200.0, 200.0], time=0.0)
        set_desired_force(
            [0.0, 0.0, -15.0, 0.0, 0.0, 0.0],
            [0, 0, 1, 0, 0, 0],
            time=0.0,
            mod=DR_FC_MOD_REL,
        )
        while True:
            # DSR_ROBOT2의 check_*_condition 계열은 0=조건 충족, -1=조건 미충족을
            # 반환한다(DRL의 bool 리턴과 반대로, 0은 python에서 False이므로
            # 반드시 `== 0`으로 비교해야 한다).
            if check_force_condition(axis=DR_AXIS_Z, min=10, ref=DR_TOOL) == 0:
                move_periodic(
                    amp=[0.0, 0.0, 0.0, 0.0, 0.0, 10.0],
                    period=[0.0, 0.0, 0.0, 0.0, 0.0, 2.0],
                    atime=1.0,
                    repeat=5,
                    ref=0,
                )
                if check_position_condition(axis=DR_AXIS_Z, max=291.4, ref=DR_BASE) == 0:
                    move_stop(DR_QSTOP)
                break
        release_compliance_ctrl()
        release_force(time=0.0)

    def center():
        move_abs(lg_center_up)
        move_abs(lg_center)
        grip_close()
        move_abs(lg_center_up)
        move_abs(rg_center_up)
        move_abs(centerpoint)
        checkforce()
        grip_open()
        move_abs(rg_center_up)
        move_abs(home)

    set_singular_handling(DR_AVOID)
    set_velj(VELJ)
    set_accj(ACCJ)
    # 원본 DRL은 set_velx(250.0, 80.625, DR_OFF)처럼 세 번째 인자를 받지만
    # DSR_ROBOT2.py의 python wrapper는 vel1, vel2 두 개만 지원하므로
    # 세 번째 인자는 생략한다.
    set_velx(VELX1, VELX2)
    set_accx(ACCX1, ACCX2)

    try:
        for i in range(CYCLE):
            node.get_logger().info(f"=== Cycle {i + 1}/{CYCLE} ===")
            move_abs(home)
            grip_open()
            gear1()
            gear2()
            gear3()
            center()

    except KeyboardInterrupt:
        node.get_logger().info("Program Stopped")

    except Exception as e:
        node.get_logger().error(f"Robot Error: {e}")

    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()



