// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from sfarm_interfaces:srv/Error.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "sfarm_interfaces/srv/detail/error__rosidl_typesupport_introspection_c.h"
#include "sfarm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "sfarm_interfaces/srv/detail/error__functions.h"
#include "sfarm_interfaces/srv/detail/error__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sfarm_interfaces__srv__Error_Request__rosidl_typesupport_introspection_c__Error_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sfarm_interfaces__srv__Error_Request__init(message_memory);
}

void sfarm_interfaces__srv__Error_Request__rosidl_typesupport_introspection_c__Error_Request_fini_function(void * message_memory)
{
  sfarm_interfaces__srv__Error_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sfarm_interfaces__srv__Error_Request__rosidl_typesupport_introspection_c__Error_Request_message_member_array[1] = {
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sfarm_interfaces__srv__Error_Request, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sfarm_interfaces__srv__Error_Request__rosidl_typesupport_introspection_c__Error_Request_message_members = {
  "sfarm_interfaces__srv",  // message namespace
  "Error_Request",  // message name
  1,  // number of fields
  sizeof(sfarm_interfaces__srv__Error_Request),
  false,  // has_any_key_member_
  sfarm_interfaces__srv__Error_Request__rosidl_typesupport_introspection_c__Error_Request_message_member_array,  // message members
  sfarm_interfaces__srv__Error_Request__rosidl_typesupport_introspection_c__Error_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  sfarm_interfaces__srv__Error_Request__rosidl_typesupport_introspection_c__Error_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sfarm_interfaces__srv__Error_Request__rosidl_typesupport_introspection_c__Error_Request_message_type_support_handle = {
  0,
  &sfarm_interfaces__srv__Error_Request__rosidl_typesupport_introspection_c__Error_Request_message_members,
  get_message_typesupport_handle_function,
  &sfarm_interfaces__srv__Error_Request__get_type_hash,
  &sfarm_interfaces__srv__Error_Request__get_type_description,
  &sfarm_interfaces__srv__Error_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sfarm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sfarm_interfaces, srv, Error_Request)() {
  if (!sfarm_interfaces__srv__Error_Request__rosidl_typesupport_introspection_c__Error_Request_message_type_support_handle.typesupport_identifier) {
    sfarm_interfaces__srv__Error_Request__rosidl_typesupport_introspection_c__Error_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sfarm_interfaces__srv__Error_Request__rosidl_typesupport_introspection_c__Error_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "sfarm_interfaces/srv/detail/error__rosidl_typesupport_introspection_c.h"
// already included above
// #include "sfarm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "sfarm_interfaces/srv/detail/error__functions.h"
// already included above
// #include "sfarm_interfaces/srv/detail/error__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void sfarm_interfaces__srv__Error_Response__rosidl_typesupport_introspection_c__Error_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sfarm_interfaces__srv__Error_Response__init(message_memory);
}

void sfarm_interfaces__srv__Error_Response__rosidl_typesupport_introspection_c__Error_Response_fini_function(void * message_memory)
{
  sfarm_interfaces__srv__Error_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sfarm_interfaces__srv__Error_Response__rosidl_typesupport_introspection_c__Error_Response_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sfarm_interfaces__srv__Error_Response, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sfarm_interfaces__srv__Error_Response__rosidl_typesupport_introspection_c__Error_Response_message_members = {
  "sfarm_interfaces__srv",  // message namespace
  "Error_Response",  // message name
  1,  // number of fields
  sizeof(sfarm_interfaces__srv__Error_Response),
  false,  // has_any_key_member_
  sfarm_interfaces__srv__Error_Response__rosidl_typesupport_introspection_c__Error_Response_message_member_array,  // message members
  sfarm_interfaces__srv__Error_Response__rosidl_typesupport_introspection_c__Error_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  sfarm_interfaces__srv__Error_Response__rosidl_typesupport_introspection_c__Error_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sfarm_interfaces__srv__Error_Response__rosidl_typesupport_introspection_c__Error_Response_message_type_support_handle = {
  0,
  &sfarm_interfaces__srv__Error_Response__rosidl_typesupport_introspection_c__Error_Response_message_members,
  get_message_typesupport_handle_function,
  &sfarm_interfaces__srv__Error_Response__get_type_hash,
  &sfarm_interfaces__srv__Error_Response__get_type_description,
  &sfarm_interfaces__srv__Error_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sfarm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sfarm_interfaces, srv, Error_Response)() {
  if (!sfarm_interfaces__srv__Error_Response__rosidl_typesupport_introspection_c__Error_Response_message_type_support_handle.typesupport_identifier) {
    sfarm_interfaces__srv__Error_Response__rosidl_typesupport_introspection_c__Error_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sfarm_interfaces__srv__Error_Response__rosidl_typesupport_introspection_c__Error_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "sfarm_interfaces/srv/detail/error__rosidl_typesupport_introspection_c.h"
// already included above
// #include "sfarm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "sfarm_interfaces/srv/detail/error__functions.h"
// already included above
// #include "sfarm_interfaces/srv/detail/error__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "sfarm_interfaces/srv/error.h"
// Member `request`
// Member `response`
// already included above
// #include "sfarm_interfaces/srv/detail/error__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sfarm_interfaces__srv__Error_Event__init(message_memory);
}

void sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_fini_function(void * message_memory)
{
  sfarm_interfaces__srv__Error_Event__fini(message_memory);
}

size_t sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__size_function__Error_Event__request(
  const void * untyped_member)
{
  const sfarm_interfaces__srv__Error_Request__Sequence * member =
    (const sfarm_interfaces__srv__Error_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__get_const_function__Error_Event__request(
  const void * untyped_member, size_t index)
{
  const sfarm_interfaces__srv__Error_Request__Sequence * member =
    (const sfarm_interfaces__srv__Error_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__get_function__Error_Event__request(
  void * untyped_member, size_t index)
{
  sfarm_interfaces__srv__Error_Request__Sequence * member =
    (sfarm_interfaces__srv__Error_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__fetch_function__Error_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sfarm_interfaces__srv__Error_Request * item =
    ((const sfarm_interfaces__srv__Error_Request *)
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__get_const_function__Error_Event__request(untyped_member, index));
  sfarm_interfaces__srv__Error_Request * value =
    (sfarm_interfaces__srv__Error_Request *)(untyped_value);
  *value = *item;
}

void sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__assign_function__Error_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sfarm_interfaces__srv__Error_Request * item =
    ((sfarm_interfaces__srv__Error_Request *)
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__get_function__Error_Event__request(untyped_member, index));
  const sfarm_interfaces__srv__Error_Request * value =
    (const sfarm_interfaces__srv__Error_Request *)(untyped_value);
  *item = *value;
}

bool sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__resize_function__Error_Event__request(
  void * untyped_member, size_t size)
{
  sfarm_interfaces__srv__Error_Request__Sequence * member =
    (sfarm_interfaces__srv__Error_Request__Sequence *)(untyped_member);
  sfarm_interfaces__srv__Error_Request__Sequence__fini(member);
  return sfarm_interfaces__srv__Error_Request__Sequence__init(member, size);
}

size_t sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__size_function__Error_Event__response(
  const void * untyped_member)
{
  const sfarm_interfaces__srv__Error_Response__Sequence * member =
    (const sfarm_interfaces__srv__Error_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__get_const_function__Error_Event__response(
  const void * untyped_member, size_t index)
{
  const sfarm_interfaces__srv__Error_Response__Sequence * member =
    (const sfarm_interfaces__srv__Error_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__get_function__Error_Event__response(
  void * untyped_member, size_t index)
{
  sfarm_interfaces__srv__Error_Response__Sequence * member =
    (sfarm_interfaces__srv__Error_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__fetch_function__Error_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sfarm_interfaces__srv__Error_Response * item =
    ((const sfarm_interfaces__srv__Error_Response *)
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__get_const_function__Error_Event__response(untyped_member, index));
  sfarm_interfaces__srv__Error_Response * value =
    (sfarm_interfaces__srv__Error_Response *)(untyped_value);
  *value = *item;
}

void sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__assign_function__Error_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sfarm_interfaces__srv__Error_Response * item =
    ((sfarm_interfaces__srv__Error_Response *)
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__get_function__Error_Event__response(untyped_member, index));
  const sfarm_interfaces__srv__Error_Response * value =
    (const sfarm_interfaces__srv__Error_Response *)(untyped_value);
  *item = *value;
}

bool sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__resize_function__Error_Event__response(
  void * untyped_member, size_t size)
{
  sfarm_interfaces__srv__Error_Response__Sequence * member =
    (sfarm_interfaces__srv__Error_Response__Sequence *)(untyped_member);
  sfarm_interfaces__srv__Error_Response__Sequence__fini(member);
  return sfarm_interfaces__srv__Error_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sfarm_interfaces__srv__Error_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(sfarm_interfaces__srv__Error_Event, request),  // bytes offset in struct
    NULL,  // default value
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__size_function__Error_Event__request,  // size() function pointer
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__get_const_function__Error_Event__request,  // get_const(index) function pointer
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__get_function__Error_Event__request,  // get(index) function pointer
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__fetch_function__Error_Event__request,  // fetch(index, &value) function pointer
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__assign_function__Error_Event__request,  // assign(index, value) function pointer
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__resize_function__Error_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(sfarm_interfaces__srv__Error_Event, response),  // bytes offset in struct
    NULL,  // default value
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__size_function__Error_Event__response,  // size() function pointer
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__get_const_function__Error_Event__response,  // get_const(index) function pointer
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__get_function__Error_Event__response,  // get(index) function pointer
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__fetch_function__Error_Event__response,  // fetch(index, &value) function pointer
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__assign_function__Error_Event__response,  // assign(index, value) function pointer
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__resize_function__Error_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_message_members = {
  "sfarm_interfaces__srv",  // message namespace
  "Error_Event",  // message name
  3,  // number of fields
  sizeof(sfarm_interfaces__srv__Error_Event),
  false,  // has_any_key_member_
  sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_message_member_array,  // message members
  sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_message_type_support_handle = {
  0,
  &sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_message_members,
  get_message_typesupport_handle_function,
  &sfarm_interfaces__srv__Error_Event__get_type_hash,
  &sfarm_interfaces__srv__Error_Event__get_type_description,
  &sfarm_interfaces__srv__Error_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sfarm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sfarm_interfaces, srv, Error_Event)() {
  sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sfarm_interfaces, srv, Error_Request)();
  sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sfarm_interfaces, srv, Error_Response)();
  if (!sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_message_type_support_handle.typesupport_identifier) {
    sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "sfarm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "sfarm_interfaces/srv/detail/error__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers sfarm_interfaces__srv__detail__error__rosidl_typesupport_introspection_c__Error_service_members = {
  "sfarm_interfaces__srv",  // service namespace
  "Error",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // sfarm_interfaces__srv__detail__error__rosidl_typesupport_introspection_c__Error_Request_message_type_support_handle,
  NULL,  // response message
  // sfarm_interfaces__srv__detail__error__rosidl_typesupport_introspection_c__Error_Response_message_type_support_handle
  NULL  // event_message
  // sfarm_interfaces__srv__detail__error__rosidl_typesupport_introspection_c__Error_Response_message_type_support_handle
};


static rosidl_service_type_support_t sfarm_interfaces__srv__detail__error__rosidl_typesupport_introspection_c__Error_service_type_support_handle = {
  0,
  &sfarm_interfaces__srv__detail__error__rosidl_typesupport_introspection_c__Error_service_members,
  get_service_typesupport_handle_function,
  &sfarm_interfaces__srv__Error_Request__rosidl_typesupport_introspection_c__Error_Request_message_type_support_handle,
  &sfarm_interfaces__srv__Error_Response__rosidl_typesupport_introspection_c__Error_Response_message_type_support_handle,
  &sfarm_interfaces__srv__Error_Event__rosidl_typesupport_introspection_c__Error_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    sfarm_interfaces,
    srv,
    Error
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    sfarm_interfaces,
    srv,
    Error
  ),
  &sfarm_interfaces__srv__Error__get_type_hash,
  &sfarm_interfaces__srv__Error__get_type_description,
  &sfarm_interfaces__srv__Error__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sfarm_interfaces, srv, Error_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sfarm_interfaces, srv, Error_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sfarm_interfaces, srv, Error_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sfarm_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sfarm_interfaces, srv, Error)(void) {
  if (!sfarm_interfaces__srv__detail__error__rosidl_typesupport_introspection_c__Error_service_type_support_handle.typesupport_identifier) {
    sfarm_interfaces__srv__detail__error__rosidl_typesupport_introspection_c__Error_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)sfarm_interfaces__srv__detail__error__rosidl_typesupport_introspection_c__Error_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sfarm_interfaces, srv, Error_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sfarm_interfaces, srv, Error_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sfarm_interfaces, srv, Error_Event)()->data;
  }

  return &sfarm_interfaces__srv__detail__error__rosidl_typesupport_introspection_c__Error_service_type_support_handle;
}
