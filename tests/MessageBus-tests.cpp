#include <iostream>

#include <Renderer.h>
#include <Windower.h>
#include <InputManager.h>
#include <SceneManager.h>
#include <MessageBus.h>
#include <PoolAllocator.h>
#include <Messages.h>

PoolAllocator gPoolAllocator;
MessageBus gMessageBus;
InputManager gInputManager;
Renderer gRenderer;
Windower gWindower;
SceneManager gSceneManager;

void MessageBusTests(){
	gPoolAllocator = PoolAllocator();
	gInputManager = InputManager();
	gRenderer = Renderer();
	gWindower = Windower();
	gSceneManager = SceneManager();
	gMessageBus = MessageBus();

	// Start subsystems in the correct order
	gPoolAllocator.StartUp(&gMessageBus);
	gInputManager.StartUp(&gMessageBus);
	gWindower.StartUp((GLFWkeyfun)gInputManager.GLFWKeyCallback, &gMessageBus); // NOTE: For some reason, Gibson crashes if you start the renderer after the windower??
	gRenderer.StartUp(&gMessageBus);
	gSceneManager.StartUp(&gMessageBus);
	gMessageBus.StartUp(&gInputManager, &gRenderer, &gWindower, &gSceneManager, &gPoolAllocator);

	int foo = 1;
	gWindower.msgBus->PostMessage(MESSAGE_TYPE::DRAW_THING, SYSTEM_TYPE::RENDERER, &foo);
}