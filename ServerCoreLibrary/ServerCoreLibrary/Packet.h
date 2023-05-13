#pragma once
#include "PacketHeader.h"
#include "Buffer.h"

class Packet
{
public:
    Packet(int p_groupId, int p_requestId) : groupId(p_groupId), requestId(p_requestId) {}
    // Packet(REQ_GROUP_ID p_groupId, int p_packetId) : groupId(static_cast<int>(p_groupId)), packetId(p_packetId) {}

private:
    int requestId;
    int groupId;
    std::shared_ptr<Buffer> buffer;

public:
    template <typename T>
    void WriteData(T& pkt);
    void WriteData();
    void CopyData(BYTE* src, uint32 size);

    template <typename T>
    inline bool ExtractData(T& data);
    int GetId() { return requestId; }
    int GetGroupId() { return groupId; }
    int GetSize() { return buffer->GetSize(); }

    BYTE* GetByteBuffer() { return buffer->GetByteBuffer(); }
    std::shared_ptr<Buffer> GetBuffer() { return buffer; }
};

template <typename T>
inline void Packet::WriteData(T& pkt)
{
    const int dataSize = static_cast<int>(pkt.ByteSizeLong());
    const int packetSize = dataSize + sizeof(PacketHeader);

    buffer = MakeShared<Buffer>(packetSize);
    PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer->GetByteBuffer());

    header->size = packetSize;
    header->groupId = groupId;
    header->id = requestId;

    ASSERT_CRASH(pkt.SerializeToArray(&header[1], dataSize));
}

template <typename T>
inline bool Packet::ExtractData(T& data)
{
    if (data.ParseFromArray(buffer->GetByteBuffer() + sizeof(PacketHeader), buffer->GetSize() - sizeof(PacketHeader)) ==
        false)
    {
        //[TODO] Error
        std::cout << "Packet::ExtractData - Packet parse error!!" << std::endl;
        return false;
    }

    return true;
}
