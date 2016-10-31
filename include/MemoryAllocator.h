#pragma once

#include <Subsystem.h>

class MessageBus; // Fwd declaration to avoid compiler error, see MessageBus.h/.cpp

class MemoryAllocator : public Subsystem
{
public:
	MemoryAllocator();
	~MemoryAllocator();
	void StartUp(MessageBus* const mb);
	void ShutDown();
	void HandleMessage(const enum MESSAGE_TYPE msg, const void* const data);
	void GibMalloc();
	void GibFree();

private:
	void Mark();
	void Sweep();
};

enum MEMORY_COLOR
{
	WHITE = 1,
	GREY = 2,
	BLACK = 3
};

struct MemoryUnit
{
public:
	void* data;
	enum MEMORY_COLOR color;
};


