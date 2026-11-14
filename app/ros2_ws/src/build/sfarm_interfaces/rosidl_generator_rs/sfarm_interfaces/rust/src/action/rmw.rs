
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_Goal() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Insert_Goal__init(msg: *mut Insert_Goal) -> bool;
    fn sfarm_interfaces__action__Insert_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Insert_Goal>, size: usize) -> bool;
    fn sfarm_interfaces__action__Insert_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Insert_Goal>);
    fn sfarm_interfaces__action__Insert_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Insert_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Insert_Goal>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Insert_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub work_id: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub start_pos_id: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pos_3d_id: i8,

}



impl Default for Insert_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Insert_Goal__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Insert_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Insert_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Insert_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Insert_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Insert_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_Goal() }
  }
}


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_Result() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Insert_Result__init(msg: *mut Insert_Result) -> bool;
    fn sfarm_interfaces__action__Insert_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Insert_Result>, size: usize) -> bool;
    fn sfarm_interfaces__action__Insert_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Insert_Result>);
    fn sfarm_interfaces__action__Insert_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Insert_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Insert_Result>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Insert_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub work_id: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub work_type: u8,

}

impl Insert_Result {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const WORK_TYPE_INSERT: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const WORK_TYPE_EJECT: u8 = 1;

}


impl Default for Insert_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Insert_Result__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Insert_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Insert_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Insert_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Insert_Result where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Insert_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_Result() }
  }
}


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Insert_Feedback__init(msg: *mut Insert_Feedback) -> bool;
    fn sfarm_interfaces__action__Insert_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Insert_Feedback>, size: usize) -> bool;
    fn sfarm_interfaces__action__Insert_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Insert_Feedback>);
    fn sfarm_interfaces__action__Insert_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Insert_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Insert_Feedback>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Insert_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub start_at: builtin_interfaces::msg::rmw::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub end_at: builtin_interfaces::msg::rmw::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub work_id: i8,

}



impl Default for Insert_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Insert_Feedback__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Insert_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Insert_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Insert_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Insert_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Insert_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_Feedback() }
  }
}


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Insert_FeedbackMessage__init(msg: *mut Insert_FeedbackMessage) -> bool;
    fn sfarm_interfaces__action__Insert_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Insert_FeedbackMessage>, size: usize) -> bool;
    fn sfarm_interfaces__action__Insert_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Insert_FeedbackMessage>);
    fn sfarm_interfaces__action__Insert_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Insert_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Insert_FeedbackMessage>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Insert_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Insert_Feedback,

}



impl Default for Insert_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Insert_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Insert_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Insert_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Insert_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Insert_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Insert_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_FeedbackMessage() }
  }
}


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_Goal() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Eject_Goal__init(msg: *mut Eject_Goal) -> bool;
    fn sfarm_interfaces__action__Eject_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Eject_Goal>, size: usize) -> bool;
    fn sfarm_interfaces__action__Eject_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Eject_Goal>);
    fn sfarm_interfaces__action__Eject_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Eject_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Eject_Goal>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Eject_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub work_id: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pos_3d_id: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub receive_pos_id: i8,

}



impl Default for Eject_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Eject_Goal__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Eject_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Eject_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Eject_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Eject_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Eject_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_Goal() }
  }
}


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_Result() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Eject_Result__init(msg: *mut Eject_Result) -> bool;
    fn sfarm_interfaces__action__Eject_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Eject_Result>, size: usize) -> bool;
    fn sfarm_interfaces__action__Eject_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Eject_Result>);
    fn sfarm_interfaces__action__Eject_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Eject_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Eject_Result>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Eject_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub work_id: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub work_type: u8,

}

impl Eject_Result {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const WORK_TYPE_INSERT: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const WORK_TYPE_EJECT: u8 = 1;

}


impl Default for Eject_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Eject_Result__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Eject_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Eject_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Eject_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Eject_Result where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Eject_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_Result() }
  }
}


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Eject_Feedback__init(msg: *mut Eject_Feedback) -> bool;
    fn sfarm_interfaces__action__Eject_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Eject_Feedback>, size: usize) -> bool;
    fn sfarm_interfaces__action__Eject_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Eject_Feedback>);
    fn sfarm_interfaces__action__Eject_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Eject_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Eject_Feedback>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Eject_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub start_at: builtin_interfaces::msg::rmw::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub end_at: builtin_interfaces::msg::rmw::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub work_id: i8,

}



impl Default for Eject_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Eject_Feedback__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Eject_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Eject_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Eject_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Eject_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Eject_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_Feedback() }
  }
}


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Eject_FeedbackMessage__init(msg: *mut Eject_FeedbackMessage) -> bool;
    fn sfarm_interfaces__action__Eject_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Eject_FeedbackMessage>, size: usize) -> bool;
    fn sfarm_interfaces__action__Eject_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Eject_FeedbackMessage>);
    fn sfarm_interfaces__action__Eject_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Eject_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Eject_FeedbackMessage>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Eject_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Eject_Feedback,

}



impl Default for Eject_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Eject_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Eject_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Eject_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Eject_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Eject_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Eject_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_FeedbackMessage() }
  }
}




#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Insert_SendGoal_Request__init(msg: *mut Insert_SendGoal_Request) -> bool;
    fn sfarm_interfaces__action__Insert_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Insert_SendGoal_Request>, size: usize) -> bool;
    fn sfarm_interfaces__action__Insert_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Insert_SendGoal_Request>);
    fn sfarm_interfaces__action__Insert_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Insert_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Insert_SendGoal_Request>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Insert_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Insert_Goal,

}



impl Default for Insert_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Insert_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Insert_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Insert_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Insert_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Insert_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Insert_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_SendGoal_Request() }
  }
}


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Insert_SendGoal_Response__init(msg: *mut Insert_SendGoal_Response) -> bool;
    fn sfarm_interfaces__action__Insert_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Insert_SendGoal_Response>, size: usize) -> bool;
    fn sfarm_interfaces__action__Insert_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Insert_SendGoal_Response>);
    fn sfarm_interfaces__action__Insert_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Insert_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Insert_SendGoal_Response>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Insert_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Insert_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Insert_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Insert_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Insert_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Insert_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Insert_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Insert_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_SendGoal_Response() }
  }
}


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Insert_GetResult_Request__init(msg: *mut Insert_GetResult_Request) -> bool;
    fn sfarm_interfaces__action__Insert_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Insert_GetResult_Request>, size: usize) -> bool;
    fn sfarm_interfaces__action__Insert_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Insert_GetResult_Request>);
    fn sfarm_interfaces__action__Insert_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Insert_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Insert_GetResult_Request>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Insert_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Insert_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Insert_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Insert_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Insert_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Insert_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Insert_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Insert_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_GetResult_Request() }
  }
}


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Insert_GetResult_Response__init(msg: *mut Insert_GetResult_Response) -> bool;
    fn sfarm_interfaces__action__Insert_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Insert_GetResult_Response>, size: usize) -> bool;
    fn sfarm_interfaces__action__Insert_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Insert_GetResult_Response>);
    fn sfarm_interfaces__action__Insert_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Insert_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Insert_GetResult_Response>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Insert_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Insert_Result,

}



impl Default for Insert_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Insert_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Insert_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Insert_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Insert_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Insert_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Insert_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Insert_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Insert_GetResult_Response() }
  }
}


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Eject_SendGoal_Request__init(msg: *mut Eject_SendGoal_Request) -> bool;
    fn sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Eject_SendGoal_Request>, size: usize) -> bool;
    fn sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Eject_SendGoal_Request>);
    fn sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Eject_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Eject_SendGoal_Request>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Eject_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Eject_Goal,

}



impl Default for Eject_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Eject_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Eject_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Eject_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Eject_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Eject_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Eject_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_SendGoal_Request() }
  }
}


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Eject_SendGoal_Response__init(msg: *mut Eject_SendGoal_Response) -> bool;
    fn sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Eject_SendGoal_Response>, size: usize) -> bool;
    fn sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Eject_SendGoal_Response>);
    fn sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Eject_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Eject_SendGoal_Response>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Eject_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Eject_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Eject_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Eject_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Eject_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Eject_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Eject_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Eject_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_SendGoal_Response() }
  }
}


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Eject_GetResult_Request__init(msg: *mut Eject_GetResult_Request) -> bool;
    fn sfarm_interfaces__action__Eject_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Eject_GetResult_Request>, size: usize) -> bool;
    fn sfarm_interfaces__action__Eject_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Eject_GetResult_Request>);
    fn sfarm_interfaces__action__Eject_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Eject_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Eject_GetResult_Request>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Eject_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Eject_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Eject_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Eject_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Eject_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Eject_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Eject_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Eject_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_GetResult_Request() }
  }
}


#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "sfarm_interfaces__rosidl_generator_c")]
extern "C" {
    fn sfarm_interfaces__action__Eject_GetResult_Response__init(msg: *mut Eject_GetResult_Response) -> bool;
    fn sfarm_interfaces__action__Eject_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Eject_GetResult_Response>, size: usize) -> bool;
    fn sfarm_interfaces__action__Eject_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Eject_GetResult_Response>);
    fn sfarm_interfaces__action__Eject_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Eject_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Eject_GetResult_Response>) -> bool;
}

// Corresponds to sfarm_interfaces__action__Eject_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Eject_Result,

}



impl Default for Eject_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !sfarm_interfaces__action__Eject_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to sfarm_interfaces__action__Eject_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Eject_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { sfarm_interfaces__action__Eject_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Eject_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Eject_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "sfarm_interfaces/action/Eject_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__sfarm_interfaces__action__Eject_GetResult_Response() }
  }
}






#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__sfarm_interfaces__action__Insert_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to sfarm_interfaces__action__Insert_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Insert_SendGoal;

impl rosidl_runtime_rs::Service for Insert_SendGoal {
    type Request = Insert_SendGoal_Request;
    type Response = Insert_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__sfarm_interfaces__action__Insert_SendGoal() }
    }
}




#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__sfarm_interfaces__action__Insert_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to sfarm_interfaces__action__Insert_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Insert_GetResult;

impl rosidl_runtime_rs::Service for Insert_GetResult {
    type Request = Insert_GetResult_Request;
    type Response = Insert_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__sfarm_interfaces__action__Insert_GetResult() }
    }
}




#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__sfarm_interfaces__action__Eject_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to sfarm_interfaces__action__Eject_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Eject_SendGoal;

impl rosidl_runtime_rs::Service for Eject_SendGoal {
    type Request = Eject_SendGoal_Request;
    type Response = Eject_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__sfarm_interfaces__action__Eject_SendGoal() }
    }
}




#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__sfarm_interfaces__action__Eject_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to sfarm_interfaces__action__Eject_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Eject_GetResult;

impl rosidl_runtime_rs::Service for Eject_GetResult {
    type Request = Eject_GetResult_Request;
    type Response = Eject_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__sfarm_interfaces__action__Eject_GetResult() }
    }
}


