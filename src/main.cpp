#include <Renderer.h>
#include <Windower.h>
#include <iostream>

#define DEBUG

Renderer gRenderer;

int main(int argc, const char * argv){
	// Start subsystems in the correct order
	gRenderer.startUp();

	// Begin game loop
	std::cout << "Game is running! \n";
	Initialize();

	// Shut down systems in the correct order
	gRenderer.shutDown();
	getchar();
	return 0; 
}