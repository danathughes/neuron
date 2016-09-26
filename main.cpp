#include <Renderer.h>
#include <iostream>

#define DEBUG

Renderer gRenderer;

int main(int argc, const char * argv){
	// Start subsystems in the correct order
	gRenderer.startUp();

	// Begin game loop
	std::cout << "Game is running! \n";

	// Shut down systems in the correct order
	gRenderer.shutDown();
	getchar();
}