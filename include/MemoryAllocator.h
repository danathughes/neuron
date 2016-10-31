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
};
