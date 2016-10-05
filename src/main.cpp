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

	// Begin game loop
	std::cout << "Game is running! \n";
	gWindower.StartUp();

	// Shut down systems in the correct order
	gRenderer.shutDown();
	getchar();
	return 0; 
}