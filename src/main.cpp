#include <Renderer.h>
#include <Windower.h>
#include <iostream>

#define DEBUG

Renderer gRenderer;
Windower gWindower;

int main(int argc, const char** argv){
	gRenderer = Renderer();
	gWindower = Windower();
	// Start subsystems in the correct order
	gWindower.StartUp();
	gRenderer.StartUp();

	// Begin game loop
	std::cout << "Game is running! \n";
	gRenderer.DrawLoop(gWindower.window, gRenderer.shaderProgram, gRenderer.VAO, gRenderer.VBO);

	// Shut down systems in the correct order
	gRenderer.ShutDown();
	gWindower.ShutDown();
	getchar();
	return 0; 
}
