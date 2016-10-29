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
	void StartUp(InputManager* const gInputManager, Renderer* const gRenderer, Windower* const gWindower,
				 SceneManager* const gSceneManager, PoolAllocator* const gPoolAllocator);
	void ShutDown();
	void PostMessage(const enum MESSAGE_TYPE msg, const enum SYSTEM_TYPE system, const void* const data);

private:
	InputManager* mbInputManager;
	PoolAllocator* mbPoolAllocator;
	Renderer* mbRenderer;
	SceneManager* mbSceneManager;
	Windower* mbWindower;
};
