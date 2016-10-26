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
	GLFWwindow* window;
	void StartUp(GLFWkeyfun callback, MessageBus* mb);
	void ShutDown();
	Windower();
	~Windower();
	void HandleMessage(MESSAGE_TYPE msg, void* data);
};
