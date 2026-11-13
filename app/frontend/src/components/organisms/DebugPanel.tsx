import { Button } from "../atoms/Button";

interface DebugPanelProps {
  onFault: (kind: "NO_BOARD" | "GRIP_FAIL") => void;
}

export function DebugPanel({ onFault }: DebugPanelProps) {
  return (
    <section className="panel debug">
      <h2>장애 주입</h2>
      <div className="button-row">
        <Button onClick={() => onFault("NO_BOARD")}>NO_BOARD 1회</Button>
        <Button onClick={() => onFault("GRIP_FAIL")}>GRIP_FAIL 1회</Button>
      </div>
    </section>
  );
}
