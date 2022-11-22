#include <node.h>
namespace wasm {

using v8::FunctionCallbackInfo;
using v8::Value;
using v8::Object;

void Track(const FunctionCallbackInfo<Value>& args) {
    args.GetReturnValue().SetNull();
}

void Equal(const FunctionCallbackInfo<Value>& args) {
    args.GetReturnValue().SetNull();
}

void Init(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "track", Track);
    NODE_SET_METHOD(exports, "equal", Equal);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init);
}  // namespace wasm
