#pragma once

#include <Messages.h>

class MessageBus; // Fwd declaration to avoid compiler error, see MessageBus.h/.cpp

class Subsystem
{
public:
	// TODO: Refactor these for correctly overriding (Windower's startup takes an arg)
	// virtual void StartUp() = 0; 
	// virtual void ShutDown() = 0;
	virtual void HandleMessage(enum MESSAGE_TYPE msg, void* data) = 0;
	MessageBus *msgBus;
};