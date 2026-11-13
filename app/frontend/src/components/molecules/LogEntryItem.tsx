import type { LogEntry } from "../../hooks/useLiveState";

interface LogEntryItemProps {
  entry: LogEntry;
}

export function LogEntryItem({ entry }: LogEntryItemProps) {
  return (
    <li>
      <span className="log-ts">{entry.ts.slice(11, 19)}</span> {entry.summary}
    </li>
  );
}
