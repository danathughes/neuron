#include <iostream>

// GLEW token, needed for staticly linked executable, needs to be defined before glew.h
#define GLEW_STATIC
#include <GL/glew.h>
#include <glfw3.h>

#include <Subsystem.h>
#include <Windower.h>
#include <Renderer.h>
#include <InputManager.h>
#include <Messages.h>
#include <MessageBus.h>

// Window dimensions
const GLuint WIDTH = 1200, HEIGHT = 800;

// ctors/dtors/Startup/Shutdown

Windower::Windower() {

}

Windower::~Windower() {

}

void Windower::StartUp(MessageBus* const mb) {
	std::cout << "Starting windowing subsystem.\n";
	this->msgBus = mb;

	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif // __APPLE__

	// Create a GLFWwindow object that we can use for GLFW's functions
	this->window = glfwCreateWindow(WIDTH, HEIGHT, "Gibson Engine", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(this->window, GLFWKeyCallback);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	// Define the viewport dimensions
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
}


void Windower::ShutDown() {
	std::cout << "Shutting down windowing subsystem.\n";
}

// public
void Windower::HandleMessage(const enum MESSAGE_TYPE msg, const void* const data) {
	if (data != nullptr) {
		std::cout << "Windower: I received a " << msg << " message! It contains data: " << *(int*)data << "\n";
	}
	else {
		std::cout << "Windower: I received a message! The data was a null pointer. \n";
	}
}

void Windower::SetUpCallback(InputManager* const gInputManager) {
	// GLFW handles input with a callback, which unfortunately tightly couples the Windower and InputManager for now.
	glfwSetWindowUserPointer(this->window, gInputManager);
}

void GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode){
		InputManager* gInputManager = (InputManager*)glfwGetWindowUserPointer(window);
		gInputManager->HandleGLFWCallback(window, key, action);
}
