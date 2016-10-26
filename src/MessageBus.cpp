#include <iostream>

#include <MessageBus.h>

void MessageBus::StartUp(InputManager* gInputManager, Renderer* gRenderer, Windower* gWindower,	SceneManager* gSceneManager, PoolAllocator* gPoolAllocator)
{
	std::cout << "Starting message bus, beep beep.\n";
	this->mbInputManager = gInputManager;
	this->mbRenderer = gRenderer;
	this->mbWindower = gWindower;
	this->mbSceneManager = gSceneManager;
	this->mbPoolAllocator = gPoolAllocator;
}

void MessageBus::ShutDown()
{
	std::cout << "Stopping message bus, honk honk.\n";

}

MessageBus::MessageBus()
{

}

MessageBus::~MessageBus()
{

}

void MessageBus::PostMessage(enum MESSAGE_TYPE msg, enum SYSTEM_TYPE system, void* data) {
	std::cout << "Processing message...\n";
	switch (system) {
		case INPUT_MANAGER:
			std::cout << "MessageBus: Messaging InputManager...\n";
			this->mbInputManager->HandleMessage(msg, data);
			break;
		case POOL_ALLOCATOR:
			std::cout << "MessageBus: Messaging PoolAllocator...\n";
			this->mbPoolAllocator->HandleMessage(msg, data);
			break;
		case RENDERER:
			std::cout << "MessageBus: Messaging Renderer...\n";
			this->mbRenderer->HandleMessage(msg, data);
			break;
		case SCENE_MANAGER:
			std::cout << "MessageBus: Messaging SceneManager...\n";
			this->mbSceneManager->HandleMessage(msg, data);
			break;
		case WINDOWER:
			std::cout << "MessageBus: Messaging Windower...\n";
			this->mbWindower->HandleMessage(msg, data);
			break;
		case BROADCAST:
			std::cout << "MessageBus: Messaging broadcast (all systems)...\n";
			this->mbInputManager->HandleMessage(msg, data);
			this->mbPoolAllocator->HandleMessage(msg, data);
			this->mbRenderer->HandleMessage(msg, data);
			this->mbSceneManager->HandleMessage(msg, data);
			this->mbWindower->HandleMessage(msg, data);
			break;
		default:
			break;
	}
}
