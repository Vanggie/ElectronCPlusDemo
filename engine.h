//engine.h
#pragma once
#include <napi.h>
namespace nertc {
class Engine : public Napi::ObjectWrap<Engine> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Engine(const Napi::CallbackInfo& info);
 private:
  Napi::Value add(const Napi::CallbackInfo& info);
};
}
