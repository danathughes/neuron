#include <Renderer.h>
#include <Windower.h>
#include <InputManager.h>
#include <iostream>

#define DEBUG

InputManager gInputManager;
Renderer gRenderer;
Windower gWindower;


int main(int argc, const char** argv){
	gInputManager = InputManager();
	gRenderer = Renderer();
	gWindower = Windower();
	// Start subsystems in the correct order
	gInputManager.StartUp();
	gWindower.StartUp((GLFWkeyfun)gInputManager.GLFWKeyCallback);
	gRenderer.StartUp();

	// Begin game loop
	std::cout << "Game is running! \n";
	gRenderer.DrawLoop(gWindower.window, gRenderer.shaderProgram, gRenderer.VAO, gRenderer.VBO);

	// Shut down systems in the correct order
	gWindower.ShutDown();
	gRenderer.ShutDown();
	gInputManager.ShutDown();
	std::cout << "Termination successful, press any key to close. \n";
	getchar();
	return 0;
}
