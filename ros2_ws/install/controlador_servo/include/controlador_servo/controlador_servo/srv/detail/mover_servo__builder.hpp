// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from controlador_servo:srv/MoverServo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "controlador_servo/srv/mover_servo.hpp"


#ifndef CONTROLADOR_SERVO__SRV__DETAIL__MOVER_SERVO__BUILDER_HPP_
#define CONTROLADOR_SERVO__SRV__DETAIL__MOVER_SERVO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "controlador_servo/srv/detail/mover_servo__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace controlador_servo
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
  ::controlador_servo::srv::MoverServo_Request angulo(::controlador_servo::srv::MoverServo_Request::_angulo_type arg)
  {
    msg_.angulo = std::move(arg);
    return std::move(msg_);
  }

private:
  ::controlador_servo::srv::MoverServo_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::controlador_servo::srv::MoverServo_Request>()
{
  return controlador_servo::srv::builder::Init_MoverServo_Request_angulo();
}

}  // namespace controlador_servo


namespace controlador_servo
{

namespace srv
{

namespace builder
{

class Init_MoverServo_Response_mensagem
{
public:
  explicit Init_MoverServo_Response_mensagem(::controlador_servo::srv::MoverServo_Response & msg)
  : msg_(msg)
  {}
  ::controlador_servo::srv::MoverServo_Response mensagem(::controlador_servo::srv::MoverServo_Response::_mensagem_type arg)
  {
    msg_.mensagem = std::move(arg);
    return std::move(msg_);
  }

private:
  ::controlador_servo::srv::MoverServo_Response msg_;
};

class Init_MoverServo_Response_sucesso
{
public:
  Init_MoverServo_Response_sucesso()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoverServo_Response_mensagem sucesso(::controlador_servo::srv::MoverServo_Response::_sucesso_type arg)
  {
    msg_.sucesso = std::move(arg);
    return Init_MoverServo_Response_mensagem(msg_);
  }

private:
  ::controlador_servo::srv::MoverServo_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::controlador_servo::srv::MoverServo_Response>()
{
  return controlador_servo::srv::builder::Init_MoverServo_Response_sucesso();
}

}  // namespace controlador_servo


namespace controlador_servo
{

namespace srv
{

namespace builder
{

class Init_MoverServo_Event_response
{
public:
  explicit Init_MoverServo_Event_response(::controlador_servo::srv::MoverServo_Event & msg)
  : msg_(msg)
  {}
  ::controlador_servo::srv::MoverServo_Event response(::controlador_servo::srv::MoverServo_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::controlador_servo::srv::MoverServo_Event msg_;
};

class Init_MoverServo_Event_request
{
public:
  explicit Init_MoverServo_Event_request(::controlador_servo::srv::MoverServo_Event & msg)
  : msg_(msg)
  {}
  Init_MoverServo_Event_response request(::controlador_servo::srv::MoverServo_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MoverServo_Event_response(msg_);
  }

private:
  ::controlador_servo::srv::MoverServo_Event msg_;
};

class Init_MoverServo_Event_info
{
public:
  Init_MoverServo_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoverServo_Event_request info(::controlador_servo::srv::MoverServo_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MoverServo_Event_request(msg_);
  }

private:
  ::controlador_servo::srv::MoverServo_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::controlador_servo::srv::MoverServo_Event>()
{
  return controlador_servo::srv::builder::Init_MoverServo_Event_info();
}

}  // namespace controlador_servo

#endif  // CONTROLADOR_SERVO__SRV__DETAIL__MOVER_SERVO__BUILDER_HPP_
