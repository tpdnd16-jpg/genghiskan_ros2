import { SHAPE_LABEL } from "../../constants";
import type { Order } from "../../types";

interface OrderListItemProps {
  order: Order;
  showStatus?: boolean;
}

export function OrderListItem({ order, showStatus = false }: OrderListItemProps) {
  return (
    <li>
      #{order.id} {SHAPE_LABEL[order.shape]}
      {showStatus ? ` · ${order.status}` : ""}
    </li>
  );
}
