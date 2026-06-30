// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from controlador_servo:srv/MoverServo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "controlador_servo/srv/mover_servo.hpp"


#ifndef CONTROLADOR_SERVO__SRV__DETAIL__MOVER_SERVO__TRAITS_HPP_
#define CONTROLADOR_SERVO__SRV__DETAIL__MOVER_SERVO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "controlador_servo/srv/detail/mover_servo__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace controlador_servo
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoverServo_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: angulo
  {
    out << "angulo: ";
    rosidl_generator_traits::value_to_yaml(msg.angulo, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoverServo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: angulo
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angulo: ";
    rosidl_generator_traits::value_to_yaml(msg.angulo, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoverServo_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace controlador_servo

namespace rosidl_generator_traits
{

[[deprecated("use controlador_servo::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const controlador_servo::srv::MoverServo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  controlador_servo::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use controlador_servo::srv::to_yaml() instead")]]
inline std::string to_yaml(const controlador_servo::srv::MoverServo_Request & msg)
{
  return controlador_servo::srv::to_yaml(msg);
}

template<>
inline const char * data_type<controlador_servo::srv::MoverServo_Request>()
{
  return "controlador_servo::srv::MoverServo_Request";
}

template<>
inline const char * name<controlador_servo::srv::MoverServo_Request>()
{
  return "controlador_servo/srv/MoverServo_Request";
}

template<>
struct has_fixed_size<controlador_servo::srv::MoverServo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<controlador_servo::srv::MoverServo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<controlador_servo::srv::MoverServo_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace controlador_servo
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoverServo_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: sucesso
  {
    out << "sucesso: ";
    rosidl_generator_traits::value_to_yaml(msg.sucesso, out);
    out << ", ";
  }

  // member: mensagem
  {
    out << "mensagem: ";
    rosidl_generator_traits::value_to_yaml(msg.mensagem, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoverServo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sucesso
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sucesso: ";
    rosidl_generator_traits::value_to_yaml(msg.sucesso, out);
    out << "\n";
  }

  // member: mensagem
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mensagem: ";
    rosidl_generator_traits::value_to_yaml(msg.mensagem, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoverServo_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace controlador_servo

namespace rosidl_generator_traits
{

[[deprecated("use controlador_servo::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const controlador_servo::srv::MoverServo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  controlador_servo::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use controlador_servo::srv::to_yaml() instead")]]
inline std::string to_yaml(const controlador_servo::srv::MoverServo_Response & msg)
{
  return controlador_servo::srv::to_yaml(msg);
}

template<>
inline const char * data_type<controlador_servo::srv::MoverServo_Response>()
{
  return "controlador_servo::srv::MoverServo_Response";
}

template<>
inline const char * name<controlador_servo::srv::MoverServo_Response>()
{
  return "controlador_servo/srv/MoverServo_Response";
}

template<>
struct has_fixed_size<controlador_servo::srv::MoverServo_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<controlador_servo::srv::MoverServo_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<controlador_servo::srv::MoverServo_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace controlador_servo
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoverServo_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoverServo_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoverServo_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace controlador_servo

namespace rosidl_generator_traits
{

[[deprecated("use controlador_servo::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const controlador_servo::srv::MoverServo_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  controlador_servo::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use controlador_servo::srv::to_yaml() instead")]]
inline std::string to_yaml(const controlador_servo::srv::MoverServo_Event & msg)
{
  return controlador_servo::srv::to_yaml(msg);
}

template<>
inline const char * data_type<controlador_servo::srv::MoverServo_Event>()
{
  return "controlador_servo::srv::MoverServo_Event";
}

template<>
inline const char * name<controlador_servo::srv::MoverServo_Event>()
{
  return "controlador_servo/srv/MoverServo_Event";
}

template<>
struct has_fixed_size<controlador_servo::srv::MoverServo_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<controlador_servo::srv::MoverServo_Event>
  : std::integral_constant<bool, has_bounded_size<controlador_servo::srv::MoverServo_Request>::value && has_bounded_size<controlador_servo::srv::MoverServo_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<controlador_servo::srv::MoverServo_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<controlador_servo::srv::MoverServo>()
{
  return "controlador_servo::srv::MoverServo";
}

template<>
inline const char * name<controlador_servo::srv::MoverServo>()
{
  return "controlador_servo/srv/MoverServo";
}

template<>
struct has_fixed_size<controlador_servo::srv::MoverServo>
  : std::integral_constant<
    bool,
    has_fixed_size<controlador_servo::srv::MoverServo_Request>::value &&
    has_fixed_size<controlador_servo::srv::MoverServo_Response>::value
  >
{
};

template<>
struct has_bounded_size<controlador_servo::srv::MoverServo>
  : std::integral_constant<
    bool,
    has_bounded_size<controlador_servo::srv::MoverServo_Request>::value &&
    has_bounded_size<controlador_servo::srv::MoverServo_Response>::value
  >
{
};

template<>
struct is_service<controlador_servo::srv::MoverServo>
  : std::true_type
{
};

template<>
struct is_service_request<controlador_servo::srv::MoverServo_Request>
  : std::true_type
{
};

template<>
struct is_service_response<controlador_servo::srv::MoverServo_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CONTROLADOR_SERVO__SRV__DETAIL__MOVER_SERVO__TRAITS_HPP_
