import {
  STOCK_BOARD_HEIGHT as BOARD_HEIGHT,
  STOCK_BOARD_STEP as BOARD_STEP,
  STOCK_BOARD_WIDTH as BOARD_WIDTH,
  stockTopIndex,
  stockVisibleCount,
} from "../../lib/stock";

interface BoardStockProps {
  x: number;
  y: number;
  remaining: number;
  capacity: number;
  /** 로봇팔이 적재대에서 보드를 집는 단계(MOVE_TO_STOCK/PICK_BOARD/CHECK_GRIP)인 동안 true. */
  picking?: boolean;
}

export function BoardStock({ x, y, remaining, capacity, picking = false }: BoardStockProps) {
  const stackCount = stockVisibleCount(remaining);
  // index 0 = 더미 맨 아래(가장 먼저 쌓인 보드), index가 클수록 위로 쌓인다.
  // 로봇은 항상 맨 위(가장 큰 index)부터 꺼내가므로, remaining이 줄면 이 배열은
  // 끝쪽(맨 위) index부터 사라진다 — 즉 "위에 있는 보드 먼저" 가 자연스럽게 지켜진다.
  // 이 index와 로봇팔이 실제로 짚는 좌표(lib/stock.ts stockPickPoint)는 같은 기준을 쓴다.
  const topIndex = stockTopIndex(remaining);

  return (
    <g transform={`translate(${x}, ${y})`} className={remaining === 0 ? "wp-stock wp-stock-empty" : "wp-stock"}>
      <rect x={-42} y={-30} width={84} height={54} rx={8} className="wp-stock-frame" />
      {Array.from({ length: stackCount }).map((_, i) => {
        const isTop = i === topIndex;
        const className = ["wp-board"];
        if (isTop) {
          className.push("wp-board-top");
          if (picking) className.push("wp-board-picking");
        }
        return (
          <rect
            key={i}
            x={-BOARD_WIDTH / 2}
            y={14 - i * BOARD_STEP}
            width={BOARD_WIDTH}
            height={BOARD_HEIGHT}
            rx={2}
            className={className.join(" ")}
          />
        );
      })}
      <text x={0} y={42} textAnchor="middle" className="wp-stock-label">
        보드 적재대 {remaining}/{capacity}
      </text>
    </g>
  );
}
