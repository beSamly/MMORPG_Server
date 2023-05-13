#include "pch.h"
#include "Packet.h"
#include <cassert>

void Packet::WriteData()
{
    if (buffer != nullptr)
    {
        // Data can be written to packet only once!
        assert(false);
    }

    const int dataSize = 0;
    const int packetSize = dataSize + sizeof(PacketHeader);

    buffer = MakeShared<Buffer>(packetSize);
    PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer->GetByteBuffer());

    header->size = packetSize;
    header->groupId = groupId;
    header->id = requestId;
}

void Packet::CopyData(BYTE* src, uint32 size)
{
    if (buffer != nullptr)
    {
        // Data can be copied to packet only once!
        assert(false);
    }

    buffer = MakeShared<Buffer>(size);
    ::memcpy(buffer->GetByteBuffer(), src, size);
}
