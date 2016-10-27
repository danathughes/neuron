#pragma once

#include <Subsystem.h>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <glfw3.h>

class MessageBus; // Fwd declaration to avoid compiler error, see MessageBus.h/.cpp

class InputManager : public Subsystem
{
public:
	InputManager();
	~InputManager();
	void StartUp(MessageBus* mb);
	void ShutDown();
	void UpArrow() const;
	void DownArrow() const;
	void LeftArrow() const;
	void RightArrow() const;

  // NOTE: GLFWKeyCallback was static in the last working build
	void GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
	void HandleMessage(enum MESSAGE_TYPE msg, void* data);
};
