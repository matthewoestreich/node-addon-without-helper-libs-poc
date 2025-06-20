#include "Greeter.hpp"
#include <node_api.h>
#include <string>

// Finalizer to clean up when JS object is garbage-collected
void GreeterDestructor(napi_env env, void *nativeObject, void * /*finalize_hint*/) {
  delete static_cast<Greeter *>(nativeObject);
}

// Constructor for JS `Greeter`
napi_value GreeterConstructor(napi_env env, napi_callback_info info) {
  size_t argc = 1;
  napi_value args[1];
  napi_value thisArg;
  void *data;

  napi_get_cb_info(env, info, &argc, args, &thisArg, &data);

  // Get string from args[0]
  size_t str_size;
  size_t str_size_read;
  napi_get_value_string_utf8(env, args[0], nullptr, 0, &str_size);
  char *buffer = new char[str_size + 1];
  napi_get_value_string_utf8(env, args[0], buffer, str_size + 1, &str_size_read);

  Greeter *greeter = new Greeter(std::string(buffer));
  delete[] buffer;

  // Associate native object with JS object
  napi_wrap(env, thisArg, greeter, GreeterDestructor, nullptr, nullptr);

  return thisArg;
}

// Greeter.prototype.greet()
napi_value GreeterGreet(napi_env env, napi_callback_info info) {
  napi_value thisArg;
  napi_get_cb_info(env, info, nullptr, nullptr, &thisArg, nullptr);

  Greeter *greeter;
  napi_unwrap(env, thisArg, reinterpret_cast<void **>(&greeter));

  std::string message = greeter->greet();

  napi_value result;
  napi_create_string_utf8(env, message.c_str(), NAPI_AUTO_LENGTH, &result);
  return result;
}

// Module initialization
napi_value Init(napi_env env, napi_value exports) {
  napi_property_descriptor properties[] = {
      {"greet", nullptr, GreeterGreet, nullptr, nullptr, nullptr, napi_default, nullptr}
  };

  napi_value GreeterClass;
  napi_define_class(env, "Greeter", NAPI_AUTO_LENGTH, GreeterConstructor, nullptr, 1, properties, &GreeterClass);

  napi_set_named_property(env, exports, "Greeter", GreeterClass);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
