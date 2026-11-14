import { useState } from "react";
import { Button } from "../atoms/Button";
import { OrderModal } from "./OrderModal";
import type { Shape } from "../../types";

interface OrderFormProps {
  onOrder: (customerName: string, shape: Shape) => Promise<boolean>;
  error: string | null;
}

export function OrderForm({ onOrder, error }: OrderFormProps) {
  const [open, setOpen] = useState(false);

  const handleSubmit = async (customerName: string, shape: Shape) => {
    const success = await onOrder(customerName, shape);
    if (success) setOpen(false);
  };

  return (
    <section className="panel order-form">
      <h2>작업요청</h2>
      <Button onClick={() => setOpen(true)}>작업요청</Button>
      <OrderModal open={open} error={error} onClose={() => setOpen(false)} onSubmit={handleSubmit} />
    </section>
  );
}
