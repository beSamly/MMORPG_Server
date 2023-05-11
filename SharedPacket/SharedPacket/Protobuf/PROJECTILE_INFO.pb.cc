// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PROJECTILE_INFO.proto

#include "PROJECTILE_INFO.pb.h"

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
PROTOBUF_CONSTEXPR PROJECTILE_INFO::PROJECTILE_INFO(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.position_)*/nullptr
  , /*decltype(_impl_.movedirection_)*/nullptr
  , /*decltype(_impl_.projectileid_)*/0
  , /*decltype(_impl_.projectileindex_)*/0
  , /*decltype(_impl_.speed_)*/0
  , /*decltype(_impl_.maxrange_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PROJECTILE_INFODefaultTypeInternal {
  PROTOBUF_CONSTEXPR PROJECTILE_INFODefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PROJECTILE_INFODefaultTypeInternal() {}
  union {
    PROJECTILE_INFO _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PROJECTILE_INFODefaultTypeInternal _PROJECTILE_INFO_default_instance_;
}  // namespace Protocol
static ::_pb::Metadata file_level_metadata_PROJECTILE_5fINFO_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_PROJECTILE_5fINFO_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_PROJECTILE_5fINFO_2eproto = nullptr;

const uint32_t TableStruct_PROJECTILE_5fINFO_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::PROJECTILE_INFO, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::PROJECTILE_INFO, _impl_.projectileid_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PROJECTILE_INFO, _impl_.projectileindex_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PROJECTILE_INFO, _impl_.speed_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PROJECTILE_INFO, _impl_.maxrange_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PROJECTILE_INFO, _impl_.position_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PROJECTILE_INFO, _impl_.movedirection_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Protocol::PROJECTILE_INFO)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::Protocol::_PROJECTILE_INFO_default_instance_._instance,
};

const char descriptor_table_protodef_PROJECTILE_5fINFO_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\025PROJECTILE_INFO.proto\022\010Protocol\032\rVECTO"
  "R3.proto\"\260\001\n\017PROJECTILE_INFO\022\024\n\014projecti"
  "leId\030\001 \001(\005\022\027\n\017projectileIndex\030\002 \001(\005\022\r\n\005s"
  "peed\030\003 \001(\005\022\020\n\010maxRange\030\004 \001(\005\022#\n\010position"
  "\030\005 \001(\0132\021.Protocol.VECTOR3\022(\n\rmoveDirecti"
  "on\030\006 \001(\0132\021.Protocol.VECTOR3b\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_PROJECTILE_5fINFO_2eproto_deps[1] = {
  &::descriptor_table_VECTOR3_2eproto,
};
static ::_pbi::once_flag descriptor_table_PROJECTILE_5fINFO_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_PROJECTILE_5fINFO_2eproto = {
    false, false, 235, descriptor_table_protodef_PROJECTILE_5fINFO_2eproto,
    "PROJECTILE_INFO.proto",
    &descriptor_table_PROJECTILE_5fINFO_2eproto_once, descriptor_table_PROJECTILE_5fINFO_2eproto_deps, 1, 1,
    schemas, file_default_instances, TableStruct_PROJECTILE_5fINFO_2eproto::offsets,
    file_level_metadata_PROJECTILE_5fINFO_2eproto, file_level_enum_descriptors_PROJECTILE_5fINFO_2eproto,
    file_level_service_descriptors_PROJECTILE_5fINFO_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_PROJECTILE_5fINFO_2eproto_getter() {
  return &descriptor_table_PROJECTILE_5fINFO_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_PROJECTILE_5fINFO_2eproto(&descriptor_table_PROJECTILE_5fINFO_2eproto);
namespace Protocol {

// ===================================================================

class PROJECTILE_INFO::_Internal {
 public:
  static const ::Protocol::VECTOR3& position(const PROJECTILE_INFO* msg);
  static const ::Protocol::VECTOR3& movedirection(const PROJECTILE_INFO* msg);
};

const ::Protocol::VECTOR3&
PROJECTILE_INFO::_Internal::position(const PROJECTILE_INFO* msg) {
  return *msg->_impl_.position_;
}
const ::Protocol::VECTOR3&
PROJECTILE_INFO::_Internal::movedirection(const PROJECTILE_INFO* msg) {
  return *msg->_impl_.movedirection_;
}
void PROJECTILE_INFO::clear_position() {
  if (GetArenaForAllocation() == nullptr && _impl_.position_ != nullptr) {
    delete _impl_.position_;
  }
  _impl_.position_ = nullptr;
}
void PROJECTILE_INFO::clear_movedirection() {
  if (GetArenaForAllocation() == nullptr && _impl_.movedirection_ != nullptr) {
    delete _impl_.movedirection_;
  }
  _impl_.movedirection_ = nullptr;
}
PROJECTILE_INFO::PROJECTILE_INFO(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Protocol.PROJECTILE_INFO)
}
PROJECTILE_INFO::PROJECTILE_INFO(const PROJECTILE_INFO& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  PROJECTILE_INFO* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.position_){nullptr}
    , decltype(_impl_.movedirection_){nullptr}
    , decltype(_impl_.projectileid_){}
    , decltype(_impl_.projectileindex_){}
    , decltype(_impl_.speed_){}
    , decltype(_impl_.maxrange_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_position()) {
    _this->_impl_.position_ = new ::Protocol::VECTOR3(*from._impl_.position_);
  }
  if (from._internal_has_movedirection()) {
    _this->_impl_.movedirection_ = new ::Protocol::VECTOR3(*from._impl_.movedirection_);
  }
  ::memcpy(&_impl_.projectileid_, &from._impl_.projectileid_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.maxrange_) -
    reinterpret_cast<char*>(&_impl_.projectileid_)) + sizeof(_impl_.maxrange_));
  // @@protoc_insertion_point(copy_constructor:Protocol.PROJECTILE_INFO)
}

inline void PROJECTILE_INFO::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.position_){nullptr}
    , decltype(_impl_.movedirection_){nullptr}
    , decltype(_impl_.projectileid_){0}
    , decltype(_impl_.projectileindex_){0}
    , decltype(_impl_.speed_){0}
    , decltype(_impl_.maxrange_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

PROJECTILE_INFO::~PROJECTILE_INFO() {
  // @@protoc_insertion_point(destructor:Protocol.PROJECTILE_INFO)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void PROJECTILE_INFO::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete _impl_.position_;
  if (this != internal_default_instance()) delete _impl_.movedirection_;
}

void PROJECTILE_INFO::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void PROJECTILE_INFO::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.PROJECTILE_INFO)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && _impl_.position_ != nullptr) {
    delete _impl_.position_;
  }
  _impl_.position_ = nullptr;
  if (GetArenaForAllocation() == nullptr && _impl_.movedirection_ != nullptr) {
    delete _impl_.movedirection_;
  }
  _impl_.movedirection_ = nullptr;
  ::memset(&_impl_.projectileid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.maxrange_) -
      reinterpret_cast<char*>(&_impl_.projectileid_)) + sizeof(_impl_.maxrange_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PROJECTILE_INFO::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 projectileId = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.projectileid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 projectileIndex = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.projectileindex_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 speed = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _impl_.speed_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 maxRange = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          _impl_.maxrange_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .Protocol.VECTOR3 position = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          ptr = ctx->ParseMessage(_internal_mutable_position(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .Protocol.VECTOR3 moveDirection = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 50)) {
          ptr = ctx->ParseMessage(_internal_mutable_movedirection(), ptr);
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

uint8_t* PROJECTILE_INFO::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.PROJECTILE_INFO)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 projectileId = 1;
  if (this->_internal_projectileid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_projectileid(), target);
  }

  // int32 projectileIndex = 2;
  if (this->_internal_projectileindex() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(2, this->_internal_projectileindex(), target);
  }

  // int32 speed = 3;
  if (this->_internal_speed() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(3, this->_internal_speed(), target);
  }

  // int32 maxRange = 4;
  if (this->_internal_maxrange() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(4, this->_internal_maxrange(), target);
  }

  // .Protocol.VECTOR3 position = 5;
  if (this->_internal_has_position()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(5, _Internal::position(this),
        _Internal::position(this).GetCachedSize(), target, stream);
  }

  // .Protocol.VECTOR3 moveDirection = 6;
  if (this->_internal_has_movedirection()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(6, _Internal::movedirection(this),
        _Internal::movedirection(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.PROJECTILE_INFO)
  return target;
}

size_t PROJECTILE_INFO::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.PROJECTILE_INFO)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .Protocol.VECTOR3 position = 5;
  if (this->_internal_has_position()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.position_);
  }

  // .Protocol.VECTOR3 moveDirection = 6;
  if (this->_internal_has_movedirection()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.movedirection_);
  }

  // int32 projectileId = 1;
  if (this->_internal_projectileid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_projectileid());
  }

  // int32 projectileIndex = 2;
  if (this->_internal_projectileindex() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_projectileindex());
  }

  // int32 speed = 3;
  if (this->_internal_speed() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_speed());
  }

  // int32 maxRange = 4;
  if (this->_internal_maxrange() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_maxrange());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData PROJECTILE_INFO::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    PROJECTILE_INFO::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*PROJECTILE_INFO::GetClassData() const { return &_class_data_; }


void PROJECTILE_INFO::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<PROJECTILE_INFO*>(&to_msg);
  auto& from = static_cast<const PROJECTILE_INFO&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Protocol.PROJECTILE_INFO)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_position()) {
    _this->_internal_mutable_position()->::Protocol::VECTOR3::MergeFrom(
        from._internal_position());
  }
  if (from._internal_has_movedirection()) {
    _this->_internal_mutable_movedirection()->::Protocol::VECTOR3::MergeFrom(
        from._internal_movedirection());
  }
  if (from._internal_projectileid() != 0) {
    _this->_internal_set_projectileid(from._internal_projectileid());
  }
  if (from._internal_projectileindex() != 0) {
    _this->_internal_set_projectileindex(from._internal_projectileindex());
  }
  if (from._internal_speed() != 0) {
    _this->_internal_set_speed(from._internal_speed());
  }
  if (from._internal_maxrange() != 0) {
    _this->_internal_set_maxrange(from._internal_maxrange());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void PROJECTILE_INFO::CopyFrom(const PROJECTILE_INFO& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.PROJECTILE_INFO)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PROJECTILE_INFO::IsInitialized() const {
  return true;
}

void PROJECTILE_INFO::InternalSwap(PROJECTILE_INFO* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(PROJECTILE_INFO, _impl_.maxrange_)
      + sizeof(PROJECTILE_INFO::_impl_.maxrange_)
      - PROTOBUF_FIELD_OFFSET(PROJECTILE_INFO, _impl_.position_)>(
          reinterpret_cast<char*>(&_impl_.position_),
          reinterpret_cast<char*>(&other->_impl_.position_));
}

::PROTOBUF_NAMESPACE_ID::Metadata PROJECTILE_INFO::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_PROJECTILE_5fINFO_2eproto_getter, &descriptor_table_PROJECTILE_5fINFO_2eproto_once,
      file_level_metadata_PROJECTILE_5fINFO_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Protocol::PROJECTILE_INFO*
Arena::CreateMaybeMessage< ::Protocol::PROJECTILE_INFO >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::PROJECTILE_INFO >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
