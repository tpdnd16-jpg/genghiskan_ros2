interface CustomerRowProps {
  x: number;
  y: number;
  count: number;
}

const MAX_SHOWN = 6;

export function CustomerRow({ x, y, count }: CustomerRowProps) {
  const shown = Math.min(MAX_SHOWN, count);
  const extra = count - shown;

  return (
    <g transform={`translate(${x}, ${y})`} className="wp-customers">
      {Array.from({ length: shown }).map((_, i) => (
        <g key={i} transform={`translate(${i * 20}, 0)`} className="wp-customer">
          <circle cx={0} cy={0} r={5} />
          <path d="M -7 17 Q 0 5 7 17 Z" />
        </g>
      ))}
      {extra > 0 && (
        <text x={shown * 20 + 2} y={14} className="wp-customer-extra">
          +{extra}
        </text>
      )}
    </g>
  );
}
