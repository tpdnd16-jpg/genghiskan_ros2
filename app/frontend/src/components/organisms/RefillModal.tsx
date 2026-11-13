import { RefillControl } from "../molecules/RefillControl";
import type { RefillAlert } from "../../hooks/useLiveState";

interface RefillModalProps {
  alert: RefillAlert | null;
  refillCount: number;
  onChangeRefillCount: (value: number) => void;
  onConfirm: () => void;
}

export function RefillModal({ alert, refillCount, onChangeRefillCount, onConfirm }: RefillModalProps) {
  if (!alert) return null;

  return (
    <div className="modal-backdrop">
      <div className="modal">
        <h3>보드를 채워주세요</h3>
        <p>
          {alert.reason === "ROBOT_NO_BOARD"
            ? "로봇이 보드를 찾지 못했습니다. 적재대를 확인하고 채워주세요."
            : "보드 재고가 없습니다."}
        </p>
        <RefillControl value={refillCount} onChange={onChangeRefillCount} onSubmit={onConfirm} submitLabel="확인" />
      </div>
    </div>
  );
}
