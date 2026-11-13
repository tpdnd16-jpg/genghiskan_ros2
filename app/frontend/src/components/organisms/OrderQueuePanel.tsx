import { OrderListItem } from "../molecules/OrderListItem";
import type { Order } from "../../types";

interface OrderQueuePanelProps {
  title: string;
  orders: Order[];
  showStatus?: boolean;
}

export function OrderQueuePanel({ title, orders, showStatus }: OrderQueuePanelProps) {
  return (
    <section className="panel queue">
      <h2>
        {title} ({orders.length})
      </h2>
      <ul>
        {orders.map((order) => (
          <OrderListItem key={order.id} order={order} showStatus={showStatus} />
        ))}
      </ul>
    </section>
  );
}
