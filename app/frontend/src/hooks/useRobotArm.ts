import { useEffect, useRef, useState } from "react";
import { ARM_BASE, ARM_SEGMENT_LEN, POSES, resolvePhaseTarget, solveTwoLinkIK, type Point } from "../lib/robotArm";
import { stockPickPoint } from "../lib/stock";
import type { FeedbackEvent } from "./useLiveState";

export interface ArmPose {
  wrist: Point;
  elbow: Point;
  holding: boolean;
}

interface Tween {
  from: Point;
  to: Point;
  holding: boolean;
  start: number;
  duration: number;
}

function wristAt(tween: Tween, now: number): { wrist: Point; done: boolean } {
  const t = tween.duration <= 0 ? 1 : Math.min(1, (now - tween.start) / tween.duration);
  return {
    wrist: {
      x: tween.from.x + (tween.to.x - tween.from.x) * t,
      y: tween.from.y + (tween.to.y - tween.from.y) * t,
    },
    done: t >= 1,
  };
}

function armPoseFromWrist(wrist: Point, holding: boolean): ArmPose {
  const { elbow } = solveTwoLinkIK(ARM_BASE, wrist, ARM_SEGMENT_LEN, ARM_SEGMENT_LEN);
  return { wrist, elbow, holding };
}

/** PRD 8.3: feedback의 phase를 받아 목표 자세로 보간 이동한다. 다음 feedback이 먼저 오면 그 즉시 다음 목표로
 * 넘어간다. 잡기/놓기(holding)는 단계가 바뀌는 그 순간(즉, 아직 이전 목표 지점에 있을 때) 전환한다 — 이동 도중에
 * 전환하면 "수령대/적재대에 놓고 온 게 아니라 들고 돌아오는" 것처럼 보인다. */
export function useRobotArm(feedback: FeedbackEvent | null, timeScale: number, stockRemaining: number): ArmPose {
  const [pose, setPose] = useState<ArmPose>(() => armPoseFromWrist(POSES.HOME, false));
  const tweenRef = useRef<Tween | null>(null);
  const rafRef = useRef<number | null>(null);
  const lastEventRef = useRef<FeedbackEvent | null>(null);

  useEffect(() => {
    if (!feedback || feedback === lastEventRef.current) return;
    lastEventRef.current = feedback;

    const now = performance.now();
    const currentWrist = tweenRef.current ? wristAt(tweenRef.current, now).wrist : POSES.HOME;
    const target = resolvePhaseTarget(feedback.type, feedback.phase, feedback.slot, timeScale);
    // STOCK은 재고가 쌓인 높이에 따라 맨 위 보드 위치가 달라지므로, BoardStock 그림과 같은 좌표를
    // 쓰는 stockPickPoint로 보정한다(그 외 포즈는 고정된 POSES 좌표를 그대로 쓴다).
    const targetPoint = target.pose === "STOCK" ? stockPickPoint(stockRemaining) : POSES[target.pose];

    tweenRef.current = {
      from: currentWrist,
      to: targetPoint,
      holding: target.holding,
      start: now,
      duration: target.durationSec * 1000,
    };

    // holding 전환은 다음 rAF까지 기다리지 않고 즉시 반영한다.
    setPose(armPoseFromWrist(currentWrist, target.holding));

    if (rafRef.current == null) {
      rafRef.current = requestAnimationFrame(tick);
    }
    // feedback 객체 참조가 바뀔 때만 새 트윈을 시작한다. timeScale은 트윈 시작 시점 값을 쓴다.
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [feedback]);

  function tick() {
    const tween = tweenRef.current;
    if (!tween) {
      rafRef.current = null;
      return;
    }
    const { wrist, done } = wristAt(tween, performance.now());
    setPose(armPoseFromWrist(wrist, tween.holding));
    rafRef.current = done ? null : requestAnimationFrame(tick);
  }

  useEffect(() => {
    return () => {
      if (rafRef.current != null) cancelAnimationFrame(rafRef.current);
    };
  }, []);

  return pose;
}
