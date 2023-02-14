//engine.cpp
#include "engine.h"
namespace nertc {
Napi::Object Engine::Init(Napi::Env env, Napi::Object exports)
{
    Napi::Function func =
        DefineClass(env, "Engine",
                   {InstanceMethod("add", &Engine::add)});
    Napi::FunctionReference* constructor = new Napi::FunctionReference();
    *constructor = Napi::Persistent(func);
    env.SetInstanceData(constructor);
    exports.Set("Engine", func);
    return exports;
}

Engine::Engine(const Napi::CallbackInfo& info): Napi::ObjectWrap<Engine>(info) {}

Napi::Value Engine::add(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();//获取环境变量
  int ret = 0;
  int length = info.Length();//获取参数个数
  if (length != 2 || !info[0].IsNumber() || !info[1].IsNumber())
  {
      Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
      ret = -1;
      return Napi::Number::New(env, ret);
  }
  int num1 = info[0].As<Napi::Number>().Int32Value();//获取第一个参数
  int num2 = info[1].As<Napi::Number>().Int32Value();////获取第二个参数
  int sum = num1 + num2;
  return Napi::Number::New(env, sum);//返回结果到js层
}
}