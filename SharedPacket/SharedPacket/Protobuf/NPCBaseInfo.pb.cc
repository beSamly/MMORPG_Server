// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: NPCBaseInfo.proto

#include "NPCBaseInfo.pb.h"

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
PROTOBUF_CONSTEXPR NPCBaseInfo::NPCBaseInfo(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.npcname_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.npcindex_)*/0
  , /*decltype(_impl_.npcid_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct NPCBaseInfoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR NPCBaseInfoDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~NPCBaseInfoDefaultTypeInternal() {}
  union {
    NPCBaseInfo _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 NPCBaseInfoDefaultTypeInternal _NPCBaseInfo_default_instance_;
}  // namespace Protocol
static ::_pb::Metadata file_level_metadata_NPCBaseInfo_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_NPCBaseInfo_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_NPCBaseInfo_2eproto = nullptr;

const uint32_t TableStruct_NPCBaseInfo_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::NPCBaseInfo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::NPCBaseInfo, _impl_.npcindex_),
  PROTOBUF_FIELD_OFFSET(::Protocol::NPCBaseInfo, _impl_.npcname_),
  PROTOBUF_FIELD_OFFSET(::Protocol::NPCBaseInfo, _impl_.npcid_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Protocol::NPCBaseInfo)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::Protocol::_NPCBaseInfo_default_instance_._instance,
};

const char descriptor_table_protodef_NPCBaseInfo_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021NPCBaseInfo.proto\022\010Protocol\"\?\n\013NPCBase"
  "Info\022\020\n\010npcIndex\030\001 \001(\005\022\017\n\007npcName\030\002 \001(\t\022"
  "\r\n\005npcId\030\003 \001(\005b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_NPCBaseInfo_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_NPCBaseInfo_2eproto = {
    false, false, 102, descriptor_table_protodef_NPCBaseInfo_2eproto,
    "NPCBaseInfo.proto",
    &descriptor_table_NPCBaseInfo_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_NPCBaseInfo_2eproto::offsets,
    file_level_metadata_NPCBaseInfo_2eproto, file_level_enum_descriptors_NPCBaseInfo_2eproto,
    file_level_service_descriptors_NPCBaseInfo_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_NPCBaseInfo_2eproto_getter() {
  return &descriptor_table_NPCBaseInfo_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_NPCBaseInfo_2eproto(&descriptor_table_NPCBaseInfo_2eproto);
namespace Protocol {

// ===================================================================

class NPCBaseInfo::_Internal {
 public:
};

NPCBaseInfo::NPCBaseInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Protocol.NPCBaseInfo)
}
NPCBaseInfo::NPCBaseInfo(const NPCBaseInfo& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  NPCBaseInfo* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.npcname_){}
    , decltype(_impl_.npcindex_){}
    , decltype(_impl_.npcid_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.npcname_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.npcname_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_npcname().empty()) {
    _this->_impl_.npcname_.Set(from._internal_npcname(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.npcindex_, &from._impl_.npcindex_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.npcid_) -
    reinterpret_cast<char*>(&_impl_.npcindex_)) + sizeof(_impl_.npcid_));
  // @@protoc_insertion_point(copy_constructor:Protocol.NPCBaseInfo)
}

inline void NPCBaseInfo::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.npcname_){}
    , decltype(_impl_.npcindex_){0}
    , decltype(_impl_.npcid_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.npcname_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.npcname_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

NPCBaseInfo::~NPCBaseInfo() {
  // @@protoc_insertion_point(destructor:Protocol.NPCBaseInfo)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void NPCBaseInfo::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.npcname_.Destroy();
}

void NPCBaseInfo::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void NPCBaseInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.NPCBaseInfo)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.npcname_.ClearToEmpty();
  ::memset(&_impl_.npcindex_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.npcid_) -
      reinterpret_cast<char*>(&_impl_.npcindex_)) + sizeof(_impl_.npcid_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* NPCBaseInfo::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 npcIndex = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.npcindex_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string npcName = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_npcname();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Protocol.NPCBaseInfo.npcName"));
        } else
          goto handle_unusual;
        continue;
      // int32 npcId = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _impl_.npcid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
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

uint8_t* NPCBaseInfo::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.NPCBaseInfo)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 npcIndex = 1;
  if (this->_internal_npcindex() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_npcindex(), target);
  }

  // string npcName = 2;
  if (!this->_internal_npcname().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_npcname().data(), static_cast<int>(this->_internal_npcname().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Protocol.NPCBaseInfo.npcName");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_npcname(), target);
  }

  // int32 npcId = 3;
  if (this->_internal_npcid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(3, this->_internal_npcid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.NPCBaseInfo)
  return target;
}

size_t NPCBaseInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.NPCBaseInfo)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string npcName = 2;
  if (!this->_internal_npcname().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_npcname());
  }

  // int32 npcIndex = 1;
  if (this->_internal_npcindex() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_npcindex());
  }

  // int32 npcId = 3;
  if (this->_internal_npcid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_npcid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData NPCBaseInfo::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    NPCBaseInfo::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*NPCBaseInfo::GetClassData() const { return &_class_data_; }


void NPCBaseInfo::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<NPCBaseInfo*>(&to_msg);
  auto& from = static_cast<const NPCBaseInfo&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Protocol.NPCBaseInfo)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_npcname().empty()) {
    _this->_internal_set_npcname(from._internal_npcname());
  }
  if (from._internal_npcindex() != 0) {
    _this->_internal_set_npcindex(from._internal_npcindex());
  }
  if (from._internal_npcid() != 0) {
    _this->_internal_set_npcid(from._internal_npcid());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void NPCBaseInfo::CopyFrom(const NPCBaseInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.NPCBaseInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NPCBaseInfo::IsInitialized() const {
  return true;
}

void NPCBaseInfo::InternalSwap(NPCBaseInfo* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.npcname_, lhs_arena,
      &other->_impl_.npcname_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(NPCBaseInfo, _impl_.npcid_)
      + sizeof(NPCBaseInfo::_impl_.npcid_)
      - PROTOBUF_FIELD_OFFSET(NPCBaseInfo, _impl_.npcindex_)>(
          reinterpret_cast<char*>(&_impl_.npcindex_),
          reinterpret_cast<char*>(&other->_impl_.npcindex_));
}

::PROTOBUF_NAMESPACE_ID::Metadata NPCBaseInfo::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_NPCBaseInfo_2eproto_getter, &descriptor_table_NPCBaseInfo_2eproto_once,
      file_level_metadata_NPCBaseInfo_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Protocol::NPCBaseInfo*
Arena::CreateMaybeMessage< ::Protocol::NPCBaseInfo >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::NPCBaseInfo >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
