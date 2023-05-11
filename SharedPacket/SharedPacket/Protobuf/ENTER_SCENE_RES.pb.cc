// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ENTER_SCENE_RES.proto

#include "ENTER_SCENE_RES.pb.h"

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
PROTOBUF_CONSTEXPR ENTER_SCENE_RES::ENTER_SCENE_RES(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.scenename_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.position_)*/nullptr
  , /*decltype(_impl_.result_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ENTER_SCENE_RESDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ENTER_SCENE_RESDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ENTER_SCENE_RESDefaultTypeInternal() {}
  union {
    ENTER_SCENE_RES _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ENTER_SCENE_RESDefaultTypeInternal _ENTER_SCENE_RES_default_instance_;
}  // namespace Protocol
static ::_pb::Metadata file_level_metadata_ENTER_5fSCENE_5fRES_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_ENTER_5fSCENE_5fRES_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_ENTER_5fSCENE_5fRES_2eproto = nullptr;

const uint32_t TableStruct_ENTER_5fSCENE_5fRES_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::ENTER_SCENE_RES, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::ENTER_SCENE_RES, _impl_.result_),
  PROTOBUF_FIELD_OFFSET(::Protocol::ENTER_SCENE_RES, _impl_.scenename_),
  PROTOBUF_FIELD_OFFSET(::Protocol::ENTER_SCENE_RES, _impl_.position_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Protocol::ENTER_SCENE_RES)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::Protocol::_ENTER_SCENE_RES_default_instance_._instance,
};

const char descriptor_table_protodef_ENTER_5fSCENE_5fRES_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\025ENTER_SCENE_RES.proto\022\010Protocol\032\rVECTO"
  "R3.proto\"Y\n\017ENTER_SCENE_RES\022\016\n\006result\030\001 "
  "\001(\005\022\021\n\tsceneName\030\002 \001(\t\022#\n\010position\030\003 \001(\013"
  "2\021.Protocol.VECTOR3b\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_ENTER_5fSCENE_5fRES_2eproto_deps[1] = {
  &::descriptor_table_VECTOR3_2eproto,
};
static ::_pbi::once_flag descriptor_table_ENTER_5fSCENE_5fRES_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_ENTER_5fSCENE_5fRES_2eproto = {
    false, false, 147, descriptor_table_protodef_ENTER_5fSCENE_5fRES_2eproto,
    "ENTER_SCENE_RES.proto",
    &descriptor_table_ENTER_5fSCENE_5fRES_2eproto_once, descriptor_table_ENTER_5fSCENE_5fRES_2eproto_deps, 1, 1,
    schemas, file_default_instances, TableStruct_ENTER_5fSCENE_5fRES_2eproto::offsets,
    file_level_metadata_ENTER_5fSCENE_5fRES_2eproto, file_level_enum_descriptors_ENTER_5fSCENE_5fRES_2eproto,
    file_level_service_descriptors_ENTER_5fSCENE_5fRES_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_ENTER_5fSCENE_5fRES_2eproto_getter() {
  return &descriptor_table_ENTER_5fSCENE_5fRES_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_ENTER_5fSCENE_5fRES_2eproto(&descriptor_table_ENTER_5fSCENE_5fRES_2eproto);
namespace Protocol {

// ===================================================================

class ENTER_SCENE_RES::_Internal {
 public:
  static const ::Protocol::VECTOR3& position(const ENTER_SCENE_RES* msg);
};

const ::Protocol::VECTOR3&
ENTER_SCENE_RES::_Internal::position(const ENTER_SCENE_RES* msg) {
  return *msg->_impl_.position_;
}
void ENTER_SCENE_RES::clear_position() {
  if (GetArenaForAllocation() == nullptr && _impl_.position_ != nullptr) {
    delete _impl_.position_;
  }
  _impl_.position_ = nullptr;
}
ENTER_SCENE_RES::ENTER_SCENE_RES(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Protocol.ENTER_SCENE_RES)
}
ENTER_SCENE_RES::ENTER_SCENE_RES(const ENTER_SCENE_RES& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  ENTER_SCENE_RES* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.scenename_){}
    , decltype(_impl_.position_){nullptr}
    , decltype(_impl_.result_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.scenename_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.scenename_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_scenename().empty()) {
    _this->_impl_.scenename_.Set(from._internal_scenename(), 
      _this->GetArenaForAllocation());
  }
  if (from._internal_has_position()) {
    _this->_impl_.position_ = new ::Protocol::VECTOR3(*from._impl_.position_);
  }
  _this->_impl_.result_ = from._impl_.result_;
  // @@protoc_insertion_point(copy_constructor:Protocol.ENTER_SCENE_RES)
}

inline void ENTER_SCENE_RES::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.scenename_){}
    , decltype(_impl_.position_){nullptr}
    , decltype(_impl_.result_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.scenename_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.scenename_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

ENTER_SCENE_RES::~ENTER_SCENE_RES() {
  // @@protoc_insertion_point(destructor:Protocol.ENTER_SCENE_RES)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ENTER_SCENE_RES::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.scenename_.Destroy();
  if (this != internal_default_instance()) delete _impl_.position_;
}

void ENTER_SCENE_RES::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void ENTER_SCENE_RES::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.ENTER_SCENE_RES)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.scenename_.ClearToEmpty();
  if (GetArenaForAllocation() == nullptr && _impl_.position_ != nullptr) {
    delete _impl_.position_;
  }
  _impl_.position_ = nullptr;
  _impl_.result_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ENTER_SCENE_RES::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 result = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.result_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string sceneName = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_scenename();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Protocol.ENTER_SCENE_RES.sceneName"));
        } else
          goto handle_unusual;
        continue;
      // .Protocol.VECTOR3 position = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_position(), ptr);
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

uint8_t* ENTER_SCENE_RES::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.ENTER_SCENE_RES)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 result = 1;
  if (this->_internal_result() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_result(), target);
  }

  // string sceneName = 2;
  if (!this->_internal_scenename().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_scenename().data(), static_cast<int>(this->_internal_scenename().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Protocol.ENTER_SCENE_RES.sceneName");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_scenename(), target);
  }

  // .Protocol.VECTOR3 position = 3;
  if (this->_internal_has_position()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, _Internal::position(this),
        _Internal::position(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.ENTER_SCENE_RES)
  return target;
}

size_t ENTER_SCENE_RES::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.ENTER_SCENE_RES)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string sceneName = 2;
  if (!this->_internal_scenename().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_scenename());
  }

  // .Protocol.VECTOR3 position = 3;
  if (this->_internal_has_position()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.position_);
  }

  // int32 result = 1;
  if (this->_internal_result() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_result());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ENTER_SCENE_RES::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    ENTER_SCENE_RES::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ENTER_SCENE_RES::GetClassData() const { return &_class_data_; }


void ENTER_SCENE_RES::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<ENTER_SCENE_RES*>(&to_msg);
  auto& from = static_cast<const ENTER_SCENE_RES&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Protocol.ENTER_SCENE_RES)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_scenename().empty()) {
    _this->_internal_set_scenename(from._internal_scenename());
  }
  if (from._internal_has_position()) {
    _this->_internal_mutable_position()->::Protocol::VECTOR3::MergeFrom(
        from._internal_position());
  }
  if (from._internal_result() != 0) {
    _this->_internal_set_result(from._internal_result());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ENTER_SCENE_RES::CopyFrom(const ENTER_SCENE_RES& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.ENTER_SCENE_RES)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ENTER_SCENE_RES::IsInitialized() const {
  return true;
}

void ENTER_SCENE_RES::InternalSwap(ENTER_SCENE_RES* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.scenename_, lhs_arena,
      &other->_impl_.scenename_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ENTER_SCENE_RES, _impl_.result_)
      + sizeof(ENTER_SCENE_RES::_impl_.result_)
      - PROTOBUF_FIELD_OFFSET(ENTER_SCENE_RES, _impl_.position_)>(
          reinterpret_cast<char*>(&_impl_.position_),
          reinterpret_cast<char*>(&other->_impl_.position_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ENTER_SCENE_RES::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ENTER_5fSCENE_5fRES_2eproto_getter, &descriptor_table_ENTER_5fSCENE_5fRES_2eproto_once,
      file_level_metadata_ENTER_5fSCENE_5fRES_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Protocol::ENTER_SCENE_RES*
Arena::CreateMaybeMessage< ::Protocol::ENTER_SCENE_RES >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::ENTER_SCENE_RES >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>