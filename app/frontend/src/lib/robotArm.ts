// PRD 8.3 로봇팔 애니메이션 동기화 + 7.6/7.7 단계·시간 정의.
// 단계 시간 기본값은 app/virtual-robot/config/phase_times.yaml과 값을 맞춘다(서버 설정이 바뀌면 같이 바꿀 것).

export type TaskType = "LOAD" | "UNLOAD";

export type PoseKey = "HOME" | "STOCK" | "PICKUP" | "PRINTER_1" | "PRINTER_2" | "PRINTER_3";

export interface Point {
  x: number;
  y: number;
}

// 프린터 박스 높이(48)·간격과 HOME의 여유 공간을 고려해 배치했다. HOME을 1층 프린터와
// 너무 가깝게 두면(이전: 16px) 팔이 쉬거나 복귀할 때 프린터 박스 경계에 거의 닿아 보여
// "보드를 엉뚱한 데 놓는 것처럼" 보이는 문제가 있었다 — 층 사이 간격도 함께 넓혔다.
export const ARM_BASE: Point = { x: 400, y: 330 };
export const ARM_SEGMENT_LEN = 150;

export const POSES: Record<PoseKey, Point> = {
  HOME: { x: 400, y: 270 },
  STOCK: { x: 640, y: 270 },
  PICKUP: { x: 160, y: 270 },
  PRINTER_1: { x: 400, y: 180 },
  PRINTER_2: { x: 400, y: 110 },
  PRINTER_3: { x: 400, y: 40 },
};

export function printerPose(slot: number): PoseKey {
  const key = `PRINTER_${slot}`;
  return key in POSES ? (key as PoseKey) : "PRINTER_1";
}

const LOAD_PHASE_SEC: Record<string, number> = {
  MOVE_TO_STOCK: 3,
  PICK_BOARD: 2,
  CHECK_GRIP: 1,
  MOVE_TO_PRINTER: 3,
  PLACE_IN_PRINTER: 2,
  RETURN_HOME: 3,
};

const UNLOAD_PHASE_SEC: Record<string, number> = {
  MOVE_TO_PRINTER: 3,
  PICK_FROM_PRINTER: 2,
  CHECK_GRIP: 1,
  MOVE_TO_PICKUP: 4,
  PLACE_AT_PICKUP: 2,
  RETURN_HOME: 3,
};

const FLOOR_OFFSET_SEC: Record<number, number> = { 1: 0, 2: 1, 3: 2 };

const LOAD_HOLDING_PHASES = new Set(["PICK_BOARD", "CHECK_GRIP", "MOVE_TO_PRINTER", "PLACE_IN_PRINTER"]);
const UNLOAD_HOLDING_PHASES = new Set(["PICK_FROM_PRINTER", "CHECK_GRIP", "MOVE_TO_PICKUP", "PLACE_AT_PICKUP"]);

function targetPoseFor(type: TaskType, phase: string, slot: number): PoseKey {
  if (type === "LOAD") {
    switch (phase) {
      case "MOVE_TO_STOCK":
      case "PICK_BOARD":
      case "CHECK_GRIP":
        return "STOCK";
      case "MOVE_TO_PRINTER":
      case "PLACE_IN_PRINTER":
        return printerPose(slot);
      default:
        return "HOME";
    }
  }

  switch (phase) {
    case "MOVE_TO_PRINTER":
    case "PICK_FROM_PRINTER":
    case "CHECK_GRIP":
      return printerPose(slot);
    case "MOVE_TO_PICKUP":
    case "PLACE_AT_PICKUP":
      return "PICKUP";
    default:
      return "HOME";
  }
}

export interface PhaseTarget {
  pose: PoseKey;
  durationSec: number;
  holding: boolean;
}

/** feedback 한 건(type, phase, slot)에 대해 로봇팔이 향할 목표와, 그 이동에 걸리는 시간(배율 반영)을 계산한다. */
export function resolvePhaseTarget(type: TaskType, phase: string, slot: number, timeScale: number): PhaseTarget {
  const secTable = type === "LOAD" ? LOAD_PHASE_SEC : UNLOAD_PHASE_SEC;
  const holdingPhases = type === "LOAD" ? LOAD_HOLDING_PHASES : UNLOAD_HOLDING_PHASES;

  let seconds = secTable[phase] ?? 1;
  if (phase === "MOVE_TO_PRINTER") seconds += FLOOR_OFFSET_SEC[slot] ?? 0;

  return {
    pose: targetPoseFor(type, phase, slot),
    durationSec: Math.max(0.05, seconds * timeScale),
    holding: holdingPhases.has(phase),
  };
}

/** 2관절 팔의 팔꿈치 위치를 구한다 (법선 코사인 법칙, elbow-up 해만 사용). */
export function solveTwoLinkIK(base: Point, target: Point, l1: number, l2: number): { elbow: Point; wrist: Point } {
  const dx = target.x - base.x;
  const dy = target.y - base.y;
  const rawDist = Math.hypot(dx, dy);
  const dist = Math.min(Math.max(rawDist, Math.abs(l1 - l2) + 0.5), l1 + l2 - 0.5);

  const baseAngle = Math.atan2(dy, dx);
  const cosAngle = (l1 * l1 + dist * dist - l2 * l2) / (2 * l1 * dist);
  const angleOffset = Math.acos(Math.min(1, Math.max(-1, cosAngle)));
  const elbowAngle = baseAngle - angleOffset;

  return {
    elbow: {
      x: base.x + l1 * Math.cos(elbowAngle),
      y: base.y + l1 * Math.sin(elbowAngle),
    },
    wrist: target,
  };
}
