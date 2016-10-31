#pragma once

#include <Subsystem.h>
#include <Messages.h>
#include <InputManager.h>
#include <Renderer.h>
#include <Windower.h>
#include <SceneManager.h>
#include <MemoryAllocator.h>

class MessageBus
{
public:
	MessageBus();
	~MessageBus();
	void StartUp(InputManager* const gInputManager, Renderer* const gRenderer, Windower* const gWindower,
				 SceneManager* const gSceneManager, MemoryAllocator* const gMemoryAllocator);
	void ShutDown();
	void PostMessage(const enum MESSAGE_TYPE msg, const enum SYSTEM_TYPE system, const void* const data);

private:
	InputManager* mbInputManager;
	MemoryAllocator* mbMemoryAllocator;
	Renderer* mbRenderer;
	SceneManager* mbSceneManager;
	Windower* mbWindower;
};
