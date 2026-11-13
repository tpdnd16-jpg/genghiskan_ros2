import type { Point } from "../../lib/robotArm";

interface RobotArmProps {
  base: Point;
  elbow: Point;
  wrist: Point;
  holding: boolean;
}

export function RobotArm({ base, elbow, wrist, holding }: RobotArmProps) {
  return (
    <g className="wp-arm">
      <circle cx={base.x} cy={base.y} r={16} className="wp-arm-base" />
      <line x1={base.x} y1={base.y} x2={elbow.x} y2={elbow.y} className="wp-arm-segment" />
      <line x1={elbow.x} y1={elbow.y} x2={wrist.x} y2={wrist.y} className="wp-arm-segment" />
      <circle cx={elbow.x} cy={elbow.y} r={6} className="wp-arm-joint" />
      <g className="wp-arm-gripper">
        <rect x={wrist.x - 6} y={wrist.y - 7} width={12} height={7} rx={2} className="wp-arm-gripper-palm" />
        <path
          d={`M ${wrist.x - 6} ${wrist.y} v 6 q 0 3 3 3 h 2 v -3 h -3 z`}
          className="wp-arm-gripper-finger"
        />
        <path
          d={`M ${wrist.x + 6} ${wrist.y} v 6 q 0 3 -3 3 h -2 v -3 h 3 z`}
          className="wp-arm-gripper-finger"
        />
      </g>
      {holding && <rect x={wrist.x - 10} y={wrist.y + 8} width={20} height={10} rx={2} className="wp-board wp-board-held" />}
    </g>
  );
}
