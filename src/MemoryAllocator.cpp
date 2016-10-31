#include <iostream>

#include <Subsystem.h>
#include <MemoryAllocator.h>
#include <Messages.h>
#include <MessageBus.h>

// ctors/dtors/Startup/Shutdown
MemoryAllocator::MemoryAllocator() {

}

MemoryAllocator::~MemoryAllocator() {

}

void MemoryAllocator::StartUp(MessageBus* const mb) {
	std::cout << "Starting memory allocator and allocating a fuckton of memory.\n";
	this->msgBus = mb;
}

void MemoryAllocator::ShutDown() {
	std::cout << "Stopping allocator and freeing that fuckton of memory.\n";

}

// public
void MemoryAllocator::HandleMessage(const enum MESSAGE_TYPE msg, const void* const data) {
	if (data != nullptr) {
		std::cout << "MemoryAllocator: I received a " << msg << " message! It contains data: " << *(int*)data << "\n";
	}
	else {
		std::cout << "MemoryAllocator: I received a message! The data was a null pointer. \n";
	}
}
