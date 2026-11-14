// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from sfarm_interfaces:action/Insert.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "sfarm_interfaces/action/detail/insert__functions.h"
#include "sfarm_interfaces/action/detail/insert__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace sfarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Insert_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Insert_Goal_type_support_ids_t;

static const _Insert_Goal_type_support_ids_t _Insert_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Insert_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Insert_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Insert_Goal_type_support_symbol_names_t _Insert_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sfarm_interfaces, action, Insert_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sfarm_interfaces, action, Insert_Goal)),
  }
};

typedef struct _Insert_Goal_type_support_data_t
{
  void * data[2];
} _Insert_Goal_type_support_data_t;

static _Insert_Goal_type_support_data_t _Insert_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Insert_Goal_message_typesupport_map = {
  2,
  "sfarm_interfaces",
  &_Insert_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_Insert_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_Insert_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Insert_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Insert_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &sfarm_interfaces__action__Insert_Goal__get_type_hash,
  &sfarm_interfaces__action__Insert_Goal__get_type_description,
  &sfarm_interfaces__action__Insert_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<sfarm_interfaces::action::Insert_Goal>()
{
  return &::sfarm_interfaces::action::rosidl_typesupport_cpp::Insert_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, sfarm_interfaces, action, Insert_Goal)() {
  return get_message_type_support_handle<sfarm_interfaces::action::Insert_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__functions.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sfarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Insert_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Insert_Result_type_support_ids_t;

static const _Insert_Result_type_support_ids_t _Insert_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Insert_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Insert_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Insert_Result_type_support_symbol_names_t _Insert_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sfarm_interfaces, action, Insert_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sfarm_interfaces, action, Insert_Result)),
  }
};

typedef struct _Insert_Result_type_support_data_t
{
  void * data[2];
} _Insert_Result_type_support_data_t;

static _Insert_Result_type_support_data_t _Insert_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Insert_Result_message_typesupport_map = {
  2,
  "sfarm_interfaces",
  &_Insert_Result_message_typesupport_ids.typesupport_identifier[0],
  &_Insert_Result_message_typesupport_symbol_names.symbol_name[0],
  &_Insert_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Insert_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Insert_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &sfarm_interfaces__action__Insert_Result__get_type_hash,
  &sfarm_interfaces__action__Insert_Result__get_type_description,
  &sfarm_interfaces__action__Insert_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<sfarm_interfaces::action::Insert_Result>()
{
  return &::sfarm_interfaces::action::rosidl_typesupport_cpp::Insert_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, sfarm_interfaces, action, Insert_Result)() {
  return get_message_type_support_handle<sfarm_interfaces::action::Insert_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__functions.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sfarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Insert_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Insert_Feedback_type_support_ids_t;

static const _Insert_Feedback_type_support_ids_t _Insert_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Insert_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Insert_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Insert_Feedback_type_support_symbol_names_t _Insert_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sfarm_interfaces, action, Insert_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sfarm_interfaces, action, Insert_Feedback)),
  }
};

typedef struct _Insert_Feedback_type_support_data_t
{
  void * data[2];
} _Insert_Feedback_type_support_data_t;

static _Insert_Feedback_type_support_data_t _Insert_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Insert_Feedback_message_typesupport_map = {
  2,
  "sfarm_interfaces",
  &_Insert_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_Insert_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_Insert_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Insert_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Insert_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &sfarm_interfaces__action__Insert_Feedback__get_type_hash,
  &sfarm_interfaces__action__Insert_Feedback__get_type_description,
  &sfarm_interfaces__action__Insert_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<sfarm_interfaces::action::Insert_Feedback>()
{
  return &::sfarm_interfaces::action::rosidl_typesupport_cpp::Insert_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, sfarm_interfaces, action, Insert_Feedback)() {
  return get_message_type_support_handle<sfarm_interfaces::action::Insert_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__functions.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sfarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Insert_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Insert_SendGoal_Request_type_support_ids_t;

static const _Insert_SendGoal_Request_type_support_ids_t _Insert_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Insert_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Insert_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Insert_SendGoal_Request_type_support_symbol_names_t _Insert_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sfarm_interfaces, action, Insert_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sfarm_interfaces, action, Insert_SendGoal_Request)),
  }
};

typedef struct _Insert_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _Insert_SendGoal_Request_type_support_data_t;

static _Insert_SendGoal_Request_type_support_data_t _Insert_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Insert_SendGoal_Request_message_typesupport_map = {
  2,
  "sfarm_interfaces",
  &_Insert_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Insert_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Insert_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Insert_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Insert_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &sfarm_interfaces__action__Insert_SendGoal_Request__get_type_hash,
  &sfarm_interfaces__action__Insert_SendGoal_Request__get_type_description,
  &sfarm_interfaces__action__Insert_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<sfarm_interfaces::action::Insert_SendGoal_Request>()
{
  return &::sfarm_interfaces::action::rosidl_typesupport_cpp::Insert_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, sfarm_interfaces, action, Insert_SendGoal_Request)() {
  return get_message_type_support_handle<sfarm_interfaces::action::Insert_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__functions.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sfarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Insert_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Insert_SendGoal_Response_type_support_ids_t;

static const _Insert_SendGoal_Response_type_support_ids_t _Insert_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Insert_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Insert_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Insert_SendGoal_Response_type_support_symbol_names_t _Insert_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sfarm_interfaces, action, Insert_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sfarm_interfaces, action, Insert_SendGoal_Response)),
  }
};

typedef struct _Insert_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _Insert_SendGoal_Response_type_support_data_t;

static _Insert_SendGoal_Response_type_support_data_t _Insert_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Insert_SendGoal_Response_message_typesupport_map = {
  2,
  "sfarm_interfaces",
  &_Insert_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Insert_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Insert_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Insert_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Insert_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &sfarm_interfaces__action__Insert_SendGoal_Response__get_type_hash,
  &sfarm_interfaces__action__Insert_SendGoal_Response__get_type_description,
  &sfarm_interfaces__action__Insert_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<sfarm_interfaces::action::Insert_SendGoal_Response>()
{
  return &::sfarm_interfaces::action::rosidl_typesupport_cpp::Insert_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, sfarm_interfaces, action, Insert_SendGoal_Response)() {
  return get_message_type_support_handle<sfarm_interfaces::action::Insert_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__functions.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sfarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Insert_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Insert_SendGoal_Event_type_support_ids_t;

static const _Insert_SendGoal_Event_type_support_ids_t _Insert_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Insert_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Insert_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Insert_SendGoal_Event_type_support_symbol_names_t _Insert_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sfarm_interfaces, action, Insert_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sfarm_interfaces, action, Insert_SendGoal_Event)),
  }
};

typedef struct _Insert_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _Insert_SendGoal_Event_type_support_data_t;

static _Insert_SendGoal_Event_type_support_data_t _Insert_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Insert_SendGoal_Event_message_typesupport_map = {
  2,
  "sfarm_interfaces",
  &_Insert_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Insert_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Insert_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Insert_SendGoal_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Insert_SendGoal_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &sfarm_interfaces__action__Insert_SendGoal_Event__get_type_hash,
  &sfarm_interfaces__action__Insert_SendGoal_Event__get_type_description,
  &sfarm_interfaces__action__Insert_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<sfarm_interfaces::action::Insert_SendGoal_Event>()
{
  return &::sfarm_interfaces::action::rosidl_typesupport_cpp::Insert_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, sfarm_interfaces, action, Insert_SendGoal_Event)() {
  return get_message_type_support_handle<sfarm_interfaces::action::Insert_SendGoal_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "sfarm_interfaces/action/detail/insert__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sfarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Insert_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Insert_SendGoal_type_support_ids_t;

static const _Insert_SendGoal_type_support_ids_t _Insert_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Insert_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Insert_SendGoal_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Insert_SendGoal_type_support_symbol_names_t _Insert_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sfarm_interfaces, action, Insert_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sfarm_interfaces, action, Insert_SendGoal)),
  }
};

typedef struct _Insert_SendGoal_type_support_data_t
{
  void * data[2];
} _Insert_SendGoal_type_support_data_t;

static _Insert_SendGoal_type_support_data_t _Insert_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Insert_SendGoal_service_typesupport_map = {
  2,
  "sfarm_interfaces",
  &_Insert_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_Insert_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_Insert_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Insert_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Insert_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<sfarm_interfaces::action::Insert_SendGoal_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<sfarm_interfaces::action::Insert_SendGoal_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<sfarm_interfaces::action::Insert_SendGoal_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<sfarm_interfaces::action::Insert_SendGoal>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<sfarm_interfaces::action::Insert_SendGoal>,
  &sfarm_interfaces__action__Insert_SendGoal__get_type_hash,
  &sfarm_interfaces__action__Insert_SendGoal__get_type_description,
  &sfarm_interfaces__action__Insert_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<sfarm_interfaces::action::Insert_SendGoal>()
{
  return &::sfarm_interfaces::action::rosidl_typesupport_cpp::Insert_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, sfarm_interfaces, action, Insert_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<sfarm_interfaces::action::Insert_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__functions.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sfarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Insert_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Insert_GetResult_Request_type_support_ids_t;

static const _Insert_GetResult_Request_type_support_ids_t _Insert_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Insert_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Insert_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Insert_GetResult_Request_type_support_symbol_names_t _Insert_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sfarm_interfaces, action, Insert_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sfarm_interfaces, action, Insert_GetResult_Request)),
  }
};

typedef struct _Insert_GetResult_Request_type_support_data_t
{
  void * data[2];
} _Insert_GetResult_Request_type_support_data_t;

static _Insert_GetResult_Request_type_support_data_t _Insert_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Insert_GetResult_Request_message_typesupport_map = {
  2,
  "sfarm_interfaces",
  &_Insert_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Insert_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Insert_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Insert_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Insert_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &sfarm_interfaces__action__Insert_GetResult_Request__get_type_hash,
  &sfarm_interfaces__action__Insert_GetResult_Request__get_type_description,
  &sfarm_interfaces__action__Insert_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<sfarm_interfaces::action::Insert_GetResult_Request>()
{
  return &::sfarm_interfaces::action::rosidl_typesupport_cpp::Insert_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, sfarm_interfaces, action, Insert_GetResult_Request)() {
  return get_message_type_support_handle<sfarm_interfaces::action::Insert_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__functions.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sfarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Insert_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Insert_GetResult_Response_type_support_ids_t;

static const _Insert_GetResult_Response_type_support_ids_t _Insert_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Insert_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Insert_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Insert_GetResult_Response_type_support_symbol_names_t _Insert_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sfarm_interfaces, action, Insert_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sfarm_interfaces, action, Insert_GetResult_Response)),
  }
};

typedef struct _Insert_GetResult_Response_type_support_data_t
{
  void * data[2];
} _Insert_GetResult_Response_type_support_data_t;

static _Insert_GetResult_Response_type_support_data_t _Insert_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Insert_GetResult_Response_message_typesupport_map = {
  2,
  "sfarm_interfaces",
  &_Insert_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Insert_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Insert_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Insert_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Insert_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &sfarm_interfaces__action__Insert_GetResult_Response__get_type_hash,
  &sfarm_interfaces__action__Insert_GetResult_Response__get_type_description,
  &sfarm_interfaces__action__Insert_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<sfarm_interfaces::action::Insert_GetResult_Response>()
{
  return &::sfarm_interfaces::action::rosidl_typesupport_cpp::Insert_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, sfarm_interfaces, action, Insert_GetResult_Response)() {
  return get_message_type_support_handle<sfarm_interfaces::action::Insert_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__functions.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sfarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Insert_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Insert_GetResult_Event_type_support_ids_t;

static const _Insert_GetResult_Event_type_support_ids_t _Insert_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Insert_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Insert_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Insert_GetResult_Event_type_support_symbol_names_t _Insert_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sfarm_interfaces, action, Insert_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sfarm_interfaces, action, Insert_GetResult_Event)),
  }
};

typedef struct _Insert_GetResult_Event_type_support_data_t
{
  void * data[2];
} _Insert_GetResult_Event_type_support_data_t;

static _Insert_GetResult_Event_type_support_data_t _Insert_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Insert_GetResult_Event_message_typesupport_map = {
  2,
  "sfarm_interfaces",
  &_Insert_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Insert_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Insert_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Insert_GetResult_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Insert_GetResult_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &sfarm_interfaces__action__Insert_GetResult_Event__get_type_hash,
  &sfarm_interfaces__action__Insert_GetResult_Event__get_type_description,
  &sfarm_interfaces__action__Insert_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<sfarm_interfaces::action::Insert_GetResult_Event>()
{
  return &::sfarm_interfaces::action::rosidl_typesupport_cpp::Insert_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, sfarm_interfaces, action, Insert_GetResult_Event)() {
  return get_message_type_support_handle<sfarm_interfaces::action::Insert_GetResult_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "sfarm_interfaces/action/detail/insert__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sfarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Insert_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Insert_GetResult_type_support_ids_t;

static const _Insert_GetResult_type_support_ids_t _Insert_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Insert_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Insert_GetResult_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Insert_GetResult_type_support_symbol_names_t _Insert_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sfarm_interfaces, action, Insert_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sfarm_interfaces, action, Insert_GetResult)),
  }
};

typedef struct _Insert_GetResult_type_support_data_t
{
  void * data[2];
} _Insert_GetResult_type_support_data_t;

static _Insert_GetResult_type_support_data_t _Insert_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Insert_GetResult_service_typesupport_map = {
  2,
  "sfarm_interfaces",
  &_Insert_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_Insert_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_Insert_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Insert_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Insert_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<sfarm_interfaces::action::Insert_GetResult_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<sfarm_interfaces::action::Insert_GetResult_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<sfarm_interfaces::action::Insert_GetResult_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<sfarm_interfaces::action::Insert_GetResult>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<sfarm_interfaces::action::Insert_GetResult>,
  &sfarm_interfaces__action__Insert_GetResult__get_type_hash,
  &sfarm_interfaces__action__Insert_GetResult__get_type_description,
  &sfarm_interfaces__action__Insert_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<sfarm_interfaces::action::Insert_GetResult>()
{
  return &::sfarm_interfaces::action::rosidl_typesupport_cpp::Insert_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, sfarm_interfaces, action, Insert_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<sfarm_interfaces::action::Insert_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__functions.h"
// already included above
// #include "sfarm_interfaces/action/detail/insert__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace sfarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Insert_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Insert_FeedbackMessage_type_support_ids_t;

static const _Insert_FeedbackMessage_type_support_ids_t _Insert_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Insert_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Insert_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Insert_FeedbackMessage_type_support_symbol_names_t _Insert_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sfarm_interfaces, action, Insert_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, sfarm_interfaces, action, Insert_FeedbackMessage)),
  }
};

typedef struct _Insert_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _Insert_FeedbackMessage_type_support_data_t;

static _Insert_FeedbackMessage_type_support_data_t _Insert_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Insert_FeedbackMessage_message_typesupport_map = {
  2,
  "sfarm_interfaces",
  &_Insert_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_Insert_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_Insert_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Insert_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Insert_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &sfarm_interfaces__action__Insert_FeedbackMessage__get_type_hash,
  &sfarm_interfaces__action__Insert_FeedbackMessage__get_type_description,
  &sfarm_interfaces__action__Insert_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<sfarm_interfaces::action::Insert_FeedbackMessage>()
{
  return &::sfarm_interfaces::action::rosidl_typesupport_cpp::Insert_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, sfarm_interfaces, action, Insert_FeedbackMessage)() {
  return get_message_type_support_handle<sfarm_interfaces::action::Insert_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "sfarm_interfaces/action/detail/insert__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace sfarm_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t Insert_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL,
  &sfarm_interfaces__action__Insert__get_type_hash,
  &sfarm_interfaces__action__Insert__get_type_description,
  &sfarm_interfaces__action__Insert__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace sfarm_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<sfarm_interfaces::action::Insert>()
{
  using ::sfarm_interfaces::action::rosidl_typesupport_cpp::Insert_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  Insert_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::sfarm_interfaces::action::Insert::Impl::SendGoalService>();
  Insert_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::sfarm_interfaces::action::Insert::Impl::GetResultService>();
  Insert_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::sfarm_interfaces::action::Insert::Impl::CancelGoalService>();
  Insert_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::sfarm_interfaces::action::Insert::Impl::FeedbackMessage>();
  Insert_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::sfarm_interfaces::action::Insert::Impl::GoalStatusMessage>();
  return &Insert_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, sfarm_interfaces, action, Insert)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<sfarm_interfaces::action::Insert>();
}

#ifdef __cplusplus
}
#endif
