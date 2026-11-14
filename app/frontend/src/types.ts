export type Shape = "TRIANGLE" | "SQUARE" | "STAR" | "CIRCLE";

export type OrderStatus =
  | "WAITING"
  // 작업요청(SQS) 경로 전용: LOAD 발행 성공 ~ pick_complete 수신 전까지 ("투입중").
  | "DISPATCHING"
  | "LOADING"
  | "PRINTING"
  | "PRINT_DONE"
  | "UNLOADING"
  | "READY_FOR_PICKUP"
  | "PICKED_UP";

export type PrinterStatus = "EMPTY" | "RESERVED" | "PRINTING" | "DONE" | "UNLOADING";
export type RobotState = "IDLE" | "BUSY" | "ERROR" | "DISCONNECTED";

// 작업요청(SQS) 경로 전용: 적재대 층(1~3)별 상태.
export type BoardStockSlotStatus = "EMPTY" | "RESERVED" | "OCCUPIED";

export interface BoardStockSlot {
  slot: number;
  status: BoardStockSlotStatus;
  updated_at: string;
}

export interface Order {
  id: number;
  user_id: number;
  shape: Shape;
  print_duration_sec: number;
  status: OrderStatus;
  source: "AUTO" | "MANUAL";
  printer_slot: number | null;
  created_at: string;
  started_at: string | null;
  print_completed_at: string | null;
  ready_at: string | null;
  pickup_delay_sec: number | null;
  picked_up_at: string | null;
  updated_at: string;
}

export interface Printer {
  slot: number;
  status: PrinterStatus;
  current_order_id: number | null;
  timer_ends_at: string | null;
  updated_at: string;
}

export interface RobotStatus {
  state: RobotState;
  current_task_id: number | null;
  bridge_connected: boolean;
}

export interface SimulatorSettings {
  running: boolean;
  interval_sec: number;
  time_scale: number;
}

export interface StateSnapshot {
  printers: Printer[];
  robot: RobotStatus;
  waiting_orders: Order[];
  active_orders: Order[];
  pickup_orders: Order[];
  simulator: SimulatorSettings;
}

export interface Envelope<T = unknown> {
  type: string;
  event_id: string;
  ts: string;
  data: T;
}
