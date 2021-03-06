// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: request.proto

#ifndef PROTOBUF_request_2eproto__INCLUDED
#define PROTOBUF_request_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003002 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace ledmodule {
class GifRequest;
class GifRequestDefaultTypeInternal;
extern GifRequestDefaultTypeInternal _GifRequest_default_instance_;
class PictureRequest;
class PictureRequestDefaultTypeInternal;
extern PictureRequestDefaultTypeInternal _PictureRequest_default_instance_;
class Request;
class RequestDefaultTypeInternal;
extern RequestDefaultTypeInternal _Request_default_instance_;
class TextRequest;
class TextRequestDefaultTypeInternal;
extern TextRequestDefaultTypeInternal _TextRequest_default_instance_;
class VideoRequest;
class VideoRequestDefaultTypeInternal;
extern VideoRequestDefaultTypeInternal _VideoRequest_default_instance_;
}  // namespace ledmodule

namespace ledmodule {

namespace protobuf_request_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_request_2eproto

enum Request_Action {
  Request_Action_TEXT = 1,
  Request_Action_PICTURE = 2,
  Request_Action_GIF = 3,
  Request_Action_VIDEO = 4,
  Request_Action_CANCEL = 5
};
bool Request_Action_IsValid(int value);
const Request_Action Request_Action_Action_MIN = Request_Action_TEXT;
const Request_Action Request_Action_Action_MAX = Request_Action_CANCEL;
const int Request_Action_Action_ARRAYSIZE = Request_Action_Action_MAX + 1;

const ::google::protobuf::EnumDescriptor* Request_Action_descriptor();
inline const ::std::string& Request_Action_Name(Request_Action value) {
  return ::google::protobuf::internal::NameOfEnum(
    Request_Action_descriptor(), value);
}
inline bool Request_Action_Parse(
    const ::std::string& name, Request_Action* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Request_Action>(
    Request_Action_descriptor(), name, value);
}
// ===================================================================

class Request : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ledmodule.Request) */ {
 public:
  Request();
  virtual ~Request();

  Request(const Request& from);

  inline Request& operator=(const Request& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Request& default_instance();

  static inline const Request* internal_default_instance() {
    return reinterpret_cast<const Request*>(
               &_Request_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Request* other);

  // implements Message ----------------------------------------------

  inline Request* New() const PROTOBUF_FINAL { return New(NULL); }

  Request* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Request& from);
  void MergeFrom(const Request& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Request* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef Request_Action Action;
  static const Action TEXT =
    Request_Action_TEXT;
  static const Action PICTURE =
    Request_Action_PICTURE;
  static const Action GIF =
    Request_Action_GIF;
  static const Action VIDEO =
    Request_Action_VIDEO;
  static const Action CANCEL =
    Request_Action_CANCEL;
  static inline bool Action_IsValid(int value) {
    return Request_Action_IsValid(value);
  }
  static const Action Action_MIN =
    Request_Action_Action_MIN;
  static const Action Action_MAX =
    Request_Action_Action_MAX;
  static const int Action_ARRAYSIZE =
    Request_Action_Action_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Action_descriptor() {
    return Request_Action_descriptor();
  }
  static inline const ::std::string& Action_Name(Action value) {
    return Request_Action_Name(value);
  }
  static inline bool Action_Parse(const ::std::string& name,
      Action* value) {
    return Request_Action_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required string sender = 2;
  bool has_sender() const;
  void clear_sender();
  static const int kSenderFieldNumber = 2;
  const ::std::string& sender() const;
  void set_sender(const ::std::string& value);
  #if LANG_CXX11
  void set_sender(::std::string&& value);
  #endif
  void set_sender(const char* value);
  void set_sender(const char* value, size_t size);
  ::std::string* mutable_sender();
  ::std::string* release_sender();
  void set_allocated_sender(::std::string* sender);

  // optional .ledmodule.TextRequest textRequest = 3;
  bool has_textrequest() const;
  void clear_textrequest();
  static const int kTextRequestFieldNumber = 3;
  const ::ledmodule::TextRequest& textrequest() const;
  ::ledmodule::TextRequest* mutable_textrequest();
  ::ledmodule::TextRequest* release_textrequest();
  void set_allocated_textrequest(::ledmodule::TextRequest* textrequest);

  // optional .ledmodule.PictureRequest pictureRequest = 4;
  bool has_picturerequest() const;
  void clear_picturerequest();
  static const int kPictureRequestFieldNumber = 4;
  const ::ledmodule::PictureRequest& picturerequest() const;
  ::ledmodule::PictureRequest* mutable_picturerequest();
  ::ledmodule::PictureRequest* release_picturerequest();
  void set_allocated_picturerequest(::ledmodule::PictureRequest* picturerequest);

  // optional .ledmodule.GifRequest gifRequest = 5;
  bool has_gifrequest() const;
  void clear_gifrequest();
  static const int kGifRequestFieldNumber = 5;
  const ::ledmodule::GifRequest& gifrequest() const;
  ::ledmodule::GifRequest* mutable_gifrequest();
  ::ledmodule::GifRequest* release_gifrequest();
  void set_allocated_gifrequest(::ledmodule::GifRequest* gifrequest);

  // optional .ledmodule.VideoRequest videoRequest = 6;
  bool has_videorequest() const;
  void clear_videorequest();
  static const int kVideoRequestFieldNumber = 6;
  const ::ledmodule::VideoRequest& videorequest() const;
  ::ledmodule::VideoRequest* mutable_videorequest();
  ::ledmodule::VideoRequest* release_videorequest();
  void set_allocated_videorequest(::ledmodule::VideoRequest* videorequest);

  // required .ledmodule.Request.Action action = 1;
  bool has_action() const;
  void clear_action();
  static const int kActionFieldNumber = 1;
  ::ledmodule::Request_Action action() const;
  void set_action(::ledmodule::Request_Action value);

  // @@protoc_insertion_point(class_scope:ledmodule.Request)
 private:
  void set_has_action();
  void clear_has_action();
  void set_has_sender();
  void clear_has_sender();
  void set_has_textrequest();
  void clear_has_textrequest();
  void set_has_picturerequest();
  void clear_has_picturerequest();
  void set_has_gifrequest();
  void clear_has_gifrequest();
  void set_has_videorequest();
  void clear_has_videorequest();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr sender_;
  ::ledmodule::TextRequest* textrequest_;
  ::ledmodule::PictureRequest* picturerequest_;
  ::ledmodule::GifRequest* gifrequest_;
  ::ledmodule::VideoRequest* videorequest_;
  int action_;
  friend struct protobuf_request_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class TextRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ledmodule.TextRequest) */ {
 public:
  TextRequest();
  virtual ~TextRequest();

  TextRequest(const TextRequest& from);

  inline TextRequest& operator=(const TextRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TextRequest& default_instance();

  static inline const TextRequest* internal_default_instance() {
    return reinterpret_cast<const TextRequest*>(
               &_TextRequest_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(TextRequest* other);

  // implements Message ----------------------------------------------

  inline TextRequest* New() const PROTOBUF_FINAL { return New(NULL); }

  TextRequest* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const TextRequest& from);
  void MergeFrom(const TextRequest& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(TextRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string text = 1;
  bool has_text() const;
  void clear_text();
  static const int kTextFieldNumber = 1;
  const ::std::string& text() const;
  void set_text(const ::std::string& value);
  #if LANG_CXX11
  void set_text(::std::string&& value);
  #endif
  void set_text(const char* value);
  void set_text(const char* value, size_t size);
  ::std::string* mutable_text();
  ::std::string* release_text();
  void set_allocated_text(::std::string* text);

  // @@protoc_insertion_point(class_scope:ledmodule.TextRequest)
 private:
  void set_has_text();
  void clear_has_text();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr text_;
  friend struct protobuf_request_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class PictureRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ledmodule.PictureRequest) */ {
 public:
  PictureRequest();
  virtual ~PictureRequest();

  PictureRequest(const PictureRequest& from);

  inline PictureRequest& operator=(const PictureRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PictureRequest& default_instance();

  static inline const PictureRequest* internal_default_instance() {
    return reinterpret_cast<const PictureRequest*>(
               &_PictureRequest_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(PictureRequest* other);

  // implements Message ----------------------------------------------

  inline PictureRequest* New() const PROTOBUF_FINAL { return New(NULL); }

  PictureRequest* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const PictureRequest& from);
  void MergeFrom(const PictureRequest& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(PictureRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:ledmodule.PictureRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  friend struct protobuf_request_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class GifRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ledmodule.GifRequest) */ {
 public:
  GifRequest();
  virtual ~GifRequest();

  GifRequest(const GifRequest& from);

  inline GifRequest& operator=(const GifRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GifRequest& default_instance();

  static inline const GifRequest* internal_default_instance() {
    return reinterpret_cast<const GifRequest*>(
               &_GifRequest_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(GifRequest* other);

  // implements Message ----------------------------------------------

  inline GifRequest* New() const PROTOBUF_FINAL { return New(NULL); }

  GifRequest* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const GifRequest& from);
  void MergeFrom(const GifRequest& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(GifRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required bytes gif = 1;
  bool has_gif() const;
  void clear_gif();
  static const int kGifFieldNumber = 1;
  const ::std::string& gif() const;
  void set_gif(const ::std::string& value);
  #if LANG_CXX11
  void set_gif(::std::string&& value);
  #endif
  void set_gif(const char* value);
  void set_gif(const void* value, size_t size);
  ::std::string* mutable_gif();
  ::std::string* release_gif();
  void set_allocated_gif(::std::string* gif);

  // @@protoc_insertion_point(class_scope:ledmodule.GifRequest)
 private:
  void set_has_gif();
  void clear_has_gif();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr gif_;
  friend struct protobuf_request_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class VideoRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ledmodule.VideoRequest) */ {
 public:
  VideoRequest();
  virtual ~VideoRequest();

  VideoRequest(const VideoRequest& from);

  inline VideoRequest& operator=(const VideoRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const VideoRequest& default_instance();

  static inline const VideoRequest* internal_default_instance() {
    return reinterpret_cast<const VideoRequest*>(
               &_VideoRequest_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    4;

  void Swap(VideoRequest* other);

  // implements Message ----------------------------------------------

  inline VideoRequest* New() const PROTOBUF_FINAL { return New(NULL); }

  VideoRequest* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const VideoRequest& from);
  void MergeFrom(const VideoRequest& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(VideoRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:ledmodule.VideoRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  friend struct protobuf_request_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Request

// required .ledmodule.Request.Action action = 1;
inline bool Request::has_action() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Request::set_has_action() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Request::clear_has_action() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Request::clear_action() {
  action_ = 1;
  clear_has_action();
}
inline ::ledmodule::Request_Action Request::action() const {
  // @@protoc_insertion_point(field_get:ledmodule.Request.action)
  return static_cast< ::ledmodule::Request_Action >(action_);
}
inline void Request::set_action(::ledmodule::Request_Action value) {
  assert(::ledmodule::Request_Action_IsValid(value));
  set_has_action();
  action_ = value;
  // @@protoc_insertion_point(field_set:ledmodule.Request.action)
}

// required string sender = 2;
inline bool Request::has_sender() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Request::set_has_sender() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Request::clear_has_sender() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Request::clear_sender() {
  sender_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_sender();
}
inline const ::std::string& Request::sender() const {
  // @@protoc_insertion_point(field_get:ledmodule.Request.sender)
  return sender_.GetNoArena();
}
inline void Request::set_sender(const ::std::string& value) {
  set_has_sender();
  sender_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ledmodule.Request.sender)
}
#if LANG_CXX11
inline void Request::set_sender(::std::string&& value) {
  set_has_sender();
  sender_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ledmodule.Request.sender)
}
#endif
inline void Request::set_sender(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_sender();
  sender_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ledmodule.Request.sender)
}
inline void Request::set_sender(const char* value, size_t size) {
  set_has_sender();
  sender_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ledmodule.Request.sender)
}
inline ::std::string* Request::mutable_sender() {
  set_has_sender();
  // @@protoc_insertion_point(field_mutable:ledmodule.Request.sender)
  return sender_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Request::release_sender() {
  // @@protoc_insertion_point(field_release:ledmodule.Request.sender)
  clear_has_sender();
  return sender_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Request::set_allocated_sender(::std::string* sender) {
  if (sender != NULL) {
    set_has_sender();
  } else {
    clear_has_sender();
  }
  sender_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), sender);
  // @@protoc_insertion_point(field_set_allocated:ledmodule.Request.sender)
}

// optional .ledmodule.TextRequest textRequest = 3;
inline bool Request::has_textrequest() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Request::set_has_textrequest() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Request::clear_has_textrequest() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Request::clear_textrequest() {
  if (textrequest_ != NULL) textrequest_->::ledmodule::TextRequest::Clear();
  clear_has_textrequest();
}
inline const ::ledmodule::TextRequest& Request::textrequest() const {
  // @@protoc_insertion_point(field_get:ledmodule.Request.textRequest)
  return textrequest_ != NULL ? *textrequest_
                         : *::ledmodule::TextRequest::internal_default_instance();
}
inline ::ledmodule::TextRequest* Request::mutable_textrequest() {
  set_has_textrequest();
  if (textrequest_ == NULL) {
    textrequest_ = new ::ledmodule::TextRequest;
  }
  // @@protoc_insertion_point(field_mutable:ledmodule.Request.textRequest)
  return textrequest_;
}
inline ::ledmodule::TextRequest* Request::release_textrequest() {
  // @@protoc_insertion_point(field_release:ledmodule.Request.textRequest)
  clear_has_textrequest();
  ::ledmodule::TextRequest* temp = textrequest_;
  textrequest_ = NULL;
  return temp;
}
inline void Request::set_allocated_textrequest(::ledmodule::TextRequest* textrequest) {
  delete textrequest_;
  textrequest_ = textrequest;
  if (textrequest) {
    set_has_textrequest();
  } else {
    clear_has_textrequest();
  }
  // @@protoc_insertion_point(field_set_allocated:ledmodule.Request.textRequest)
}

// optional .ledmodule.PictureRequest pictureRequest = 4;
inline bool Request::has_picturerequest() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Request::set_has_picturerequest() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Request::clear_has_picturerequest() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Request::clear_picturerequest() {
  if (picturerequest_ != NULL) picturerequest_->::ledmodule::PictureRequest::Clear();
  clear_has_picturerequest();
}
inline const ::ledmodule::PictureRequest& Request::picturerequest() const {
  // @@protoc_insertion_point(field_get:ledmodule.Request.pictureRequest)
  return picturerequest_ != NULL ? *picturerequest_
                         : *::ledmodule::PictureRequest::internal_default_instance();
}
inline ::ledmodule::PictureRequest* Request::mutable_picturerequest() {
  set_has_picturerequest();
  if (picturerequest_ == NULL) {
    picturerequest_ = new ::ledmodule::PictureRequest;
  }
  // @@protoc_insertion_point(field_mutable:ledmodule.Request.pictureRequest)
  return picturerequest_;
}
inline ::ledmodule::PictureRequest* Request::release_picturerequest() {
  // @@protoc_insertion_point(field_release:ledmodule.Request.pictureRequest)
  clear_has_picturerequest();
  ::ledmodule::PictureRequest* temp = picturerequest_;
  picturerequest_ = NULL;
  return temp;
}
inline void Request::set_allocated_picturerequest(::ledmodule::PictureRequest* picturerequest) {
  delete picturerequest_;
  picturerequest_ = picturerequest;
  if (picturerequest) {
    set_has_picturerequest();
  } else {
    clear_has_picturerequest();
  }
  // @@protoc_insertion_point(field_set_allocated:ledmodule.Request.pictureRequest)
}

// optional .ledmodule.GifRequest gifRequest = 5;
inline bool Request::has_gifrequest() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Request::set_has_gifrequest() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Request::clear_has_gifrequest() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Request::clear_gifrequest() {
  if (gifrequest_ != NULL) gifrequest_->::ledmodule::GifRequest::Clear();
  clear_has_gifrequest();
}
inline const ::ledmodule::GifRequest& Request::gifrequest() const {
  // @@protoc_insertion_point(field_get:ledmodule.Request.gifRequest)
  return gifrequest_ != NULL ? *gifrequest_
                         : *::ledmodule::GifRequest::internal_default_instance();
}
inline ::ledmodule::GifRequest* Request::mutable_gifrequest() {
  set_has_gifrequest();
  if (gifrequest_ == NULL) {
    gifrequest_ = new ::ledmodule::GifRequest;
  }
  // @@protoc_insertion_point(field_mutable:ledmodule.Request.gifRequest)
  return gifrequest_;
}
inline ::ledmodule::GifRequest* Request::release_gifrequest() {
  // @@protoc_insertion_point(field_release:ledmodule.Request.gifRequest)
  clear_has_gifrequest();
  ::ledmodule::GifRequest* temp = gifrequest_;
  gifrequest_ = NULL;
  return temp;
}
inline void Request::set_allocated_gifrequest(::ledmodule::GifRequest* gifrequest) {
  delete gifrequest_;
  gifrequest_ = gifrequest;
  if (gifrequest) {
    set_has_gifrequest();
  } else {
    clear_has_gifrequest();
  }
  // @@protoc_insertion_point(field_set_allocated:ledmodule.Request.gifRequest)
}

// optional .ledmodule.VideoRequest videoRequest = 6;
inline bool Request::has_videorequest() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Request::set_has_videorequest() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Request::clear_has_videorequest() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Request::clear_videorequest() {
  if (videorequest_ != NULL) videorequest_->::ledmodule::VideoRequest::Clear();
  clear_has_videorequest();
}
inline const ::ledmodule::VideoRequest& Request::videorequest() const {
  // @@protoc_insertion_point(field_get:ledmodule.Request.videoRequest)
  return videorequest_ != NULL ? *videorequest_
                         : *::ledmodule::VideoRequest::internal_default_instance();
}
inline ::ledmodule::VideoRequest* Request::mutable_videorequest() {
  set_has_videorequest();
  if (videorequest_ == NULL) {
    videorequest_ = new ::ledmodule::VideoRequest;
  }
  // @@protoc_insertion_point(field_mutable:ledmodule.Request.videoRequest)
  return videorequest_;
}
inline ::ledmodule::VideoRequest* Request::release_videorequest() {
  // @@protoc_insertion_point(field_release:ledmodule.Request.videoRequest)
  clear_has_videorequest();
  ::ledmodule::VideoRequest* temp = videorequest_;
  videorequest_ = NULL;
  return temp;
}
inline void Request::set_allocated_videorequest(::ledmodule::VideoRequest* videorequest) {
  delete videorequest_;
  videorequest_ = videorequest;
  if (videorequest) {
    set_has_videorequest();
  } else {
    clear_has_videorequest();
  }
  // @@protoc_insertion_point(field_set_allocated:ledmodule.Request.videoRequest)
}

// -------------------------------------------------------------------

// TextRequest

// required string text = 1;
inline bool TextRequest::has_text() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TextRequest::set_has_text() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TextRequest::clear_has_text() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TextRequest::clear_text() {
  text_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_text();
}
inline const ::std::string& TextRequest::text() const {
  // @@protoc_insertion_point(field_get:ledmodule.TextRequest.text)
  return text_.GetNoArena();
}
inline void TextRequest::set_text(const ::std::string& value) {
  set_has_text();
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ledmodule.TextRequest.text)
}
#if LANG_CXX11
inline void TextRequest::set_text(::std::string&& value) {
  set_has_text();
  text_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ledmodule.TextRequest.text)
}
#endif
inline void TextRequest::set_text(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_text();
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ledmodule.TextRequest.text)
}
inline void TextRequest::set_text(const char* value, size_t size) {
  set_has_text();
  text_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ledmodule.TextRequest.text)
}
inline ::std::string* TextRequest::mutable_text() {
  set_has_text();
  // @@protoc_insertion_point(field_mutable:ledmodule.TextRequest.text)
  return text_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* TextRequest::release_text() {
  // @@protoc_insertion_point(field_release:ledmodule.TextRequest.text)
  clear_has_text();
  return text_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TextRequest::set_allocated_text(::std::string* text) {
  if (text != NULL) {
    set_has_text();
  } else {
    clear_has_text();
  }
  text_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), text);
  // @@protoc_insertion_point(field_set_allocated:ledmodule.TextRequest.text)
}

// -------------------------------------------------------------------

// PictureRequest

// -------------------------------------------------------------------

// GifRequest

// required bytes gif = 1;
inline bool GifRequest::has_gif() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GifRequest::set_has_gif() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GifRequest::clear_has_gif() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GifRequest::clear_gif() {
  gif_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_gif();
}
inline const ::std::string& GifRequest::gif() const {
  // @@protoc_insertion_point(field_get:ledmodule.GifRequest.gif)
  return gif_.GetNoArena();
}
inline void GifRequest::set_gif(const ::std::string& value) {
  set_has_gif();
  gif_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ledmodule.GifRequest.gif)
}
#if LANG_CXX11
inline void GifRequest::set_gif(::std::string&& value) {
  set_has_gif();
  gif_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ledmodule.GifRequest.gif)
}
#endif
inline void GifRequest::set_gif(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_gif();
  gif_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ledmodule.GifRequest.gif)
}
inline void GifRequest::set_gif(const void* value, size_t size) {
  set_has_gif();
  gif_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ledmodule.GifRequest.gif)
}
inline ::std::string* GifRequest::mutable_gif() {
  set_has_gif();
  // @@protoc_insertion_point(field_mutable:ledmodule.GifRequest.gif)
  return gif_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GifRequest::release_gif() {
  // @@protoc_insertion_point(field_release:ledmodule.GifRequest.gif)
  clear_has_gif();
  return gif_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GifRequest::set_allocated_gif(::std::string* gif) {
  if (gif != NULL) {
    set_has_gif();
  } else {
    clear_has_gif();
  }
  gif_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), gif);
  // @@protoc_insertion_point(field_set_allocated:ledmodule.GifRequest.gif)
}

// -------------------------------------------------------------------

// VideoRequest

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace ledmodule

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::ledmodule::Request_Action> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ledmodule::Request_Action>() {
  return ::ledmodule::Request_Action_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_request_2eproto__INCLUDED
