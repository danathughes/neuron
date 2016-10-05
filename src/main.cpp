#include <Renderer.h>
#include <Windower.h>
#include <iostream>

#define DEBUG

Renderer gRenderer;
Windower gWindower;

int main(int argc, const char * argv){
	gWindower = Windower();
	gRenderer = Renderer();
	// Start subsystems in the correct order
	gRenderer.startUp();
	gWindower.StartUp();

	// Begin game loop
	std::cout << "Game is running! \n";
	gWindower.GameLoop(gWindower.window, gWindower.shaderProgram, gWindower.VAO, gWindower.VBO);

	// Shut down systems in the correct order
	gRenderer.shutDown();
	getchar();
	return 0; 
}