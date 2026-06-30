// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from servo_interfaces:srv/MoverServo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "servo_interfaces/srv/mover_servo.h"


#ifndef SERVO_INTERFACES__SRV__DETAIL__MOVER_SERVO__STRUCT_H_
#define SERVO_INTERFACES__SRV__DETAIL__MOVER_SERVO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/MoverServo in the package servo_interfaces.
typedef struct servo_interfaces__srv__MoverServo_Request
{
  float angulo;
} servo_interfaces__srv__MoverServo_Request;

// Struct for a sequence of servo_interfaces__srv__MoverServo_Request.
typedef struct servo_interfaces__srv__MoverServo_Request__Sequence
{
  servo_interfaces__srv__MoverServo_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} servo_interfaces__srv__MoverServo_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'mensagem'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/MoverServo in the package servo_interfaces.
typedef struct servo_interfaces__srv__MoverServo_Response
{
  bool sucesso;
  rosidl_runtime_c__String mensagem;
} servo_interfaces__srv__MoverServo_Response;

// Struct for a sequence of servo_interfaces__srv__MoverServo_Response.
typedef struct servo_interfaces__srv__MoverServo_Response__Sequence
{
  servo_interfaces__srv__MoverServo_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} servo_interfaces__srv__MoverServo_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  servo_interfaces__srv__MoverServo_Event__request__MAX_SIZE = 1
};
// response
enum
{
  servo_interfaces__srv__MoverServo_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/MoverServo in the package servo_interfaces.
typedef struct servo_interfaces__srv__MoverServo_Event
{
  service_msgs__msg__ServiceEventInfo info;
  servo_interfaces__srv__MoverServo_Request__Sequence request;
  servo_interfaces__srv__MoverServo_Response__Sequence response;
} servo_interfaces__srv__MoverServo_Event;

// Struct for a sequence of servo_interfaces__srv__MoverServo_Event.
typedef struct servo_interfaces__srv__MoverServo_Event__Sequence
{
  servo_interfaces__srv__MoverServo_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} servo_interfaces__srv__MoverServo_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERVO_INTERFACES__SRV__DETAIL__MOVER_SERVO__STRUCT_H_
