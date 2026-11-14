// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sfarm_interfaces:action/Insert.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sfarm_interfaces/action/insert.hpp"


#ifndef SFARM_INTERFACES__ACTION__DETAIL__INSERT__BUILDER_HPP_
#define SFARM_INTERFACES__ACTION__DETAIL__INSERT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sfarm_interfaces/action/detail/insert__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sfarm_interfaces
{

namespace action
{

namespace builder
{

class Init_Insert_Goal_pos_3d_id
{
public:
  explicit Init_Insert_Goal_pos_3d_id(::sfarm_interfaces::action::Insert_Goal & msg)
  : msg_(msg)
  {}
  ::sfarm_interfaces::action::Insert_Goal pos_3d_id(::sfarm_interfaces::action::Insert_Goal::_pos_3d_id_type arg)
  {
    msg_.pos_3d_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_Goal msg_;
};

class Init_Insert_Goal_start_pos_id
{
public:
  explicit Init_Insert_Goal_start_pos_id(::sfarm_interfaces::action::Insert_Goal & msg)
  : msg_(msg)
  {}
  Init_Insert_Goal_pos_3d_id start_pos_id(::sfarm_interfaces::action::Insert_Goal::_start_pos_id_type arg)
  {
    msg_.start_pos_id = std::move(arg);
    return Init_Insert_Goal_pos_3d_id(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_Goal msg_;
};

class Init_Insert_Goal_work_id
{
public:
  Init_Insert_Goal_work_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Insert_Goal_start_pos_id work_id(::sfarm_interfaces::action::Insert_Goal::_work_id_type arg)
  {
    msg_.work_id = std::move(arg);
    return Init_Insert_Goal_start_pos_id(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sfarm_interfaces::action::Insert_Goal>()
{
  return sfarm_interfaces::action::builder::Init_Insert_Goal_work_id();
}

}  // namespace sfarm_interfaces


namespace sfarm_interfaces
{

namespace action
{

namespace builder
{

class Init_Insert_Result_work_type
{
public:
  explicit Init_Insert_Result_work_type(::sfarm_interfaces::action::Insert_Result & msg)
  : msg_(msg)
  {}
  ::sfarm_interfaces::action::Insert_Result work_type(::sfarm_interfaces::action::Insert_Result::_work_type_type arg)
  {
    msg_.work_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_Result msg_;
};

class Init_Insert_Result_work_id
{
public:
  explicit Init_Insert_Result_work_id(::sfarm_interfaces::action::Insert_Result & msg)
  : msg_(msg)
  {}
  Init_Insert_Result_work_type work_id(::sfarm_interfaces::action::Insert_Result::_work_id_type arg)
  {
    msg_.work_id = std::move(arg);
    return Init_Insert_Result_work_type(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_Result msg_;
};

class Init_Insert_Result_message
{
public:
  explicit Init_Insert_Result_message(::sfarm_interfaces::action::Insert_Result & msg)
  : msg_(msg)
  {}
  Init_Insert_Result_work_id message(::sfarm_interfaces::action::Insert_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_Insert_Result_work_id(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_Result msg_;
};

class Init_Insert_Result_success
{
public:
  Init_Insert_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Insert_Result_message success(::sfarm_interfaces::action::Insert_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Insert_Result_message(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sfarm_interfaces::action::Insert_Result>()
{
  return sfarm_interfaces::action::builder::Init_Insert_Result_success();
}

}  // namespace sfarm_interfaces


namespace sfarm_interfaces
{

namespace action
{

namespace builder
{

class Init_Insert_Feedback_work_id
{
public:
  explicit Init_Insert_Feedback_work_id(::sfarm_interfaces::action::Insert_Feedback & msg)
  : msg_(msg)
  {}
  ::sfarm_interfaces::action::Insert_Feedback work_id(::sfarm_interfaces::action::Insert_Feedback::_work_id_type arg)
  {
    msg_.work_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_Feedback msg_;
};

class Init_Insert_Feedback_end_at
{
public:
  explicit Init_Insert_Feedback_end_at(::sfarm_interfaces::action::Insert_Feedback & msg)
  : msg_(msg)
  {}
  Init_Insert_Feedback_work_id end_at(::sfarm_interfaces::action::Insert_Feedback::_end_at_type arg)
  {
    msg_.end_at = std::move(arg);
    return Init_Insert_Feedback_work_id(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_Feedback msg_;
};

class Init_Insert_Feedback_start_at
{
public:
  Init_Insert_Feedback_start_at()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Insert_Feedback_end_at start_at(::sfarm_interfaces::action::Insert_Feedback::_start_at_type arg)
  {
    msg_.start_at = std::move(arg);
    return Init_Insert_Feedback_end_at(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sfarm_interfaces::action::Insert_Feedback>()
{
  return sfarm_interfaces::action::builder::Init_Insert_Feedback_start_at();
}

}  // namespace sfarm_interfaces


namespace sfarm_interfaces
{

namespace action
{

namespace builder
{

class Init_Insert_SendGoal_Request_goal
{
public:
  explicit Init_Insert_SendGoal_Request_goal(::sfarm_interfaces::action::Insert_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::sfarm_interfaces::action::Insert_SendGoal_Request goal(::sfarm_interfaces::action::Insert_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_SendGoal_Request msg_;
};

class Init_Insert_SendGoal_Request_goal_id
{
public:
  Init_Insert_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Insert_SendGoal_Request_goal goal_id(::sfarm_interfaces::action::Insert_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Insert_SendGoal_Request_goal(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sfarm_interfaces::action::Insert_SendGoal_Request>()
{
  return sfarm_interfaces::action::builder::Init_Insert_SendGoal_Request_goal_id();
}

}  // namespace sfarm_interfaces


namespace sfarm_interfaces
{

namespace action
{

namespace builder
{

class Init_Insert_SendGoal_Response_stamp
{
public:
  explicit Init_Insert_SendGoal_Response_stamp(::sfarm_interfaces::action::Insert_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::sfarm_interfaces::action::Insert_SendGoal_Response stamp(::sfarm_interfaces::action::Insert_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_SendGoal_Response msg_;
};

class Init_Insert_SendGoal_Response_accepted
{
public:
  Init_Insert_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Insert_SendGoal_Response_stamp accepted(::sfarm_interfaces::action::Insert_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Insert_SendGoal_Response_stamp(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sfarm_interfaces::action::Insert_SendGoal_Response>()
{
  return sfarm_interfaces::action::builder::Init_Insert_SendGoal_Response_accepted();
}

}  // namespace sfarm_interfaces


namespace sfarm_interfaces
{

namespace action
{

namespace builder
{

class Init_Insert_SendGoal_Event_response
{
public:
  explicit Init_Insert_SendGoal_Event_response(::sfarm_interfaces::action::Insert_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::sfarm_interfaces::action::Insert_SendGoal_Event response(::sfarm_interfaces::action::Insert_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_SendGoal_Event msg_;
};

class Init_Insert_SendGoal_Event_request
{
public:
  explicit Init_Insert_SendGoal_Event_request(::sfarm_interfaces::action::Insert_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_Insert_SendGoal_Event_response request(::sfarm_interfaces::action::Insert_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Insert_SendGoal_Event_response(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_SendGoal_Event msg_;
};

class Init_Insert_SendGoal_Event_info
{
public:
  Init_Insert_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Insert_SendGoal_Event_request info(::sfarm_interfaces::action::Insert_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Insert_SendGoal_Event_request(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sfarm_interfaces::action::Insert_SendGoal_Event>()
{
  return sfarm_interfaces::action::builder::Init_Insert_SendGoal_Event_info();
}

}  // namespace sfarm_interfaces


namespace sfarm_interfaces
{

namespace action
{

namespace builder
{

class Init_Insert_GetResult_Request_goal_id
{
public:
  Init_Insert_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sfarm_interfaces::action::Insert_GetResult_Request goal_id(::sfarm_interfaces::action::Insert_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sfarm_interfaces::action::Insert_GetResult_Request>()
{
  return sfarm_interfaces::action::builder::Init_Insert_GetResult_Request_goal_id();
}

}  // namespace sfarm_interfaces


namespace sfarm_interfaces
{

namespace action
{

namespace builder
{

class Init_Insert_GetResult_Response_result
{
public:
  explicit Init_Insert_GetResult_Response_result(::sfarm_interfaces::action::Insert_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::sfarm_interfaces::action::Insert_GetResult_Response result(::sfarm_interfaces::action::Insert_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_GetResult_Response msg_;
};

class Init_Insert_GetResult_Response_status
{
public:
  Init_Insert_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Insert_GetResult_Response_result status(::sfarm_interfaces::action::Insert_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Insert_GetResult_Response_result(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sfarm_interfaces::action::Insert_GetResult_Response>()
{
  return sfarm_interfaces::action::builder::Init_Insert_GetResult_Response_status();
}

}  // namespace sfarm_interfaces


namespace sfarm_interfaces
{

namespace action
{

namespace builder
{

class Init_Insert_GetResult_Event_response
{
public:
  explicit Init_Insert_GetResult_Event_response(::sfarm_interfaces::action::Insert_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::sfarm_interfaces::action::Insert_GetResult_Event response(::sfarm_interfaces::action::Insert_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_GetResult_Event msg_;
};

class Init_Insert_GetResult_Event_request
{
public:
  explicit Init_Insert_GetResult_Event_request(::sfarm_interfaces::action::Insert_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_Insert_GetResult_Event_response request(::sfarm_interfaces::action::Insert_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Insert_GetResult_Event_response(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_GetResult_Event msg_;
};

class Init_Insert_GetResult_Event_info
{
public:
  Init_Insert_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Insert_GetResult_Event_request info(::sfarm_interfaces::action::Insert_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Insert_GetResult_Event_request(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sfarm_interfaces::action::Insert_GetResult_Event>()
{
  return sfarm_interfaces::action::builder::Init_Insert_GetResult_Event_info();
}

}  // namespace sfarm_interfaces


namespace sfarm_interfaces
{

namespace action
{

namespace builder
{

class Init_Insert_FeedbackMessage_feedback
{
public:
  explicit Init_Insert_FeedbackMessage_feedback(::sfarm_interfaces::action::Insert_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::sfarm_interfaces::action::Insert_FeedbackMessage feedback(::sfarm_interfaces::action::Insert_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_FeedbackMessage msg_;
};

class Init_Insert_FeedbackMessage_goal_id
{
public:
  Init_Insert_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Insert_FeedbackMessage_feedback goal_id(::sfarm_interfaces::action::Insert_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Insert_FeedbackMessage_feedback(msg_);
  }

private:
  ::sfarm_interfaces::action::Insert_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::sfarm_interfaces::action::Insert_FeedbackMessage>()
{
  return sfarm_interfaces::action::builder::Init_Insert_FeedbackMessage_goal_id();
}

}  // namespace sfarm_interfaces

#endif  // SFARM_INTERFACES__ACTION__DETAIL__INSERT__BUILDER_HPP_
