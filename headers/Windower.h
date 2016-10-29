#pragma once

#include <iostream>

#include <Subsystem.h>
#include <InputManager.h>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <glfw3.h>

class MessageBus; // Fwd declaration to avoid compiler error, see MessageBus.h/.cpp

class Windower : public Subsystem
{
public:
	Windower();
	~Windower();
	void StartUp(MessageBus* const mb);
	void ShutDown();
	void HandleMessage(const enum MESSAGE_TYPE msg, const void* const data);

	void SetUpCallback(InputManager* const gInputManager);

	GLFWwindow* window;
};

void GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
