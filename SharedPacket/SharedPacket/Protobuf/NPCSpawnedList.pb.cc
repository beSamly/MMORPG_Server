// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: NPCSpawnedList.proto

#include "NPCSpawnedList.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace Protocol {
PROTOBUF_CONSTEXPR NPCSpawnedList::NPCSpawnedList(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.npcinfo_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct NPCSpawnedListDefaultTypeInternal {
  PROTOBUF_CONSTEXPR NPCSpawnedListDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~NPCSpawnedListDefaultTypeInternal() {}
  union {
    NPCSpawnedList _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 NPCSpawnedListDefaultTypeInternal _NPCSpawnedList_default_instance_;
}  // namespace Protocol
static ::_pb::Metadata file_level_metadata_NPCSpawnedList_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_NPCSpawnedList_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_NPCSpawnedList_2eproto = nullptr;

const uint32_t TableStruct_NPCSpawnedList_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::NPCSpawnedList, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::NPCSpawnedList, _impl_.npcinfo_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Protocol::NPCSpawnedList)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::Protocol::_NPCSpawnedList_default_instance_._instance,
};

const char descriptor_table_protodef_NPCSpawnedList_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\024NPCSpawnedList.proto\022\010Protocol\032\rNPCInf"
  "o.proto\"4\n\016NPCSpawnedList\022\"\n\007npcInfo\030\001 \003"
  "(\0132\021.Protocol.NPCInfob\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_NPCSpawnedList_2eproto_deps[1] = {
  &::descriptor_table_NPCInfo_2eproto,
};
static ::_pbi::once_flag descriptor_table_NPCSpawnedList_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_NPCSpawnedList_2eproto = {
    false, false, 109, descriptor_table_protodef_NPCSpawnedList_2eproto,
    "NPCSpawnedList.proto",
    &descriptor_table_NPCSpawnedList_2eproto_once, descriptor_table_NPCSpawnedList_2eproto_deps, 1, 1,
    schemas, file_default_instances, TableStruct_NPCSpawnedList_2eproto::offsets,
    file_level_metadata_NPCSpawnedList_2eproto, file_level_enum_descriptors_NPCSpawnedList_2eproto,
    file_level_service_descriptors_NPCSpawnedList_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_NPCSpawnedList_2eproto_getter() {
  return &descriptor_table_NPCSpawnedList_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_NPCSpawnedList_2eproto(&descriptor_table_NPCSpawnedList_2eproto);
namespace Protocol {

// ===================================================================

class NPCSpawnedList::_Internal {
 public:
};

void NPCSpawnedList::clear_npcinfo() {
  _impl_.npcinfo_.Clear();
}
NPCSpawnedList::NPCSpawnedList(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Protocol.NPCSpawnedList)
}
NPCSpawnedList::NPCSpawnedList(const NPCSpawnedList& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  NPCSpawnedList* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.npcinfo_){from._impl_.npcinfo_}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:Protocol.NPCSpawnedList)
}

inline void NPCSpawnedList::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.npcinfo_){arena}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

NPCSpawnedList::~NPCSpawnedList() {
  // @@protoc_insertion_point(destructor:Protocol.NPCSpawnedList)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void NPCSpawnedList::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.npcinfo_.~RepeatedPtrField();
}

void NPCSpawnedList::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void NPCSpawnedList::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.NPCSpawnedList)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.npcinfo_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* NPCSpawnedList::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .Protocol.NPCInfo npcInfo = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_npcinfo(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* NPCSpawnedList::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.NPCSpawnedList)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .Protocol.NPCInfo npcInfo = 1;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_npcinfo_size()); i < n; i++) {
    const auto& repfield = this->_internal_npcinfo(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(1, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.NPCSpawnedList)
  return target;
}

size_t NPCSpawnedList::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.NPCSpawnedList)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .Protocol.NPCInfo npcInfo = 1;
  total_size += 1UL * this->_internal_npcinfo_size();
  for (const auto& msg : this->_impl_.npcinfo_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData NPCSpawnedList::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    NPCSpawnedList::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*NPCSpawnedList::GetClassData() const { return &_class_data_; }


void NPCSpawnedList::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<NPCSpawnedList*>(&to_msg);
  auto& from = static_cast<const NPCSpawnedList&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Protocol.NPCSpawnedList)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.npcinfo_.MergeFrom(from._impl_.npcinfo_);
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void NPCSpawnedList::CopyFrom(const NPCSpawnedList& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.NPCSpawnedList)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NPCSpawnedList::IsInitialized() const {
  return true;
}

void NPCSpawnedList::InternalSwap(NPCSpawnedList* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.npcinfo_.InternalSwap(&other->_impl_.npcinfo_);
}

::PROTOBUF_NAMESPACE_ID::Metadata NPCSpawnedList::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_NPCSpawnedList_2eproto_getter, &descriptor_table_NPCSpawnedList_2eproto_once,
      file_level_metadata_NPCSpawnedList_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Protocol::NPCSpawnedList*
Arena::CreateMaybeMessage< ::Protocol::NPCSpawnedList >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::NPCSpawnedList >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
