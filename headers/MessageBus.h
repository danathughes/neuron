#pragma once

#include <Subsystem.h>
#include <Messages.h>
#include <InputManager.h>
#include <Renderer.h>
#include <Windower.h>
#include <SceneManager.h>
#include <PoolAllocator.h>

class MessageBus
{
public:
	MessageBus();
	~MessageBus();
	void StartUp(InputManager* gInputManager, Renderer* gRenderer, Windower* gWindower, SceneManager* gSceneManager, PoolAllocator* gPoolAllocator);
	void ShutDown();
	void PostMessage(enum MESSAGE_TYPE msg, enum SYSTEM_TYPE system, void* data);

private:
	InputManager* mbInputManager;
	PoolAllocator* mbPoolAllocator;
	Renderer* mbRenderer;
	SceneManager* mbSceneManager;
	Windower* mbWindower;
};
