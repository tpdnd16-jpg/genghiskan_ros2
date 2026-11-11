
# =====================================
# Gear Assembly - 4 Gears
# =====================================

set_velj(30)
set_accj(30)
set_velx(50)
set_accx(50)

HOME_POS = Global_Home

# Gear 1
PICK_APPROACH_1 = Global_LG_1_1
PICK_1 = Global_LG_1
PLACE_APPROACH_1 = Global_RG_1_1
INSERT_1 = Global_RG_1

# Gear 2
PICK_APPROACH_2 = Global_LG_2_1
PICK_2 = Global_LG_2
PLACE_APPROACH_2 = Global_RG_2_1
INSERT_2 = Global_RG_2

# Gear 3
PICK_APPROACH_3 = Global_LG_3_1
PICK_3 = Global_LG_3
PLACE_APPROACH_3 = Global_RG_3_1
INSERT_3 = Global_RG_3

# Gear 4
PICK_APPROACH_4 = Global_LG_Center_1
PICK_4 = Global_LG_Center
PLACE_APPROACH_4 = Global_RG_Center_1
INSERT_4 = Global_RG_Center


def gear_assembly(pick_approach, pick,
                  place_approach, insert):

    # Pick
    movel(pick_approach)

    # TODO: Open Gripper
    movel(pick)

    # TODO: Close Gripper
    # 그리퍼 닫기
    set_digital_output(1, OFF)
    set_digital_output(2, ON)

    wait(0.5)

    # Lift
    movel(pick_approach)

    # Horizontal Transfer
    movel(place_approach)

    # Compliance
    task_compliance_ctrl(
        stx=[2000, 2000, 1500, 150, 150, 150],
        time=0.3
    )

    # Force Control
    set_desired_force(
        fd=[0, 0, -10, 0, 0, 0],
        dir=[0, 0, 1, 0, 0, 0],
        time=0.3,
        mod=DR_FC_MOD_REL
    )

    # Vertical Insertion
    movel(insert)

    # Periodic Motion
    move_periodic(
        amp=[0, 0, 0.5, 0, 0, 0],
        period=1.0,
        atime=0.3,
        repeat=2,
        ref=DR_BASE
    )

    # Release Control
    release_force(time=0.3)
    release_compliance_ctrl()

    # TODO: Open Gripper
    set_digital_output(1, ON)
    set_digital_output(2, OFF)
    wait(0.5)

    # Retract
    movel(place_approach)


# =====================================
# Main
# =====================================

movej(HOME_POS)

gear_assembly(
    PICK_APPROACH_1, PICK_1,
    PLACE_APPROACH_1, INSERT_1
)

gear_assembly(
    PICK_APPROACH_2, PICK_2,
    PLACE_APPROACH_2, INSERT_2
)

gear_assembly(
    PICK_APPROACH_3, PICK_3,
    PLACE_APPROACH_3, INSERT_3
)

gear_assembly(
    PICK_APPROACH_4, PICK_4,
    PLACE_APPROACH_4, INSERT_4
)

movej(HOME_POS)
