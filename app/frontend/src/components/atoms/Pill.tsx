import type { ReactNode } from "react";

export type PillVariant = "ok" | "bad" | "neutral";

interface PillProps {
  variant?: PillVariant;
  children: ReactNode;
}

export function Pill({ variant = "neutral", children }: PillProps) {
  const variantClass = variant === "neutral" ? "" : ` ${variant}`;
  return <span className={`pill${variantClass}`}>{children}</span>;
}
