// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from controlador_servo:srv/MoverServo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "controlador_servo/srv/mover_servo.hpp"


#ifndef CONTROLADOR_SERVO__SRV__DETAIL__MOVER_SERVO__STRUCT_HPP_
#define CONTROLADOR_SERVO__SRV__DETAIL__MOVER_SERVO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__controlador_servo__srv__MoverServo_Request __attribute__((deprecated))
#else
# define DEPRECATED__controlador_servo__srv__MoverServo_Request __declspec(deprecated)
#endif

namespace controlador_servo
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoverServo_Request_
{
  using Type = MoverServo_Request_<ContainerAllocator>;

  explicit MoverServo_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->angulo = 0.0f;
    }
  }

  explicit MoverServo_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->angulo = 0.0f;
    }
  }

  // field types and members
  using _angulo_type =
    float;
  _angulo_type angulo;

  // setters for named parameter idiom
  Type & set__angulo(
    const float & _arg)
  {
    this->angulo = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    controlador_servo::srv::MoverServo_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const controlador_servo::srv::MoverServo_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<controlador_servo::srv::MoverServo_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<controlador_servo::srv::MoverServo_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      controlador_servo::srv::MoverServo_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<controlador_servo::srv::MoverServo_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      controlador_servo::srv::MoverServo_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<controlador_servo::srv::MoverServo_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<controlador_servo::srv::MoverServo_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<controlador_servo::srv::MoverServo_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__controlador_servo__srv__MoverServo_Request
    std::shared_ptr<controlador_servo::srv::MoverServo_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__controlador_servo__srv__MoverServo_Request
    std::shared_ptr<controlador_servo::srv::MoverServo_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoverServo_Request_ & other) const
  {
    if (this->angulo != other.angulo) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoverServo_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoverServo_Request_

// alias to use template instance with default allocator
using MoverServo_Request =
  controlador_servo::srv::MoverServo_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace controlador_servo


#ifndef _WIN32
# define DEPRECATED__controlador_servo__srv__MoverServo_Response __attribute__((deprecated))
#else
# define DEPRECATED__controlador_servo__srv__MoverServo_Response __declspec(deprecated)
#endif

namespace controlador_servo
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoverServo_Response_
{
  using Type = MoverServo_Response_<ContainerAllocator>;

  explicit MoverServo_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sucesso = false;
      this->mensagem = "";
    }
  }

  explicit MoverServo_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mensagem(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sucesso = false;
      this->mensagem = "";
    }
  }

  // field types and members
  using _sucesso_type =
    bool;
  _sucesso_type sucesso;
  using _mensagem_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mensagem_type mensagem;

  // setters for named parameter idiom
  Type & set__sucesso(
    const bool & _arg)
  {
    this->sucesso = _arg;
    return *this;
  }
  Type & set__mensagem(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mensagem = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    controlador_servo::srv::MoverServo_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const controlador_servo::srv::MoverServo_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<controlador_servo::srv::MoverServo_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<controlador_servo::srv::MoverServo_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      controlador_servo::srv::MoverServo_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<controlador_servo::srv::MoverServo_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      controlador_servo::srv::MoverServo_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<controlador_servo::srv::MoverServo_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<controlador_servo::srv::MoverServo_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<controlador_servo::srv::MoverServo_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__controlador_servo__srv__MoverServo_Response
    std::shared_ptr<controlador_servo::srv::MoverServo_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__controlador_servo__srv__MoverServo_Response
    std::shared_ptr<controlador_servo::srv::MoverServo_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoverServo_Response_ & other) const
  {
    if (this->sucesso != other.sucesso) {
      return false;
    }
    if (this->mensagem != other.mensagem) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoverServo_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoverServo_Response_

// alias to use template instance with default allocator
using MoverServo_Response =
  controlador_servo::srv::MoverServo_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace controlador_servo


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__controlador_servo__srv__MoverServo_Event __attribute__((deprecated))
#else
# define DEPRECATED__controlador_servo__srv__MoverServo_Event __declspec(deprecated)
#endif

namespace controlador_servo
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoverServo_Event_
{
  using Type = MoverServo_Event_<ContainerAllocator>;

  explicit MoverServo_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit MoverServo_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<controlador_servo::srv::MoverServo_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<controlador_servo::srv::MoverServo_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<controlador_servo::srv::MoverServo_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<controlador_servo::srv::MoverServo_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<controlador_servo::srv::MoverServo_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<controlador_servo::srv::MoverServo_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<controlador_servo::srv::MoverServo_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<controlador_servo::srv::MoverServo_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    controlador_servo::srv::MoverServo_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const controlador_servo::srv::MoverServo_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<controlador_servo::srv::MoverServo_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<controlador_servo::srv::MoverServo_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      controlador_servo::srv::MoverServo_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<controlador_servo::srv::MoverServo_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      controlador_servo::srv::MoverServo_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<controlador_servo::srv::MoverServo_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<controlador_servo::srv::MoverServo_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<controlador_servo::srv::MoverServo_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__controlador_servo__srv__MoverServo_Event
    std::shared_ptr<controlador_servo::srv::MoverServo_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__controlador_servo__srv__MoverServo_Event
    std::shared_ptr<controlador_servo::srv::MoverServo_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoverServo_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoverServo_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoverServo_Event_

// alias to use template instance with default allocator
using MoverServo_Event =
  controlador_servo::srv::MoverServo_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace controlador_servo

namespace controlador_servo
{

namespace srv
{

struct MoverServo
{
  using Request = controlador_servo::srv::MoverServo_Request;
  using Response = controlador_servo::srv::MoverServo_Response;
  using Event = controlador_servo::srv::MoverServo_Event;
};

}  // namespace srv

}  // namespace controlador_servo

#endif  // CONTROLADOR_SERVO__SRV__DETAIL__MOVER_SERVO__STRUCT_HPP_
