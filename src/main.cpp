#include <iostream>

#include <Renderer.h>
#include <Windower.h>
#include <InputManager.h>
#include <SceneManager.h>
#include <MessageBus.h>
#include <MemoryAllocator.h>

#define DEBUG

MemoryAllocator gMemoryAllocator;
MessageBus gMessageBus;
InputManager gInputManager;
Renderer gRenderer;
Windower gWindower;
SceneManager gSceneManager;

int main(int argc, const char** argv){
	gMemoryAllocator = MemoryAllocator();
	gInputManager = InputManager();
	gRenderer = Renderer();
	gWindower = Windower();
	gSceneManager = SceneManager();
	gMessageBus = MessageBus();

	// Start subsystems in the correct order
	gMemoryAllocator.StartUp(&gMessageBus);
	gInputManager.StartUp(&gMessageBus);
	gWindower.StartUp(&gMessageBus); // NOTE: For some reason, Gibson crashes if you start the renderer after the windower??
	gWindower.SetUpCallback(&gInputManager); // FIXME: Special method needed to initialize GLFW;
	gRenderer.StartUp(&gMessageBus);
	gSceneManager.StartUp(&gMessageBus);
	gMessageBus.StartUp(&gInputManager, &gRenderer, &gWindower, &gSceneManager, &gMemoryAllocator);

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
