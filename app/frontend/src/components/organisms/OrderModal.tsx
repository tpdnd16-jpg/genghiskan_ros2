import { useEffect, useState } from "react";
import { Button } from "../atoms/Button";
import { TextField } from "../atoms/TextField";
import { SHAPE_LABEL } from "../../constants";
import type { Shape } from "../../types";

const SHAPES = Object.keys(SHAPE_LABEL) as Shape[];

interface OrderModalProps {
  open: boolean;
  error: string | null;
  onClose: () => void;
  onSubmit: (customerName: string, shape: Shape) => void;
}

export function OrderModal({ open, error, onClose, onSubmit }: OrderModalProps) {
  const [customerName, setCustomerName] = useState("");
  const [shape, setShape] = useState<Shape>(SHAPES[0]);

  useEffect(() => {
    if (open) {
      setCustomerName("");
      setShape(SHAPES[0]);
    }
  }, [open]);

  if (!open) return null;

  const handleSubmit = () => {
    onSubmit(customerName.trim(), shape);
  };

  return (
    <div className="modal-backdrop">
      <div className="modal order-modal">
        <button type="button" className="modal-close" onClick={onClose} aria-label="닫기">
          ×
        </button>
        <h3>주문하기</h3>
        <p className="modal-subtitle">고객명과 요청사항을 입력하고 작업을 등록하세요.</p>

        <TextField label="고객명" value={customerName} placeholder="고객명을 입력하세요" onChange={setCustomerName} />

        <div className="order-modal-field">
          <span className="field-label">요청사항</span>
          <div className="chip-row">
            {SHAPES.map((s) => (
              <button
                key={s}
                type="button"
                className={`chip${s === shape ? " selected" : ""}`}
                onClick={() => setShape(s)}
              >
                {SHAPE_LABEL[s]}
              </button>
            ))}
          </div>
        </div>

        {error && <p className="error">{error}</p>}

        <div className="modal-footer">
          <Button className="btn-outline" onClick={onClose}>
            취소
          </Button>
          <Button className="btn-primary" onClick={handleSubmit}>
            작업 넣기
          </Button>
        </div>
      </div>
    </div>
  );
}
