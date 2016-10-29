#pragma once

#include <Messages.h>

class MessageBus; // Fwd declaration to avoid compiler error, see MessageBus.h/.cpp

class Subsystem
{
public:
	virtual void StartUp(MessageBus* const mb) = 0;
	virtual void ShutDown() = 0;
	virtual void HandleMessage(const enum MESSAGE_TYPE msg, const void* const data) = 0;

	MessageBus *msgBus;
};
