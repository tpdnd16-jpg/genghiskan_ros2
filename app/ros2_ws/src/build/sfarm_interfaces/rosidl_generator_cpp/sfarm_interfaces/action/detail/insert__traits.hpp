// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sfarm_interfaces:action/Insert.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sfarm_interfaces/action/insert.hpp"


#ifndef SFARM_INTERFACES__ACTION__DETAIL__INSERT__TRAITS_HPP_
#define SFARM_INTERFACES__ACTION__DETAIL__INSERT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sfarm_interfaces/action/detail/insert__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sfarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Insert_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: work_id
  {
    out << "work_id: ";
    rosidl_generator_traits::value_to_yaml(msg.work_id, out);
    out << ", ";
  }

  // member: start_pos_id
  {
    out << "start_pos_id: ";
    rosidl_generator_traits::value_to_yaml(msg.start_pos_id, out);
    out << ", ";
  }

  // member: pos_3d_id
  {
    out << "pos_3d_id: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_3d_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Insert_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: work_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "work_id: ";
    rosidl_generator_traits::value_to_yaml(msg.work_id, out);
    out << "\n";
  }

  // member: start_pos_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_pos_id: ";
    rosidl_generator_traits::value_to_yaml(msg.start_pos_id, out);
    out << "\n";
  }

  // member: pos_3d_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_3d_id: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_3d_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Insert_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sfarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sfarm_interfaces::action::Insert_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  sfarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sfarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const sfarm_interfaces::action::Insert_Goal & msg)
{
  return sfarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<sfarm_interfaces::action::Insert_Goal>()
{
  return "sfarm_interfaces::action::Insert_Goal";
}

template<>
inline const char * name<sfarm_interfaces::action::Insert_Goal>()
{
  return "sfarm_interfaces/action/Insert_Goal";
}

template<>
struct has_fixed_size<sfarm_interfaces::action::Insert_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sfarm_interfaces::action::Insert_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sfarm_interfaces::action::Insert_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace sfarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Insert_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: work_id
  {
    out << "work_id: ";
    rosidl_generator_traits::value_to_yaml(msg.work_id, out);
    out << ", ";
  }

  // member: work_type
  {
    out << "work_type: ";
    rosidl_generator_traits::value_to_yaml(msg.work_type, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Insert_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: work_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "work_id: ";
    rosidl_generator_traits::value_to_yaml(msg.work_id, out);
    out << "\n";
  }

  // member: work_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "work_type: ";
    rosidl_generator_traits::value_to_yaml(msg.work_type, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Insert_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sfarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sfarm_interfaces::action::Insert_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  sfarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sfarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const sfarm_interfaces::action::Insert_Result & msg)
{
  return sfarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<sfarm_interfaces::action::Insert_Result>()
{
  return "sfarm_interfaces::action::Insert_Result";
}

template<>
inline const char * name<sfarm_interfaces::action::Insert_Result>()
{
  return "sfarm_interfaces/action/Insert_Result";
}

template<>
struct has_fixed_size<sfarm_interfaces::action::Insert_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sfarm_interfaces::action::Insert_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sfarm_interfaces::action::Insert_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'start_at'
// Member 'end_at'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace sfarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Insert_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: start_at
  {
    out << "start_at: ";
    to_flow_style_yaml(msg.start_at, out);
    out << ", ";
  }

  // member: end_at
  {
    out << "end_at: ";
    to_flow_style_yaml(msg.end_at, out);
    out << ", ";
  }

  // member: work_id
  {
    out << "work_id: ";
    rosidl_generator_traits::value_to_yaml(msg.work_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Insert_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: start_at
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_at:\n";
    to_block_style_yaml(msg.start_at, out, indentation + 2);
  }

  // member: end_at
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "end_at:\n";
    to_block_style_yaml(msg.end_at, out, indentation + 2);
  }

  // member: work_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "work_id: ";
    rosidl_generator_traits::value_to_yaml(msg.work_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Insert_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sfarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sfarm_interfaces::action::Insert_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  sfarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sfarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const sfarm_interfaces::action::Insert_Feedback & msg)
{
  return sfarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<sfarm_interfaces::action::Insert_Feedback>()
{
  return "sfarm_interfaces::action::Insert_Feedback";
}

template<>
inline const char * name<sfarm_interfaces::action::Insert_Feedback>()
{
  return "sfarm_interfaces/action/Insert_Feedback";
}

template<>
struct has_fixed_size<sfarm_interfaces::action::Insert_Feedback>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<sfarm_interfaces::action::Insert_Feedback>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<sfarm_interfaces::action::Insert_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "sfarm_interfaces/action/detail/insert__traits.hpp"

namespace sfarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Insert_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Insert_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Insert_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sfarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sfarm_interfaces::action::Insert_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  sfarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sfarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const sfarm_interfaces::action::Insert_SendGoal_Request & msg)
{
  return sfarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<sfarm_interfaces::action::Insert_SendGoal_Request>()
{
  return "sfarm_interfaces::action::Insert_SendGoal_Request";
}

template<>
inline const char * name<sfarm_interfaces::action::Insert_SendGoal_Request>()
{
  return "sfarm_interfaces/action/Insert_SendGoal_Request";
}

template<>
struct has_fixed_size<sfarm_interfaces::action::Insert_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<sfarm_interfaces::action::Insert_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<sfarm_interfaces::action::Insert_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<sfarm_interfaces::action::Insert_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<sfarm_interfaces::action::Insert_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
// already included above
// #include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace sfarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Insert_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Insert_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Insert_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sfarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sfarm_interfaces::action::Insert_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  sfarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sfarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const sfarm_interfaces::action::Insert_SendGoal_Response & msg)
{
  return sfarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<sfarm_interfaces::action::Insert_SendGoal_Response>()
{
  return "sfarm_interfaces::action::Insert_SendGoal_Response";
}

template<>
inline const char * name<sfarm_interfaces::action::Insert_SendGoal_Response>()
{
  return "sfarm_interfaces/action/Insert_SendGoal_Response";
}

template<>
struct has_fixed_size<sfarm_interfaces::action::Insert_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<sfarm_interfaces::action::Insert_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<sfarm_interfaces::action::Insert_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace sfarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Insert_SendGoal_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Insert_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Insert_SendGoal_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sfarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sfarm_interfaces::action::Insert_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  sfarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sfarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const sfarm_interfaces::action::Insert_SendGoal_Event & msg)
{
  return sfarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<sfarm_interfaces::action::Insert_SendGoal_Event>()
{
  return "sfarm_interfaces::action::Insert_SendGoal_Event";
}

template<>
inline const char * name<sfarm_interfaces::action::Insert_SendGoal_Event>()
{
  return "sfarm_interfaces/action/Insert_SendGoal_Event";
}

template<>
struct has_fixed_size<sfarm_interfaces::action::Insert_SendGoal_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sfarm_interfaces::action::Insert_SendGoal_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<sfarm_interfaces::action::Insert_SendGoal_Request>::value && has_bounded_size<sfarm_interfaces::action::Insert_SendGoal_Response>::value> {};

template<>
struct is_message<sfarm_interfaces::action::Insert_SendGoal_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sfarm_interfaces::action::Insert_SendGoal>()
{
  return "sfarm_interfaces::action::Insert_SendGoal";
}

template<>
inline const char * name<sfarm_interfaces::action::Insert_SendGoal>()
{
  return "sfarm_interfaces/action/Insert_SendGoal";
}

template<>
struct has_fixed_size<sfarm_interfaces::action::Insert_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<sfarm_interfaces::action::Insert_SendGoal_Request>::value &&
    has_fixed_size<sfarm_interfaces::action::Insert_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<sfarm_interfaces::action::Insert_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<sfarm_interfaces::action::Insert_SendGoal_Request>::value &&
    has_bounded_size<sfarm_interfaces::action::Insert_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<sfarm_interfaces::action::Insert_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<sfarm_interfaces::action::Insert_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<sfarm_interfaces::action::Insert_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace sfarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Insert_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Insert_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Insert_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sfarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sfarm_interfaces::action::Insert_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  sfarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sfarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const sfarm_interfaces::action::Insert_GetResult_Request & msg)
{
  return sfarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<sfarm_interfaces::action::Insert_GetResult_Request>()
{
  return "sfarm_interfaces::action::Insert_GetResult_Request";
}

template<>
inline const char * name<sfarm_interfaces::action::Insert_GetResult_Request>()
{
  return "sfarm_interfaces/action/Insert_GetResult_Request";
}

template<>
struct has_fixed_size<sfarm_interfaces::action::Insert_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<sfarm_interfaces::action::Insert_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<sfarm_interfaces::action::Insert_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "sfarm_interfaces/action/detail/insert__traits.hpp"

namespace sfarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Insert_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Insert_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Insert_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sfarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sfarm_interfaces::action::Insert_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  sfarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sfarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const sfarm_interfaces::action::Insert_GetResult_Response & msg)
{
  return sfarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<sfarm_interfaces::action::Insert_GetResult_Response>()
{
  return "sfarm_interfaces::action::Insert_GetResult_Response";
}

template<>
inline const char * name<sfarm_interfaces::action::Insert_GetResult_Response>()
{
  return "sfarm_interfaces/action/Insert_GetResult_Response";
}

template<>
struct has_fixed_size<sfarm_interfaces::action::Insert_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<sfarm_interfaces::action::Insert_Result>::value> {};

template<>
struct has_bounded_size<sfarm_interfaces::action::Insert_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<sfarm_interfaces::action::Insert_Result>::value> {};

template<>
struct is_message<sfarm_interfaces::action::Insert_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace sfarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Insert_GetResult_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Insert_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Insert_GetResult_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sfarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sfarm_interfaces::action::Insert_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  sfarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sfarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const sfarm_interfaces::action::Insert_GetResult_Event & msg)
{
  return sfarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<sfarm_interfaces::action::Insert_GetResult_Event>()
{
  return "sfarm_interfaces::action::Insert_GetResult_Event";
}

template<>
inline const char * name<sfarm_interfaces::action::Insert_GetResult_Event>()
{
  return "sfarm_interfaces/action/Insert_GetResult_Event";
}

template<>
struct has_fixed_size<sfarm_interfaces::action::Insert_GetResult_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sfarm_interfaces::action::Insert_GetResult_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<sfarm_interfaces::action::Insert_GetResult_Request>::value && has_bounded_size<sfarm_interfaces::action::Insert_GetResult_Response>::value> {};

template<>
struct is_message<sfarm_interfaces::action::Insert_GetResult_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sfarm_interfaces::action::Insert_GetResult>()
{
  return "sfarm_interfaces::action::Insert_GetResult";
}

template<>
inline const char * name<sfarm_interfaces::action::Insert_GetResult>()
{
  return "sfarm_interfaces/action/Insert_GetResult";
}

template<>
struct has_fixed_size<sfarm_interfaces::action::Insert_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<sfarm_interfaces::action::Insert_GetResult_Request>::value &&
    has_fixed_size<sfarm_interfaces::action::Insert_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<sfarm_interfaces::action::Insert_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<sfarm_interfaces::action::Insert_GetResult_Request>::value &&
    has_bounded_size<sfarm_interfaces::action::Insert_GetResult_Response>::value
  >
{
};

template<>
struct is_service<sfarm_interfaces::action::Insert_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<sfarm_interfaces::action::Insert_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<sfarm_interfaces::action::Insert_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "sfarm_interfaces/action/detail/insert__traits.hpp"

namespace sfarm_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Insert_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Insert_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Insert_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sfarm_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sfarm_interfaces::action::Insert_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  sfarm_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sfarm_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const sfarm_interfaces::action::Insert_FeedbackMessage & msg)
{
  return sfarm_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<sfarm_interfaces::action::Insert_FeedbackMessage>()
{
  return "sfarm_interfaces::action::Insert_FeedbackMessage";
}

template<>
inline const char * name<sfarm_interfaces::action::Insert_FeedbackMessage>()
{
  return "sfarm_interfaces/action/Insert_FeedbackMessage";
}

template<>
struct has_fixed_size<sfarm_interfaces::action::Insert_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<sfarm_interfaces::action::Insert_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<sfarm_interfaces::action::Insert_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<sfarm_interfaces::action::Insert_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<sfarm_interfaces::action::Insert_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<sfarm_interfaces::action::Insert>
  : std::true_type
{
};

template<>
struct is_action_goal<sfarm_interfaces::action::Insert_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<sfarm_interfaces::action::Insert_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<sfarm_interfaces::action::Insert_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // SFARM_INTERFACES__ACTION__DETAIL__INSERT__TRAITS_HPP_
