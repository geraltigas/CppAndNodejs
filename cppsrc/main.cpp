/* cppsrc/main.cpp */
#include <napi.h>
#include "Queen.h"

Napi::String dfss(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

//	std::string strings = info[0].As<Napi::String>().ToString(); //input

	std::string returns = std::string(dfs()); // returns

	return Napi::String::New(env, returns);
}


Napi::String bfss(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

//    std::string strings = info[0].As<Napi::String>().ToString(); //input

    std::string returns = std::string(bfs()); // returns

    return Napi::String::New(env, returns);
}



Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports.Set(Napi::String::New(env, "dfs"), Napi::Function::New(env, dfss));
    exports.Set(Napi::String::New(env, "bfs"), Napi::Function::New(env, bfss));
	return exports;
}

NODE_API_MODULE(test, Init)