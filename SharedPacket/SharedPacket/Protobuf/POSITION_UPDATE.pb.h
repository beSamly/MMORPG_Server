// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: POSITION_UPDATE.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_POSITION_5fUPDATE_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_POSITION_5fUPDATE_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021001 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/unknown_field_set.h>
#include "VECTOR3.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_POSITION_5fUPDATE_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_POSITION_5fUPDATE_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_POSITION_5fUPDATE_2eproto;
namespace Protocol {
class POSITION_UPDATE;
struct POSITION_UPDATEDefaultTypeInternal;
extern POSITION_UPDATEDefaultTypeInternal _POSITION_UPDATE_default_instance_;
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> ::Protocol::POSITION_UPDATE* Arena::CreateMaybeMessage<::Protocol::POSITION_UPDATE>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Protocol {

// ===================================================================

class POSITION_UPDATE final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.POSITION_UPDATE) */ {
 public:
  inline POSITION_UPDATE() : POSITION_UPDATE(nullptr) {}
  ~POSITION_UPDATE() override;
  explicit PROTOBUF_CONSTEXPR POSITION_UPDATE(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  POSITION_UPDATE(const POSITION_UPDATE& from);
  POSITION_UPDATE(POSITION_UPDATE&& from) noexcept
    : POSITION_UPDATE() {
    *this = ::std::move(from);
  }

  inline POSITION_UPDATE& operator=(const POSITION_UPDATE& from) {
    CopyFrom(from);
    return *this;
  }
  inline POSITION_UPDATE& operator=(POSITION_UPDATE&& from) noexcept {
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
  static const POSITION_UPDATE& default_instance() {
    return *internal_default_instance();
  }
  static inline const POSITION_UPDATE* internal_default_instance() {
    return reinterpret_cast<const POSITION_UPDATE*>(
               &_POSITION_UPDATE_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(POSITION_UPDATE& a, POSITION_UPDATE& b) {
    a.Swap(&b);
  }
  inline void Swap(POSITION_UPDATE* other) {
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
  void UnsafeArenaSwap(POSITION_UPDATE* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  POSITION_UPDATE* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<POSITION_UPDATE>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const POSITION_UPDATE& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const POSITION_UPDATE& from) {
    POSITION_UPDATE::MergeImpl(*this, from);
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
  void InternalSwap(POSITION_UPDATE* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.POSITION_UPDATE";
  }
  protected:
  explicit POSITION_UPDATE(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPositionFieldNumber = 3,
    kMoveDirectionFieldNumber = 4,
    kTransformEntityTypeFieldNumber = 1,
    kTransformEntityIdFieldNumber = 2,
  };
  // .Protocol.VECTOR3 position = 3;
  bool has_position() const;
  private:
  bool _internal_has_position() const;
  public:
  void clear_position();
  const ::Protocol::VECTOR3& position() const;
  PROTOBUF_NODISCARD ::Protocol::VECTOR3* release_position();
  ::Protocol::VECTOR3* mutable_position();
  void set_allocated_position(::Protocol::VECTOR3* position);
  private:
  const ::Protocol::VECTOR3& _internal_position() const;
  ::Protocol::VECTOR3* _internal_mutable_position();
  public:
  void unsafe_arena_set_allocated_position(
      ::Protocol::VECTOR3* position);
  ::Protocol::VECTOR3* unsafe_arena_release_position();

  // .Protocol.VECTOR3 moveDirection = 4;
  bool has_movedirection() const;
  private:
  bool _internal_has_movedirection() const;
  public:
  void clear_movedirection();
  const ::Protocol::VECTOR3& movedirection() const;
  PROTOBUF_NODISCARD ::Protocol::VECTOR3* release_movedirection();
  ::Protocol::VECTOR3* mutable_movedirection();
  void set_allocated_movedirection(::Protocol::VECTOR3* movedirection);
  private:
  const ::Protocol::VECTOR3& _internal_movedirection() const;
  ::Protocol::VECTOR3* _internal_mutable_movedirection();
  public:
  void unsafe_arena_set_allocated_movedirection(
      ::Protocol::VECTOR3* movedirection);
  ::Protocol::VECTOR3* unsafe_arena_release_movedirection();

  // int32 transformEntityType = 1;
  void clear_transformentitytype();
  int32_t transformentitytype() const;
  void set_transformentitytype(int32_t value);
  private:
  int32_t _internal_transformentitytype() const;
  void _internal_set_transformentitytype(int32_t value);
  public:

  // int32 transformEntityId = 2;
  void clear_transformentityid();
  int32_t transformentityid() const;
  void set_transformentityid(int32_t value);
  private:
  int32_t _internal_transformentityid() const;
  void _internal_set_transformentityid(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.POSITION_UPDATE)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::Protocol::VECTOR3* position_;
    ::Protocol::VECTOR3* movedirection_;
    int32_t transformentitytype_;
    int32_t transformentityid_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_POSITION_5fUPDATE_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// POSITION_UPDATE

// int32 transformEntityType = 1;
inline void POSITION_UPDATE::clear_transformentitytype() {
  _impl_.transformentitytype_ = 0;
}
inline int32_t POSITION_UPDATE::_internal_transformentitytype() const {
  return _impl_.transformentitytype_;
}
inline int32_t POSITION_UPDATE::transformentitytype() const {
  // @@protoc_insertion_point(field_get:Protocol.POSITION_UPDATE.transformEntityType)
  return _internal_transformentitytype();
}
inline void POSITION_UPDATE::_internal_set_transformentitytype(int32_t value) {
  
  _impl_.transformentitytype_ = value;
}
inline void POSITION_UPDATE::set_transformentitytype(int32_t value) {
  _internal_set_transformentitytype(value);
  // @@protoc_insertion_point(field_set:Protocol.POSITION_UPDATE.transformEntityType)
}

// int32 transformEntityId = 2;
inline void POSITION_UPDATE::clear_transformentityid() {
  _impl_.transformentityid_ = 0;
}
inline int32_t POSITION_UPDATE::_internal_transformentityid() const {
  return _impl_.transformentityid_;
}
inline int32_t POSITION_UPDATE::transformentityid() const {
  // @@protoc_insertion_point(field_get:Protocol.POSITION_UPDATE.transformEntityId)
  return _internal_transformentityid();
}
inline void POSITION_UPDATE::_internal_set_transformentityid(int32_t value) {
  
  _impl_.transformentityid_ = value;
}
inline void POSITION_UPDATE::set_transformentityid(int32_t value) {
  _internal_set_transformentityid(value);
  // @@protoc_insertion_point(field_set:Protocol.POSITION_UPDATE.transformEntityId)
}

// .Protocol.VECTOR3 position = 3;
inline bool POSITION_UPDATE::_internal_has_position() const {
  return this != internal_default_instance() && _impl_.position_ != nullptr;
}
inline bool POSITION_UPDATE::has_position() const {
  return _internal_has_position();
}
inline const ::Protocol::VECTOR3& POSITION_UPDATE::_internal_position() const {
  const ::Protocol::VECTOR3* p = _impl_.position_;
  return p != nullptr ? *p : reinterpret_cast<const ::Protocol::VECTOR3&>(
      ::Protocol::_VECTOR3_default_instance_);
}
inline const ::Protocol::VECTOR3& POSITION_UPDATE::position() const {
  // @@protoc_insertion_point(field_get:Protocol.POSITION_UPDATE.position)
  return _internal_position();
}
inline void POSITION_UPDATE::unsafe_arena_set_allocated_position(
    ::Protocol::VECTOR3* position) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.position_);
  }
  _impl_.position_ = position;
  if (position) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Protocol.POSITION_UPDATE.position)
}
inline ::Protocol::VECTOR3* POSITION_UPDATE::release_position() {
  
  ::Protocol::VECTOR3* temp = _impl_.position_;
  _impl_.position_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::Protocol::VECTOR3* POSITION_UPDATE::unsafe_arena_release_position() {
  // @@protoc_insertion_point(field_release:Protocol.POSITION_UPDATE.position)
  
  ::Protocol::VECTOR3* temp = _impl_.position_;
  _impl_.position_ = nullptr;
  return temp;
}
inline ::Protocol::VECTOR3* POSITION_UPDATE::_internal_mutable_position() {
  
  if (_impl_.position_ == nullptr) {
    auto* p = CreateMaybeMessage<::Protocol::VECTOR3>(GetArenaForAllocation());
    _impl_.position_ = p;
  }
  return _impl_.position_;
}
inline ::Protocol::VECTOR3* POSITION_UPDATE::mutable_position() {
  ::Protocol::VECTOR3* _msg = _internal_mutable_position();
  // @@protoc_insertion_point(field_mutable:Protocol.POSITION_UPDATE.position)
  return _msg;
}
inline void POSITION_UPDATE::set_allocated_position(::Protocol::VECTOR3* position) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.position_);
  }
  if (position) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(position));
    if (message_arena != submessage_arena) {
      position = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, position, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.position_ = position;
  // @@protoc_insertion_point(field_set_allocated:Protocol.POSITION_UPDATE.position)
}

// .Protocol.VECTOR3 moveDirection = 4;
inline bool POSITION_UPDATE::_internal_has_movedirection() const {
  return this != internal_default_instance() && _impl_.movedirection_ != nullptr;
}
inline bool POSITION_UPDATE::has_movedirection() const {
  return _internal_has_movedirection();
}
inline const ::Protocol::VECTOR3& POSITION_UPDATE::_internal_movedirection() const {
  const ::Protocol::VECTOR3* p = _impl_.movedirection_;
  return p != nullptr ? *p : reinterpret_cast<const ::Protocol::VECTOR3&>(
      ::Protocol::_VECTOR3_default_instance_);
}
inline const ::Protocol::VECTOR3& POSITION_UPDATE::movedirection() const {
  // @@protoc_insertion_point(field_get:Protocol.POSITION_UPDATE.moveDirection)
  return _internal_movedirection();
}
inline void POSITION_UPDATE::unsafe_arena_set_allocated_movedirection(
    ::Protocol::VECTOR3* movedirection) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.movedirection_);
  }
  _impl_.movedirection_ = movedirection;
  if (movedirection) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Protocol.POSITION_UPDATE.moveDirection)
}
inline ::Protocol::VECTOR3* POSITION_UPDATE::release_movedirection() {
  
  ::Protocol::VECTOR3* temp = _impl_.movedirection_;
  _impl_.movedirection_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::Protocol::VECTOR3* POSITION_UPDATE::unsafe_arena_release_movedirection() {
  // @@protoc_insertion_point(field_release:Protocol.POSITION_UPDATE.moveDirection)
  
  ::Protocol::VECTOR3* temp = _impl_.movedirection_;
  _impl_.movedirection_ = nullptr;
  return temp;
}
inline ::Protocol::VECTOR3* POSITION_UPDATE::_internal_mutable_movedirection() {
  
  if (_impl_.movedirection_ == nullptr) {
    auto* p = CreateMaybeMessage<::Protocol::VECTOR3>(GetArenaForAllocation());
    _impl_.movedirection_ = p;
  }
  return _impl_.movedirection_;
}
inline ::Protocol::VECTOR3* POSITION_UPDATE::mutable_movedirection() {
  ::Protocol::VECTOR3* _msg = _internal_mutable_movedirection();
  // @@protoc_insertion_point(field_mutable:Protocol.POSITION_UPDATE.moveDirection)
  return _msg;
}
inline void POSITION_UPDATE::set_allocated_movedirection(::Protocol::VECTOR3* movedirection) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.movedirection_);
  }
  if (movedirection) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(movedirection));
    if (message_arena != submessage_arena) {
      movedirection = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, movedirection, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.movedirection_ = movedirection;
  // @@protoc_insertion_point(field_set_allocated:Protocol.POSITION_UPDATE.moveDirection)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_POSITION_5fUPDATE_2eproto
