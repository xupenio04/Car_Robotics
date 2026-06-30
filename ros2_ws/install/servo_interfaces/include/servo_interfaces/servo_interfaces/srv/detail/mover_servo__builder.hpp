// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from servo_interfaces:srv/MoverServo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "servo_interfaces/srv/mover_servo.hpp"


#ifndef SERVO_INTERFACES__SRV__DETAIL__MOVER_SERVO__BUILDER_HPP_
#define SERVO_INTERFACES__SRV__DETAIL__MOVER_SERVO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "servo_interfaces/srv/detail/mover_servo__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace servo_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoverServo_Request_angulo
{
public:
  Init_MoverServo_Request_angulo()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::servo_interfaces::srv::MoverServo_Request angulo(::servo_interfaces::srv::MoverServo_Request::_angulo_type arg)
  {
    msg_.angulo = std::move(arg);
    return std::move(msg_);
  }

private:
  ::servo_interfaces::srv::MoverServo_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::servo_interfaces::srv::MoverServo_Request>()
{
  return servo_interfaces::srv::builder::Init_MoverServo_Request_angulo();
}

}  // namespace servo_interfaces


namespace servo_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoverServo_Response_mensagem
{
public:
  explicit Init_MoverServo_Response_mensagem(::servo_interfaces::srv::MoverServo_Response & msg)
  : msg_(msg)
  {}
  ::servo_interfaces::srv::MoverServo_Response mensagem(::servo_interfaces::srv::MoverServo_Response::_mensagem_type arg)
  {
    msg_.mensagem = std::move(arg);
    return std::move(msg_);
  }

private:
  ::servo_interfaces::srv::MoverServo_Response msg_;
};

class Init_MoverServo_Response_sucesso
{
public:
  Init_MoverServo_Response_sucesso()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoverServo_Response_mensagem sucesso(::servo_interfaces::srv::MoverServo_Response::_sucesso_type arg)
  {
    msg_.sucesso = std::move(arg);
    return Init_MoverServo_Response_mensagem(msg_);
  }

private:
  ::servo_interfaces::srv::MoverServo_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::servo_interfaces::srv::MoverServo_Response>()
{
  return servo_interfaces::srv::builder::Init_MoverServo_Response_sucesso();
}

}  // namespace servo_interfaces


namespace servo_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoverServo_Event_response
{
public:
  explicit Init_MoverServo_Event_response(::servo_interfaces::srv::MoverServo_Event & msg)
  : msg_(msg)
  {}
  ::servo_interfaces::srv::MoverServo_Event response(::servo_interfaces::srv::MoverServo_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::servo_interfaces::srv::MoverServo_Event msg_;
};

class Init_MoverServo_Event_request
{
public:
  explicit Init_MoverServo_Event_request(::servo_interfaces::srv::MoverServo_Event & msg)
  : msg_(msg)
  {}
  Init_MoverServo_Event_response request(::servo_interfaces::srv::MoverServo_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MoverServo_Event_response(msg_);
  }

private:
  ::servo_interfaces::srv::MoverServo_Event msg_;
};

class Init_MoverServo_Event_info
{
public:
  Init_MoverServo_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoverServo_Event_request info(::servo_interfaces::srv::MoverServo_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MoverServo_Event_request(msg_);
  }

private:
  ::servo_interfaces::srv::MoverServo_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::servo_interfaces::srv::MoverServo_Event>()
{
  return servo_interfaces::srv::builder::Init_MoverServo_Event_info();
}

}  // namespace servo_interfaces

#endif  // SERVO_INTERFACES__SRV__DETAIL__MOVER_SERVO__BUILDER_HPP_
