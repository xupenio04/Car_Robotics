// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from controlador_servo:srv/MoverServo.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "controlador_servo/srv/detail/mover_servo__struct.h"
#include "controlador_servo/srv/detail/mover_servo__type_support.h"
#include "controlador_servo/srv/detail/mover_servo__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace controlador_servo
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _MoverServo_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoverServo_Request_type_support_ids_t;

static const _MoverServo_Request_type_support_ids_t _MoverServo_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoverServo_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoverServo_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoverServo_Request_type_support_symbol_names_t _MoverServo_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, controlador_servo, srv, MoverServo_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, controlador_servo, srv, MoverServo_Request)),
  }
};

typedef struct _MoverServo_Request_type_support_data_t
{
  void * data[2];
} _MoverServo_Request_type_support_data_t;

static _MoverServo_Request_type_support_data_t _MoverServo_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoverServo_Request_message_typesupport_map = {
  2,
  "controlador_servo",
  &_MoverServo_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoverServo_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoverServo_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoverServo_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoverServo_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &controlador_servo__srv__MoverServo_Request__get_type_hash,
  &controlador_servo__srv__MoverServo_Request__get_type_description,
  &controlador_servo__srv__MoverServo_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace controlador_servo

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, controlador_servo, srv, MoverServo_Request)() {
  return &::controlador_servo::srv::rosidl_typesupport_c::MoverServo_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "controlador_servo/srv/detail/mover_servo__struct.h"
// already included above
// #include "controlador_servo/srv/detail/mover_servo__type_support.h"
// already included above
// #include "controlador_servo/srv/detail/mover_servo__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace controlador_servo
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _MoverServo_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoverServo_Response_type_support_ids_t;

static const _MoverServo_Response_type_support_ids_t _MoverServo_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoverServo_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoverServo_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoverServo_Response_type_support_symbol_names_t _MoverServo_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, controlador_servo, srv, MoverServo_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, controlador_servo, srv, MoverServo_Response)),
  }
};

typedef struct _MoverServo_Response_type_support_data_t
{
  void * data[2];
} _MoverServo_Response_type_support_data_t;

static _MoverServo_Response_type_support_data_t _MoverServo_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoverServo_Response_message_typesupport_map = {
  2,
  "controlador_servo",
  &_MoverServo_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoverServo_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoverServo_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoverServo_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoverServo_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &controlador_servo__srv__MoverServo_Response__get_type_hash,
  &controlador_servo__srv__MoverServo_Response__get_type_description,
  &controlador_servo__srv__MoverServo_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace controlador_servo

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, controlador_servo, srv, MoverServo_Response)() {
  return &::controlador_servo::srv::rosidl_typesupport_c::MoverServo_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "controlador_servo/srv/detail/mover_servo__struct.h"
// already included above
// #include "controlador_servo/srv/detail/mover_servo__type_support.h"
// already included above
// #include "controlador_servo/srv/detail/mover_servo__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace controlador_servo
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _MoverServo_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoverServo_Event_type_support_ids_t;

static const _MoverServo_Event_type_support_ids_t _MoverServo_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoverServo_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoverServo_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoverServo_Event_type_support_symbol_names_t _MoverServo_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, controlador_servo, srv, MoverServo_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, controlador_servo, srv, MoverServo_Event)),
  }
};

typedef struct _MoverServo_Event_type_support_data_t
{
  void * data[2];
} _MoverServo_Event_type_support_data_t;

static _MoverServo_Event_type_support_data_t _MoverServo_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoverServo_Event_message_typesupport_map = {
  2,
  "controlador_servo",
  &_MoverServo_Event_message_typesupport_ids.typesupport_identifier[0],
  &_MoverServo_Event_message_typesupport_symbol_names.symbol_name[0],
  &_MoverServo_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoverServo_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoverServo_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &controlador_servo__srv__MoverServo_Event__get_type_hash,
  &controlador_servo__srv__MoverServo_Event__get_type_description,
  &controlador_servo__srv__MoverServo_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace controlador_servo

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, controlador_servo, srv, MoverServo_Event)() {
  return &::controlador_servo::srv::rosidl_typesupport_c::MoverServo_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "controlador_servo/srv/detail/mover_servo__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace controlador_servo
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _MoverServo_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoverServo_type_support_ids_t;

static const _MoverServo_type_support_ids_t _MoverServo_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoverServo_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoverServo_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoverServo_type_support_symbol_names_t _MoverServo_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, controlador_servo, srv, MoverServo)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, controlador_servo, srv, MoverServo)),
  }
};

typedef struct _MoverServo_type_support_data_t
{
  void * data[2];
} _MoverServo_type_support_data_t;

static _MoverServo_type_support_data_t _MoverServo_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoverServo_service_typesupport_map = {
  2,
  "controlador_servo",
  &_MoverServo_service_typesupport_ids.typesupport_identifier[0],
  &_MoverServo_service_typesupport_symbol_names.symbol_name[0],
  &_MoverServo_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoverServo_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoverServo_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &MoverServo_Request_message_type_support_handle,
  &MoverServo_Response_message_type_support_handle,
  &MoverServo_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    controlador_servo,
    srv,
    MoverServo
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    controlador_servo,
    srv,
    MoverServo
  ),
  &controlador_servo__srv__MoverServo__get_type_hash,
  &controlador_servo__srv__MoverServo__get_type_description,
  &controlador_servo__srv__MoverServo__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace controlador_servo

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, controlador_servo, srv, MoverServo)() {
  return &::controlador_servo::srv::rosidl_typesupport_c::MoverServo_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
