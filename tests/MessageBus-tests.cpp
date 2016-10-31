#include <iostream>

#include <Renderer.h>
#include <Windower.h>
#include <InputManager.h>
#include <SceneManager.h>
#include <MessageBus.h>
#include <MemoryAllocator.h>
#include <Messages.h>

MemoryAllocator gMemoryAllocator;
MessageBus gMessageBus;
InputManager gInputManager;
Renderer gRenderer;
Windower gWindower;
SceneManager gSceneManager;

void MessageBusTests(){
	gMemoryAllocator = MemoryAllocator();
	gInputManager = InputManager();
	gRenderer = Renderer();
	gWindower = Windower();
	gSceneManager = SceneManager();
	gMessageBus = MessageBus();

	// Start subsystems in the correct order
	gMemoryAllocator.StartUp(&gMessageBus);
	gInputManager.StartUp(&gMessageBus);
	gWindower.StartUp(&gInputManager, &gMessageBus); // NOTE: For some reason, Gibson crashes if you start the renderer after the windower??
	gRenderer.StartUp(&gMessageBus);
	gSceneManager.StartUp(&gMessageBus);
	gMessageBus.StartUp(&gInputManager, &gRenderer, &gWindower, &gSceneManager, &gMemoryAllocator);

	int foo = 1;
	gWindower.msgBus->PostMessage(MESSAGE_TYPE::DRAW_THING, SYSTEM_TYPE::RENDERER, &foo);
}
