#include <iostream>

#include <MessageBus.h>

void MessageBus::StartUp(InputManager* const gInputManager, Renderer* const gRenderer, Windower* const gWindower,
	SceneManager* const gSceneManager, PoolAllocator* const gPoolAllocator)
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

void MessageBus::PostMessage(enum MESSAGE_TYPE msg, enum SYSTEM_TYPE system, void* data) const {
	switch (system) {
		case INPUT_MANAGER:
			this->mbInputManager->HandleMessage(msg, data);
			break;
		case POOL_ALLOCATOR:
			this->mbPoolAllocator->HandleMessage(msg, data);
			break;
		case RENDERER:
			this->mbRenderer->HandleMessage(msg, data);
			break;
		case SCENE_MANAGER:
			this->mbSceneManager->HandleMessage(msg, data);
			break;
		case WINDOWER:
			this->mbWindower->HandleMessage(msg, data);
			break;
		case BROADCAST:
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
