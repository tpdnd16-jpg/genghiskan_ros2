// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sfarm_interfaces:action/Insert.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "sfarm_interfaces/action/insert.h"


#ifndef SFARM_INTERFACES__ACTION__DETAIL__INSERT__STRUCT_H_
#define SFARM_INTERFACES__ACTION__DETAIL__INSERT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Insert in the package sfarm_interfaces.
typedef struct sfarm_interfaces__action__Insert_Goal
{
  int8_t work_id;
  int8_t start_pos_id;
  int8_t pos_3d_id;
} sfarm_interfaces__action__Insert_Goal;

// Struct for a sequence of sfarm_interfaces__action__Insert_Goal.
typedef struct sfarm_interfaces__action__Insert_Goal__Sequence
{
  sfarm_interfaces__action__Insert_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sfarm_interfaces__action__Insert_Goal__Sequence;

// Constants defined in the message

/// Constant 'WORK_TYPE_INSERT'.
enum
{
  sfarm_interfaces__action__Insert_Result__WORK_TYPE_INSERT = 0
};

/// Constant 'WORK_TYPE_EJECT'.
enum
{
  sfarm_interfaces__action__Insert_Result__WORK_TYPE_EJECT = 1
};

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Insert in the package sfarm_interfaces.
typedef struct sfarm_interfaces__action__Insert_Result
{
  bool success;
  rosidl_runtime_c__String message;
  int8_t work_id;
  uint8_t work_type;
} sfarm_interfaces__action__Insert_Result;

// Struct for a sequence of sfarm_interfaces__action__Insert_Result.
typedef struct sfarm_interfaces__action__Insert_Result__Sequence
{
  sfarm_interfaces__action__Insert_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sfarm_interfaces__action__Insert_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'start_at'
// Member 'end_at'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Insert in the package sfarm_interfaces.
typedef struct sfarm_interfaces__action__Insert_Feedback
{
  builtin_interfaces__msg__Time start_at;
  builtin_interfaces__msg__Time end_at;
  int8_t work_id;
} sfarm_interfaces__action__Insert_Feedback;

// Struct for a sequence of sfarm_interfaces__action__Insert_Feedback.
typedef struct sfarm_interfaces__action__Insert_Feedback__Sequence
{
  sfarm_interfaces__action__Insert_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sfarm_interfaces__action__Insert_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "sfarm_interfaces/action/detail/insert__struct.h"

/// Struct defined in action/Insert in the package sfarm_interfaces.
typedef struct sfarm_interfaces__action__Insert_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  sfarm_interfaces__action__Insert_Goal goal;
} sfarm_interfaces__action__Insert_SendGoal_Request;

// Struct for a sequence of sfarm_interfaces__action__Insert_SendGoal_Request.
typedef struct sfarm_interfaces__action__Insert_SendGoal_Request__Sequence
{
  sfarm_interfaces__action__Insert_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sfarm_interfaces__action__Insert_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
// already included above
// #include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Insert in the package sfarm_interfaces.
typedef struct sfarm_interfaces__action__Insert_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} sfarm_interfaces__action__Insert_SendGoal_Response;

// Struct for a sequence of sfarm_interfaces__action__Insert_SendGoal_Response.
typedef struct sfarm_interfaces__action__Insert_SendGoal_Response__Sequence
{
  sfarm_interfaces__action__Insert_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sfarm_interfaces__action__Insert_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  sfarm_interfaces__action__Insert_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  sfarm_interfaces__action__Insert_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Insert in the package sfarm_interfaces.
typedef struct sfarm_interfaces__action__Insert_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  sfarm_interfaces__action__Insert_SendGoal_Request__Sequence request;
  sfarm_interfaces__action__Insert_SendGoal_Response__Sequence response;
} sfarm_interfaces__action__Insert_SendGoal_Event;

// Struct for a sequence of sfarm_interfaces__action__Insert_SendGoal_Event.
typedef struct sfarm_interfaces__action__Insert_SendGoal_Event__Sequence
{
  sfarm_interfaces__action__Insert_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sfarm_interfaces__action__Insert_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Insert in the package sfarm_interfaces.
typedef struct sfarm_interfaces__action__Insert_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} sfarm_interfaces__action__Insert_GetResult_Request;

// Struct for a sequence of sfarm_interfaces__action__Insert_GetResult_Request.
typedef struct sfarm_interfaces__action__Insert_GetResult_Request__Sequence
{
  sfarm_interfaces__action__Insert_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sfarm_interfaces__action__Insert_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "sfarm_interfaces/action/detail/insert__struct.h"

/// Struct defined in action/Insert in the package sfarm_interfaces.
typedef struct sfarm_interfaces__action__Insert_GetResult_Response
{
  int8_t status;
  sfarm_interfaces__action__Insert_Result result;
} sfarm_interfaces__action__Insert_GetResult_Response;

// Struct for a sequence of sfarm_interfaces__action__Insert_GetResult_Response.
typedef struct sfarm_interfaces__action__Insert_GetResult_Response__Sequence
{
  sfarm_interfaces__action__Insert_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sfarm_interfaces__action__Insert_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  sfarm_interfaces__action__Insert_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  sfarm_interfaces__action__Insert_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Insert in the package sfarm_interfaces.
typedef struct sfarm_interfaces__action__Insert_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  sfarm_interfaces__action__Insert_GetResult_Request__Sequence request;
  sfarm_interfaces__action__Insert_GetResult_Response__Sequence response;
} sfarm_interfaces__action__Insert_GetResult_Event;

// Struct for a sequence of sfarm_interfaces__action__Insert_GetResult_Event.
typedef struct sfarm_interfaces__action__Insert_GetResult_Event__Sequence
{
  sfarm_interfaces__action__Insert_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sfarm_interfaces__action__Insert_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "sfarm_interfaces/action/detail/insert__struct.h"

/// Struct defined in action/Insert in the package sfarm_interfaces.
typedef struct sfarm_interfaces__action__Insert_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  sfarm_interfaces__action__Insert_Feedback feedback;
} sfarm_interfaces__action__Insert_FeedbackMessage;

// Struct for a sequence of sfarm_interfaces__action__Insert_FeedbackMessage.
typedef struct sfarm_interfaces__action__Insert_FeedbackMessage__Sequence
{
  sfarm_interfaces__action__Insert_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sfarm_interfaces__action__Insert_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SFARM_INTERFACES__ACTION__DETAIL__INSERT__STRUCT_H_
