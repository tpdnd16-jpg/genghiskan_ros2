// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sfarm_interfaces:srv/Error.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sfarm_interfaces/srv/error.hpp"


#ifndef SFARM_INTERFACES__SRV__DETAIL__ERROR__BUILDER_HPP_
#define SFARM_INTERFACES__SRV__DETAIL__ERROR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sfarm_interfaces/srv/detail/error__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sfarm_interfaces
{

namespace srv
{

namespace builder
{

class Init_Error_Request_message
{
public:
  Init_Error_Request_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::sfarm_interfaces::srv::Error_Request message(::sfarm_interfaces::srv::Error_Request::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sfarm_interfaces::srv::Error_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sfarm_interfaces::srv::Error_Request>()
{
  return sfarm_interfaces::srv::builder::Init_Error_Request_message();
}

}  // namespace sfarm_interfaces


namespace sfarm_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sfarm_interfaces::srv::Error_Response>()
{
  return ::sfarm_interfaces::srv::Error_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace sfarm_interfaces


namespace sfarm_interfaces
{

namespace srv
{

namespace builder
{

class Init_Error_Event_response
{
public:
  explicit Init_Error_Event_response(::sfarm_interfaces::srv::Error_Event & msg)
  : msg_(msg)
  {}
  ::sfarm_interfaces::srv::Error_Event response(::sfarm_interfaces::srv::Error_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sfarm_interfaces::srv::Error_Event msg_;
};

class Init_Error_Event_request
{
public:
  explicit Init_Error_Event_request(::sfarm_interfaces::srv::Error_Event & msg)
  : msg_(msg)
  {}
  Init_Error_Event_response request(::sfarm_interfaces::srv::Error_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Error_Event_response(msg_);
  }

private:
  ::sfarm_interfaces::srv::Error_Event msg_;
};

class Init_Error_Event_info
{
public:
  Init_Error_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Error_Event_request info(::sfarm_interfaces::srv::Error_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Error_Event_request(msg_);
  }

private:
  ::sfarm_interfaces::srv::Error_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sfarm_interfaces::srv::Error_Event>()
{
  return sfarm_interfaces::srv::builder::Init_Error_Event_info();
}

}  // namespace sfarm_interfaces

#endif  // SFARM_INTERFACES__SRV__DETAIL__ERROR__BUILDER_HPP_
