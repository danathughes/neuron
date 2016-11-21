#include <iostream>
#include <Windows.h>
#include <winhttp.h>

#include <Subsystem.h>
#include <PoolAllocator.h>
#include <Messages.h>
#include <MessageBus.h>

// ctors/dtors/Startup/Shutdown
PoolAllocator::PoolAllocator() {

}

PoolAllocator::~PoolAllocator() {

}

void PoolAllocator::StartUp(MessageBus* const mb) {
	std::cout << "Starting memory allocator and allocating a fuckton of memory.\n";
	this->msgBus = mb;
}

void PoolAllocator::ShutDown() {
	std::cout << "Stopping allocator and freeing that fuckton of memory.\n";

}

// public
void PoolAllocator::HandleMessage(const enum MESSAGE_TYPE msg, const void* const data) {
	if (data != nullptr) {
		std::cout << "PoolAllocator: I received a " << msg << " message! It contains data: " << *(int*)data << "\n";
	}
	else {
		std::cout << "PoolAllocator: I received a message! The data was a null pointer. \n";
	}
}
