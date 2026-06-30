#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to controlador_servo__srv__MoverServo_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoverServo_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub angulo: f32,

}



impl Default for MoverServo_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::MoverServo_Request::default())
  }
}

impl rosidl_runtime_rs::Message for MoverServo_Request {
  type RmwMsg = super::srv::rmw::MoverServo_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        angulo: msg.angulo,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      angulo: msg.angulo,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      angulo: msg.angulo,
    }
  }
}


// Corresponds to controlador_servo__srv__MoverServo_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MoverServo_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sucesso: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mensagem: std::string::String,

}



impl Default for MoverServo_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::MoverServo_Response::default())
  }
}

impl rosidl_runtime_rs::Message for MoverServo_Response {
  type RmwMsg = super::srv::rmw::MoverServo_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sucesso: msg.sucesso,
        mensagem: msg.mensagem.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      sucesso: msg.sucesso,
        mensagem: msg.mensagem.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      sucesso: msg.sucesso,
      mensagem: msg.mensagem.to_string(),
    }
  }
}






#[link(name = "controlador_servo__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__controlador_servo__srv__MoverServo() -> *const std::ffi::c_void;
}

// Corresponds to controlador_servo__srv__MoverServo
#[allow(missing_docs, non_camel_case_types)]
pub struct MoverServo;

impl rosidl_runtime_rs::Service for MoverServo {
    type Request = MoverServo_Request;
    type Response = MoverServo_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__controlador_servo__srv__MoverServo() }
    }
}


