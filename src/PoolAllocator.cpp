#include <iostream>

#include <Subsystem.h>
#include <PoolAllocator.h>
#include <Messages.h>
#include <MessageBus.h>


void PoolAllocator::StartUp(MessageBus* mb)
{
	std::cout << "Starting memory allocator and allocating a fuckton of memory.\n";
	this->msgBus = mb;
}

void PoolAllocator::ShutDown()
{
	std::cout << "Stopping allocator and freeing that fuckton of memory.\n";

}

PoolAllocator::PoolAllocator()
{

}

PoolAllocator::~PoolAllocator()
{

}

void PoolAllocator::HandleMessage(enum MESSAGE_TYPE msg, void* data) {
	std::cout << "PoolAllocator: I received a message! It contains data: " << *(int*)data << "\n";

}