#include <iostream>

#include <Renderer.h>
#include <Windower.h>
#include <InputManager.h>
#include <SceneManager.h>
#include <MessageBus.h>
#include <PoolAllocator.h>

#define DEBUG

PoolAllocator gPoolAllocator;
MessageBus gMessageBus;
InputManager gInputManager;
Renderer gRenderer;
Windower gWindower;
SceneManager gSceneManager;

int main(int argc, const char** argv){
	gPoolAllocator = PoolAllocator();
	gInputManager = InputManager();
	gRenderer = Renderer();
	gWindower = Windower();
	gSceneManager = SceneManager();
	gMessageBus = MessageBus();

	// Start subsystems in the correct order
	gPoolAllocator.StartUp(&gMessageBus);
	gInputManager.StartUp(&gMessageBus);
	gWindower.StartUp(&gInputManager, &gMessageBus); // NOTE: For some reason, Gibson crashes if you start the renderer after the windower??
	gRenderer.StartUp(&gMessageBus);
	gSceneManager.StartUp(&gMessageBus);
	gMessageBus.StartUp(&gInputManager, &gRenderer, &gWindower, &gSceneManager, &gPoolAllocator);

	// Begin game loop
	std::cout << "Game is running! \n";
	gRenderer.DrawLoop(gWindower.window, gRenderer.shaderProgram, gRenderer.VAO, gRenderer.VBO);

	// Shut down systems in the correct order
	gSceneManager.ShutDown();
	gWindower.ShutDown();
	gRenderer.ShutDown();
	gInputManager.ShutDown();
	gMessageBus.ShutDown();
	std::cout << "Termination successful, press any key to close. \n";
	getchar();
	return 0;
}
