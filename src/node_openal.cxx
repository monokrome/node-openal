#include <v8.h>
#include <node.h>

using namespace v8;

class OpenAL : node::ObjectWrap {
private:
public:
  OpenAL() {}
  ~OpenAL() {}

  static v8::Persistent<FunctionTemplate> persistent_function_template;

  static void Init(Handle<Object> target) {
    v8::Local<FunctionTemplate> local_function_template = v8::FunctionTemplate::New(New);

    OpenAL::persistent_function_template = v8::Persistent<FunctionTemplate>::New(local_function_template);
    OpenAL::persistent_function_template->InstanceTemplate()->SetInternalFieldCount(1);
    OpenAL::persistent_function_template->SetClassName(v8::String::NewSymbol("OpenAL"));
  }

  static Handle<Value> New(const Arguments& args) {
    HandleScope scope;
    OpenAL* al_instance = new OpenAL();

    al_instance->Wrap(args.This());

    return args.This();
  }

  /**
   * Buffer functions.
   */
  static void GenBuffers(const Arguments& args) {
  }
};

v8::Persistent<FunctionTemplate> OpenAL::persistent_function_template;

extern "C" {
  static void init(Handle<Object> target) {
    OpenAL::Init(target);
  }

  NODE_MODULE(openal, init);
}

