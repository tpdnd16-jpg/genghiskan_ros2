import type { Order } from "../../types";

interface PickupCounterProps {
  x: number;
  y: number;
  orders: Order[];
}

export function PickupCounter({ x, y, orders }: PickupCounterProps) {
  const shown = orders.slice(0, 4);
  const extra = orders.length - shown.length;

  return (
    <g transform={`translate(${x}, ${y})`} className="wp-pickup">
      <rect x={-52} y={-30} width={104} height={54} rx={8} className="wp-pickup-frame" />
      {shown.map((order, i) => (
        <g key={order.id} transform={`translate(${-38 + i * 24}, -8)`}>
          <rect width={20} height={10} rx={2} className="wp-board wp-board-ready" />
          <text x={10} y={24} textAnchor="middle" className="wp-pickup-order">
            #{order.id}
          </text>
        </g>
      ))}
      {extra > 0 && (
        <text x={46} y={-16} textAnchor="end" className="wp-pickup-extra">
          +{extra}
        </text>
      )}
      <text x={0} y={42} textAnchor="middle" className="wp-pickup-label">
        수령대
      </text>
    </g>
  );
}
