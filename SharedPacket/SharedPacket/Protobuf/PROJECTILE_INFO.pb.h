// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PROJECTILE_INFO.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_PROJECTILE_5fINFO_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_PROJECTILE_5fINFO_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_PROJECTILE_5fINFO_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_PROJECTILE_5fINFO_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_PROJECTILE_5fINFO_2eproto;
namespace Protocol {
class PROJECTILE_INFO;
struct PROJECTILE_INFODefaultTypeInternal;
extern PROJECTILE_INFODefaultTypeInternal _PROJECTILE_INFO_default_instance_;
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> ::Protocol::PROJECTILE_INFO* Arena::CreateMaybeMessage<::Protocol::PROJECTILE_INFO>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Protocol {

// ===================================================================

class PROJECTILE_INFO final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.PROJECTILE_INFO) */ {
 public:
  inline PROJECTILE_INFO() : PROJECTILE_INFO(nullptr) {}
  ~PROJECTILE_INFO() override;
  explicit PROTOBUF_CONSTEXPR PROJECTILE_INFO(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PROJECTILE_INFO(const PROJECTILE_INFO& from);
  PROJECTILE_INFO(PROJECTILE_INFO&& from) noexcept
    : PROJECTILE_INFO() {
    *this = ::std::move(from);
  }

  inline PROJECTILE_INFO& operator=(const PROJECTILE_INFO& from) {
    CopyFrom(from);
    return *this;
  }
  inline PROJECTILE_INFO& operator=(PROJECTILE_INFO&& from) noexcept {
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
  static const PROJECTILE_INFO& default_instance() {
    return *internal_default_instance();
  }
  static inline const PROJECTILE_INFO* internal_default_instance() {
    return reinterpret_cast<const PROJECTILE_INFO*>(
               &_PROJECTILE_INFO_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PROJECTILE_INFO& a, PROJECTILE_INFO& b) {
    a.Swap(&b);
  }
  inline void Swap(PROJECTILE_INFO* other) {
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
  void UnsafeArenaSwap(PROJECTILE_INFO* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PROJECTILE_INFO* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PROJECTILE_INFO>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PROJECTILE_INFO& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const PROJECTILE_INFO& from) {
    PROJECTILE_INFO::MergeImpl(*this, from);
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
  void InternalSwap(PROJECTILE_INFO* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.PROJECTILE_INFO";
  }
  protected:
  explicit PROJECTILE_INFO(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPositionFieldNumber = 5,
    kMoveDirectionFieldNumber = 6,
    kProjectileIdFieldNumber = 1,
    kProjectileIndexFieldNumber = 2,
    kSpeedFieldNumber = 3,
    kMaxRangeFieldNumber = 4,
  };
  // .Protocol.VECTOR3 position = 5;
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

  // .Protocol.VECTOR3 moveDirection = 6;
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

  // int32 projectileId = 1;
  void clear_projectileid();
  int32_t projectileid() const;
  void set_projectileid(int32_t value);
  private:
  int32_t _internal_projectileid() const;
  void _internal_set_projectileid(int32_t value);
  public:

  // int32 projectileIndex = 2;
  void clear_projectileindex();
  int32_t projectileindex() const;
  void set_projectileindex(int32_t value);
  private:
  int32_t _internal_projectileindex() const;
  void _internal_set_projectileindex(int32_t value);
  public:

  // int32 speed = 3;
  void clear_speed();
  int32_t speed() const;
  void set_speed(int32_t value);
  private:
  int32_t _internal_speed() const;
  void _internal_set_speed(int32_t value);
  public:

  // int32 maxRange = 4;
  void clear_maxrange();
  int32_t maxrange() const;
  void set_maxrange(int32_t value);
  private:
  int32_t _internal_maxrange() const;
  void _internal_set_maxrange(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.PROJECTILE_INFO)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::Protocol::VECTOR3* position_;
    ::Protocol::VECTOR3* movedirection_;
    int32_t projectileid_;
    int32_t projectileindex_;
    int32_t speed_;
    int32_t maxrange_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_PROJECTILE_5fINFO_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PROJECTILE_INFO

// int32 projectileId = 1;
inline void PROJECTILE_INFO::clear_projectileid() {
  _impl_.projectileid_ = 0;
}
inline int32_t PROJECTILE_INFO::_internal_projectileid() const {
  return _impl_.projectileid_;
}
inline int32_t PROJECTILE_INFO::projectileid() const {
  // @@protoc_insertion_point(field_get:Protocol.PROJECTILE_INFO.projectileId)
  return _internal_projectileid();
}
inline void PROJECTILE_INFO::_internal_set_projectileid(int32_t value) {
  
  _impl_.projectileid_ = value;
}
inline void PROJECTILE_INFO::set_projectileid(int32_t value) {
  _internal_set_projectileid(value);
  // @@protoc_insertion_point(field_set:Protocol.PROJECTILE_INFO.projectileId)
}

// int32 projectileIndex = 2;
inline void PROJECTILE_INFO::clear_projectileindex() {
  _impl_.projectileindex_ = 0;
}
inline int32_t PROJECTILE_INFO::_internal_projectileindex() const {
  return _impl_.projectileindex_;
}
inline int32_t PROJECTILE_INFO::projectileindex() const {
  // @@protoc_insertion_point(field_get:Protocol.PROJECTILE_INFO.projectileIndex)
  return _internal_projectileindex();
}
inline void PROJECTILE_INFO::_internal_set_projectileindex(int32_t value) {
  
  _impl_.projectileindex_ = value;
}
inline void PROJECTILE_INFO::set_projectileindex(int32_t value) {
  _internal_set_projectileindex(value);
  // @@protoc_insertion_point(field_set:Protocol.PROJECTILE_INFO.projectileIndex)
}

// int32 speed = 3;
inline void PROJECTILE_INFO::clear_speed() {
  _impl_.speed_ = 0;
}
inline int32_t PROJECTILE_INFO::_internal_speed() const {
  return _impl_.speed_;
}
inline int32_t PROJECTILE_INFO::speed() const {
  // @@protoc_insertion_point(field_get:Protocol.PROJECTILE_INFO.speed)
  return _internal_speed();
}
inline void PROJECTILE_INFO::_internal_set_speed(int32_t value) {
  
  _impl_.speed_ = value;
}
inline void PROJECTILE_INFO::set_speed(int32_t value) {
  _internal_set_speed(value);
  // @@protoc_insertion_point(field_set:Protocol.PROJECTILE_INFO.speed)
}

// int32 maxRange = 4;
inline void PROJECTILE_INFO::clear_maxrange() {
  _impl_.maxrange_ = 0;
}
inline int32_t PROJECTILE_INFO::_internal_maxrange() const {
  return _impl_.maxrange_;
}
inline int32_t PROJECTILE_INFO::maxrange() const {
  // @@protoc_insertion_point(field_get:Protocol.PROJECTILE_INFO.maxRange)
  return _internal_maxrange();
}
inline void PROJECTILE_INFO::_internal_set_maxrange(int32_t value) {
  
  _impl_.maxrange_ = value;
}
inline void PROJECTILE_INFO::set_maxrange(int32_t value) {
  _internal_set_maxrange(value);
  // @@protoc_insertion_point(field_set:Protocol.PROJECTILE_INFO.maxRange)
}

// .Protocol.VECTOR3 position = 5;
inline bool PROJECTILE_INFO::_internal_has_position() const {
  return this != internal_default_instance() && _impl_.position_ != nullptr;
}
inline bool PROJECTILE_INFO::has_position() const {
  return _internal_has_position();
}
inline const ::Protocol::VECTOR3& PROJECTILE_INFO::_internal_position() const {
  const ::Protocol::VECTOR3* p = _impl_.position_;
  return p != nullptr ? *p : reinterpret_cast<const ::Protocol::VECTOR3&>(
      ::Protocol::_VECTOR3_default_instance_);
}
inline const ::Protocol::VECTOR3& PROJECTILE_INFO::position() const {
  // @@protoc_insertion_point(field_get:Protocol.PROJECTILE_INFO.position)
  return _internal_position();
}
inline void PROJECTILE_INFO::unsafe_arena_set_allocated_position(
    ::Protocol::VECTOR3* position) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.position_);
  }
  _impl_.position_ = position;
  if (position) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Protocol.PROJECTILE_INFO.position)
}
inline ::Protocol::VECTOR3* PROJECTILE_INFO::release_position() {
  
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
inline ::Protocol::VECTOR3* PROJECTILE_INFO::unsafe_arena_release_position() {
  // @@protoc_insertion_point(field_release:Protocol.PROJECTILE_INFO.position)
  
  ::Protocol::VECTOR3* temp = _impl_.position_;
  _impl_.position_ = nullptr;
  return temp;
}
inline ::Protocol::VECTOR3* PROJECTILE_INFO::_internal_mutable_position() {
  
  if (_impl_.position_ == nullptr) {
    auto* p = CreateMaybeMessage<::Protocol::VECTOR3>(GetArenaForAllocation());
    _impl_.position_ = p;
  }
  return _impl_.position_;
}
inline ::Protocol::VECTOR3* PROJECTILE_INFO::mutable_position() {
  ::Protocol::VECTOR3* _msg = _internal_mutable_position();
  // @@protoc_insertion_point(field_mutable:Protocol.PROJECTILE_INFO.position)
  return _msg;
}
inline void PROJECTILE_INFO::set_allocated_position(::Protocol::VECTOR3* position) {
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
  // @@protoc_insertion_point(field_set_allocated:Protocol.PROJECTILE_INFO.position)
}

// .Protocol.VECTOR3 moveDirection = 6;
inline bool PROJECTILE_INFO::_internal_has_movedirection() const {
  return this != internal_default_instance() && _impl_.movedirection_ != nullptr;
}
inline bool PROJECTILE_INFO::has_movedirection() const {
  return _internal_has_movedirection();
}
inline const ::Protocol::VECTOR3& PROJECTILE_INFO::_internal_movedirection() const {
  const ::Protocol::VECTOR3* p = _impl_.movedirection_;
  return p != nullptr ? *p : reinterpret_cast<const ::Protocol::VECTOR3&>(
      ::Protocol::_VECTOR3_default_instance_);
}
inline const ::Protocol::VECTOR3& PROJECTILE_INFO::movedirection() const {
  // @@protoc_insertion_point(field_get:Protocol.PROJECTILE_INFO.moveDirection)
  return _internal_movedirection();
}
inline void PROJECTILE_INFO::unsafe_arena_set_allocated_movedirection(
    ::Protocol::VECTOR3* movedirection) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.movedirection_);
  }
  _impl_.movedirection_ = movedirection;
  if (movedirection) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:Protocol.PROJECTILE_INFO.moveDirection)
}
inline ::Protocol::VECTOR3* PROJECTILE_INFO::release_movedirection() {
  
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
inline ::Protocol::VECTOR3* PROJECTILE_INFO::unsafe_arena_release_movedirection() {
  // @@protoc_insertion_point(field_release:Protocol.PROJECTILE_INFO.moveDirection)
  
  ::Protocol::VECTOR3* temp = _impl_.movedirection_;
  _impl_.movedirection_ = nullptr;
  return temp;
}
inline ::Protocol::VECTOR3* PROJECTILE_INFO::_internal_mutable_movedirection() {
  
  if (_impl_.movedirection_ == nullptr) {
    auto* p = CreateMaybeMessage<::Protocol::VECTOR3>(GetArenaForAllocation());
    _impl_.movedirection_ = p;
  }
  return _impl_.movedirection_;
}
inline ::Protocol::VECTOR3* PROJECTILE_INFO::mutable_movedirection() {
  ::Protocol::VECTOR3* _msg = _internal_mutable_movedirection();
  // @@protoc_insertion_point(field_mutable:Protocol.PROJECTILE_INFO.moveDirection)
  return _msg;
}
inline void PROJECTILE_INFO::set_allocated_movedirection(::Protocol::VECTOR3* movedirection) {
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
  // @@protoc_insertion_point(field_set_allocated:Protocol.PROJECTILE_INFO.moveDirection)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_PROJECTILE_5fINFO_2eproto
