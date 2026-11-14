import { Button } from "../atoms/Button";
import type { RefillAlert } from "../../hooks/useLiveState";

interface BoardStockRefillModalProps {
  alert: RefillAlert | null;
  onConfirm: () => void;
}

/** 작업요청(SQS) 경로 전용: 적재대(board_stock)가 비었을 때 뜨는 모달. 수량 입력
 * 없이, 사람이 직접 채운 뒤 "채우기 완료"만 누른다 (PRD: assets/docs/prd-work-request-sqs.md 5장). */
export function BoardStockRefillModal({ alert, onConfirm }: BoardStockRefillModalProps) {
  if (!alert || alert.reason !== "BOARD_STOCK_EMPTY") return null;

  return (
    <div className="modal-backdrop">
      <div className="modal">
        <h3>적재대에 베드가 비어있습니다</h3>
        <p>적재대에 베드를 직접 채운 뒤 아래 버튼을 눌러주세요.</p>
        <Button className="btn-primary" onClick={onConfirm}>
          채우기 완료
        </Button>
      </div>
    </div>
  );
}
