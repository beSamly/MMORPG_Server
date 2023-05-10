#include "pch.h"
#include "Buffer.h"

Buffer::Buffer(BYTE* buffer, uint32 allocSize)
	: _buffer(buffer), _allocSize(allocSize)
{
}

Buffer::Buffer(uint32 allocSize)
{
	_allocSize = allocSize;
	_buffer = new BYTE[allocSize];
}

Buffer::~Buffer()
{
	delete _buffer;
}

void Buffer::Close(uint32 writeSize)
{
	ASSERT_CRASH(_allocSize >= writeSize);
	_writeSize = writeSize;
}
