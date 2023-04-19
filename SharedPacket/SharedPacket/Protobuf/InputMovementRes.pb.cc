// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: InputMovementRes.proto

#include "InputMovementRes.pb.h"

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
PROTOBUF_CONSTEXPR InputMovementRes::InputMovementRes(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.result_)*/0
  , /*decltype(_impl_.up_)*/false
  , /*decltype(_impl_.down_)*/false
  , /*decltype(_impl_.left_)*/false
  , /*decltype(_impl_.right_)*/false
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct InputMovementResDefaultTypeInternal {
  PROTOBUF_CONSTEXPR InputMovementResDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~InputMovementResDefaultTypeInternal() {}
  union {
    InputMovementRes _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 InputMovementResDefaultTypeInternal _InputMovementRes_default_instance_;
}  // namespace Protocol
static ::_pb::Metadata file_level_metadata_InputMovementRes_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_InputMovementRes_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_InputMovementRes_2eproto = nullptr;

const uint32_t TableStruct_InputMovementRes_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::InputMovementRes, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::InputMovementRes, _impl_.result_),
  PROTOBUF_FIELD_OFFSET(::Protocol::InputMovementRes, _impl_.up_),
  PROTOBUF_FIELD_OFFSET(::Protocol::InputMovementRes, _impl_.down_),
  PROTOBUF_FIELD_OFFSET(::Protocol::InputMovementRes, _impl_.left_),
  PROTOBUF_FIELD_OFFSET(::Protocol::InputMovementRes, _impl_.right_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Protocol::InputMovementRes)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::Protocol::_InputMovementRes_default_instance_._instance,
};

const char descriptor_table_protodef_InputMovementRes_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\026InputMovementRes.proto\022\010Protocol\"Y\n\020In"
  "putMovementRes\022\016\n\006result\030\001 \001(\005\022\n\n\002up\030\002 \001"
  "(\010\022\014\n\004down\030\003 \001(\010\022\014\n\004left\030\004 \001(\010\022\r\n\005right\030"
  "\005 \001(\010b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_InputMovementRes_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_InputMovementRes_2eproto = {
    false, false, 133, descriptor_table_protodef_InputMovementRes_2eproto,
    "InputMovementRes.proto",
    &descriptor_table_InputMovementRes_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_InputMovementRes_2eproto::offsets,
    file_level_metadata_InputMovementRes_2eproto, file_level_enum_descriptors_InputMovementRes_2eproto,
    file_level_service_descriptors_InputMovementRes_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_InputMovementRes_2eproto_getter() {
  return &descriptor_table_InputMovementRes_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_InputMovementRes_2eproto(&descriptor_table_InputMovementRes_2eproto);
namespace Protocol {

// ===================================================================

class InputMovementRes::_Internal {
 public:
};

InputMovementRes::InputMovementRes(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Protocol.InputMovementRes)
}
InputMovementRes::InputMovementRes(const InputMovementRes& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  InputMovementRes* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.result_){}
    , decltype(_impl_.up_){}
    , decltype(_impl_.down_){}
    , decltype(_impl_.left_){}
    , decltype(_impl_.right_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&_impl_.result_, &from._impl_.result_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.right_) -
    reinterpret_cast<char*>(&_impl_.result_)) + sizeof(_impl_.right_));
  // @@protoc_insertion_point(copy_constructor:Protocol.InputMovementRes)
}

inline void InputMovementRes::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.result_){0}
    , decltype(_impl_.up_){false}
    , decltype(_impl_.down_){false}
    , decltype(_impl_.left_){false}
    , decltype(_impl_.right_){false}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

InputMovementRes::~InputMovementRes() {
  // @@protoc_insertion_point(destructor:Protocol.InputMovementRes)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void InputMovementRes::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void InputMovementRes::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void InputMovementRes::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.InputMovementRes)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.result_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.right_) -
      reinterpret_cast<char*>(&_impl_.result_)) + sizeof(_impl_.right_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* InputMovementRes::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
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
      // bool up = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.up_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bool down = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _impl_.down_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bool left = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          _impl_.left_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bool right = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          _impl_.right_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
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

uint8_t* InputMovementRes::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.InputMovementRes)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 result = 1;
  if (this->_internal_result() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_result(), target);
  }

  // bool up = 2;
  if (this->_internal_up() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(2, this->_internal_up(), target);
  }

  // bool down = 3;
  if (this->_internal_down() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(3, this->_internal_down(), target);
  }

  // bool left = 4;
  if (this->_internal_left() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(4, this->_internal_left(), target);
  }

  // bool right = 5;
  if (this->_internal_right() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(5, this->_internal_right(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.InputMovementRes)
  return target;
}

size_t InputMovementRes::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.InputMovementRes)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 result = 1;
  if (this->_internal_result() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_result());
  }

  // bool up = 2;
  if (this->_internal_up() != 0) {
    total_size += 1 + 1;
  }

  // bool down = 3;
  if (this->_internal_down() != 0) {
    total_size += 1 + 1;
  }

  // bool left = 4;
  if (this->_internal_left() != 0) {
    total_size += 1 + 1;
  }

  // bool right = 5;
  if (this->_internal_right() != 0) {
    total_size += 1 + 1;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData InputMovementRes::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    InputMovementRes::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*InputMovementRes::GetClassData() const { return &_class_data_; }


void InputMovementRes::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<InputMovementRes*>(&to_msg);
  auto& from = static_cast<const InputMovementRes&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Protocol.InputMovementRes)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_result() != 0) {
    _this->_internal_set_result(from._internal_result());
  }
  if (from._internal_up() != 0) {
    _this->_internal_set_up(from._internal_up());
  }
  if (from._internal_down() != 0) {
    _this->_internal_set_down(from._internal_down());
  }
  if (from._internal_left() != 0) {
    _this->_internal_set_left(from._internal_left());
  }
  if (from._internal_right() != 0) {
    _this->_internal_set_right(from._internal_right());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void InputMovementRes::CopyFrom(const InputMovementRes& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.InputMovementRes)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool InputMovementRes::IsInitialized() const {
  return true;
}

void InputMovementRes::InternalSwap(InputMovementRes* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(InputMovementRes, _impl_.right_)
      + sizeof(InputMovementRes::_impl_.right_)
      - PROTOBUF_FIELD_OFFSET(InputMovementRes, _impl_.result_)>(
          reinterpret_cast<char*>(&_impl_.result_),
          reinterpret_cast<char*>(&other->_impl_.result_));
}

::PROTOBUF_NAMESPACE_ID::Metadata InputMovementRes::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_InputMovementRes_2eproto_getter, &descriptor_table_InputMovementRes_2eproto_once,
      file_level_metadata_InputMovementRes_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Protocol::InputMovementRes*
Arena::CreateMaybeMessage< ::Protocol::InputMovementRes >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::InputMovementRes >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>