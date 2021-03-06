// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message_workgroup.proto

#ifndef PROTOBUF_message_5fworkgroup_2eproto__INCLUDED
#define PROTOBUF_message_5fworkgroup_2eproto__INCLUDED

#include "../defines.h"
#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "message_common.pb.h"
// @@protoc_insertion_point(includes)

namespace rpc {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_message_5fworkgroup_2eproto();
void protobuf_AssignDesc_message_5fworkgroup_2eproto();
void protobuf_ShutdownFile_message_5fworkgroup_2eproto();

class WorkGroupsListRequest;
class WorkGroupsListResponse;

// ===================================================================

class WorkGroupsListRequest : public ::google::protobuf::Message {
 public:
  WorkGroupsListRequest();
  virtual ~WorkGroupsListRequest();

  WorkGroupsListRequest(const WorkGroupsListRequest& from);

  inline WorkGroupsListRequest& operator=(const WorkGroupsListRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const WorkGroupsListRequest& default_instance();

  void Swap(WorkGroupsListRequest* other);

  // implements Message ----------------------------------------------

  WorkGroupsListRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const WorkGroupsListRequest& from);
  void MergeFrom(const WorkGroupsListRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string session_id = 1;
  inline bool has_session_id() const;
  inline void clear_session_id();
  static const int kSessionIdFieldNumber = 1;
  inline const ::std::string& session_id() const;
  inline void set_session_id(const ::std::string& value);
  inline void set_session_id(const char* value);
  inline void set_session_id(const char* value, size_t size);
  inline ::std::string* mutable_session_id();
  inline ::std::string* release_session_id();
  inline void set_allocated_session_id(::std::string* session_id);

  // optional .rpc.Filter filter = 2;
  inline bool has_filter() const;
  inline void clear_filter();
  static const int kFilterFieldNumber = 2;
  inline ::rpc::Filter filter() const;
  inline void set_filter(::rpc::Filter value);

  // @@protoc_insertion_point(class_scope:rpc.WorkGroupsListRequest)
 private:
  inline void set_has_session_id();
  inline void clear_has_session_id();
  inline void set_has_filter();
  inline void clear_has_filter();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* session_id_;
  int filter_;
  friend void  protobuf_AddDesc_message_5fworkgroup_2eproto();
  friend void protobuf_AssignDesc_message_5fworkgroup_2eproto();
  friend void protobuf_ShutdownFile_message_5fworkgroup_2eproto();

  void InitAsDefaultInstance();
  static WorkGroupsListRequest* default_instance_;
};
// -------------------------------------------------------------------

class WorkGroupsListResponse : public ::google::protobuf::Message {
 public:
  WorkGroupsListResponse();
  virtual ~WorkGroupsListResponse();

  WorkGroupsListResponse(const WorkGroupsListResponse& from);

  inline WorkGroupsListResponse& operator=(const WorkGroupsListResponse& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const WorkGroupsListResponse& default_instance();

  void Swap(WorkGroupsListResponse* other);

  // implements Message ----------------------------------------------

  WorkGroupsListResponse* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const WorkGroupsListResponse& from);
  void MergeFrom(const WorkGroupsListResponse& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 error_code = 1;
  inline bool has_error_code() const;
  inline void clear_error_code();
  static const int kErrorCodeFieldNumber = 1;
  inline ::google::protobuf::int32 error_code() const;
  inline void set_error_code(::google::protobuf::int32 value);

  // repeated .rpc.WorkGroupInfo workgroup_info_list = 2;
  inline int workgroup_info_list_size() const;
  inline void clear_workgroup_info_list();
  static const int kWorkgroupInfoListFieldNumber = 2;
  inline const ::rpc::WorkGroupInfo& workgroup_info_list(int index) const;
  inline ::rpc::WorkGroupInfo* mutable_workgroup_info_list(int index);
  inline ::rpc::WorkGroupInfo* add_workgroup_info_list();
  inline const ::google::protobuf::RepeatedPtrField< ::rpc::WorkGroupInfo >&
      workgroup_info_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::rpc::WorkGroupInfo >*
      mutable_workgroup_info_list();

  // optional int64 last_event_id = 3;
  inline bool has_last_event_id() const;
  inline void clear_last_event_id();
  static const int kLastEventIdFieldNumber = 3;
  inline ::google::protobuf::int64 last_event_id() const;
  inline void set_last_event_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:rpc.WorkGroupsListResponse)
 private:
  inline void set_has_error_code();
  inline void clear_has_error_code();
  inline void set_has_last_event_id();
  inline void clear_has_last_event_id();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::rpc::WorkGroupInfo > workgroup_info_list_;
  ::google::protobuf::int64 last_event_id_;
  ::google::protobuf::int32 error_code_;
  friend void  protobuf_AddDesc_message_5fworkgroup_2eproto();
  friend void protobuf_AssignDesc_message_5fworkgroup_2eproto();
  friend void protobuf_ShutdownFile_message_5fworkgroup_2eproto();

  void InitAsDefaultInstance();
  static WorkGroupsListResponse* default_instance_;
};
// ===================================================================


// ===================================================================

// WorkGroupsListRequest

// optional string session_id = 1;
inline bool WorkGroupsListRequest::has_session_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void WorkGroupsListRequest::set_has_session_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void WorkGroupsListRequest::clear_has_session_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void WorkGroupsListRequest::clear_session_id() {
  if (session_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    session_id_->clear();
  }
  clear_has_session_id();
}
inline const ::std::string& WorkGroupsListRequest::session_id() const {
  // @@protoc_insertion_point(field_get:rpc.WorkGroupsListRequest.session_id)
  return *session_id_;
}
inline void WorkGroupsListRequest::set_session_id(const ::std::string& value) {
  set_has_session_id();
  if (session_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    session_id_ = new ::std::string;
  }
  session_id_->assign(value);
  // @@protoc_insertion_point(field_set:rpc.WorkGroupsListRequest.session_id)
}
inline void WorkGroupsListRequest::set_session_id(const char* value) {
  set_has_session_id();
  if (session_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    session_id_ = new ::std::string;
  }
  session_id_->assign(value);
  // @@protoc_insertion_point(field_set_char:rpc.WorkGroupsListRequest.session_id)
}
inline void WorkGroupsListRequest::set_session_id(const char* value, size_t size) {
  set_has_session_id();
  if (session_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    session_id_ = new ::std::string;
  }
  session_id_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:rpc.WorkGroupsListRequest.session_id)
}
inline ::std::string* WorkGroupsListRequest::mutable_session_id() {
  set_has_session_id();
  if (session_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    session_id_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:rpc.WorkGroupsListRequest.session_id)
  return session_id_;
}
inline ::std::string* WorkGroupsListRequest::release_session_id() {
  clear_has_session_id();
  if (session_id_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = session_id_;
    session_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void WorkGroupsListRequest::set_allocated_session_id(::std::string* session_id) {
  if (session_id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete session_id_;
  }
  if (session_id) {
    set_has_session_id();
    session_id_ = session_id;
  } else {
    clear_has_session_id();
    session_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:rpc.WorkGroupsListRequest.session_id)
}

// optional .rpc.Filter filter = 2;
inline bool WorkGroupsListRequest::has_filter() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void WorkGroupsListRequest::set_has_filter() {
  _has_bits_[0] |= 0x00000002u;
}
inline void WorkGroupsListRequest::clear_has_filter() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void WorkGroupsListRequest::clear_filter() {
  filter_ = 0;
  clear_has_filter();
}
inline ::rpc::Filter WorkGroupsListRequest::filter() const {
  // @@protoc_insertion_point(field_get:rpc.WorkGroupsListRequest.filter)
  return static_cast< ::rpc::Filter >(filter_);
}
inline void WorkGroupsListRequest::set_filter(::rpc::Filter value) {
  assert(::rpc::Filter_IsValid(value));
  set_has_filter();
  filter_ = value;
  // @@protoc_insertion_point(field_set:rpc.WorkGroupsListRequest.filter)
}

// -------------------------------------------------------------------

// WorkGroupsListResponse

// optional int32 error_code = 1;
inline bool WorkGroupsListResponse::has_error_code() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void WorkGroupsListResponse::set_has_error_code() {
  _has_bits_[0] |= 0x00000001u;
}
inline void WorkGroupsListResponse::clear_has_error_code() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void WorkGroupsListResponse::clear_error_code() {
  error_code_ = 0;
  clear_has_error_code();
}
inline ::google::protobuf::int32 WorkGroupsListResponse::error_code() const {
  // @@protoc_insertion_point(field_get:rpc.WorkGroupsListResponse.error_code)
  return error_code_;
}
inline void WorkGroupsListResponse::set_error_code(::google::protobuf::int32 value) {
  set_has_error_code();
  error_code_ = value;
  // @@protoc_insertion_point(field_set:rpc.WorkGroupsListResponse.error_code)
}

// repeated .rpc.WorkGroupInfo workgroup_info_list = 2;
inline int WorkGroupsListResponse::workgroup_info_list_size() const {
  return workgroup_info_list_.size();
}
inline void WorkGroupsListResponse::clear_workgroup_info_list() {
  workgroup_info_list_.Clear();
}
inline const ::rpc::WorkGroupInfo& WorkGroupsListResponse::workgroup_info_list(int index) const {
  // @@protoc_insertion_point(field_get:rpc.WorkGroupsListResponse.workgroup_info_list)
  return workgroup_info_list_.Get(index);
}
inline ::rpc::WorkGroupInfo* WorkGroupsListResponse::mutable_workgroup_info_list(int index) {
  // @@protoc_insertion_point(field_mutable:rpc.WorkGroupsListResponse.workgroup_info_list)
  return workgroup_info_list_.Mutable(index);
}
inline ::rpc::WorkGroupInfo* WorkGroupsListResponse::add_workgroup_info_list() {
  // @@protoc_insertion_point(field_add:rpc.WorkGroupsListResponse.workgroup_info_list)
  return workgroup_info_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::rpc::WorkGroupInfo >&
WorkGroupsListResponse::workgroup_info_list() const {
  // @@protoc_insertion_point(field_list:rpc.WorkGroupsListResponse.workgroup_info_list)
  return workgroup_info_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::rpc::WorkGroupInfo >*
WorkGroupsListResponse::mutable_workgroup_info_list() {
  // @@protoc_insertion_point(field_mutable_list:rpc.WorkGroupsListResponse.workgroup_info_list)
  return &workgroup_info_list_;
}

// optional int64 last_event_id = 3;
inline bool WorkGroupsListResponse::has_last_event_id() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void WorkGroupsListResponse::set_has_last_event_id() {
  _has_bits_[0] |= 0x00000004u;
}
inline void WorkGroupsListResponse::clear_has_last_event_id() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void WorkGroupsListResponse::clear_last_event_id() {
  last_event_id_ = GOOGLE_LONGLONG(0);
  clear_has_last_event_id();
}
inline ::google::protobuf::int64 WorkGroupsListResponse::last_event_id() const {
  // @@protoc_insertion_point(field_get:rpc.WorkGroupsListResponse.last_event_id)
  return last_event_id_;
}
inline void WorkGroupsListResponse::set_last_event_id(::google::protobuf::int64 value) {
  set_has_last_event_id();
  last_event_id_ = value;
  // @@protoc_insertion_point(field_set:rpc.WorkGroupsListResponse.last_event_id)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace rpc

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_message_5fworkgroup_2eproto__INCLUDED
