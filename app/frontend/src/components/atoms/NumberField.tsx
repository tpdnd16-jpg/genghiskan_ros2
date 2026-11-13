interface NumberFieldProps {
  label?: string;
  value: number;
  min?: number;
  step?: number;
  onChange: (value: number) => void;
}

export function NumberField({ label, value, min, step, onChange }: NumberFieldProps) {
  const input = (
    <input
      type="number"
      min={min}
      step={step}
      value={value}
      onChange={(e) => onChange(Number(e.target.value))}
    />
  );

  if (!label) return input;

  return (
    <label>
      {label}
      {input}
    </label>
  );
}
