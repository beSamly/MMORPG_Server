// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: POSITION_UPDATE.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021, 8981
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Protocol {

  /// <summary>Holder for reflection information generated from POSITION_UPDATE.proto</summary>
  public static partial class POSITIONUPDATEReflection {

    #region Descriptor
    /// <summary>File descriptor for POSITION_UPDATE.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static POSITIONUPDATEReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "ChVQT1NJVElPTl9VUERBVEUucHJvdG8SCFByb3RvY29sGg1WRUNUT1IzLnBy",
            "b3RvIpgBCg9QT1NJVElPTl9VUERBVEUSGwoTdHJhbnNmb3JtRW50aXR5VHlw",
            "ZRgBIAEoBRIZChF0cmFuc2Zvcm1FbnRpdHlJZBgCIAEoBRIjCghwb3NpdGlv",
            "bhgDIAEoCzIRLlByb3RvY29sLlZFQ1RPUjMSKAoNbW92ZURpcmVjdGlvbhgE",
            "IAEoCzIRLlByb3RvY29sLlZFQ1RPUjNiBnByb3RvMw=="));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { global::Protocol.VECTOR3Reflection.Descriptor, },
          new pbr::GeneratedClrTypeInfo(null, null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Protocol.POSITION_UPDATE), global::Protocol.POSITION_UPDATE.Parser, new[]{ "TransformEntityType", "TransformEntityId", "Position", "MoveDirection" }, null, null, null, null)
          }));
    }
    #endregion

  }
  #region Messages
  public sealed partial class POSITION_UPDATE : pb::IMessage<POSITION_UPDATE>
  #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
      , pb::IBufferMessage
  #endif
  {
    private static readonly pb::MessageParser<POSITION_UPDATE> _parser = new pb::MessageParser<POSITION_UPDATE>(() => new POSITION_UPDATE());
    private pb::UnknownFieldSet _unknownFields;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public static pb::MessageParser<POSITION_UPDATE> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Protocol.POSITIONUPDATEReflection.Descriptor.MessageTypes[0]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public POSITION_UPDATE() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public POSITION_UPDATE(POSITION_UPDATE other) : this() {
      transformEntityType_ = other.transformEntityType_;
      transformEntityId_ = other.transformEntityId_;
      position_ = other.position_ != null ? other.position_.Clone() : null;
      moveDirection_ = other.moveDirection_ != null ? other.moveDirection_.Clone() : null;
      _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public POSITION_UPDATE Clone() {
      return new POSITION_UPDATE(this);
    }

    /// <summary>Field number for the "transformEntityType" field.</summary>
    public const int TransformEntityTypeFieldNumber = 1;
    private int transformEntityType_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public int TransformEntityType {
      get { return transformEntityType_; }
      set {
        transformEntityType_ = value;
      }
    }

    /// <summary>Field number for the "transformEntityId" field.</summary>
    public const int TransformEntityIdFieldNumber = 2;
    private int transformEntityId_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public int TransformEntityId {
      get { return transformEntityId_; }
      set {
        transformEntityId_ = value;
      }
    }

    /// <summary>Field number for the "position" field.</summary>
    public const int PositionFieldNumber = 3;
    private global::Protocol.VECTOR3 position_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public global::Protocol.VECTOR3 Position {
      get { return position_; }
      set {
        position_ = value;
      }
    }

    /// <summary>Field number for the "moveDirection" field.</summary>
    public const int MoveDirectionFieldNumber = 4;
    private global::Protocol.VECTOR3 moveDirection_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public global::Protocol.VECTOR3 MoveDirection {
      get { return moveDirection_; }
      set {
        moveDirection_ = value;
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public override bool Equals(object other) {
      return Equals(other as POSITION_UPDATE);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public bool Equals(POSITION_UPDATE other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (TransformEntityType != other.TransformEntityType) return false;
      if (TransformEntityId != other.TransformEntityId) return false;
      if (!object.Equals(Position, other.Position)) return false;
      if (!object.Equals(MoveDirection, other.MoveDirection)) return false;
      return Equals(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public override int GetHashCode() {
      int hash = 1;
      if (TransformEntityType != 0) hash ^= TransformEntityType.GetHashCode();
      if (TransformEntityId != 0) hash ^= TransformEntityId.GetHashCode();
      if (position_ != null) hash ^= Position.GetHashCode();
      if (moveDirection_ != null) hash ^= MoveDirection.GetHashCode();
      if (_unknownFields != null) {
        hash ^= _unknownFields.GetHashCode();
      }
      return hash;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public override string ToString() {
      return pb::JsonFormatter.ToDiagnosticString(this);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public void WriteTo(pb::CodedOutputStream output) {
    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
      output.WriteRawMessage(this);
    #else
      if (TransformEntityType != 0) {
        output.WriteRawTag(8);
        output.WriteInt32(TransformEntityType);
      }
      if (TransformEntityId != 0) {
        output.WriteRawTag(16);
        output.WriteInt32(TransformEntityId);
      }
      if (position_ != null) {
        output.WriteRawTag(26);
        output.WriteMessage(Position);
      }
      if (moveDirection_ != null) {
        output.WriteRawTag(34);
        output.WriteMessage(MoveDirection);
      }
      if (_unknownFields != null) {
        _unknownFields.WriteTo(output);
      }
    #endif
    }

    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    void pb::IBufferMessage.InternalWriteTo(ref pb::WriteContext output) {
      if (TransformEntityType != 0) {
        output.WriteRawTag(8);
        output.WriteInt32(TransformEntityType);
      }
      if (TransformEntityId != 0) {
        output.WriteRawTag(16);
        output.WriteInt32(TransformEntityId);
      }
      if (position_ != null) {
        output.WriteRawTag(26);
        output.WriteMessage(Position);
      }
      if (moveDirection_ != null) {
        output.WriteRawTag(34);
        output.WriteMessage(MoveDirection);
      }
      if (_unknownFields != null) {
        _unknownFields.WriteTo(ref output);
      }
    }
    #endif

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public int CalculateSize() {
      int size = 0;
      if (TransformEntityType != 0) {
        size += 1 + pb::CodedOutputStream.ComputeInt32Size(TransformEntityType);
      }
      if (TransformEntityId != 0) {
        size += 1 + pb::CodedOutputStream.ComputeInt32Size(TransformEntityId);
      }
      if (position_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Position);
      }
      if (moveDirection_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(MoveDirection);
      }
      if (_unknownFields != null) {
        size += _unknownFields.CalculateSize();
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public void MergeFrom(POSITION_UPDATE other) {
      if (other == null) {
        return;
      }
      if (other.TransformEntityType != 0) {
        TransformEntityType = other.TransformEntityType;
      }
      if (other.TransformEntityId != 0) {
        TransformEntityId = other.TransformEntityId;
      }
      if (other.position_ != null) {
        if (position_ == null) {
          Position = new global::Protocol.VECTOR3();
        }
        Position.MergeFrom(other.Position);
      }
      if (other.moveDirection_ != null) {
        if (moveDirection_ == null) {
          MoveDirection = new global::Protocol.VECTOR3();
        }
        MoveDirection.MergeFrom(other.MoveDirection);
      }
      _unknownFields = pb::UnknownFieldSet.MergeFrom(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public void MergeFrom(pb::CodedInputStream input) {
    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
      input.ReadRawMessage(this);
    #else
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            _unknownFields = pb::UnknownFieldSet.MergeFieldFrom(_unknownFields, input);
            break;
          case 8: {
            TransformEntityType = input.ReadInt32();
            break;
          }
          case 16: {
            TransformEntityId = input.ReadInt32();
            break;
          }
          case 26: {
            if (position_ == null) {
              Position = new global::Protocol.VECTOR3();
            }
            input.ReadMessage(Position);
            break;
          }
          case 34: {
            if (moveDirection_ == null) {
              MoveDirection = new global::Protocol.VECTOR3();
            }
            input.ReadMessage(MoveDirection);
            break;
          }
        }
      }
    #endif
    }

    #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    void pb::IBufferMessage.InternalMergeFrom(ref pb::ParseContext input) {
      uint tag;
      while ((tag = input.ReadTag()) != 0) {
        switch(tag) {
          default:
            _unknownFields = pb::UnknownFieldSet.MergeFieldFrom(_unknownFields, ref input);
            break;
          case 8: {
            TransformEntityType = input.ReadInt32();
            break;
          }
          case 16: {
            TransformEntityId = input.ReadInt32();
            break;
          }
          case 26: {
            if (position_ == null) {
              Position = new global::Protocol.VECTOR3();
            }
            input.ReadMessage(Position);
            break;
          }
          case 34: {
            if (moveDirection_ == null) {
              MoveDirection = new global::Protocol.VECTOR3();
            }
            input.ReadMessage(MoveDirection);
            break;
          }
        }
      }
    }
    #endif

  }

  #endregion

}

#endregion Designer generated code
