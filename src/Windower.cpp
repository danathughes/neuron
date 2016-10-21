#include <iostream>
#include <Windower.h>
#include <Renderer.h>
#include <InputManager.h>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <glfw3.h>

// Window dimensions
const GLuint WIDTH = 1200, HEIGHT = 800;

void Windower::StartUp(GLFWkeyfun callback)
{
	std::cout << "Starting windowing subsystem.\n";
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	this->window = glfwCreateWindow(WIDTH, HEIGHT, "Gibson Engine", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	//glfwSetKeyCallback(window, callback);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	// Define the viewport dimensions
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
}


void Windower::ShutDown()
{
	std::cout << "Shutting down windowing subsystem.\n";
}


Windower::Windower()
{

}

Windower::~Windower()
{

}
