#pragma once
#include "Buffer.h"

class Buffer;

using std::queue;
using std::shared_ptr;

class SendBufferQueue
{
public:
    SendBufferQueue(uint32 bufferSize);
    void PushBuffer(shared_ptr<Buffer> buffer);
    BYTE* GetAllData(int& totalDataSize);

private:
    BYTE* serializedBuffer;
    queue<shared_ptr<Buffer>> bufferQueue;
};