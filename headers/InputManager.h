#pragma once

#include <Subsystem.h>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <glfw3.h>

class InputManager : public Subsystem
{
public:
	InputManager();
	~InputManager();
	void StartUp();
	void ShutDown();
	static void GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void HandleMessage(enum MESSAGE_TYPE msg, void* data);
};
