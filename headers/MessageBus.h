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
	void PostMessage(enum MESSAGE_TYPE msg, enum SYSTEM_TYPE system, void* data) const;
private:
	InputManager* mbInputManager;
	Renderer* mbRenderer;
	Windower* mbWindower;
	SceneManager* mbSceneManager;
	PoolAllocator* mbPoolAllocator;
};
