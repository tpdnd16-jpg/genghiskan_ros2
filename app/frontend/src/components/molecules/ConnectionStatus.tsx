import { Pill } from "../atoms/Pill";
import type { RobotState } from "../../types";

interface ConnectionStatusProps {
  wsConnected: boolean;
  bridgeConnected: boolean;
  robotState: RobotState;
}

export function ConnectionStatus({ wsConnected, bridgeConnected, robotState }: ConnectionStatusProps) {
  return (
    <div className="status-group">
      <Pill variant={wsConnected ? "ok" : "bad"}>WS {wsConnected ? "연결됨" : "끊김"}</Pill>
      <Pill variant={bridgeConnected ? "ok" : "bad"}>로봇 {bridgeConnected ? "연결됨" : "끊김"}</Pill>
      <Pill>로봇 상태: {robotState}</Pill>
    </div>
  );
}
