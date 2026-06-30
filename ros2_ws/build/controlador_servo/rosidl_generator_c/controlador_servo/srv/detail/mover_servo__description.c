// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from controlador_servo:srv/MoverServo.idl
// generated code does not contain a copyright notice

#include "controlador_servo/srv/detail/mover_servo__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_controlador_servo
const rosidl_type_hash_t *
controlador_servo__srv__MoverServo__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1d, 0x90, 0x02, 0x4e, 0xda, 0x00, 0xeb, 0x06,
      0x1f, 0x7a, 0xb0, 0x66, 0x64, 0xf2, 0x37, 0x39,
      0xf5, 0x32, 0x22, 0x90, 0x0c, 0xd7, 0xae, 0x2d,
      0xce, 0xf1, 0x5b, 0x7f, 0xdc, 0x5d, 0xa3, 0x38,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_controlador_servo
const rosidl_type_hash_t *
controlador_servo__srv__MoverServo_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd4, 0x20, 0x14, 0x8b, 0xa4, 0x24, 0xc4, 0x91,
      0x65, 0x86, 0x02, 0x01, 0x3b, 0xab, 0xa5, 0x88,
      0xf3, 0x4b, 0x3a, 0x59, 0x9b, 0x01, 0x76, 0xad,
      0x7c, 0x55, 0x40, 0x92, 0x5d, 0xd8, 0xfb, 0x16,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_controlador_servo
const rosidl_type_hash_t *
controlador_servo__srv__MoverServo_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc8, 0x35, 0x30, 0x2c, 0xef, 0x89, 0x3e, 0xa0,
      0x4c, 0x18, 0xf1, 0xde, 0xfe, 0xa0, 0x0f, 0x1b,
      0x4b, 0x30, 0x3b, 0x25, 0xc0, 0xa1, 0x79, 0x8d,
      0xb9, 0xe9, 0x2a, 0xde, 0xff, 0xa5, 0x15, 0xc7,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_controlador_servo
const rosidl_type_hash_t *
controlador_servo__srv__MoverServo_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x57, 0x2a, 0x02, 0xf8, 0x4a, 0x95, 0x71, 0x96,
      0x14, 0x7b, 0xf0, 0xfd, 0xfe, 0xfb, 0x18, 0xfc,
      0xd0, 0x60, 0x4c, 0x98, 0x24, 0x74, 0xa8, 0x38,
      0xfa, 0x2a, 0xd1, 0xb4, 0xaf, 0x46, 0x60, 0x2e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char controlador_servo__srv__MoverServo__TYPE_NAME[] = "controlador_servo/srv/MoverServo";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char controlador_servo__srv__MoverServo_Event__TYPE_NAME[] = "controlador_servo/srv/MoverServo_Event";
static char controlador_servo__srv__MoverServo_Request__TYPE_NAME[] = "controlador_servo/srv/MoverServo_Request";
static char controlador_servo__srv__MoverServo_Response__TYPE_NAME[] = "controlador_servo/srv/MoverServo_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char controlador_servo__srv__MoverServo__FIELD_NAME__request_message[] = "request_message";
static char controlador_servo__srv__MoverServo__FIELD_NAME__response_message[] = "response_message";
static char controlador_servo__srv__MoverServo__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field controlador_servo__srv__MoverServo__FIELDS[] = {
  {
    {controlador_servo__srv__MoverServo__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {controlador_servo__srv__MoverServo_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {controlador_servo__srv__MoverServo__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {controlador_servo__srv__MoverServo_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {controlador_servo__srv__MoverServo__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {controlador_servo__srv__MoverServo_Event__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription controlador_servo__srv__MoverServo__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {controlador_servo__srv__MoverServo_Event__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {controlador_servo__srv__MoverServo_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {controlador_servo__srv__MoverServo_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
controlador_servo__srv__MoverServo__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {controlador_servo__srv__MoverServo__TYPE_NAME, 32, 32},
      {controlador_servo__srv__MoverServo__FIELDS, 3, 3},
    },
    {controlador_servo__srv__MoverServo__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = controlador_servo__srv__MoverServo_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = controlador_servo__srv__MoverServo_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = controlador_servo__srv__MoverServo_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char controlador_servo__srv__MoverServo_Request__FIELD_NAME__angulo[] = "angulo";

static rosidl_runtime_c__type_description__Field controlador_servo__srv__MoverServo_Request__FIELDS[] = {
  {
    {controlador_servo__srv__MoverServo_Request__FIELD_NAME__angulo, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
controlador_servo__srv__MoverServo_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {controlador_servo__srv__MoverServo_Request__TYPE_NAME, 40, 40},
      {controlador_servo__srv__MoverServo_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char controlador_servo__srv__MoverServo_Response__FIELD_NAME__sucesso[] = "sucesso";
static char controlador_servo__srv__MoverServo_Response__FIELD_NAME__mensagem[] = "mensagem";

static rosidl_runtime_c__type_description__Field controlador_servo__srv__MoverServo_Response__FIELDS[] = {
  {
    {controlador_servo__srv__MoverServo_Response__FIELD_NAME__sucesso, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {controlador_servo__srv__MoverServo_Response__FIELD_NAME__mensagem, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
controlador_servo__srv__MoverServo_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {controlador_servo__srv__MoverServo_Response__TYPE_NAME, 41, 41},
      {controlador_servo__srv__MoverServo_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char controlador_servo__srv__MoverServo_Event__FIELD_NAME__info[] = "info";
static char controlador_servo__srv__MoverServo_Event__FIELD_NAME__request[] = "request";
static char controlador_servo__srv__MoverServo_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field controlador_servo__srv__MoverServo_Event__FIELDS[] = {
  {
    {controlador_servo__srv__MoverServo_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {controlador_servo__srv__MoverServo_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {controlador_servo__srv__MoverServo_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {controlador_servo__srv__MoverServo_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {controlador_servo__srv__MoverServo_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription controlador_servo__srv__MoverServo_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {controlador_servo__srv__MoverServo_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {controlador_servo__srv__MoverServo_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
controlador_servo__srv__MoverServo_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {controlador_servo__srv__MoverServo_Event__TYPE_NAME, 38, 38},
      {controlador_servo__srv__MoverServo_Event__FIELDS, 3, 3},
    },
    {controlador_servo__srv__MoverServo_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = controlador_servo__srv__MoverServo_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = controlador_servo__srv__MoverServo_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 angulo\n"
  "---\n"
  "bool sucesso\n"
  "string mensagem";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
controlador_servo__srv__MoverServo__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {controlador_servo__srv__MoverServo__TYPE_NAME, 32, 32},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 48, 48},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
controlador_servo__srv__MoverServo_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {controlador_servo__srv__MoverServo_Request__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
controlador_servo__srv__MoverServo_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {controlador_servo__srv__MoverServo_Response__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
controlador_servo__srv__MoverServo_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {controlador_servo__srv__MoverServo_Event__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
controlador_servo__srv__MoverServo__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *controlador_servo__srv__MoverServo__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *controlador_servo__srv__MoverServo_Event__get_individual_type_description_source(NULL);
    sources[3] = *controlador_servo__srv__MoverServo_Request__get_individual_type_description_source(NULL);
    sources[4] = *controlador_servo__srv__MoverServo_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
controlador_servo__srv__MoverServo_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *controlador_servo__srv__MoverServo_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
controlador_servo__srv__MoverServo_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *controlador_servo__srv__MoverServo_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
controlador_servo__srv__MoverServo_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *controlador_servo__srv__MoverServo_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *controlador_servo__srv__MoverServo_Request__get_individual_type_description_source(NULL);
    sources[3] = *controlador_servo__srv__MoverServo_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
