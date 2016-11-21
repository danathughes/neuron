#pragma once

#include <Windows.h>
#include <winhttp.h>

#include <Subsystem.h>

class MessageBus; // Fwd declaration to avoid compiler error, see MessageBus.h/.cpp

class PoolAllocator : public Subsystem
{
public:
	PoolAllocator();
	~PoolAllocator();
	void StartUp(MessageBus* const mb);
	void ShutDown();
	void HandleMessage(const enum MESSAGE_TYPE msg, const void* const data);
};
