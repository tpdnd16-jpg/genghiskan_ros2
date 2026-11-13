import { LogEntryItem } from "../molecules/LogEntryItem";
import type { LogEntry } from "../../hooks/useLiveState";

interface EventLogPanelProps {
  log: LogEntry[];
}

export function EventLogPanel({ log }: EventLogPanelProps) {
  return (
    <section className="panel log">
      <h2>이벤트 로그</h2>
      <ul>
        {log.map((entry) => (
          <LogEntryItem key={entry.id} entry={entry} />
        ))}
      </ul>
    </section>
  );
}
