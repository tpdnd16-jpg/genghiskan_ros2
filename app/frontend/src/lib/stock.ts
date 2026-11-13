// 보드 적재대(BoardStock)의 보드 쌓임 위치 계산. BoardStock.tsx(그림)와
// useRobotArm.ts(로봇팔이 집는 좌표)가 같은 기준을 쓰도록 여기서 한 번만 정의한다.

import { POSES, type Point } from "./robotArm";

export const STOCK_MAX_VISIBLE = 5;
export const STOCK_BOARD_WIDTH = 56;
export const STOCK_BOARD_HEIGHT = 6;
// 높이보다 큰 스텝을 줘서 보드 사이에 항상 눈에 보이는 간격이 남도록 한다.
export const STOCK_BOARD_GAP = 4;
export const STOCK_BOARD_STEP = STOCK_BOARD_HEIGHT + STOCK_BOARD_GAP;
// BoardStock 로컬 좌표에서 맨 아래(첫 번째로 쌓인) 보드의 y.
const STOCK_BASE_LOCAL_Y = 14;

// RobotArm.tsx가 "집은 보드"를 그리는 위치는 wrist 좌표 자체가 아니라 그보다 아래쪽
// (y + 8 ~ y + 18, 중심 y + 13)이다 — 그리퍼 손가락에 매달린 모습을 표현하기 위함.
// 적재대에서 꺼낼 때는 이 held-board 중심이 실제 맨 위 보드 중심과 겹쳐야 하므로,
// wrist 목표 좌표를 그만큼 위로 보정한다.
const GRIPPER_HELD_BOARD_OFFSET_Y = 13;

export function stockVisibleCount(remaining: number): number {
  return Math.min(STOCK_MAX_VISIBLE, Math.max(0, remaining));
}

/** 현재 보이는 보드 중 맨 위(다음에 로봇이 집어갈) 보드의 index. 보드가 없으면 빈 칸의 index(0)를 반환한다. */
export function stockTopIndex(remaining: number): number {
  return Math.max(0, stockVisibleCount(remaining) - 1);
}

/** BoardStock 로컬 좌표에서 맨 위 보드의 중심 y. */
function stockTopLocalY(remaining: number): number {
  return STOCK_BASE_LOCAL_Y - stockTopIndex(remaining) * STOCK_BOARD_STEP + STOCK_BOARD_HEIGHT / 2;
}

/** 로봇팔이 적재대에서 보드를 집을 때 실제로 향해야 하는 월드 좌표(wrist 목표).
 * remaining이 줄어 보드가 낮게 쌓일수록 더 아래를, 많이 쌓였을수록 더 위를 짚어
 * 그림에 보이는 "맨 위 보드" 위치와 로봇팔(및 집은 보드 표시)이 항상 일치하도록 한다. */
export function stockPickPoint(remaining: number): Point {
  const topBoardCenterY = POSES.STOCK.y + stockTopLocalY(remaining);
  return { x: POSES.STOCK.x, y: topBoardCenterY - GRIPPER_HELD_BOARD_OFFSET_Y };
}
