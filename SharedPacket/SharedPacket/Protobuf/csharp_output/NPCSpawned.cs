// <auto-generated>
//     Generated by the protocol buffer compiler.  DO NOT EDIT!
//     source: NPCSpawned.proto
// </auto-generated>
#pragma warning disable 1591, 0612, 3021, 8981
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace Protocol {

  /// <summary>Holder for reflection information generated from NPCSpawned.proto</summary>
  public static partial class NPCSpawnedReflection {

    #region Descriptor
    /// <summary>File descriptor for NPCSpawned.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static NPCSpawnedReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "ChBOUENTcGF3bmVkLnByb3RvEghQcm90b2NvbBoNVmVjdG9yMy5wcm90bxoO",
            "U3RhdEluZm8ucHJvdG8aDU5QQ0luZm8ucHJvdG8iewoKTlBDU3Bhd25lZBIi",
            "CgducGNJbmZvGAEgASgLMhEuUHJvdG9jb2wuTlBDSW5mbxIkCghzdGF0SW5m",
            "bxgCIAEoCzISLlByb3RvY29sLlN0YXRJbmZvEiMKCHBvc2l0aW9uGAMgASgL",
            "MhEuUHJvdG9jb2wuVmVjdG9yM2IGcHJvdG8z"));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { global::Protocol.Vector3Reflection.Descriptor, global::Protocol.StatInfoReflection.Descriptor, global::Protocol.NPCInfoReflection.Descriptor, },
          new pbr::GeneratedClrTypeInfo(null, null, new pbr::GeneratedClrTypeInfo[] {
            new pbr::GeneratedClrTypeInfo(typeof(global::Protocol.NPCSpawned), global::Protocol.NPCSpawned.Parser, new[]{ "NpcInfo", "StatInfo", "Position" }, null, null, null, null)
          }));
    }
    #endregion

  }
  #region Messages
  public sealed partial class NPCSpawned : pb::IMessage<NPCSpawned>
  #if !GOOGLE_PROTOBUF_REFSTRUCT_COMPATIBILITY_MODE
      , pb::IBufferMessage
  #endif
  {
    private static readonly pb::MessageParser<NPCSpawned> _parser = new pb::MessageParser<NPCSpawned>(() => new NPCSpawned());
    private pb::UnknownFieldSet _unknownFields;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public static pb::MessageParser<NPCSpawned> Parser { get { return _parser; } }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public static pbr::MessageDescriptor Descriptor {
      get { return global::Protocol.NPCSpawnedReflection.Descriptor.MessageTypes[0]; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    pbr::MessageDescriptor pb::IMessage.Descriptor {
      get { return Descriptor; }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public NPCSpawned() {
      OnConstruction();
    }

    partial void OnConstruction();

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public NPCSpawned(NPCSpawned other) : this() {
      npcInfo_ = other.npcInfo_ != null ? other.npcInfo_.Clone() : null;
      statInfo_ = other.statInfo_ != null ? other.statInfo_.Clone() : null;
      position_ = other.position_ != null ? other.position_.Clone() : null;
      _unknownFields = pb::UnknownFieldSet.Clone(other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public NPCSpawned Clone() {
      return new NPCSpawned(this);
    }

    /// <summary>Field number for the "npcInfo" field.</summary>
    public const int NpcInfoFieldNumber = 1;
    private global::Protocol.NPCInfo npcInfo_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public global::Protocol.NPCInfo NpcInfo {
      get { return npcInfo_; }
      set {
        npcInfo_ = value;
      }
    }

    /// <summary>Field number for the "statInfo" field.</summary>
    public const int StatInfoFieldNumber = 2;
    private global::Protocol.StatInfo statInfo_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public global::Protocol.StatInfo StatInfo {
      get { return statInfo_; }
      set {
        statInfo_ = value;
      }
    }

    /// <summary>Field number for the "position" field.</summary>
    public const int PositionFieldNumber = 3;
    private global::Protocol.Vector3 position_;
    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public global::Protocol.Vector3 Position {
      get { return position_; }
      set {
        position_ = value;
      }
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public override bool Equals(object other) {
      return Equals(other as NPCSpawned);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public bool Equals(NPCSpawned other) {
      if (ReferenceEquals(other, null)) {
        return false;
      }
      if (ReferenceEquals(other, this)) {
        return true;
      }
      if (!object.Equals(NpcInfo, other.NpcInfo)) return false;
      if (!object.Equals(StatInfo, other.StatInfo)) return false;
      if (!object.Equals(Position, other.Position)) return false;
      return Equals(_unknownFields, other._unknownFields);
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public override int GetHashCode() {
      int hash = 1;
      if (npcInfo_ != null) hash ^= NpcInfo.GetHashCode();
      if (statInfo_ != null) hash ^= StatInfo.GetHashCode();
      if (position_ != null) hash ^= Position.GetHashCode();
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
      if (npcInfo_ != null) {
        output.WriteRawTag(10);
        output.WriteMessage(NpcInfo);
      }
      if (statInfo_ != null) {
        output.WriteRawTag(18);
        output.WriteMessage(StatInfo);
      }
      if (position_ != null) {
        output.WriteRawTag(26);
        output.WriteMessage(Position);
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
      if (npcInfo_ != null) {
        output.WriteRawTag(10);
        output.WriteMessage(NpcInfo);
      }
      if (statInfo_ != null) {
        output.WriteRawTag(18);
        output.WriteMessage(StatInfo);
      }
      if (position_ != null) {
        output.WriteRawTag(26);
        output.WriteMessage(Position);
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
      if (npcInfo_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(NpcInfo);
      }
      if (statInfo_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(StatInfo);
      }
      if (position_ != null) {
        size += 1 + pb::CodedOutputStream.ComputeMessageSize(Position);
      }
      if (_unknownFields != null) {
        size += _unknownFields.CalculateSize();
      }
      return size;
    }

    [global::System.Diagnostics.DebuggerNonUserCodeAttribute]
    [global::System.CodeDom.Compiler.GeneratedCode("protoc", null)]
    public void MergeFrom(NPCSpawned other) {
      if (other == null) {
        return;
      }
      if (other.npcInfo_ != null) {
        if (npcInfo_ == null) {
          NpcInfo = new global::Protocol.NPCInfo();
        }
        NpcInfo.MergeFrom(other.NpcInfo);
      }
      if (other.statInfo_ != null) {
        if (statInfo_ == null) {
          StatInfo = new global::Protocol.StatInfo();
        }
        StatInfo.MergeFrom(other.StatInfo);
      }
      if (other.position_ != null) {
        if (position_ == null) {
          Position = new global::Protocol.Vector3();
        }
        Position.MergeFrom(other.Position);
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
          case 10: {
            if (npcInfo_ == null) {
              NpcInfo = new global::Protocol.NPCInfo();
            }
            input.ReadMessage(NpcInfo);
            break;
          }
          case 18: {
            if (statInfo_ == null) {
              StatInfo = new global::Protocol.StatInfo();
            }
            input.ReadMessage(StatInfo);
            break;
          }
          case 26: {
            if (position_ == null) {
              Position = new global::Protocol.Vector3();
            }
            input.ReadMessage(Position);
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
          case 10: {
            if (npcInfo_ == null) {
              NpcInfo = new global::Protocol.NPCInfo();
            }
            input.ReadMessage(NpcInfo);
            break;
          }
          case 18: {
            if (statInfo_ == null) {
              StatInfo = new global::Protocol.StatInfo();
            }
            input.ReadMessage(StatInfo);
            break;
          }
          case 26: {
            if (position_ == null) {
              Position = new global::Protocol.Vector3();
            }
            input.ReadMessage(Position);
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