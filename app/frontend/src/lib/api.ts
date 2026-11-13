import type { Order, Shape, SimulatorSettings, StateSnapshot } from "../types";

async function request<T>(path: string, init?: RequestInit): Promise<T> {
  const res = await fetch(path, {
    headers: { "Content-Type": "application/json" },
    ...init,
  });
  if (!res.ok) {
    throw new Error(`${init?.method ?? "GET"} ${path} failed: ${res.status}`);
  }
  return res.json() as Promise<T>;
}

export const api = {
  getState: () => request<StateSnapshot>("/api/state"),

  createOrder: (customerName: string, shape: Shape) =>
    request<Order>("/api/orders", {
      method: "POST",
      body: JSON.stringify({ shape, customer_name: customerName || null }),
    }),

  refillInventory: (count: number) =>
    request("/api/inventory/refill", {
      method: "POST",
      body: JSON.stringify({ count }),
    }),

  getSimulator: () => request<SimulatorSettings>("/api/simulator"),

  patchSimulator: (patch: Partial<SimulatorSettings>) =>
    request<SimulatorSettings>("/api/simulator", {
      method: "PATCH",
      body: JSON.stringify(patch),
    }),

  setDebugFault: (kind: "NO_BOARD" | "GRIP_FAIL") =>
    request("/api/debug/faults", {
      method: "PATCH",
      body: JSON.stringify({ kind, once: true }),
    }),
};
