#pragma once

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <glfw3.h>


class Windower
{
public:
	GLuint VAO;
	GLuint VBO;
	GLuint shaderProgram;
	GLFWwindow* window;
	void GameLoop(GLFWwindow* window, const GLuint shaderProgram, const GLuint VAO, const GLuint VBO);
	void StartUp();
	void ShutDown();
	Windower();
	~Windower();
};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
