interface TextFieldProps {
  label?: string;
  value: string;
  placeholder?: string;
  onChange: (value: string) => void;
}

export function TextField({ label, value, placeholder, onChange }: TextFieldProps) {
  const input = (
    <input type="text" value={value} placeholder={placeholder} onChange={(e) => onChange(e.target.value)} />
  );

  if (!label) return input;

  return (
    <label>
      {label}
      {input}
    </label>
  );
}
