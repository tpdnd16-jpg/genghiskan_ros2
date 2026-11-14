// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sfarm_interfaces:action/Eject.idl
// generated code does not contain a copyright notice
#include "sfarm_interfaces/action/detail/eject__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
sfarm_interfaces__action__Eject_Goal__init(sfarm_interfaces__action__Eject_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // work_id
  // pos_3d_id
  // receive_pos_id
  return true;
}

void
sfarm_interfaces__action__Eject_Goal__fini(sfarm_interfaces__action__Eject_Goal * msg)
{
  if (!msg) {
    return;
  }
  // work_id
  // pos_3d_id
  // receive_pos_id
}

bool
sfarm_interfaces__action__Eject_Goal__are_equal(const sfarm_interfaces__action__Eject_Goal * lhs, const sfarm_interfaces__action__Eject_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // work_id
  if (lhs->work_id != rhs->work_id) {
    return false;
  }
  // pos_3d_id
  if (lhs->pos_3d_id != rhs->pos_3d_id) {
    return false;
  }
  // receive_pos_id
  if (lhs->receive_pos_id != rhs->receive_pos_id) {
    return false;
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_Goal__copy(
  const sfarm_interfaces__action__Eject_Goal * input,
  sfarm_interfaces__action__Eject_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // work_id
  output->work_id = input->work_id;
  // pos_3d_id
  output->pos_3d_id = input->pos_3d_id;
  // receive_pos_id
  output->receive_pos_id = input->receive_pos_id;
  return true;
}

sfarm_interfaces__action__Eject_Goal *
sfarm_interfaces__action__Eject_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_Goal * msg = (sfarm_interfaces__action__Eject_Goal *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sfarm_interfaces__action__Eject_Goal));
  bool success = sfarm_interfaces__action__Eject_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sfarm_interfaces__action__Eject_Goal__destroy(sfarm_interfaces__action__Eject_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sfarm_interfaces__action__Eject_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sfarm_interfaces__action__Eject_Goal__Sequence__init(sfarm_interfaces__action__Eject_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_Goal * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_Goal)) {
      return false;
    }
    data = (sfarm_interfaces__action__Eject_Goal *)allocator.zero_allocate(size, sizeof(sfarm_interfaces__action__Eject_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sfarm_interfaces__action__Eject_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sfarm_interfaces__action__Eject_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sfarm_interfaces__action__Eject_Goal__Sequence__fini(sfarm_interfaces__action__Eject_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sfarm_interfaces__action__Eject_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sfarm_interfaces__action__Eject_Goal__Sequence *
sfarm_interfaces__action__Eject_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_Goal__Sequence * array = (sfarm_interfaces__action__Eject_Goal__Sequence *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sfarm_interfaces__action__Eject_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sfarm_interfaces__action__Eject_Goal__Sequence__destroy(sfarm_interfaces__action__Eject_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sfarm_interfaces__action__Eject_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sfarm_interfaces__action__Eject_Goal__Sequence__are_equal(const sfarm_interfaces__action__Eject_Goal__Sequence * lhs, const sfarm_interfaces__action__Eject_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sfarm_interfaces__action__Eject_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_Goal__Sequence__copy(
  const sfarm_interfaces__action__Eject_Goal__Sequence * input,
  sfarm_interfaces__action__Eject_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_Goal)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(sfarm_interfaces__action__Eject_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sfarm_interfaces__action__Eject_Goal * data =
      (sfarm_interfaces__action__Eject_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sfarm_interfaces__action__Eject_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sfarm_interfaces__action__Eject_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sfarm_interfaces__action__Eject_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
sfarm_interfaces__action__Eject_Result__init(sfarm_interfaces__action__Eject_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    sfarm_interfaces__action__Eject_Result__fini(msg);
    return false;
  }
  // work_id
  // work_type
  return true;
}

void
sfarm_interfaces__action__Eject_Result__fini(sfarm_interfaces__action__Eject_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // work_id
  // work_type
}

bool
sfarm_interfaces__action__Eject_Result__are_equal(const sfarm_interfaces__action__Eject_Result * lhs, const sfarm_interfaces__action__Eject_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // work_id
  if (lhs->work_id != rhs->work_id) {
    return false;
  }
  // work_type
  if (lhs->work_type != rhs->work_type) {
    return false;
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_Result__copy(
  const sfarm_interfaces__action__Eject_Result * input,
  sfarm_interfaces__action__Eject_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // work_id
  output->work_id = input->work_id;
  // work_type
  output->work_type = input->work_type;
  return true;
}

sfarm_interfaces__action__Eject_Result *
sfarm_interfaces__action__Eject_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_Result * msg = (sfarm_interfaces__action__Eject_Result *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sfarm_interfaces__action__Eject_Result));
  bool success = sfarm_interfaces__action__Eject_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sfarm_interfaces__action__Eject_Result__destroy(sfarm_interfaces__action__Eject_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sfarm_interfaces__action__Eject_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sfarm_interfaces__action__Eject_Result__Sequence__init(sfarm_interfaces__action__Eject_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_Result * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_Result)) {
      return false;
    }
    data = (sfarm_interfaces__action__Eject_Result *)allocator.zero_allocate(size, sizeof(sfarm_interfaces__action__Eject_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sfarm_interfaces__action__Eject_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sfarm_interfaces__action__Eject_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sfarm_interfaces__action__Eject_Result__Sequence__fini(sfarm_interfaces__action__Eject_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sfarm_interfaces__action__Eject_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sfarm_interfaces__action__Eject_Result__Sequence *
sfarm_interfaces__action__Eject_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_Result__Sequence * array = (sfarm_interfaces__action__Eject_Result__Sequence *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sfarm_interfaces__action__Eject_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sfarm_interfaces__action__Eject_Result__Sequence__destroy(sfarm_interfaces__action__Eject_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sfarm_interfaces__action__Eject_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sfarm_interfaces__action__Eject_Result__Sequence__are_equal(const sfarm_interfaces__action__Eject_Result__Sequence * lhs, const sfarm_interfaces__action__Eject_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sfarm_interfaces__action__Eject_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_Result__Sequence__copy(
  const sfarm_interfaces__action__Eject_Result__Sequence * input,
  sfarm_interfaces__action__Eject_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_Result)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(sfarm_interfaces__action__Eject_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sfarm_interfaces__action__Eject_Result * data =
      (sfarm_interfaces__action__Eject_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sfarm_interfaces__action__Eject_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sfarm_interfaces__action__Eject_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sfarm_interfaces__action__Eject_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `start_at`
// Member `end_at`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
sfarm_interfaces__action__Eject_Feedback__init(sfarm_interfaces__action__Eject_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // start_at
  if (!builtin_interfaces__msg__Time__init(&msg->start_at)) {
    sfarm_interfaces__action__Eject_Feedback__fini(msg);
    return false;
  }
  // end_at
  if (!builtin_interfaces__msg__Time__init(&msg->end_at)) {
    sfarm_interfaces__action__Eject_Feedback__fini(msg);
    return false;
  }
  // work_id
  return true;
}

void
sfarm_interfaces__action__Eject_Feedback__fini(sfarm_interfaces__action__Eject_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // start_at
  builtin_interfaces__msg__Time__fini(&msg->start_at);
  // end_at
  builtin_interfaces__msg__Time__fini(&msg->end_at);
  // work_id
}

bool
sfarm_interfaces__action__Eject_Feedback__are_equal(const sfarm_interfaces__action__Eject_Feedback * lhs, const sfarm_interfaces__action__Eject_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // start_at
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->start_at), &(rhs->start_at)))
  {
    return false;
  }
  // end_at
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->end_at), &(rhs->end_at)))
  {
    return false;
  }
  // work_id
  if (lhs->work_id != rhs->work_id) {
    return false;
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_Feedback__copy(
  const sfarm_interfaces__action__Eject_Feedback * input,
  sfarm_interfaces__action__Eject_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // start_at
  if (!builtin_interfaces__msg__Time__copy(
      &(input->start_at), &(output->start_at)))
  {
    return false;
  }
  // end_at
  if (!builtin_interfaces__msg__Time__copy(
      &(input->end_at), &(output->end_at)))
  {
    return false;
  }
  // work_id
  output->work_id = input->work_id;
  return true;
}

sfarm_interfaces__action__Eject_Feedback *
sfarm_interfaces__action__Eject_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_Feedback * msg = (sfarm_interfaces__action__Eject_Feedback *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sfarm_interfaces__action__Eject_Feedback));
  bool success = sfarm_interfaces__action__Eject_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sfarm_interfaces__action__Eject_Feedback__destroy(sfarm_interfaces__action__Eject_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sfarm_interfaces__action__Eject_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sfarm_interfaces__action__Eject_Feedback__Sequence__init(sfarm_interfaces__action__Eject_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_Feedback * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_Feedback)) {
      return false;
    }
    data = (sfarm_interfaces__action__Eject_Feedback *)allocator.zero_allocate(size, sizeof(sfarm_interfaces__action__Eject_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sfarm_interfaces__action__Eject_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sfarm_interfaces__action__Eject_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sfarm_interfaces__action__Eject_Feedback__Sequence__fini(sfarm_interfaces__action__Eject_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sfarm_interfaces__action__Eject_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sfarm_interfaces__action__Eject_Feedback__Sequence *
sfarm_interfaces__action__Eject_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_Feedback__Sequence * array = (sfarm_interfaces__action__Eject_Feedback__Sequence *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sfarm_interfaces__action__Eject_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sfarm_interfaces__action__Eject_Feedback__Sequence__destroy(sfarm_interfaces__action__Eject_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sfarm_interfaces__action__Eject_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sfarm_interfaces__action__Eject_Feedback__Sequence__are_equal(const sfarm_interfaces__action__Eject_Feedback__Sequence * lhs, const sfarm_interfaces__action__Eject_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sfarm_interfaces__action__Eject_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_Feedback__Sequence__copy(
  const sfarm_interfaces__action__Eject_Feedback__Sequence * input,
  sfarm_interfaces__action__Eject_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_Feedback)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(sfarm_interfaces__action__Eject_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sfarm_interfaces__action__Eject_Feedback * data =
      (sfarm_interfaces__action__Eject_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sfarm_interfaces__action__Eject_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sfarm_interfaces__action__Eject_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sfarm_interfaces__action__Eject_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "sfarm_interfaces/action/detail/eject__functions.h"

bool
sfarm_interfaces__action__Eject_SendGoal_Request__init(sfarm_interfaces__action__Eject_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    sfarm_interfaces__action__Eject_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!sfarm_interfaces__action__Eject_Goal__init(&msg->goal)) {
    sfarm_interfaces__action__Eject_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
sfarm_interfaces__action__Eject_SendGoal_Request__fini(sfarm_interfaces__action__Eject_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  sfarm_interfaces__action__Eject_Goal__fini(&msg->goal);
}

bool
sfarm_interfaces__action__Eject_SendGoal_Request__are_equal(const sfarm_interfaces__action__Eject_SendGoal_Request * lhs, const sfarm_interfaces__action__Eject_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!sfarm_interfaces__action__Eject_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_SendGoal_Request__copy(
  const sfarm_interfaces__action__Eject_SendGoal_Request * input,
  sfarm_interfaces__action__Eject_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!sfarm_interfaces__action__Eject_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

sfarm_interfaces__action__Eject_SendGoal_Request *
sfarm_interfaces__action__Eject_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_SendGoal_Request * msg = (sfarm_interfaces__action__Eject_SendGoal_Request *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sfarm_interfaces__action__Eject_SendGoal_Request));
  bool success = sfarm_interfaces__action__Eject_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sfarm_interfaces__action__Eject_SendGoal_Request__destroy(sfarm_interfaces__action__Eject_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sfarm_interfaces__action__Eject_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__init(sfarm_interfaces__action__Eject_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_SendGoal_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_SendGoal_Request)) {
      return false;
    }
    data = (sfarm_interfaces__action__Eject_SendGoal_Request *)allocator.zero_allocate(size, sizeof(sfarm_interfaces__action__Eject_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sfarm_interfaces__action__Eject_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sfarm_interfaces__action__Eject_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__fini(sfarm_interfaces__action__Eject_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sfarm_interfaces__action__Eject_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sfarm_interfaces__action__Eject_SendGoal_Request__Sequence *
sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_SendGoal_Request__Sequence * array = (sfarm_interfaces__action__Eject_SendGoal_Request__Sequence *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__destroy(sfarm_interfaces__action__Eject_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__are_equal(const sfarm_interfaces__action__Eject_SendGoal_Request__Sequence * lhs, const sfarm_interfaces__action__Eject_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sfarm_interfaces__action__Eject_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__copy(
  const sfarm_interfaces__action__Eject_SendGoal_Request__Sequence * input,
  sfarm_interfaces__action__Eject_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_SendGoal_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(sfarm_interfaces__action__Eject_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sfarm_interfaces__action__Eject_SendGoal_Request * data =
      (sfarm_interfaces__action__Eject_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sfarm_interfaces__action__Eject_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sfarm_interfaces__action__Eject_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sfarm_interfaces__action__Eject_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
// already included above
// #include "builtin_interfaces/msg/detail/time__functions.h"

bool
sfarm_interfaces__action__Eject_SendGoal_Response__init(sfarm_interfaces__action__Eject_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    sfarm_interfaces__action__Eject_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
sfarm_interfaces__action__Eject_SendGoal_Response__fini(sfarm_interfaces__action__Eject_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
sfarm_interfaces__action__Eject_SendGoal_Response__are_equal(const sfarm_interfaces__action__Eject_SendGoal_Response * lhs, const sfarm_interfaces__action__Eject_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_SendGoal_Response__copy(
  const sfarm_interfaces__action__Eject_SendGoal_Response * input,
  sfarm_interfaces__action__Eject_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

sfarm_interfaces__action__Eject_SendGoal_Response *
sfarm_interfaces__action__Eject_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_SendGoal_Response * msg = (sfarm_interfaces__action__Eject_SendGoal_Response *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sfarm_interfaces__action__Eject_SendGoal_Response));
  bool success = sfarm_interfaces__action__Eject_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sfarm_interfaces__action__Eject_SendGoal_Response__destroy(sfarm_interfaces__action__Eject_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sfarm_interfaces__action__Eject_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__init(sfarm_interfaces__action__Eject_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_SendGoal_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_SendGoal_Response)) {
      return false;
    }
    data = (sfarm_interfaces__action__Eject_SendGoal_Response *)allocator.zero_allocate(size, sizeof(sfarm_interfaces__action__Eject_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sfarm_interfaces__action__Eject_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sfarm_interfaces__action__Eject_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__fini(sfarm_interfaces__action__Eject_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sfarm_interfaces__action__Eject_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sfarm_interfaces__action__Eject_SendGoal_Response__Sequence *
sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_SendGoal_Response__Sequence * array = (sfarm_interfaces__action__Eject_SendGoal_Response__Sequence *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__destroy(sfarm_interfaces__action__Eject_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__are_equal(const sfarm_interfaces__action__Eject_SendGoal_Response__Sequence * lhs, const sfarm_interfaces__action__Eject_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sfarm_interfaces__action__Eject_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__copy(
  const sfarm_interfaces__action__Eject_SendGoal_Response__Sequence * input,
  sfarm_interfaces__action__Eject_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_SendGoal_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(sfarm_interfaces__action__Eject_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sfarm_interfaces__action__Eject_SendGoal_Response * data =
      (sfarm_interfaces__action__Eject_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sfarm_interfaces__action__Eject_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sfarm_interfaces__action__Eject_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sfarm_interfaces__action__Eject_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "sfarm_interfaces/action/detail/eject__functions.h"

bool
sfarm_interfaces__action__Eject_SendGoal_Event__init(sfarm_interfaces__action__Eject_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    sfarm_interfaces__action__Eject_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    sfarm_interfaces__action__Eject_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    sfarm_interfaces__action__Eject_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
sfarm_interfaces__action__Eject_SendGoal_Event__fini(sfarm_interfaces__action__Eject_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
sfarm_interfaces__action__Eject_SendGoal_Event__are_equal(const sfarm_interfaces__action__Eject_SendGoal_Event * lhs, const sfarm_interfaces__action__Eject_SendGoal_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_SendGoal_Event__copy(
  const sfarm_interfaces__action__Eject_SendGoal_Event * input,
  sfarm_interfaces__action__Eject_SendGoal_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!sfarm_interfaces__action__Eject_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!sfarm_interfaces__action__Eject_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

sfarm_interfaces__action__Eject_SendGoal_Event *
sfarm_interfaces__action__Eject_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_SendGoal_Event * msg = (sfarm_interfaces__action__Eject_SendGoal_Event *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sfarm_interfaces__action__Eject_SendGoal_Event));
  bool success = sfarm_interfaces__action__Eject_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sfarm_interfaces__action__Eject_SendGoal_Event__destroy(sfarm_interfaces__action__Eject_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sfarm_interfaces__action__Eject_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sfarm_interfaces__action__Eject_SendGoal_Event__Sequence__init(sfarm_interfaces__action__Eject_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_SendGoal_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_SendGoal_Event)) {
      return false;
    }
    data = (sfarm_interfaces__action__Eject_SendGoal_Event *)allocator.zero_allocate(size, sizeof(sfarm_interfaces__action__Eject_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sfarm_interfaces__action__Eject_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sfarm_interfaces__action__Eject_SendGoal_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sfarm_interfaces__action__Eject_SendGoal_Event__Sequence__fini(sfarm_interfaces__action__Eject_SendGoal_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sfarm_interfaces__action__Eject_SendGoal_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sfarm_interfaces__action__Eject_SendGoal_Event__Sequence *
sfarm_interfaces__action__Eject_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_SendGoal_Event__Sequence * array = (sfarm_interfaces__action__Eject_SendGoal_Event__Sequence *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sfarm_interfaces__action__Eject_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sfarm_interfaces__action__Eject_SendGoal_Event__Sequence__destroy(sfarm_interfaces__action__Eject_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sfarm_interfaces__action__Eject_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sfarm_interfaces__action__Eject_SendGoal_Event__Sequence__are_equal(const sfarm_interfaces__action__Eject_SendGoal_Event__Sequence * lhs, const sfarm_interfaces__action__Eject_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sfarm_interfaces__action__Eject_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_SendGoal_Event__Sequence__copy(
  const sfarm_interfaces__action__Eject_SendGoal_Event__Sequence * input,
  sfarm_interfaces__action__Eject_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_SendGoal_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(sfarm_interfaces__action__Eject_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sfarm_interfaces__action__Eject_SendGoal_Event * data =
      (sfarm_interfaces__action__Eject_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sfarm_interfaces__action__Eject_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sfarm_interfaces__action__Eject_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sfarm_interfaces__action__Eject_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
sfarm_interfaces__action__Eject_GetResult_Request__init(sfarm_interfaces__action__Eject_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    sfarm_interfaces__action__Eject_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
sfarm_interfaces__action__Eject_GetResult_Request__fini(sfarm_interfaces__action__Eject_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
sfarm_interfaces__action__Eject_GetResult_Request__are_equal(const sfarm_interfaces__action__Eject_GetResult_Request * lhs, const sfarm_interfaces__action__Eject_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_GetResult_Request__copy(
  const sfarm_interfaces__action__Eject_GetResult_Request * input,
  sfarm_interfaces__action__Eject_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

sfarm_interfaces__action__Eject_GetResult_Request *
sfarm_interfaces__action__Eject_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_GetResult_Request * msg = (sfarm_interfaces__action__Eject_GetResult_Request *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sfarm_interfaces__action__Eject_GetResult_Request));
  bool success = sfarm_interfaces__action__Eject_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sfarm_interfaces__action__Eject_GetResult_Request__destroy(sfarm_interfaces__action__Eject_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sfarm_interfaces__action__Eject_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sfarm_interfaces__action__Eject_GetResult_Request__Sequence__init(sfarm_interfaces__action__Eject_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_GetResult_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_GetResult_Request)) {
      return false;
    }
    data = (sfarm_interfaces__action__Eject_GetResult_Request *)allocator.zero_allocate(size, sizeof(sfarm_interfaces__action__Eject_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sfarm_interfaces__action__Eject_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sfarm_interfaces__action__Eject_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sfarm_interfaces__action__Eject_GetResult_Request__Sequence__fini(sfarm_interfaces__action__Eject_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sfarm_interfaces__action__Eject_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sfarm_interfaces__action__Eject_GetResult_Request__Sequence *
sfarm_interfaces__action__Eject_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_GetResult_Request__Sequence * array = (sfarm_interfaces__action__Eject_GetResult_Request__Sequence *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sfarm_interfaces__action__Eject_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sfarm_interfaces__action__Eject_GetResult_Request__Sequence__destroy(sfarm_interfaces__action__Eject_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sfarm_interfaces__action__Eject_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sfarm_interfaces__action__Eject_GetResult_Request__Sequence__are_equal(const sfarm_interfaces__action__Eject_GetResult_Request__Sequence * lhs, const sfarm_interfaces__action__Eject_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sfarm_interfaces__action__Eject_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_GetResult_Request__Sequence__copy(
  const sfarm_interfaces__action__Eject_GetResult_Request__Sequence * input,
  sfarm_interfaces__action__Eject_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_GetResult_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(sfarm_interfaces__action__Eject_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sfarm_interfaces__action__Eject_GetResult_Request * data =
      (sfarm_interfaces__action__Eject_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sfarm_interfaces__action__Eject_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sfarm_interfaces__action__Eject_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sfarm_interfaces__action__Eject_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "sfarm_interfaces/action/detail/eject__functions.h"

bool
sfarm_interfaces__action__Eject_GetResult_Response__init(sfarm_interfaces__action__Eject_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!sfarm_interfaces__action__Eject_Result__init(&msg->result)) {
    sfarm_interfaces__action__Eject_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
sfarm_interfaces__action__Eject_GetResult_Response__fini(sfarm_interfaces__action__Eject_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  sfarm_interfaces__action__Eject_Result__fini(&msg->result);
}

bool
sfarm_interfaces__action__Eject_GetResult_Response__are_equal(const sfarm_interfaces__action__Eject_GetResult_Response * lhs, const sfarm_interfaces__action__Eject_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!sfarm_interfaces__action__Eject_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_GetResult_Response__copy(
  const sfarm_interfaces__action__Eject_GetResult_Response * input,
  sfarm_interfaces__action__Eject_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!sfarm_interfaces__action__Eject_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

sfarm_interfaces__action__Eject_GetResult_Response *
sfarm_interfaces__action__Eject_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_GetResult_Response * msg = (sfarm_interfaces__action__Eject_GetResult_Response *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sfarm_interfaces__action__Eject_GetResult_Response));
  bool success = sfarm_interfaces__action__Eject_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sfarm_interfaces__action__Eject_GetResult_Response__destroy(sfarm_interfaces__action__Eject_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sfarm_interfaces__action__Eject_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sfarm_interfaces__action__Eject_GetResult_Response__Sequence__init(sfarm_interfaces__action__Eject_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_GetResult_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_GetResult_Response)) {
      return false;
    }
    data = (sfarm_interfaces__action__Eject_GetResult_Response *)allocator.zero_allocate(size, sizeof(sfarm_interfaces__action__Eject_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sfarm_interfaces__action__Eject_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sfarm_interfaces__action__Eject_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sfarm_interfaces__action__Eject_GetResult_Response__Sequence__fini(sfarm_interfaces__action__Eject_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sfarm_interfaces__action__Eject_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sfarm_interfaces__action__Eject_GetResult_Response__Sequence *
sfarm_interfaces__action__Eject_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_GetResult_Response__Sequence * array = (sfarm_interfaces__action__Eject_GetResult_Response__Sequence *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sfarm_interfaces__action__Eject_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sfarm_interfaces__action__Eject_GetResult_Response__Sequence__destroy(sfarm_interfaces__action__Eject_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sfarm_interfaces__action__Eject_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sfarm_interfaces__action__Eject_GetResult_Response__Sequence__are_equal(const sfarm_interfaces__action__Eject_GetResult_Response__Sequence * lhs, const sfarm_interfaces__action__Eject_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sfarm_interfaces__action__Eject_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_GetResult_Response__Sequence__copy(
  const sfarm_interfaces__action__Eject_GetResult_Response__Sequence * input,
  sfarm_interfaces__action__Eject_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_GetResult_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(sfarm_interfaces__action__Eject_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sfarm_interfaces__action__Eject_GetResult_Response * data =
      (sfarm_interfaces__action__Eject_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sfarm_interfaces__action__Eject_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sfarm_interfaces__action__Eject_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sfarm_interfaces__action__Eject_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "sfarm_interfaces/action/detail/eject__functions.h"

bool
sfarm_interfaces__action__Eject_GetResult_Event__init(sfarm_interfaces__action__Eject_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    sfarm_interfaces__action__Eject_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!sfarm_interfaces__action__Eject_GetResult_Request__Sequence__init(&msg->request, 0)) {
    sfarm_interfaces__action__Eject_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!sfarm_interfaces__action__Eject_GetResult_Response__Sequence__init(&msg->response, 0)) {
    sfarm_interfaces__action__Eject_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
sfarm_interfaces__action__Eject_GetResult_Event__fini(sfarm_interfaces__action__Eject_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  sfarm_interfaces__action__Eject_GetResult_Request__Sequence__fini(&msg->request);
  // response
  sfarm_interfaces__action__Eject_GetResult_Response__Sequence__fini(&msg->response);
}

bool
sfarm_interfaces__action__Eject_GetResult_Event__are_equal(const sfarm_interfaces__action__Eject_GetResult_Event * lhs, const sfarm_interfaces__action__Eject_GetResult_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!sfarm_interfaces__action__Eject_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!sfarm_interfaces__action__Eject_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_GetResult_Event__copy(
  const sfarm_interfaces__action__Eject_GetResult_Event * input,
  sfarm_interfaces__action__Eject_GetResult_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!sfarm_interfaces__action__Eject_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!sfarm_interfaces__action__Eject_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

sfarm_interfaces__action__Eject_GetResult_Event *
sfarm_interfaces__action__Eject_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_GetResult_Event * msg = (sfarm_interfaces__action__Eject_GetResult_Event *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sfarm_interfaces__action__Eject_GetResult_Event));
  bool success = sfarm_interfaces__action__Eject_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sfarm_interfaces__action__Eject_GetResult_Event__destroy(sfarm_interfaces__action__Eject_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sfarm_interfaces__action__Eject_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sfarm_interfaces__action__Eject_GetResult_Event__Sequence__init(sfarm_interfaces__action__Eject_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_GetResult_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_GetResult_Event)) {
      return false;
    }
    data = (sfarm_interfaces__action__Eject_GetResult_Event *)allocator.zero_allocate(size, sizeof(sfarm_interfaces__action__Eject_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sfarm_interfaces__action__Eject_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sfarm_interfaces__action__Eject_GetResult_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sfarm_interfaces__action__Eject_GetResult_Event__Sequence__fini(sfarm_interfaces__action__Eject_GetResult_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sfarm_interfaces__action__Eject_GetResult_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sfarm_interfaces__action__Eject_GetResult_Event__Sequence *
sfarm_interfaces__action__Eject_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_GetResult_Event__Sequence * array = (sfarm_interfaces__action__Eject_GetResult_Event__Sequence *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sfarm_interfaces__action__Eject_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sfarm_interfaces__action__Eject_GetResult_Event__Sequence__destroy(sfarm_interfaces__action__Eject_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sfarm_interfaces__action__Eject_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sfarm_interfaces__action__Eject_GetResult_Event__Sequence__are_equal(const sfarm_interfaces__action__Eject_GetResult_Event__Sequence * lhs, const sfarm_interfaces__action__Eject_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sfarm_interfaces__action__Eject_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_GetResult_Event__Sequence__copy(
  const sfarm_interfaces__action__Eject_GetResult_Event__Sequence * input,
  sfarm_interfaces__action__Eject_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_GetResult_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(sfarm_interfaces__action__Eject_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sfarm_interfaces__action__Eject_GetResult_Event * data =
      (sfarm_interfaces__action__Eject_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sfarm_interfaces__action__Eject_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sfarm_interfaces__action__Eject_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sfarm_interfaces__action__Eject_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "sfarm_interfaces/action/detail/eject__functions.h"

bool
sfarm_interfaces__action__Eject_FeedbackMessage__init(sfarm_interfaces__action__Eject_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    sfarm_interfaces__action__Eject_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!sfarm_interfaces__action__Eject_Feedback__init(&msg->feedback)) {
    sfarm_interfaces__action__Eject_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
sfarm_interfaces__action__Eject_FeedbackMessage__fini(sfarm_interfaces__action__Eject_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  sfarm_interfaces__action__Eject_Feedback__fini(&msg->feedback);
}

bool
sfarm_interfaces__action__Eject_FeedbackMessage__are_equal(const sfarm_interfaces__action__Eject_FeedbackMessage * lhs, const sfarm_interfaces__action__Eject_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!sfarm_interfaces__action__Eject_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_FeedbackMessage__copy(
  const sfarm_interfaces__action__Eject_FeedbackMessage * input,
  sfarm_interfaces__action__Eject_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!sfarm_interfaces__action__Eject_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

sfarm_interfaces__action__Eject_FeedbackMessage *
sfarm_interfaces__action__Eject_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_FeedbackMessage * msg = (sfarm_interfaces__action__Eject_FeedbackMessage *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sfarm_interfaces__action__Eject_FeedbackMessage));
  bool success = sfarm_interfaces__action__Eject_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sfarm_interfaces__action__Eject_FeedbackMessage__destroy(sfarm_interfaces__action__Eject_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sfarm_interfaces__action__Eject_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sfarm_interfaces__action__Eject_FeedbackMessage__Sequence__init(sfarm_interfaces__action__Eject_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_FeedbackMessage * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_FeedbackMessage)) {
      return false;
    }
    data = (sfarm_interfaces__action__Eject_FeedbackMessage *)allocator.zero_allocate(size, sizeof(sfarm_interfaces__action__Eject_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sfarm_interfaces__action__Eject_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sfarm_interfaces__action__Eject_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sfarm_interfaces__action__Eject_FeedbackMessage__Sequence__fini(sfarm_interfaces__action__Eject_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sfarm_interfaces__action__Eject_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sfarm_interfaces__action__Eject_FeedbackMessage__Sequence *
sfarm_interfaces__action__Eject_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sfarm_interfaces__action__Eject_FeedbackMessage__Sequence * array = (sfarm_interfaces__action__Eject_FeedbackMessage__Sequence *)allocator.allocate(sizeof(sfarm_interfaces__action__Eject_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sfarm_interfaces__action__Eject_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sfarm_interfaces__action__Eject_FeedbackMessage__Sequence__destroy(sfarm_interfaces__action__Eject_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sfarm_interfaces__action__Eject_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sfarm_interfaces__action__Eject_FeedbackMessage__Sequence__are_equal(const sfarm_interfaces__action__Eject_FeedbackMessage__Sequence * lhs, const sfarm_interfaces__action__Eject_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sfarm_interfaces__action__Eject_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sfarm_interfaces__action__Eject_FeedbackMessage__Sequence__copy(
  const sfarm_interfaces__action__Eject_FeedbackMessage__Sequence * input,
  sfarm_interfaces__action__Eject_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(sfarm_interfaces__action__Eject_FeedbackMessage)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(sfarm_interfaces__action__Eject_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sfarm_interfaces__action__Eject_FeedbackMessage * data =
      (sfarm_interfaces__action__Eject_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sfarm_interfaces__action__Eject_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sfarm_interfaces__action__Eject_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sfarm_interfaces__action__Eject_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
