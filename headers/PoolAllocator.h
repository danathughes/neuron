#pragma once

#include <Subsystem.h>

class PoolAllocator : public Subsystem
{
public:
	PoolAllocator();
	~PoolAllocator();
	void StartUp();
	void ShutDown();
	void HandleMessage(enum MESSAGE_TYPE msg, void* data);
};
