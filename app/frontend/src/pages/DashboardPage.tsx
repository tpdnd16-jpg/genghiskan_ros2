import { useState } from "react";
import { DashboardTemplate } from "../components/templates/DashboardTemplate";
import { TopBar } from "../components/organisms/TopBar";
import { WorkshopStage } from "../components/organisms/WorkshopStage";
import { OrderQueuePanel } from "../components/organisms/OrderQueuePanel";
import { OrderForm } from "../components/organisms/OrderForm";
import { DebugPanel } from "../components/organisms/DebugPanel";
import { EventLogPanel } from "../components/organisms/EventLogPanel";
import { BoardStockRefillModal } from "../components/organisms/BoardStockRefillModal";
import { useLiveState } from "../hooks/useLiveState";
import { api, WorkRequestError } from "../lib/api";
import type { Shape } from "../types";

export function DashboardPage() {
  const { snapshot, connected, alert, log, setAlert, feedback, updateSimulator } = useLiveState();
  const [orderError, setOrderError] = useState<string | null>(null);

  const handleOrder = async (customerName: string, shape: Shape) => {
    try {
      setOrderError(null);
      // 작업요청(SQS) 경로: 베드·프린터를 즉시 확인해 가능하면 SQS로 디스패치한다
      // (PRD: assets/docs/prd-work-request-sqs.md).
      await api.createWorkRequest(customerName, shape);
      return true;
    } catch (e) {
      setOrderError(e instanceof WorkRequestError ? e.message : String(e));
      return false;
    }
  };

  const handleBoardStockRefillComplete = async () => {
    await api.refillBoardStockComplete();
    setAlert(null);
  };

  if (!snapshot) {
    return <div className="app-loading">서버에 연결하는 중...</div>;
  }

  const { printers, robot, waiting_orders, active_orders, pickup_orders, simulator } = snapshot;

  return (
    <DashboardTemplate
      topBar={
        <TopBar
          wsConnected={connected}
          robot={robot}
          simulator={simulator}
          onPatchSimulator={(patch) => api.patchSimulator(patch).then(updateSimulator)}
        />
      }
      workshopStage={
        <WorkshopStage
          printers={printers}
          waitingOrders={waiting_orders}
          activeOrders={active_orders}
          pickupOrders={pickup_orders}
          feedback={feedback}
          timeScale={simulator.time_scale}
        />
      }
      waitingQueue={<OrderQueuePanel title="대기 큐" orders={waiting_orders} />}
      activeQueue={<OrderQueuePanel title="작업중" orders={active_orders} showStatus />}
      pickupQueue={<OrderQueuePanel title="수령 대기" orders={pickup_orders} />}
      orderForm={<OrderForm onOrder={handleOrder} error={orderError} />}
      debugPanel={<DebugPanel onFault={(kind) => api.setDebugFault(kind)} />}
      eventLogPanel={<EventLogPanel log={log} />}
      modal={<BoardStockRefillModal alert={alert} onConfirm={handleBoardStockRefillComplete} />}
    />
  );
}
