#include "pch.h"
#include "SendBufferQueue.h"
#include "PacketHeader.h"

SendBufferQueue::SendBufferQueue(uint32 bufferSize) { serializedBuffer = new BYTE[bufferSize]; }

void SendBufferQueue::PushBuffer(shared_ptr<Buffer> buffer) { bufferQueue.push(buffer); }

BYTE* SendBufferQueue::GetAllData(int& totalDataSize)
{
    int writePos = 0;

    while (!bufferQueue.empty())
    {
        shared_ptr<Buffer> buffer = bufferQueue.front();

        int dataSize = buffer->GetSize();
        std::memcpy(serializedBuffer + writePos, buffer->GetByteBuffer(), dataSize);

        writePos += dataSize;

        PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer->GetByteBuffer());
        //  spdlog::debug("GroupId = {} id = {} size = {}", header->groupId, header->id, header->size);

        bufferQueue.pop();
    }

    totalDataSize = writePos;
    return serializedBuffer;
}
