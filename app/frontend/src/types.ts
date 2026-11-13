export type Shape = "TRIANGLE" | "SQUARE" | "STAR" | "CIRCLE";

export type OrderStatus =
  | "WAITING"
  | "LOADING"
  | "PRINTING"
  | "PRINT_DONE"
  | "UNLOADING"
  | "READY_FOR_PICKUP"
  | "PICKED_UP";

export type PrinterStatus = "EMPTY" | "RESERVED" | "PRINTING" | "DONE" | "UNLOADING";
export type RobotState = "IDLE" | "BUSY" | "ERROR" | "DISCONNECTED";

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

export interface BoardInventory {
  remaining_count: number;
  capacity: number;
  refill_required: boolean;
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
  inventory: BoardInventory;
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
