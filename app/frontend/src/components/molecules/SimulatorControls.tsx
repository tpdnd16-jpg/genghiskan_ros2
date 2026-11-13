import { Checkbox } from "../atoms/Checkbox";
import { NumberField } from "../atoms/NumberField";
import type { SimulatorSettings } from "../../types";

interface SimulatorControlsProps {
  settings: SimulatorSettings;
  onPatch: (patch: Partial<SimulatorSettings>) => void;
}

export function SimulatorControls({ settings, onPatch }: SimulatorControlsProps) {
  return (
    <div className="simulator-controls">
      <Checkbox label="자동 주문" checked={settings.running} onChange={(running) => onPatch({ running })} />
      <NumberField
        label="배율"
        min={0.1}
        step={0.1}
        value={settings.time_scale}
        onChange={(time_scale) => onPatch({ time_scale })}
      />
    </div>
  );
}
