import { parseServerTime } from "../../lib/time";
import type { Order, Printer } from "../../types";

interface PrinterUnitProps {
  slot: number;
  x: number;
  y: number;
  printer?: Printer;
  order?: Order;
  /** 로봇이 막 이 슬롯에 보드를 놓고 복귀 중 — 서버가 PRINTING으로 반영하기 전 틈을 메운다. */
  justLoaded?: boolean;
  now: number;
}

const WIDTH = 72;
const HEIGHT = 48;

export function PrinterUnit({ slot, x, y, printer, order, justLoaded, now }: PrinterUnitProps) {
  const status = printer?.status ?? "EMPTY";

  let fraction = 0;
  let remainingSec: number | null = null;
  if (status === "PRINTING" && printer?.timer_ends_at && order?.started_at) {
    const start = parseServerTime(order.started_at);
    const end = parseServerTime(printer.timer_ends_at);
    const total = Math.max(1, end - start);
    fraction = Math.min(1, Math.max(0, (now - start) / total));
    remainingSec = Math.max(0, Math.round((end - now) / 1000));
  }

  return (
    <g transform={`translate(${x - WIDTH / 2}, ${y - HEIGHT / 2})`} className={`wp-printer wp-printer-${status.toLowerCase()}`}>
      <rect width={WIDTH} height={HEIGHT} rx={6} className="wp-printer-body" />
      <text x={8} y={16} className="wp-printer-label">
        {slot}층
      </text>
      {order && (
        <text x={WIDTH - 8} y={16} textAnchor="end" className="wp-printer-order">
          #{order.id}
        </text>
      )}
      {status === "PRINTING" && (
        <>
          <text x={8} y={HEIGHT - 20} className="wp-printer-sub">
            {remainingSec}s
          </text>
          <rect x={8} y={HEIGHT - 14} width={WIDTH - 16} height={8} rx={2} className="wp-progress-track" />
          <rect x={8} y={HEIGHT - 14} width={(WIDTH - 16) * fraction} height={8} rx={2} className="wp-progress-fill" />
        </>
      )}
      {status === "DONE" && (
        <text x={8} y={HEIGHT - 18} className="wp-printer-sub wp-blink">
          출력 완료
        </text>
      )}
      {status === "UNLOADING" && (
        <text x={8} y={HEIGHT - 18} className="wp-printer-sub">
          꺼내는 중
        </text>
      )}
      {justLoaded && status !== "PRINTING" && (
        <rect x={WIDTH / 2 - 14} y={HEIGHT / 2 - 3} width={28} height={10} rx={2} className="wp-board" />
      )}
    </g>
  );
}
