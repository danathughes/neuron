#pragma once

#include <Subsystem.h>

class MessageBus; // Fwd declaration to avoid compiler error, see MessageBus.h/.cpp

class PoolAllocator : public Subsystem
{
public:
	PoolAllocator();
	~PoolAllocator();
	void StartUp(MessageBus* mb);
	void ShutDown();
	void HandleMessage(enum MESSAGE_TYPE msg, void* data);
};
