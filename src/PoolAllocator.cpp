#include <iostream>

#include <Subsystem.h>
#include <PoolAllocator.h>
#include <Messages.h>


void PoolAllocator::StartUp()
{
	std::cout << "Starting memory allocator and allocating a fuckton of memory.\n";
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

}