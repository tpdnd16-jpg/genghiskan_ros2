import { useState } from "react";
import { DashboardTemplate } from "../components/templates/DashboardTemplate";
import { TopBar } from "../components/organisms/TopBar";
import { WorkshopStage } from "../components/organisms/WorkshopStage";
import { InventoryPanel } from "../components/organisms/InventoryPanel";
import { OrderQueuePanel } from "../components/organisms/OrderQueuePanel";
import { OrderForm } from "../components/organisms/OrderForm";
import { DebugPanel } from "../components/organisms/DebugPanel";
import { EventLogPanel } from "../components/organisms/EventLogPanel";
import { RefillModal } from "../components/organisms/RefillModal";
import { useLiveState } from "../hooks/useLiveState";
import { api } from "../lib/api";
import type { Shape } from "../types";

export function DashboardPage() {
  const { snapshot, connected, alert, log, setAlert, feedback, updateSimulator } = useLiveState();
  const [refillCount, setRefillCount] = useState(6);
  const [orderError, setOrderError] = useState<string | null>(null);

  const handleOrder = async (customerName: string, shape: Shape) => {
    try {
      setOrderError(null);
      await api.createOrder(customerName, shape);
      return true;
    } catch (e) {
      setOrderError(String(e));
      return false;
    }
  };

  const handleRefill = async () => {
    await api.refillInventory(refillCount);
    setAlert(null);
  };

  if (!snapshot) {
    return <div className="app-loading">서버에 연결하는 중...</div>;
  }

  const { printers, inventory, robot, waiting_orders, active_orders, pickup_orders, simulator } = snapshot;

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
          inventory={inventory}
          waitingOrders={waiting_orders}
          activeOrders={active_orders}
          pickupOrders={pickup_orders}
          feedback={feedback}
          timeScale={simulator.time_scale}
        />
      }
      inventoryPanel={
        <InventoryPanel
          inventory={inventory}
          refillCount={refillCount}
          onChangeRefillCount={setRefillCount}
          onRefill={handleRefill}
        />
      }
      waitingQueue={<OrderQueuePanel title="대기 큐" orders={waiting_orders} />}
      activeQueue={<OrderQueuePanel title="작업중" orders={active_orders} showStatus />}
      pickupQueue={<OrderQueuePanel title="수령 대기" orders={pickup_orders} />}
      orderForm={<OrderForm onOrder={handleOrder} error={orderError} />}
      debugPanel={<DebugPanel onFault={(kind) => api.setDebugFault(kind)} />}
      eventLogPanel={<EventLogPanel log={log} />}
      modal={
        <RefillModal
          alert={alert}
          refillCount={refillCount}
          onChangeRefillCount={setRefillCount}
          onConfirm={handleRefill}
        />
      }
    />
  );
}
