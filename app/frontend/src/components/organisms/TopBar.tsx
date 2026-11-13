import { ConnectionStatus } from "../molecules/ConnectionStatus";
import { SimulatorControls } from "../molecules/SimulatorControls";
import type { RobotStatus, SimulatorSettings } from "../../types";

interface TopBarProps {
  wsConnected: boolean;
  robot: RobotStatus;
  simulator: SimulatorSettings;
  onPatchSimulator: (patch: Partial<SimulatorSettings>) => void;
}

export function TopBar({ wsConnected, robot, simulator, onPatchSimulator }: TopBarProps) {
  return (
    <header className="topbar">
      <h1>3D 프린트 업장 관리</h1>
      <ConnectionStatus
        wsConnected={wsConnected}
        bridgeConnected={robot.bridge_connected}
        robotState={robot.state}
      />
      <SimulatorControls settings={simulator} onPatch={onPatchSimulator} />
    </header>
  );
}
