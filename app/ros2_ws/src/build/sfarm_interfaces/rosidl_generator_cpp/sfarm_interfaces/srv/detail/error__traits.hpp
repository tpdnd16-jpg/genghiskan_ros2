// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sfarm_interfaces:srv/Error.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sfarm_interfaces/srv/error.hpp"


#ifndef SFARM_INTERFACES__SRV__DETAIL__ERROR__TRAITS_HPP_
#define SFARM_INTERFACES__SRV__DETAIL__ERROR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sfarm_interfaces/srv/detail/error__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sfarm_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Error_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Error_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Error_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace sfarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sfarm_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sfarm_interfaces::srv::Error_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  sfarm_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sfarm_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const sfarm_interfaces::srv::Error_Request & msg)
{
  return sfarm_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<sfarm_interfaces::srv::Error_Request>()
{
  return "sfarm_interfaces::srv::Error_Request";
}

template<>
inline const char * name<sfarm_interfaces::srv::Error_Request>()
{
  return "sfarm_interfaces/srv/Error_Request";
}

template<>
struct has_fixed_size<sfarm_interfaces::srv::Error_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sfarm_interfaces::srv::Error_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sfarm_interfaces::srv::Error_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace sfarm_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Error_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Error_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Error_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace sfarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sfarm_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sfarm_interfaces::srv::Error_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  sfarm_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sfarm_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const sfarm_interfaces::srv::Error_Response & msg)
{
  return sfarm_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<sfarm_interfaces::srv::Error_Response>()
{
  return "sfarm_interfaces::srv::Error_Response";
}

template<>
inline const char * name<sfarm_interfaces::srv::Error_Response>()
{
  return "sfarm_interfaces/srv/Error_Response";
}

template<>
struct has_fixed_size<sfarm_interfaces::srv::Error_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sfarm_interfaces::srv::Error_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sfarm_interfaces::srv::Error_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace sfarm_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Error_Event & msg,
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
  const Error_Event & msg,
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

inline std::string to_yaml(const Error_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace sfarm_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sfarm_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sfarm_interfaces::srv::Error_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  sfarm_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sfarm_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const sfarm_interfaces::srv::Error_Event & msg)
{
  return sfarm_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<sfarm_interfaces::srv::Error_Event>()
{
  return "sfarm_interfaces::srv::Error_Event";
}

template<>
inline const char * name<sfarm_interfaces::srv::Error_Event>()
{
  return "sfarm_interfaces/srv/Error_Event";
}

template<>
struct has_fixed_size<sfarm_interfaces::srv::Error_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sfarm_interfaces::srv::Error_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<sfarm_interfaces::srv::Error_Request>::value && has_bounded_size<sfarm_interfaces::srv::Error_Response>::value> {};

template<>
struct is_message<sfarm_interfaces::srv::Error_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sfarm_interfaces::srv::Error>()
{
  return "sfarm_interfaces::srv::Error";
}

template<>
inline const char * name<sfarm_interfaces::srv::Error>()
{
  return "sfarm_interfaces/srv/Error";
}

template<>
struct has_fixed_size<sfarm_interfaces::srv::Error>
  : std::integral_constant<
    bool,
    has_fixed_size<sfarm_interfaces::srv::Error_Request>::value &&
    has_fixed_size<sfarm_interfaces::srv::Error_Response>::value
  >
{
};

template<>
struct has_bounded_size<sfarm_interfaces::srv::Error>
  : std::integral_constant<
    bool,
    has_bounded_size<sfarm_interfaces::srv::Error_Request>::value &&
    has_bounded_size<sfarm_interfaces::srv::Error_Response>::value
  >
{
};

template<>
struct is_service<sfarm_interfaces::srv::Error>
  : std::true_type
{
};

template<>
struct is_service_request<sfarm_interfaces::srv::Error_Request>
  : std::true_type
{
};

template<>
struct is_service_response<sfarm_interfaces::srv::Error_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SFARM_INTERFACES__SRV__DETAIL__ERROR__TRAITS_HPP_
