// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: redispb.proto

#ifndef PROTOBUF_redispb_2eproto__INCLUDED
#define PROTOBUF_redispb_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
namespace redispb {
}  // namespace redispb

namespace redispb {

namespace protobuf_redispb_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_redispb_2eproto

enum KeyType {
  Invalid = 0,
  KEY_META = 1,
  KEY_STRING = 2,
  KEY_HASH = 3,
  KEY_HASH_FIELD = 4,
  KEY_SET = 5,
  KEY_SET_MEMBER = 6,
  KEY_LIST = 7,
  KEY_LIST_ELEMENT = 8,
  KEY_ZSET = 9,
  KEY_ZSET_SCORE = 10,
  KEY_ZSET_SORT = 11,
  KeyType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  KeyType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool KeyType_IsValid(int value);
const KeyType KeyType_MIN = Invalid;
const KeyType KeyType_MAX = KEY_ZSET_SORT;
const int KeyType_ARRAYSIZE = KeyType_MAX + 1;

const ::google::protobuf::EnumDescriptor* KeyType_descriptor();
inline const ::std::string& KeyType_Name(KeyType value) {
  return ::google::protobuf::internal::NameOfEnum(
    KeyType_descriptor(), value);
}
inline bool KeyType_Parse(
    const ::std::string& name, KeyType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<KeyType>(
    KeyType_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace redispb

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::redispb::KeyType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::redispb::KeyType>() {
  return ::redispb::KeyType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_redispb_2eproto__INCLUDED
