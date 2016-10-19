#include <iostream>
#include <Windower.h>
#include <Renderer.h>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <glfw3.h>

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 1200, HEIGHT = 800;

void Windower::StartUp()
{
	std::cout << "Starting windowing subsystem.\n";
	// Init GLFW
	glfwInit();
	std::cout << "Windower.cpp:Line 23.\n";
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	std::cout << "Windower.cpp:Line 26.\n";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	std::cout << "Windower.cpp:Line 28.\n";
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	std::cout << "Windower.cpp:Line 30.\n";
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	this->window = glfwCreateWindow(WIDTH, HEIGHT, "Gibson Engine", nullptr, nullptr);
	std::cout << "Windower.cpp:Line 35.\n";
	glfwMakeContextCurrent(window);
	std::cout << "Windower.cpp:Line 37.\n";
	// Set the required callback functions
	//FIXME: glfwSetKeyCallback(window, key_callback);
	std::cout << "Windower.cpp:Line 40.\n";
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	std::cout << "Windower.cpp:Line 43.\n";
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	std::cout << "Windower.cpp:Line 46.\n";
	// Define the viewport dimensions
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	std::cout << "Windower.cpp:Line 50.\n";
	glViewport(0, 0, width, height);
	std::cout << "Windower.cpp:Line 52.\n";
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

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
