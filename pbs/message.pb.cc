// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "message.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace rpc {

namespace {

const ::google::protobuf::Descriptor* Request_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Request_reflection_ = NULL;
const ::google::protobuf::Descriptor* Response_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Response_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_message_2eproto() {
  protobuf_AddDesc_message_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "message.proto");
  GOOGLE_CHECK(file != NULL);
  Request_descriptor_ = file->message_type(0);
  static const int Request_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Request, message_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Request, workgroups_list_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Request, service_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Request, is_debug_),
  };
  Request_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Request_descriptor_,
      Request::default_instance_,
      Request_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Request, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Request, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Request));
  Response_descriptor_ = file->message_type(1);
  static const int Response_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Response, message_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Response, workgroups_list_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Response, error_code_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Response, error_message_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Response, request_id_),
  };
  Response_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Response_descriptor_,
      Response::default_instance_,
      Response_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Response, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Response, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Response));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_message_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Request_descriptor_, &Request::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Response_descriptor_, &Response::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_message_2eproto() {
  delete Request::default_instance_;
  delete Request_reflection_;
  delete Response::default_instance_;
  delete Response_reflection_;
}

void protobuf_AddDesc_message_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protobuf_AddDesc_message_5ftype_2eproto();
  ::rpc::protobuf_AddDesc_message_5fworkgroup_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rmessage.proto\022\003rpc\032\022message_type.proto"
    "\032\027message_workgroup.proto\"\214\001\n\007Request\022\"\n"
    "\014message_type\030\001 \001(\0162\014.MessageType\0223\n\017wor"
    "kgroups_list\030@ \001(\0132\032.rpc.WorkGroupsListR"
    "equest\022\025\n\014service_type\030\200  \001(\003\022\021\n\010is_debu"
    "g\030\201  \001(\010\"\246\001\n\010Response\022\"\n\014message_type\030\001 "
    "\001(\0162\014.MessageType\0224\n\017workgroups_list\030@ \001"
    "(\0132\033.rpc.WorkGroupsListResponse\022\023\n\nerror"
    "_code\030\200\020 \001(\005\022\026\n\rerror_message\030\201\020 \003(\t\022\023\n\n"
    "request_id\030\202\020 \001(\tB\002H\001", 381);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "message.proto", &protobuf_RegisterTypes);
  Request::default_instance_ = new Request();
  Response::default_instance_ = new Response();
  Request::default_instance_->InitAsDefaultInstance();
  Response::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_message_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_message_2eproto {
  StaticDescriptorInitializer_message_2eproto() {
    protobuf_AddDesc_message_2eproto();
  }
} static_descriptor_initializer_message_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Request::kMessageTypeFieldNumber;
const int Request::kWorkgroupsListFieldNumber;
const int Request::kServiceTypeFieldNumber;
const int Request::kIsDebugFieldNumber;
#endif  // !_MSC_VER

Request::Request()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:rpc.Request)
}

void Request::InitAsDefaultInstance() {
  workgroups_list_ = const_cast< ::rpc::WorkGroupsListRequest*>(&::rpc::WorkGroupsListRequest::default_instance());
}

Request::Request(const Request& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:rpc.Request)
}

void Request::SharedCtor() {
  _cached_size_ = 0;
  message_type_ = 64;
  workgroups_list_ = NULL;
  service_type_ = GOOGLE_LONGLONG(0);
  is_debug_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Request::~Request() {
  // @@protoc_insertion_point(destructor:rpc.Request)
  SharedDtor();
}

void Request::SharedDtor() {
  if (this != default_instance_) {
    delete workgroups_list_;
  }
}

void Request::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Request::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Request_descriptor_;
}

const Request& Request::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_message_2eproto();
  return *default_instance_;
}

Request* Request::default_instance_ = NULL;

Request* Request::New() const {
  return new Request;
}

void Request::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Request*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 15) {
    ZR_(is_debug_, service_type_);
    message_type_ = 64;
    if (has_workgroups_list()) {
      if (workgroups_list_ != NULL) workgroups_list_->::rpc::WorkGroupsListRequest::Clear();
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Request::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:rpc.Request)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(32776);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .MessageType message_type = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::MessageType_IsValid(value)) {
            set_message_type(static_cast< ::MessageType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(514)) goto parse_workgroups_list;
        break;
      }

      // optional .rpc.WorkGroupsListRequest workgroups_list = 64;
      case 64: {
        if (tag == 514) {
         parse_workgroups_list:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_workgroups_list()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32768)) goto parse_service_type;
        break;
      }

      // optional int64 service_type = 4096;
      case 4096: {
        if (tag == 32768) {
         parse_service_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &service_type_)));
          set_has_service_type();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32776)) goto parse_is_debug;
        break;
      }

      // optional bool is_debug = 4097;
      case 4097: {
        if (tag == 32776) {
         parse_is_debug:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_debug_)));
          set_has_is_debug();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:rpc.Request)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:rpc.Request)
  return false;
#undef DO_
}

void Request::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:rpc.Request)
  // optional .MessageType message_type = 1;
  if (has_message_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->message_type(), output);
  }

  // optional .rpc.WorkGroupsListRequest workgroups_list = 64;
  if (has_workgroups_list()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      64, this->workgroups_list(), output);
  }

  // optional int64 service_type = 4096;
  if (has_service_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(4096, this->service_type(), output);
  }

  // optional bool is_debug = 4097;
  if (has_is_debug()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(4097, this->is_debug(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:rpc.Request)
}

::google::protobuf::uint8* Request::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:rpc.Request)
  // optional .MessageType message_type = 1;
  if (has_message_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->message_type(), target);
  }

  // optional .rpc.WorkGroupsListRequest workgroups_list = 64;
  if (has_workgroups_list()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        64, this->workgroups_list(), target);
  }

  // optional int64 service_type = 4096;
  if (has_service_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(4096, this->service_type(), target);
  }

  // optional bool is_debug = 4097;
  if (has_is_debug()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(4097, this->is_debug(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rpc.Request)
  return target;
}

int Request::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .MessageType message_type = 1;
    if (has_message_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->message_type());
    }

    // optional .rpc.WorkGroupsListRequest workgroups_list = 64;
    if (has_workgroups_list()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->workgroups_list());
    }

    // optional int64 service_type = 4096;
    if (has_service_type()) {
      total_size += 3 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->service_type());
    }

    // optional bool is_debug = 4097;
    if (has_is_debug()) {
      total_size += 3 + 1;
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Request::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Request* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Request*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Request::MergeFrom(const Request& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_message_type()) {
      set_message_type(from.message_type());
    }
    if (from.has_workgroups_list()) {
      mutable_workgroups_list()->::rpc::WorkGroupsListRequest::MergeFrom(from.workgroups_list());
    }
    if (from.has_service_type()) {
      set_service_type(from.service_type());
    }
    if (from.has_is_debug()) {
      set_is_debug(from.is_debug());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Request::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Request::CopyFrom(const Request& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Request::IsInitialized() const {

  return true;
}

void Request::Swap(Request* other) {
  if (other != this) {
    std::swap(message_type_, other->message_type_);
    std::swap(workgroups_list_, other->workgroups_list_);
    std::swap(service_type_, other->service_type_);
    std::swap(is_debug_, other->is_debug_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Request::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Request_descriptor_;
  metadata.reflection = Request_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Response::kMessageTypeFieldNumber;
const int Response::kWorkgroupsListFieldNumber;
const int Response::kErrorCodeFieldNumber;
const int Response::kErrorMessageFieldNumber;
const int Response::kRequestIdFieldNumber;
#endif  // !_MSC_VER

Response::Response()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:rpc.Response)
}

void Response::InitAsDefaultInstance() {
  workgroups_list_ = const_cast< ::rpc::WorkGroupsListResponse*>(&::rpc::WorkGroupsListResponse::default_instance());
}

Response::Response(const Response& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:rpc.Response)
}

void Response::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  message_type_ = 64;
  workgroups_list_ = NULL;
  error_code_ = 0;
  request_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Response::~Response() {
  // @@protoc_insertion_point(destructor:rpc.Response)
  SharedDtor();
}

void Response::SharedDtor() {
  if (request_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete request_id_;
  }
  if (this != default_instance_) {
    delete workgroups_list_;
  }
}

void Response::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Response::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Response_descriptor_;
}

const Response& Response::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_message_2eproto();
  return *default_instance_;
}

Response* Response::default_instance_ = NULL;

Response* Response::New() const {
  return new Response;
}

void Response::Clear() {
  if (_has_bits_[0 / 32] & 23) {
    message_type_ = 64;
    if (has_workgroups_list()) {
      if (workgroups_list_ != NULL) workgroups_list_->::rpc::WorkGroupsListResponse::Clear();
    }
    error_code_ = 0;
    if (has_request_id()) {
      if (request_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        request_id_->clear();
      }
    }
  }
  error_message_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Response::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:rpc.Response)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(16402);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .MessageType message_type = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::MessageType_IsValid(value)) {
            set_message_type(static_cast< ::MessageType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(514)) goto parse_workgroups_list;
        break;
      }

      // optional .rpc.WorkGroupsListResponse workgroups_list = 64;
      case 64: {
        if (tag == 514) {
         parse_workgroups_list:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_workgroups_list()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16384)) goto parse_error_code;
        break;
      }

      // optional int32 error_code = 2048;
      case 2048: {
        if (tag == 16384) {
         parse_error_code:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &error_code_)));
          set_has_error_code();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16394)) goto parse_error_message;
        break;
      }

      // repeated string error_message = 2049;
      case 2049: {
        if (tag == 16394) {
         parse_error_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_error_message()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->error_message(this->error_message_size() - 1).data(),
            this->error_message(this->error_message_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "error_message");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16394)) goto parse_error_message;
        if (input->ExpectTag(16402)) goto parse_request_id;
        break;
      }

      // optional string request_id = 2050;
      case 2050: {
        if (tag == 16402) {
         parse_request_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_request_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->request_id().data(), this->request_id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "request_id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:rpc.Response)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:rpc.Response)
  return false;
#undef DO_
}

void Response::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:rpc.Response)
  // optional .MessageType message_type = 1;
  if (has_message_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->message_type(), output);
  }

  // optional .rpc.WorkGroupsListResponse workgroups_list = 64;
  if (has_workgroups_list()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      64, this->workgroups_list(), output);
  }

  // optional int32 error_code = 2048;
  if (has_error_code()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2048, this->error_code(), output);
  }

  // repeated string error_message = 2049;
  for (int i = 0; i < this->error_message_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
    this->error_message(i).data(), this->error_message(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE,
    "error_message");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2049, this->error_message(i), output);
  }

  // optional string request_id = 2050;
  if (has_request_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->request_id().data(), this->request_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "request_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2050, this->request_id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:rpc.Response)
}

::google::protobuf::uint8* Response::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:rpc.Response)
  // optional .MessageType message_type = 1;
  if (has_message_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->message_type(), target);
  }

  // optional .rpc.WorkGroupsListResponse workgroups_list = 64;
  if (has_workgroups_list()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        64, this->workgroups_list(), target);
  }

  // optional int32 error_code = 2048;
  if (has_error_code()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2048, this->error_code(), target);
  }

  // repeated string error_message = 2049;
  for (int i = 0; i < this->error_message_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->error_message(i).data(), this->error_message(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "error_message");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(2049, this->error_message(i), target);
  }

  // optional string request_id = 2050;
  if (has_request_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->request_id().data(), this->request_id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "request_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2050, this->request_id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:rpc.Response)
  return target;
}

int Response::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .MessageType message_type = 1;
    if (has_message_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->message_type());
    }

    // optional .rpc.WorkGroupsListResponse workgroups_list = 64;
    if (has_workgroups_list()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->workgroups_list());
    }

    // optional int32 error_code = 2048;
    if (has_error_code()) {
      total_size += 3 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->error_code());
    }

    // optional string request_id = 2050;
    if (has_request_id()) {
      total_size += 3 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->request_id());
    }

  }
  // repeated string error_message = 2049;
  total_size += 3 * this->error_message_size();
  for (int i = 0; i < this->error_message_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->error_message(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Response::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Response* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Response*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Response::MergeFrom(const Response& from) {
  GOOGLE_CHECK_NE(&from, this);
  error_message_.MergeFrom(from.error_message_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_message_type()) {
      set_message_type(from.message_type());
    }
    if (from.has_workgroups_list()) {
      mutable_workgroups_list()->::rpc::WorkGroupsListResponse::MergeFrom(from.workgroups_list());
    }
    if (from.has_error_code()) {
      set_error_code(from.error_code());
    }
    if (from.has_request_id()) {
      set_request_id(from.request_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Response::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Response::CopyFrom(const Response& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Response::IsInitialized() const {

  return true;
}

void Response::Swap(Response* other) {
  if (other != this) {
    std::swap(message_type_, other->message_type_);
    std::swap(workgroups_list_, other->workgroups_list_);
    std::swap(error_code_, other->error_code_);
    error_message_.Swap(&other->error_message_);
    std::swap(request_id_, other->request_id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Response::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Response_descriptor_;
  metadata.reflection = Response_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace rpc

// @@protoc_insertion_point(global_scope)