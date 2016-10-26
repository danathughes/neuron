#include <iostream>

#include <Subsystem.h>
#include <InputManager.h>
#include <Messages.h>
#include <MessageBus.h>


// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <glfw3.h>

void InputManager::StartUp(MessageBus* mb)
{
	std::cout << "Starting input manager.\n";
	this->msgBus = mb;
}

void InputManager::ShutDown()
{
	std::cout << "Shutting down input manager.\n";

}

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

void InputManager::GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, GL_TRUE);
	}
	else if (key == GLFW_KEY_UP && action == GLFW_PRESS) {

	}
	else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {

	}
	else if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {

	}
	else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {

	}
	else {
			std::cout << "Unrecognized key, ignoring.\n";
	}

}

void InputManager::HandleMessage(enum MESSAGE_TYPE msg, void* data) {
	std::cout << "InputManager: I received a message! It contains data: " << *(int*)data << "\n";
}