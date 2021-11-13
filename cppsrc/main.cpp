/* cppsrc/main.cpp */
#include <napi.h>
#include <iostream>

Napi::String SayHelloTo(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	std::string strings = info[0].As<Napi::String>().ToString();

	std::cout << "hello" + strings << std::endl;

	std::string returns = std::string("hhhhhhh,get it?");

	return Napi::String::New(env, returns);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports.Set(Napi::String::New(env, "testFunc"), Napi::Function::New(env, SayHelloTo));
	return exports;
}

NODE_API_MODULE(test, Init)