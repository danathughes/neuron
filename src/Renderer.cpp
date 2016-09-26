#include "Renderer.h"
#include <iostream>

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
	
}

void Renderer::startUp()
{
	std::cout << "Starting rendering subsystem.\n";
}

void Renderer::shutDown()
{
	std::cout << "Shutting down rendering subsystem.\n";
}