// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sfarm_interfaces:action/Eject.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sfarm_interfaces/action/eject.hpp"


#ifndef SFARM_INTERFACES__ACTION__DETAIL__EJECT__STRUCT_HPP_
#define SFARM_INTERFACES__ACTION__DETAIL__EJECT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sfarm_interfaces__action__Eject_Goal __attribute__((deprecated))
#else
# define DEPRECATED__sfarm_interfaces__action__Eject_Goal __declspec(deprecated)
#endif

namespace sfarm_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Eject_Goal_
{
  using Type = Eject_Goal_<ContainerAllocator>;

  explicit Eject_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->work_id = 0;
      this->pos_3d_id = 0;
      this->receive_pos_id = 0;
    }
  }

  explicit Eject_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->work_id = 0;
      this->pos_3d_id = 0;
      this->receive_pos_id = 0;
    }
  }

  // field types and members
  using _work_id_type =
    int8_t;
  _work_id_type work_id;
  using _pos_3d_id_type =
    int8_t;
  _pos_3d_id_type pos_3d_id;
  using _receive_pos_id_type =
    int8_t;
  _receive_pos_id_type receive_pos_id;

  // setters for named parameter idiom
  Type & set__work_id(
    const int8_t & _arg)
  {
    this->work_id = _arg;
    return *this;
  }
  Type & set__pos_3d_id(
    const int8_t & _arg)
  {
    this->pos_3d_id = _arg;
    return *this;
  }
  Type & set__receive_pos_id(
    const int8_t & _arg)
  {
    this->receive_pos_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sfarm_interfaces::action::Eject_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const sfarm_interfaces::action::Eject_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sfarm_interfaces__action__Eject_Goal
    std::shared_ptr<sfarm_interfaces::action::Eject_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sfarm_interfaces__action__Eject_Goal
    std::shared_ptr<sfarm_interfaces::action::Eject_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Eject_Goal_ & other) const
  {
    if (this->work_id != other.work_id) {
      return false;
    }
    if (this->pos_3d_id != other.pos_3d_id) {
      return false;
    }
    if (this->receive_pos_id != other.receive_pos_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Eject_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Eject_Goal_

// alias to use template instance with default allocator
using Eject_Goal =
  sfarm_interfaces::action::Eject_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace sfarm_interfaces


#ifndef _WIN32
# define DEPRECATED__sfarm_interfaces__action__Eject_Result __attribute__((deprecated))
#else
# define DEPRECATED__sfarm_interfaces__action__Eject_Result __declspec(deprecated)
#endif

namespace sfarm_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Eject_Result_
{
  using Type = Eject_Result_<ContainerAllocator>;

  explicit Eject_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->work_id = 0;
      this->work_type = 0;
    }
  }

  explicit Eject_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->work_id = 0;
      this->work_type = 0;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _work_id_type =
    int8_t;
  _work_id_type work_id;
  using _work_type_type =
    uint8_t;
  _work_type_type work_type;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__work_id(
    const int8_t & _arg)
  {
    this->work_id = _arg;
    return *this;
  }
  Type & set__work_type(
    const uint8_t & _arg)
  {
    this->work_type = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t WORK_TYPE_INSERT =
    0u;
  static constexpr uint8_t WORK_TYPE_EJECT =
    1u;

  // pointer types
  using RawPtr =
    sfarm_interfaces::action::Eject_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const sfarm_interfaces::action::Eject_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sfarm_interfaces__action__Eject_Result
    std::shared_ptr<sfarm_interfaces::action::Eject_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sfarm_interfaces__action__Eject_Result
    std::shared_ptr<sfarm_interfaces::action::Eject_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Eject_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->work_id != other.work_id) {
      return false;
    }
    if (this->work_type != other.work_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const Eject_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Eject_Result_

// alias to use template instance with default allocator
using Eject_Result =
  sfarm_interfaces::action::Eject_Result_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Eject_Result_<ContainerAllocator>::WORK_TYPE_INSERT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t Eject_Result_<ContainerAllocator>::WORK_TYPE_EJECT;
#endif  // __cplusplus < 201703L

}  // namespace action

}  // namespace sfarm_interfaces


// Include directives for member types
// Member 'start_at'
// Member 'end_at'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sfarm_interfaces__action__Eject_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__sfarm_interfaces__action__Eject_Feedback __declspec(deprecated)
#endif

namespace sfarm_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Eject_Feedback_
{
  using Type = Eject_Feedback_<ContainerAllocator>;

  explicit Eject_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start_at(_init),
    end_at(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->work_id = 0;
    }
  }

  explicit Eject_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : start_at(_alloc, _init),
    end_at(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->work_id = 0;
    }
  }

  // field types and members
  using _start_at_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _start_at_type start_at;
  using _end_at_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _end_at_type end_at;
  using _work_id_type =
    int8_t;
  _work_id_type work_id;

  // setters for named parameter idiom
  Type & set__start_at(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->start_at = _arg;
    return *this;
  }
  Type & set__end_at(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->end_at = _arg;
    return *this;
  }
  Type & set__work_id(
    const int8_t & _arg)
  {
    this->work_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sfarm_interfaces::action::Eject_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const sfarm_interfaces::action::Eject_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sfarm_interfaces__action__Eject_Feedback
    std::shared_ptr<sfarm_interfaces::action::Eject_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sfarm_interfaces__action__Eject_Feedback
    std::shared_ptr<sfarm_interfaces::action::Eject_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Eject_Feedback_ & other) const
  {
    if (this->start_at != other.start_at) {
      return false;
    }
    if (this->end_at != other.end_at) {
      return false;
    }
    if (this->work_id != other.work_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Eject_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Eject_Feedback_

// alias to use template instance with default allocator
using Eject_Feedback =
  sfarm_interfaces::action::Eject_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace sfarm_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "sfarm_interfaces/action/detail/eject__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sfarm_interfaces__action__Eject_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__sfarm_interfaces__action__Eject_SendGoal_Request __declspec(deprecated)
#endif

namespace sfarm_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Eject_SendGoal_Request_
{
  using Type = Eject_SendGoal_Request_<ContainerAllocator>;

  explicit Eject_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit Eject_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    sfarm_interfaces::action::Eject_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const sfarm_interfaces::action::Eject_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sfarm_interfaces__action__Eject_SendGoal_Request
    std::shared_ptr<sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sfarm_interfaces__action__Eject_SendGoal_Request
    std::shared_ptr<sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Eject_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const Eject_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Eject_SendGoal_Request_

// alias to use template instance with default allocator
using Eject_SendGoal_Request =
  sfarm_interfaces::action::Eject_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace sfarm_interfaces


// Include directives for member types
// Member 'stamp'
// already included above
// #include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sfarm_interfaces__action__Eject_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__sfarm_interfaces__action__Eject_SendGoal_Response __declspec(deprecated)
#endif

namespace sfarm_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Eject_SendGoal_Response_
{
  using Type = Eject_SendGoal_Response_<ContainerAllocator>;

  explicit Eject_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit Eject_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sfarm_interfaces__action__Eject_SendGoal_Response
    std::shared_ptr<sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sfarm_interfaces__action__Eject_SendGoal_Response
    std::shared_ptr<sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Eject_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const Eject_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Eject_SendGoal_Response_

// alias to use template instance with default allocator
using Eject_SendGoal_Response =
  sfarm_interfaces::action::Eject_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace sfarm_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sfarm_interfaces__action__Eject_SendGoal_Event __attribute__((deprecated))
#else
# define DEPRECATED__sfarm_interfaces__action__Eject_SendGoal_Event __declspec(deprecated)
#endif

namespace sfarm_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Eject_SendGoal_Event_
{
  using Type = Eject_SendGoal_Event_<ContainerAllocator>;

  explicit Eject_SendGoal_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit Eject_SendGoal_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sfarm_interfaces::action::Eject_SendGoal_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sfarm_interfaces::action::Eject_SendGoal_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sfarm_interfaces::action::Eject_SendGoal_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const sfarm_interfaces::action::Eject_SendGoal_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_SendGoal_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_SendGoal_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_SendGoal_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_SendGoal_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_SendGoal_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_SendGoal_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_SendGoal_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_SendGoal_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sfarm_interfaces__action__Eject_SendGoal_Event
    std::shared_ptr<sfarm_interfaces::action::Eject_SendGoal_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sfarm_interfaces__action__Eject_SendGoal_Event
    std::shared_ptr<sfarm_interfaces::action::Eject_SendGoal_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Eject_SendGoal_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const Eject_SendGoal_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Eject_SendGoal_Event_

// alias to use template instance with default allocator
using Eject_SendGoal_Event =
  sfarm_interfaces::action::Eject_SendGoal_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace sfarm_interfaces

namespace sfarm_interfaces
{

namespace action
{

struct Eject_SendGoal
{
  using Request = sfarm_interfaces::action::Eject_SendGoal_Request;
  using Response = sfarm_interfaces::action::Eject_SendGoal_Response;
  using Event = sfarm_interfaces::action::Eject_SendGoal_Event;
};

}  // namespace action

}  // namespace sfarm_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sfarm_interfaces__action__Eject_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__sfarm_interfaces__action__Eject_GetResult_Request __declspec(deprecated)
#endif

namespace sfarm_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Eject_GetResult_Request_
{
  using Type = Eject_GetResult_Request_<ContainerAllocator>;

  explicit Eject_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit Eject_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sfarm_interfaces__action__Eject_GetResult_Request
    std::shared_ptr<sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sfarm_interfaces__action__Eject_GetResult_Request
    std::shared_ptr<sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Eject_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Eject_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Eject_GetResult_Request_

// alias to use template instance with default allocator
using Eject_GetResult_Request =
  sfarm_interfaces::action::Eject_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace sfarm_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "sfarm_interfaces/action/detail/eject__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sfarm_interfaces__action__Eject_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__sfarm_interfaces__action__Eject_GetResult_Response __declspec(deprecated)
#endif

namespace sfarm_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Eject_GetResult_Response_
{
  using Type = Eject_GetResult_Response_<ContainerAllocator>;

  explicit Eject_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit Eject_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    sfarm_interfaces::action::Eject_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const sfarm_interfaces::action::Eject_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sfarm_interfaces__action__Eject_GetResult_Response
    std::shared_ptr<sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sfarm_interfaces__action__Eject_GetResult_Response
    std::shared_ptr<sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Eject_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Eject_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Eject_GetResult_Response_

// alias to use template instance with default allocator
using Eject_GetResult_Response =
  sfarm_interfaces::action::Eject_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace sfarm_interfaces


// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sfarm_interfaces__action__Eject_GetResult_Event __attribute__((deprecated))
#else
# define DEPRECATED__sfarm_interfaces__action__Eject_GetResult_Event __declspec(deprecated)
#endif

namespace sfarm_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Eject_GetResult_Event_
{
  using Type = Eject_GetResult_Event_<ContainerAllocator>;

  explicit Eject_GetResult_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit Eject_GetResult_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sfarm_interfaces::action::Eject_GetResult_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sfarm_interfaces::action::Eject_GetResult_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sfarm_interfaces::action::Eject_GetResult_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const sfarm_interfaces::action::Eject_GetResult_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_GetResult_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_GetResult_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_GetResult_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_GetResult_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_GetResult_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_GetResult_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_GetResult_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_GetResult_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sfarm_interfaces__action__Eject_GetResult_Event
    std::shared_ptr<sfarm_interfaces::action::Eject_GetResult_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sfarm_interfaces__action__Eject_GetResult_Event
    std::shared_ptr<sfarm_interfaces::action::Eject_GetResult_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Eject_GetResult_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const Eject_GetResult_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Eject_GetResult_Event_

// alias to use template instance with default allocator
using Eject_GetResult_Event =
  sfarm_interfaces::action::Eject_GetResult_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace sfarm_interfaces

namespace sfarm_interfaces
{

namespace action
{

struct Eject_GetResult
{
  using Request = sfarm_interfaces::action::Eject_GetResult_Request;
  using Response = sfarm_interfaces::action::Eject_GetResult_Response;
  using Event = sfarm_interfaces::action::Eject_GetResult_Event;
};

}  // namespace action

}  // namespace sfarm_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "sfarm_interfaces/action/detail/eject__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__sfarm_interfaces__action__Eject_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__sfarm_interfaces__action__Eject_FeedbackMessage __declspec(deprecated)
#endif

namespace sfarm_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Eject_FeedbackMessage_
{
  using Type = Eject_FeedbackMessage_<ContainerAllocator>;

  explicit Eject_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit Eject_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    sfarm_interfaces::action::Eject_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const sfarm_interfaces::action::Eject_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sfarm_interfaces::action::Eject_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const sfarm_interfaces::action::Eject_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sfarm_interfaces::action::Eject_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sfarm_interfaces::action::Eject_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sfarm_interfaces::action::Eject_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sfarm_interfaces::action::Eject_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sfarm_interfaces__action__Eject_FeedbackMessage
    std::shared_ptr<sfarm_interfaces::action::Eject_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sfarm_interfaces__action__Eject_FeedbackMessage
    std::shared_ptr<sfarm_interfaces::action::Eject_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Eject_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const Eject_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Eject_FeedbackMessage_

// alias to use template instance with default allocator
using Eject_FeedbackMessage =
  sfarm_interfaces::action::Eject_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace sfarm_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace sfarm_interfaces
{

namespace action
{

struct Eject
{
  /// The goal message defined in the action definition.
  using Goal = sfarm_interfaces::action::Eject_Goal;
  /// The result message defined in the action definition.
  using Result = sfarm_interfaces::action::Eject_Result;
  /// The feedback message defined in the action definition.
  using Feedback = sfarm_interfaces::action::Eject_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = sfarm_interfaces::action::Eject_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = sfarm_interfaces::action::Eject_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = sfarm_interfaces::action::Eject_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct Eject Eject;

}  // namespace action

}  // namespace sfarm_interfaces

#endif  // SFARM_INTERFACES__ACTION__DETAIL__EJECT__STRUCT_HPP_
