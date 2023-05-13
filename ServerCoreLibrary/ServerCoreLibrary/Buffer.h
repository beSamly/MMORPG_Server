#pragma once
#include "pch.h"

/*----------------
        Common purpose Buffer class
-----------------*/

class Buffer
{
public:
    Buffer(BYTE* buffer, uint32 allocSize);
    Buffer(uint32 allocSize);
    ~Buffer();

    BYTE* GetByteBuffer() { return _buffer; }
    uint32 GetSize() { return _allocSize; }

private:
    BYTE* _buffer;
    uint32 _allocSize = 0;
};
