import {
  STOCK_BOARD_HEIGHT as BOARD_HEIGHT,
  STOCK_BOARD_STEP as BOARD_STEP,
  STOCK_BOARD_WIDTH as BOARD_WIDTH,
  STOCK_MAX_VISIBLE,
  STOCK_TOP_INDEX,
} from "../../lib/stock";

interface BoardStockProps {
  x: number;
  y: number;
  /** 로봇팔이 적재대에서 보드를 집는 단계(MOVE_TO_STOCK/PICK_BOARD/CHECK_GRIP)인 동안 true. */
  picking?: boolean;
}

export function BoardStock({ x, y, picking = false }: BoardStockProps) {
  return (
    <g transform={`translate(${x}, ${y})`} className="wp-stock">
      <rect x={-42} y={-30} width={84} height={54} rx={8} className="wp-stock-frame" />
      {Array.from({ length: STOCK_MAX_VISIBLE }).map((_, i) => {
        const isTop = i === STOCK_TOP_INDEX;
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
        보드 적재대
      </text>
    </g>
  );
}
