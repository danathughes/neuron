#pragma once

#include <GL/glew.h>
#include <glfw3.h>
#include <Subsystem.h>

#define GLEW_STATIC
class MessageBus; // Fwd declaration to avoid compiler error, see MessageBus.h/.cpp

class InputManager : public Subsystem
{
public:
	InputManager();
	~InputManager();
	void StartUp(MessageBus* mb);
	void ShutDown();
	void HandleGLFWCallback(GLFWwindow* window, int key, int action);
	void HandleMessage(enum MESSAGE_TYPE msg, void* data);
	void DownArrow() const;
	void LeftArrow() const;
	void RightArrow() const;
	void UpArrow() const;
};
