#include "pch.h"
#include "Packet.h"

void Packet::WriteData() {
	const int dataSize = 0;
	const int packetSize = dataSize + sizeof(PacketHeader);

	buffer = MakeShared<Buffer>(packetSize);
	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer->GetByteBuffer());

	header->size = packetSize;
	header->groupId = groupId;
	header->id = requestId;

	buffer->Close(packetSize);
}

void Packet::CopyData(BYTE* src, uint32 size)
{
	::memcpy(buffer->GetByteBuffer(), src, size);
}
