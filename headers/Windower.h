#pragma once
#include <iostream>
#include <InputManager.h>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <glfw3.h>

class Windower
{
public:
	GLFWwindow* window;
	void StartUp(GLFWkeyfun callback);
	void ShutDown();
	Windower();
	~Windower();
};
