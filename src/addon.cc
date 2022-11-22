#include <node.h>
#include <stdint.h>
#include <iostream>

namespace wasm {

using v8::FunctionCallbackInfo;
using v8::Local;
using v8::Value;
using v8::Object;
using v8::Boolean;

uintptr_t *gRef = nullptr;

uintptr_t GetValueInternalPointer(Local<Value> val) {
    return *reinterpret_cast<uintptr_t*>(*val);
}

void Track(const FunctionCallbackInfo<Value>& args) {
    auto value = args[0];

    if (value->IsString()) {
        *gRef = GetValueInternalPointer(value);
        //std::cout << "gRef to: " << gRef << std::endl;
        args.GetReturnValue().Set(value);
    } else {
        args.GetReturnValue().SetNull();
    }
}

void Equal(const FunctionCallbackInfo<Value>& args) {
    auto value = args[0];

    args.GetReturnValue().Set(false);
    if (value->IsString()) {
        auto ref = GetValueInternalPointer(value);
        //std::cout << "ref: " << ref << std::endl;
        if (ref == *gRef) {
            args.GetReturnValue().Set(true);
        }
    }
}

void Init(v8::Local<v8::Object> exports) {
    gRef = new uintptr_t;
    NODE_SET_METHOD(exports, "track", Track);
    NODE_SET_METHOD(exports, "equal", Equal);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init);
}  // namespace wasm
