// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from controlador_servo:srv/MoverServo.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "controlador_servo/srv/detail/mover_servo__functions.h"
#include "controlador_servo/srv/detail/mover_servo__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace controlador_servo
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoverServo_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoverServo_Request_type_support_ids_t;

static const _MoverServo_Request_type_support_ids_t _MoverServo_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, controlador_servo, srv, MoverServo_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, controlador_servo, srv, MoverServo_Request)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoverServo_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &controlador_servo__srv__MoverServo_Request__get_type_hash,
  &controlador_servo__srv__MoverServo_Request__get_type_description,
  &controlador_servo__srv__MoverServo_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace controlador_servo

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<controlador_servo::srv::MoverServo_Request>()
{
  return &::controlador_servo::srv::rosidl_typesupport_cpp::MoverServo_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, controlador_servo, srv, MoverServo_Request)() {
  return get_message_type_support_handle<controlador_servo::srv::MoverServo_Request>();
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
// #include "controlador_servo/srv/detail/mover_servo__functions.h"
// already included above
// #include "controlador_servo/srv/detail/mover_servo__struct.hpp"
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

namespace controlador_servo
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoverServo_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoverServo_Response_type_support_ids_t;

static const _MoverServo_Response_type_support_ids_t _MoverServo_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, controlador_servo, srv, MoverServo_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, controlador_servo, srv, MoverServo_Response)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoverServo_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &controlador_servo__srv__MoverServo_Response__get_type_hash,
  &controlador_servo__srv__MoverServo_Response__get_type_description,
  &controlador_servo__srv__MoverServo_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace controlador_servo

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<controlador_servo::srv::MoverServo_Response>()
{
  return &::controlador_servo::srv::rosidl_typesupport_cpp::MoverServo_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, controlador_servo, srv, MoverServo_Response)() {
  return get_message_type_support_handle<controlador_servo::srv::MoverServo_Response>();
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
// #include "controlador_servo/srv/detail/mover_servo__functions.h"
// already included above
// #include "controlador_servo/srv/detail/mover_servo__struct.hpp"
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

namespace controlador_servo
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoverServo_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoverServo_Event_type_support_ids_t;

static const _MoverServo_Event_type_support_ids_t _MoverServo_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, controlador_servo, srv, MoverServo_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, controlador_servo, srv, MoverServo_Event)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoverServo_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &controlador_servo__srv__MoverServo_Event__get_type_hash,
  &controlador_servo__srv__MoverServo_Event__get_type_description,
  &controlador_servo__srv__MoverServo_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace controlador_servo

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<controlador_servo::srv::MoverServo_Event>()
{
  return &::controlador_servo::srv::rosidl_typesupport_cpp::MoverServo_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, controlador_servo, srv, MoverServo_Event)() {
  return get_message_type_support_handle<controlador_servo::srv::MoverServo_Event>();
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
// #include "controlador_servo/srv/detail/mover_servo__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace controlador_servo
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _MoverServo_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoverServo_type_support_ids_t;

static const _MoverServo_type_support_ids_t _MoverServo_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, controlador_servo, srv, MoverServo)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, controlador_servo, srv, MoverServo)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoverServo_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<controlador_servo::srv::MoverServo_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<controlador_servo::srv::MoverServo_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<controlador_servo::srv::MoverServo_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<controlador_servo::srv::MoverServo>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<controlador_servo::srv::MoverServo>,
  &controlador_servo__srv__MoverServo__get_type_hash,
  &controlador_servo__srv__MoverServo__get_type_description,
  &controlador_servo__srv__MoverServo__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace controlador_servo

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<controlador_servo::srv::MoverServo>()
{
  return &::controlador_servo::srv::rosidl_typesupport_cpp::MoverServo_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, controlador_servo, srv, MoverServo)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<controlador_servo::srv::MoverServo>();
}

#ifdef __cplusplus
}
#endif
