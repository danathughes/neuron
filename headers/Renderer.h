#pragma once

#include <Subsystem.h>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <glfw3.h>

class Renderer : public Subsystem
{
public:
	GLuint shaderProgram;
	GLuint VAO;
	GLuint VBO;
	GLfloat* vertices; // our array of vertices for drawing

	void DrawLoop(GLFWwindow* window, const GLuint shaderProgram, const GLuint VAO, const GLuint VBO);
	void HandleMessage(enum MESSAGE_TYPE msg, void* data);
	void InitializeDrawData();
	void InitializeShaders();
	void StartUp();
	void ShutDown();
	Renderer();
	~Renderer();
};
