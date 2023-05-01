// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: NPCSpawnedList.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_NPCSpawnedList_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_NPCSpawnedList_2eproto

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
#include "NPCInfo.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_NPCSpawnedList_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_NPCSpawnedList_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_NPCSpawnedList_2eproto;
namespace Protocol {
class NPCSpawnedList;
struct NPCSpawnedListDefaultTypeInternal;
extern NPCSpawnedListDefaultTypeInternal _NPCSpawnedList_default_instance_;
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> ::Protocol::NPCSpawnedList* Arena::CreateMaybeMessage<::Protocol::NPCSpawnedList>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Protocol {

// ===================================================================

class NPCSpawnedList final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.NPCSpawnedList) */ {
 public:
  inline NPCSpawnedList() : NPCSpawnedList(nullptr) {}
  ~NPCSpawnedList() override;
  explicit PROTOBUF_CONSTEXPR NPCSpawnedList(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  NPCSpawnedList(const NPCSpawnedList& from);
  NPCSpawnedList(NPCSpawnedList&& from) noexcept
    : NPCSpawnedList() {
    *this = ::std::move(from);
  }

  inline NPCSpawnedList& operator=(const NPCSpawnedList& from) {
    CopyFrom(from);
    return *this;
  }
  inline NPCSpawnedList& operator=(NPCSpawnedList&& from) noexcept {
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
  static const NPCSpawnedList& default_instance() {
    return *internal_default_instance();
  }
  static inline const NPCSpawnedList* internal_default_instance() {
    return reinterpret_cast<const NPCSpawnedList*>(
               &_NPCSpawnedList_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(NPCSpawnedList& a, NPCSpawnedList& b) {
    a.Swap(&b);
  }
  inline void Swap(NPCSpawnedList* other) {
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
  void UnsafeArenaSwap(NPCSpawnedList* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  NPCSpawnedList* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<NPCSpawnedList>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const NPCSpawnedList& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const NPCSpawnedList& from) {
    NPCSpawnedList::MergeImpl(*this, from);
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
  void InternalSwap(NPCSpawnedList* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.NPCSpawnedList";
  }
  protected:
  explicit NPCSpawnedList(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNpcInfoFieldNumber = 1,
  };
  // repeated .Protocol.NPCInfo npcInfo = 1;
  int npcinfo_size() const;
  private:
  int _internal_npcinfo_size() const;
  public:
  void clear_npcinfo();
  ::Protocol::NPCInfo* mutable_npcinfo(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Protocol::NPCInfo >*
      mutable_npcinfo();
  private:
  const ::Protocol::NPCInfo& _internal_npcinfo(int index) const;
  ::Protocol::NPCInfo* _internal_add_npcinfo();
  public:
  const ::Protocol::NPCInfo& npcinfo(int index) const;
  ::Protocol::NPCInfo* add_npcinfo();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Protocol::NPCInfo >&
      npcinfo() const;

  // @@protoc_insertion_point(class_scope:Protocol.NPCSpawnedList)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Protocol::NPCInfo > npcinfo_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_NPCSpawnedList_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// NPCSpawnedList

// repeated .Protocol.NPCInfo npcInfo = 1;
inline int NPCSpawnedList::_internal_npcinfo_size() const {
  return _impl_.npcinfo_.size();
}
inline int NPCSpawnedList::npcinfo_size() const {
  return _internal_npcinfo_size();
}
inline ::Protocol::NPCInfo* NPCSpawnedList::mutable_npcinfo(int index) {
  // @@protoc_insertion_point(field_mutable:Protocol.NPCSpawnedList.npcInfo)
  return _impl_.npcinfo_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Protocol::NPCInfo >*
NPCSpawnedList::mutable_npcinfo() {
  // @@protoc_insertion_point(field_mutable_list:Protocol.NPCSpawnedList.npcInfo)
  return &_impl_.npcinfo_;
}
inline const ::Protocol::NPCInfo& NPCSpawnedList::_internal_npcinfo(int index) const {
  return _impl_.npcinfo_.Get(index);
}
inline const ::Protocol::NPCInfo& NPCSpawnedList::npcinfo(int index) const {
  // @@protoc_insertion_point(field_get:Protocol.NPCSpawnedList.npcInfo)
  return _internal_npcinfo(index);
}
inline ::Protocol::NPCInfo* NPCSpawnedList::_internal_add_npcinfo() {
  return _impl_.npcinfo_.Add();
}
inline ::Protocol::NPCInfo* NPCSpawnedList::add_npcinfo() {
  ::Protocol::NPCInfo* _add = _internal_add_npcinfo();
  // @@protoc_insertion_point(field_add:Protocol.NPCSpawnedList.npcInfo)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Protocol::NPCInfo >&
NPCSpawnedList::npcinfo() const {
  // @@protoc_insertion_point(field_list:Protocol.NPCSpawnedList.npcInfo)
  return _impl_.npcinfo_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_NPCSpawnedList_2eproto