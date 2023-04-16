#pragma once
#include "PacketHeader.h"
#include "SendBuffer.h"

class Packet
{
public:
    Packet(int p_groupId, int p_packetId) : groupId(p_groupId), packetId(p_packetId) {}
    //Packet(PACKET_GROUP_ID p_groupId, int p_packetId) : groupId(static_cast<int>(p_groupId)), packetId(p_packetId) {}

private:
    int packetId;
    int groupId;
    std::shared_ptr<SendBuffer> send_buffer;

public:
    template <typename T>
    void WriteData(T& pkt);
    void WriteData();
    int GetSize() { return send_buffer->WriteSize(); }

    std::shared_ptr<SendBuffer> GetSendBuffer() { return send_buffer; };
    BYTE* GetByteBuffer() { return send_buffer->GetBuffer(); }
};

template <typename T>
inline void Packet::WriteData(T& pkt)
{
    const int dataSize = static_cast<int>(pkt.ByteSizeLong());
    const int packetSize = dataSize + sizeof(PacketHeader);

    send_buffer = MakeShared<SendBuffer>(packetSize);
    PacketHeader* header = reinterpret_cast<PacketHeader*>(send_buffer->Buffer());

    header->size = packetSize;
    header->groupId = groupId;
    header->id = packetId;

    ASSERT_CRASH(pkt.SerializeToArray(&header[1], dataSize));
    send_buffer->Close(packetSize);
}
