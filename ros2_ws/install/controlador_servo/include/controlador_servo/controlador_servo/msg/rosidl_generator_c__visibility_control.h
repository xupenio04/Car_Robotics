// generated from rosidl_generator_c/resource/rosidl_generator_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef CONTROLADOR_SERVO__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
#define CONTROLADOR_SERVO__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_C_EXPORT_controlador_servo __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_C_IMPORT_controlador_servo __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_C_EXPORT_controlador_servo __declspec(dllexport)
    #define ROSIDL_GENERATOR_C_IMPORT_controlador_servo __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_C_BUILDING_DLL_controlador_servo
    #define ROSIDL_GENERATOR_C_PUBLIC_controlador_servo ROSIDL_GENERATOR_C_EXPORT_controlador_servo
  #else
    #define ROSIDL_GENERATOR_C_PUBLIC_controlador_servo ROSIDL_GENERATOR_C_IMPORT_controlador_servo
  #endif
#else
  #define ROSIDL_GENERATOR_C_EXPORT_controlador_servo __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_C_IMPORT_controlador_servo
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_C_PUBLIC_controlador_servo __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_C_PUBLIC_controlador_servo
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // CONTROLADOR_SERVO__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
