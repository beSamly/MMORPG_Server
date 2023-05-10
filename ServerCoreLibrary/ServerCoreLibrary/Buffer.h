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
	uint32		GetWriteSize() { return _writeSize; }
	void		Close(uint32 writeSize);

private:
	BYTE* _buffer;
	uint32				_allocSize = 0;
	uint32				_writeSize = 0;

};
