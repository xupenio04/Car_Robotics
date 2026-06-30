#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "servo_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__servo_interfaces__srv__MoverServo_Request() -> *const std::ffi::c_void;
}

#[link(name = "servo_interfaces__rosidl_generator_c")]
extern "C" {
    fn servo_interfaces__srv__MoverServo_Request__init(msg: *mut MoverServo_Request) -> bool;
    fn servo_interfaces__srv__MoverServo_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoverServo_Request>, size: usize) -> bool;
    fn servo_interfaces__srv__MoverServo_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoverServo_Request>);
    fn servo_interfaces__srv__MoverServo_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoverServo_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<MoverServo_Request>) -> bool;
}

// Corresponds to servo_interfaces__srv__MoverServo_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoverServo_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub angulo: f32,

}



impl Default for MoverServo_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !servo_interfaces__srv__MoverServo_Request__init(&mut msg as *mut _) {
        panic!("Call to servo_interfaces__srv__MoverServo_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoverServo_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { servo_interfaces__srv__MoverServo_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { servo_interfaces__srv__MoverServo_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { servo_interfaces__srv__MoverServo_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoverServo_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoverServo_Request where Self: Sized {
  const TYPE_NAME: &'static str = "servo_interfaces/srv/MoverServo_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__servo_interfaces__srv__MoverServo_Request() }
  }
}


#[link(name = "servo_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__servo_interfaces__srv__MoverServo_Response() -> *const std::ffi::c_void;
}

#[link(name = "servo_interfaces__rosidl_generator_c")]
extern "C" {
    fn servo_interfaces__srv__MoverServo_Response__init(msg: *mut MoverServo_Response) -> bool;
    fn servo_interfaces__srv__MoverServo_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MoverServo_Response>, size: usize) -> bool;
    fn servo_interfaces__srv__MoverServo_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MoverServo_Response>);
    fn servo_interfaces__srv__MoverServo_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MoverServo_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<MoverServo_Response>) -> bool;
}

// Corresponds to servo_interfaces__srv__MoverServo_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoverServo_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sucesso: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mensagem: rosidl_runtime_rs::String,

}



impl Default for MoverServo_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !servo_interfaces__srv__MoverServo_Response__init(&mut msg as *mut _) {
        panic!("Call to servo_interfaces__srv__MoverServo_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MoverServo_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { servo_interfaces__srv__MoverServo_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { servo_interfaces__srv__MoverServo_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { servo_interfaces__srv__MoverServo_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MoverServo_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MoverServo_Response where Self: Sized {
  const TYPE_NAME: &'static str = "servo_interfaces/srv/MoverServo_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__servo_interfaces__srv__MoverServo_Response() }
  }
}






#[link(name = "servo_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__servo_interfaces__srv__MoverServo() -> *const std::ffi::c_void;
}

// Corresponds to servo_interfaces__srv__MoverServo
#[allow(missing_docs, non_camel_case_types)]
pub struct MoverServo;

impl rosidl_runtime_rs::Service for MoverServo {
    type Request = MoverServo_Request;
    type Response = MoverServo_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__servo_interfaces__srv__MoverServo() }
    }
}


