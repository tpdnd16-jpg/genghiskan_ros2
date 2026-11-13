import { RefillControl } from "../molecules/RefillControl";
import type { BoardInventory } from "../../types";

interface InventoryPanelProps {
  inventory: BoardInventory;
  refillCount: number;
  onChangeRefillCount: (value: number) => void;
  onRefill: () => void;
}

export function InventoryPanel({ inventory, refillCount, onChangeRefillCount, onRefill }: InventoryPanelProps) {
  return (
    <section className="panel inventory">
      <h2>보드 적재대</h2>
      <div className={inventory.remaining_count === 0 ? "inventory-empty" : ""}>
        남은 보드: {inventory.remaining_count} / {inventory.capacity}
      </div>
      <RefillControl value={refillCount} onChange={onChangeRefillCount} onSubmit={onRefill} submitLabel="보충" />
    </section>
  );
}
