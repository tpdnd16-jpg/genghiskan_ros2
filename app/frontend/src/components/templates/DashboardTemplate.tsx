import type { ReactNode } from "react";

interface DashboardTemplateProps {
  topBar: ReactNode;
  workshopStage: ReactNode;
  waitingQueue: ReactNode;
  activeQueue: ReactNode;
  pickupQueue: ReactNode;
  orderForm: ReactNode;
  debugPanel: ReactNode;
  eventLogPanel: ReactNode;
  modal?: ReactNode;
}

export function DashboardTemplate({
  topBar,
  workshopStage,
  waitingQueue,
  activeQueue,
  pickupQueue,
  orderForm,
  debugPanel,
  eventLogPanel,
  modal,
}: DashboardTemplateProps) {
  return (
    <div className="app">
      {topBar}
      {workshopStage}
      <main className="layout">
        {waitingQueue}
        {activeQueue}
        {pickupQueue}
        {orderForm}
        {debugPanel}
        {eventLogPanel}
      </main>
      {modal}
    </div>
  );
}
