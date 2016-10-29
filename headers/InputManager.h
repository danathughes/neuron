#pragma once

#define GLEW_STATIC  // this must be defined before including GLEW
#include <GL/glew.h> // gl.h has to be included after glew.h
#include <glfw3.h>

#include <Subsystem.h>


class MessageBus; // Fwd declaration to avoid compiler error, see MessageBus.h/.cpp

class InputManager : public Subsystem
{
public:
	InputManager();
	~InputManager();
	void StartUp(MessageBus* const mb);
	void ShutDown();
	void HandleMessage(const enum MESSAGE_TYPE msg, const void* const data);

	void HandleGLFWCallback(GLFWwindow* window, const int key, const int action);
	void DownArrow() const;
	void LeftArrow() const;
	void RightArrow() const;
	void UpArrow() const;
};
