import { Button } from "../atoms/Button";
import { NumberField } from "../atoms/NumberField";

interface RefillControlProps {
  value: number;
  onChange: (value: number) => void;
  onSubmit: () => void;
  submitLabel: string;
}

export function RefillControl({ value, onChange, onSubmit, submitLabel }: RefillControlProps) {
  return (
    <div className="refill-row">
      <NumberField value={value} min={0} onChange={onChange} />
      <Button onClick={onSubmit}>{submitLabel}</Button>
    </div>
  );
}
