// generated from rosidl_generator_c/resource/idl__type_support.h.em
// with input from controlador_servo:srv/MoverServo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "controlador_servo/srv/mover_servo.h"


#ifndef CONTROLADOR_SERVO__SRV__DETAIL__MOVER_SERVO__TYPE_SUPPORT_H_
#define CONTROLADOR_SERVO__SRV__DETAIL__MOVER_SERVO__TYPE_SUPPORT_H_

#include "rosidl_typesupport_interface/macros.h"

#include "controlador_servo/msg/rosidl_generator_c__visibility_control.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "rosidl_runtime_c/message_type_support_struct.h"

// Forward declare the get type support functions for this type.
ROSIDL_GENERATOR_C_PUBLIC_controlador_servo
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  controlador_servo,
  srv,
  MoverServo_Request
)(void);

// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"

// Forward declare the get type support functions for this type.
ROSIDL_GENERATOR_C_PUBLIC_controlador_servo
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  controlador_servo,
  srv,
  MoverServo_Response
)(void);

// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"

// Forward declare the get type support functions for this type.
ROSIDL_GENERATOR_C_PUBLIC_controlador_servo
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  controlador_servo,
  srv,
  MoverServo_Event
)(void);

#include "rosidl_runtime_c/service_type_support_struct.h"

// Forward declare the get type support functions for this type.
ROSIDL_GENERATOR_C_PUBLIC_controlador_servo
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
  rosidl_typesupport_c,
  controlador_servo,
  srv,
  MoverServo
)(void);

// Forward declare the function to create a service event message for this type.
ROSIDL_GENERATOR_C_PUBLIC_controlador_servo
void *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  controlador_servo,
  srv,
  MoverServo
)(
  const rosidl_service_introspection_info_t * info,
  rcutils_allocator_t * allocator,
  const void * request_message,
  const void * response_message);

// Forward declare the function to destroy a service event message for this type.
ROSIDL_GENERATOR_C_PUBLIC_controlador_servo
bool
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  controlador_servo,
  srv,
  MoverServo
)(
  void * event_msg,
  rcutils_allocator_t * allocator);

#ifdef __cplusplus
}
#endif

#endif  // CONTROLADOR_SERVO__SRV__DETAIL__MOVER_SERVO__TYPE_SUPPORT_H_
