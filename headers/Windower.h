#pragma once

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <glfw3.h>


class Windower
{
public:
	Windower();
	~Windower();
	void StartUp();
	void ShutDown();
};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
