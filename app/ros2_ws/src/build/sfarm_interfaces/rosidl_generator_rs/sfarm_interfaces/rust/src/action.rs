
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to sfarm_interfaces__action__Insert_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Insert_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for Insert_Goal {
  type RmwMsg = super::action::rmw::Insert_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        work_id: msg.work_id,
        start_pos_id: msg.start_pos_id,
        pos_3d_id: msg.pos_3d_id,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      work_id: msg.work_id,
      start_pos_id: msg.start_pos_id,
      pos_3d_id: msg.pos_3d_id,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      work_id: msg.work_id,
      start_pos_id: msg.start_pos_id,
      pos_3d_id: msg.pos_3d_id,
    }
  }
}


// Corresponds to sfarm_interfaces__action__Insert_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Insert_Result::default())
  }
}

impl rosidl_runtime_rs::Message for Insert_Result {
  type RmwMsg = super::action::rmw::Insert_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
        work_id: msg.work_id,
        work_type: msg.work_type,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      work_id: msg.work_id,
      work_type: msg.work_type,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
      work_id: msg.work_id,
      work_type: msg.work_type,
    }
  }
}


// Corresponds to sfarm_interfaces__action__Insert_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub start_at: builtin_interfaces::msg::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub end_at: builtin_interfaces::msg::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub work_id: i8,

}



impl Default for Insert_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Insert_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for Insert_Feedback {
  type RmwMsg = super::action::rmw::Insert_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        start_at: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.start_at)).into_owned(),
        end_at: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.end_at)).into_owned(),
        work_id: msg.work_id,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        start_at: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.start_at)).into_owned(),
        end_at: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.end_at)).into_owned(),
      work_id: msg.work_id,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      start_at: builtin_interfaces::msg::Time::from_rmw_message(msg.start_at),
      end_at: builtin_interfaces::msg::Time::from_rmw_message(msg.end_at),
      work_id: msg.work_id,
    }
  }
}


// Corresponds to sfarm_interfaces__action__Insert_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::Insert_Feedback,

}



impl Default for Insert_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Insert_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for Insert_FeedbackMessage {
  type RmwMsg = super::action::rmw::Insert_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::Insert_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::Insert_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::Insert_Feedback::from_rmw_message(msg.feedback),
    }
  }
}


// Corresponds to sfarm_interfaces__action__Eject_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Eject_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for Eject_Goal {
  type RmwMsg = super::action::rmw::Eject_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        work_id: msg.work_id,
        pos_3d_id: msg.pos_3d_id,
        receive_pos_id: msg.receive_pos_id,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      work_id: msg.work_id,
      pos_3d_id: msg.pos_3d_id,
      receive_pos_id: msg.receive_pos_id,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      work_id: msg.work_id,
      pos_3d_id: msg.pos_3d_id,
      receive_pos_id: msg.receive_pos_id,
    }
  }
}


// Corresponds to sfarm_interfaces__action__Eject_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Eject_Result::default())
  }
}

impl rosidl_runtime_rs::Message for Eject_Result {
  type RmwMsg = super::action::rmw::Eject_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
        work_id: msg.work_id,
        work_type: msg.work_type,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      work_id: msg.work_id,
      work_type: msg.work_type,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
      work_id: msg.work_id,
      work_type: msg.work_type,
    }
  }
}


// Corresponds to sfarm_interfaces__action__Eject_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub start_at: builtin_interfaces::msg::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub end_at: builtin_interfaces::msg::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub work_id: i8,

}



impl Default for Eject_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Eject_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for Eject_Feedback {
  type RmwMsg = super::action::rmw::Eject_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        start_at: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.start_at)).into_owned(),
        end_at: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.end_at)).into_owned(),
        work_id: msg.work_id,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        start_at: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.start_at)).into_owned(),
        end_at: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.end_at)).into_owned(),
      work_id: msg.work_id,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      start_at: builtin_interfaces::msg::Time::from_rmw_message(msg.start_at),
      end_at: builtin_interfaces::msg::Time::from_rmw_message(msg.end_at),
      work_id: msg.work_id,
    }
  }
}


// Corresponds to sfarm_interfaces__action__Eject_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::Eject_Feedback,

}



impl Default for Eject_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Eject_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for Eject_FeedbackMessage {
  type RmwMsg = super::action::rmw::Eject_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::Eject_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::Eject_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::Eject_Feedback::from_rmw_message(msg.feedback),
    }
  }
}






// Corresponds to sfarm_interfaces__action__Insert_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::Insert_Goal,

}



impl Default for Insert_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Insert_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Insert_SendGoal_Request {
  type RmwMsg = super::action::rmw::Insert_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::Insert_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::Insert_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::Insert_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to sfarm_interfaces__action__Insert_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for Insert_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Insert_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Insert_SendGoal_Response {
  type RmwMsg = super::action::rmw::Insert_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to sfarm_interfaces__action__Insert_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for Insert_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Insert_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Insert_GetResult_Request {
  type RmwMsg = super::action::rmw::Insert_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to sfarm_interfaces__action__Insert_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Insert_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::Insert_Result,

}



impl Default for Insert_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Insert_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Insert_GetResult_Response {
  type RmwMsg = super::action::rmw::Insert_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::Insert_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::Insert_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::Insert_Result::from_rmw_message(msg.result),
    }
  }
}


// Corresponds to sfarm_interfaces__action__Eject_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::Eject_Goal,

}



impl Default for Eject_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Eject_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Eject_SendGoal_Request {
  type RmwMsg = super::action::rmw::Eject_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::Eject_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::Eject_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::Eject_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to sfarm_interfaces__action__Eject_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for Eject_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Eject_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Eject_SendGoal_Response {
  type RmwMsg = super::action::rmw::Eject_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to sfarm_interfaces__action__Eject_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for Eject_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Eject_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Eject_GetResult_Request {
  type RmwMsg = super::action::rmw::Eject_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to sfarm_interfaces__action__Eject_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Eject_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::Eject_Result,

}



impl Default for Eject_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::Eject_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Eject_GetResult_Response {
  type RmwMsg = super::action::rmw::Eject_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::Eject_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::Eject_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::Eject_Result::from_rmw_message(msg.result),
    }
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






#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__sfarm_interfaces__action__Insert() -> *const std::ffi::c_void;
}

// Corresponds to sfarm_interfaces__action__Insert
#[allow(missing_docs, non_camel_case_types)]
pub struct Insert;

impl rosidl_runtime_rs::Action for Insert {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = Insert_Goal;

  /// The result message defined in the action definition.
  type Result = Insert_Result;

  /// The feedback message defined in the action definition.
  type Feedback = Insert_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::Insert_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::Insert_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::Insert_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__sfarm_interfaces__action__Insert() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::Insert_Goal,
  ) -> super::action::rmw::Insert_SendGoal_Request {
   super::action::rmw::Insert_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::Insert_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::Insert_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::Insert_SendGoal_Response {
   super::action::rmw::Insert_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::Insert_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::Insert_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::Insert_Feedback,
  ) -> super::action::rmw::Insert_FeedbackMessage {
    let mut message = super::action::rmw::Insert_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::Insert_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::Insert_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::Insert_GetResult_Request {
   super::action::rmw::Insert_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::Insert_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::Insert_Result,
  ) -> super::action::rmw::Insert_GetResult_Response {
   super::action::rmw::Insert_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::Insert_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::Insert_Result,
  ) {
    (response.status, response.result)
  }
}




#[link(name = "sfarm_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__sfarm_interfaces__action__Eject() -> *const std::ffi::c_void;
}

// Corresponds to sfarm_interfaces__action__Eject
#[allow(missing_docs, non_camel_case_types)]
pub struct Eject;

impl rosidl_runtime_rs::Action for Eject {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = Eject_Goal;

  /// The result message defined in the action definition.
  type Result = Eject_Result;

  /// The feedback message defined in the action definition.
  type Feedback = Eject_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::Eject_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::Eject_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::Eject_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__sfarm_interfaces__action__Eject() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::Eject_Goal,
  ) -> super::action::rmw::Eject_SendGoal_Request {
   super::action::rmw::Eject_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::Eject_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::Eject_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::Eject_SendGoal_Response {
   super::action::rmw::Eject_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::Eject_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::Eject_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::Eject_Feedback,
  ) -> super::action::rmw::Eject_FeedbackMessage {
    let mut message = super::action::rmw::Eject_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::Eject_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::Eject_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::Eject_GetResult_Request {
   super::action::rmw::Eject_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::Eject_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::Eject_Result,
  ) -> super::action::rmw::Eject_GetResult_Response {
   super::action::rmw::Eject_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::Eject_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::Eject_Result,
  ) {
    (response.status, response.result)
  }
}


