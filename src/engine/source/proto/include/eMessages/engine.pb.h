// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: engine.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_engine_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_engine_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_engine_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_engine_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_engine_2eproto;
namespace com {
namespace wazuh {
namespace api {
namespace engine {
class GenericStatus_Response;
struct GenericStatus_ResponseDefaultTypeInternal;
extern GenericStatus_ResponseDefaultTypeInternal _GenericStatus_Response_default_instance_;
}  // namespace engine
}  // namespace api
}  // namespace wazuh
}  // namespace com
PROTOBUF_NAMESPACE_OPEN
template<> ::com::wazuh::api::engine::GenericStatus_Response* Arena::CreateMaybeMessage<::com::wazuh::api::engine::GenericStatus_Response>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace com {
namespace wazuh {
namespace api {
namespace engine {

enum ReturnStatus : int {
  UNKNOWN = 0,
  OK = 1,
  ERROR = 2,
  ReturnStatus_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  ReturnStatus_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool ReturnStatus_IsValid(int value);
constexpr ReturnStatus ReturnStatus_MIN = UNKNOWN;
constexpr ReturnStatus ReturnStatus_MAX = ERROR;
constexpr int ReturnStatus_ARRAYSIZE = ReturnStatus_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ReturnStatus_descriptor();
template<typename T>
inline const std::string& ReturnStatus_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ReturnStatus>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ReturnStatus_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ReturnStatus_descriptor(), enum_t_value);
}
inline bool ReturnStatus_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ReturnStatus* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ReturnStatus>(
    ReturnStatus_descriptor(), name, value);
}
// ===================================================================

class GenericStatus_Response final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:com.wazuh.api.engine.GenericStatus_Response) */ {
 public:
  inline GenericStatus_Response() : GenericStatus_Response(nullptr) {}
  ~GenericStatus_Response() override;
  explicit PROTOBUF_CONSTEXPR GenericStatus_Response(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  GenericStatus_Response(const GenericStatus_Response& from);
  GenericStatus_Response(GenericStatus_Response&& from) noexcept
    : GenericStatus_Response() {
    *this = ::std::move(from);
  }

  inline GenericStatus_Response& operator=(const GenericStatus_Response& from) {
    CopyFrom(from);
    return *this;
  }
  inline GenericStatus_Response& operator=(GenericStatus_Response&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const GenericStatus_Response& default_instance() {
    return *internal_default_instance();
  }
  static inline const GenericStatus_Response* internal_default_instance() {
    return reinterpret_cast<const GenericStatus_Response*>(
               &_GenericStatus_Response_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(GenericStatus_Response& a, GenericStatus_Response& b) {
    a.Swap(&b);
  }
  inline void Swap(GenericStatus_Response* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GenericStatus_Response* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  GenericStatus_Response* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<GenericStatus_Response>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const GenericStatus_Response& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const GenericStatus_Response& from) {
    GenericStatus_Response::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(GenericStatus_Response* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "com.wazuh.api.engine.GenericStatus_Response";
  }
  protected:
  explicit GenericStatus_Response(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kErrorFieldNumber = 2,
    kStatusFieldNumber = 1,
  };
  // optional string error = 2;
  bool has_error() const;
  private:
  bool _internal_has_error() const;
  public:
  void clear_error();
  const std::string& error() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_error(ArgT0&& arg0, ArgT... args);
  std::string* mutable_error();
  PROTOBUF_NODISCARD std::string* release_error();
  void set_allocated_error(std::string* error);
  private:
  const std::string& _internal_error() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_error(const std::string& value);
  std::string* _internal_mutable_error();
  public:

  // .com.wazuh.api.engine.ReturnStatus status = 1;
  void clear_status();
  ::com::wazuh::api::engine::ReturnStatus status() const;
  void set_status(::com::wazuh::api::engine::ReturnStatus value);
  private:
  ::com::wazuh::api::engine::ReturnStatus _internal_status() const;
  void _internal_set_status(::com::wazuh::api::engine::ReturnStatus value);
  public:

  // @@protoc_insertion_point(class_scope:com.wazuh.api.engine.GenericStatus_Response)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr error_;
    int status_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_engine_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GenericStatus_Response

// .com.wazuh.api.engine.ReturnStatus status = 1;
inline void GenericStatus_Response::clear_status() {
  _impl_.status_ = 0;
}
inline ::com::wazuh::api::engine::ReturnStatus GenericStatus_Response::_internal_status() const {
  return static_cast< ::com::wazuh::api::engine::ReturnStatus >(_impl_.status_);
}
inline ::com::wazuh::api::engine::ReturnStatus GenericStatus_Response::status() const {
  // @@protoc_insertion_point(field_get:com.wazuh.api.engine.GenericStatus_Response.status)
  return _internal_status();
}
inline void GenericStatus_Response::_internal_set_status(::com::wazuh::api::engine::ReturnStatus value) {
  
  _impl_.status_ = value;
}
inline void GenericStatus_Response::set_status(::com::wazuh::api::engine::ReturnStatus value) {
  _internal_set_status(value);
  // @@protoc_insertion_point(field_set:com.wazuh.api.engine.GenericStatus_Response.status)
}

// optional string error = 2;
inline bool GenericStatus_Response::_internal_has_error() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool GenericStatus_Response::has_error() const {
  return _internal_has_error();
}
inline void GenericStatus_Response::clear_error() {
  _impl_.error_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& GenericStatus_Response::error() const {
  // @@protoc_insertion_point(field_get:com.wazuh.api.engine.GenericStatus_Response.error)
  return _internal_error();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void GenericStatus_Response::set_error(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.error_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:com.wazuh.api.engine.GenericStatus_Response.error)
}
inline std::string* GenericStatus_Response::mutable_error() {
  std::string* _s = _internal_mutable_error();
  // @@protoc_insertion_point(field_mutable:com.wazuh.api.engine.GenericStatus_Response.error)
  return _s;
}
inline const std::string& GenericStatus_Response::_internal_error() const {
  return _impl_.error_.Get();
}
inline void GenericStatus_Response::_internal_set_error(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.error_.Set(value, GetArenaForAllocation());
}
inline std::string* GenericStatus_Response::_internal_mutable_error() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.error_.Mutable(GetArenaForAllocation());
}
inline std::string* GenericStatus_Response::release_error() {
  // @@protoc_insertion_point(field_release:com.wazuh.api.engine.GenericStatus_Response.error)
  if (!_internal_has_error()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.error_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.error_.IsDefault()) {
    _impl_.error_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void GenericStatus_Response::set_allocated_error(std::string* error) {
  if (error != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.error_.SetAllocated(error, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.error_.IsDefault()) {
    _impl_.error_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:com.wazuh.api.engine.GenericStatus_Response.error)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace engine
}  // namespace api
}  // namespace wazuh
}  // namespace com

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::com::wazuh::api::engine::ReturnStatus> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::com::wazuh::api::engine::ReturnStatus>() {
  return ::com::wazuh::api::engine::ReturnStatus_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_engine_2eproto
