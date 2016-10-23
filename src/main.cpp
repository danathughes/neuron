#include <Renderer.h>
#include <Windower.h>
#include <InputManager.h>
#include <SceneManager.h>
#include <iostream>

#define DEBUG

InputManager gInputManager;
Renderer gRenderer;
Windower gWindower;
SceneManager gSceneManager;


int main(int argc, const char** argv){
	gInputManager = InputManager();
	gRenderer = Renderer();
	gWindower = Windower();
	gSceneManager = SceneManager();
	// Start subsystems in the correct order
	gInputManager.StartUp();
	gWindower.StartUp((GLFWkeyfun)gInputManager.GLFWKeyCallback); // NOTE: For some reason, Gibson crashes if you start the renderer after the windower??
	gRenderer.StartUp();
	gSceneManager.StartUp();

	// Begin game loop
	std::cout << "Game is running! \n";
	gRenderer.DrawLoop(gWindower.window, gRenderer.shaderProgram, gRenderer.VAO, gRenderer.VBO);

	// Shut down systems in the correct order
	gSceneManager.ShutDown();
	gWindower.ShutDown();
	gRenderer.ShutDown();
	gInputManager.ShutDown();
	std::cout << "Termination successful, press any key to close. \n";
	getchar();
	return 0;
}
