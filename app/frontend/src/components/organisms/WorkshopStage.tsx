import { useEffect, useRef, useState } from "react";
import { PrinterUnit } from "../molecules/PrinterUnit";
import { BoardStock } from "../molecules/BoardStock";
import { PickupCounter } from "../molecules/PickupCounter";
import { CustomerRow } from "../molecules/CustomerRow";
import { RobotArm } from "../molecules/RobotArm";
import { useRobotArm } from "../../hooks/useRobotArm";
import { ARM_BASE, POSES, printerPose } from "../../lib/robotArm";
import type { Order, Printer } from "../../types";
import type { FeedbackEvent } from "../../hooks/useLiveState";

interface WorkshopStageProps {
  printers: Printer[];
  waitingOrders: Order[];
  activeOrders: Order[];
  pickupOrders: Order[];
  feedback: FeedbackEvent | null;
  timeScale: number;
}

/** PRD 8.1~8.3: 프린터·로봇팔·적재대·수령대·손님을 배치한 2D 업장 화면. */
export function WorkshopStage({
  printers,
  waitingOrders,
  activeOrders,
  pickupOrders,
  feedback,
  timeScale,
}: WorkshopStageProps) {
  const [now, setNow] = useState(() => Date.now());
  useEffect(() => {
    const id = setInterval(() => setNow(Date.now()), 250);
    return () => clearInterval(id);
  }, []);

  const { wrist, elbow, holding } = useRobotArm(feedback, timeScale);
  const inShopCount = waitingOrders.length + activeOrders.length + pickupOrders.length;

  // 적재대(STOCK)에서 보드를 집는 단계인 동안에만 맨 위 보드를 "꺼내는 중"으로 강조한다.
  const STOCK_PHASES = new Set(["MOVE_TO_STOCK", "PICK_BOARD", "CHECK_GRIP"]);
  const pickingFromStock = feedback?.type === "LOAD" && STOCK_PHASES.has(feedback.phase);

  // 서버의 상태 반영(READY_FOR_PICKUP/PRINTING)은 RETURN_HOME 단계가 다 끝난 뒤(task.result 시점)에야
  // 오므로, 그리퍼에서 보드가 사라지는 시점(RETURN_HOME 시작)과 수령대/프린터에 보드가 나타나는 시점
  // 사이에 몇 초간 "아무 데도 없는" 빈 구간이 생긴다. RETURN_HOME을 본 순간 바로 미리 얹어 보여주고,
  // 서버 데이터가 따라오면 자연스럽게 교체한다. 직전 phase가 실제 "놓기"였을 때만 반영해, CHECK_GRIP
  // 실패로 곧장 RETURN_HOME으로 건너뛴 경우(NO_BOARD/GRIP_FAIL)에는 뜨지 않게 한다.
  const [pendingPickup, setPendingPickup] = useState<Order | null>(null);
  const [pendingLoadSlot, setPendingLoadSlot] = useState<number | null>(null);
  const lastFeedbackRef = useRef<FeedbackEvent | null>(null);
  const prevPhaseRef = useRef<string | null>(null);

  useEffect(() => {
    if (!feedback || feedback === lastFeedbackRef.current) return;
    const prevPhase = prevPhaseRef.current;
    lastFeedbackRef.current = feedback;
    prevPhaseRef.current = feedback.phase;
    if (feedback.phase !== "RETURN_HOME") return;

    if (feedback.type === "UNLOAD" && prevPhase === "PLACE_AT_PICKUP") {
      const order = activeOrders.find((o) => o.printer_slot === feedback.slot && o.status === "UNLOADING");
      if (order) setPendingPickup(order);
    } else if (feedback.type === "LOAD" && prevPhase === "PLACE_IN_PRINTER") {
      setPendingLoadSlot(feedback.slot);
    }
  }, [feedback, activeOrders]);

  useEffect(() => {
    if (pendingPickup && pickupOrders.some((o) => o.id === pendingPickup.id)) {
      setPendingPickup(null);
    }
  }, [pendingPickup, pickupOrders]);

  useEffect(() => {
    if (pendingLoadSlot != null && printers.find((p) => p.slot === pendingLoadSlot)?.status === "PRINTING") {
      setPendingLoadSlot(null);
    }
  }, [pendingLoadSlot, printers]);

  const displayedPickupOrders =
    pendingPickup && !pickupOrders.some((o) => o.id === pendingPickup.id)
      ? [pendingPickup, ...pickupOrders]
      : pickupOrders;

  return (
    <section className="panel workshop-stage">
      <h2>업장 현황</h2>
      <svg viewBox="0 0 800 380" className="wp-canvas" role="img" aria-label="업장 현황">
        {[3, 2, 1].map((slot) => {
          const pos = POSES[printerPose(slot)];
          return (
            <PrinterUnit
              key={slot}
              slot={slot}
              x={pos.x}
              y={pos.y}
              printer={printers.find((p) => p.slot === slot)}
              order={activeOrders.find((o) => o.printer_slot === slot)}
              justLoaded={pendingLoadSlot === slot}
              now={now}
            />
          );
        })}
        <PickupCounter x={POSES.PICKUP.x} y={POSES.PICKUP.y} orders={displayedPickupOrders} />
        <BoardStock x={POSES.STOCK.x} y={POSES.STOCK.y} picking={pickingFromStock} />
        <CustomerRow x={POSES.PICKUP.x - 50} y={POSES.PICKUP.y + 60} count={inShopCount} />
        {/* 로봇팔은 정지 배경(적재대/수령대) 위에 겹칠 수 있으니 SVG 쌓임 순서상 마지막(맨 위)에 그린다 */}
        <RobotArm base={ARM_BASE} elbow={elbow} wrist={wrist} holding={holding} />
      </svg>
    </section>
  );
}
