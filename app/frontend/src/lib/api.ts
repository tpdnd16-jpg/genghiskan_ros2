import type { BoardStockSlot, Order, Shape, SimulatorSettings, StateSnapshot } from "../types";

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

/** 작업요청(SQS) 경로 전용: 서버가 {"detail": {error_code, message, order_id}} 형태로
 * 돌려주는 에러(409 베드 없음, 502 SQS 전송 실패 등)를 그대로 담아 던진다
 * (PRD: assets/docs/prd-work-request-sqs.md 6장). */
export class WorkRequestError extends Error {
  errorCode?: string;
  orderId?: number;

  constructor(message: string, errorCode?: string, orderId?: number) {
    super(message);
    this.errorCode = errorCode;
    this.orderId = orderId;
  }
}

async function createWorkRequest(customerName: string, shape: Shape): Promise<Order> {
  const res = await fetch("/api/work-requests", {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({ shape, customer_name: customerName || null }),
  });
  const body = await res.json().catch(() => null);
  if (!res.ok) {
    const detail = body?.detail as { error_code?: string; message?: string; order_id?: number } | undefined;
    throw new WorkRequestError(
      detail?.message ?? `작업요청 실패: ${res.status}`,
      detail?.error_code,
      detail?.order_id
    );
  }
  return body as Order;
}

export const api = {
  getState: () => request<StateSnapshot>("/api/state"),

  createOrder: (customerName: string, shape: Shape) =>
    request<Order>("/api/orders", {
      method: "POST",
      body: JSON.stringify({ shape, customer_name: customerName || null }),
    }),

  // 작업요청(SQS) 경로 전용 (PRD: assets/docs/prd-work-request-sqs.md).
  createWorkRequest,

  getBoardStock: () => request<BoardStockSlot[]>("/api/board-stock"),

  refillBoardStockComplete: () =>
    request<BoardStockSlot[]>("/api/board-stock/refill-complete", { method: "POST" }),

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
