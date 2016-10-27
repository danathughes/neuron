#pragma once

#include <Subsystem.h>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <glfw3.h>

class MessageBus; // Fwd declaration to avoid compiler error, see MessageBus.h/.cpp

class Renderer : public Subsystem
{
public:
	GLuint shaderProgram;
	GLuint VAO;
	GLuint VBO;
	//GLfloat* vertices; // our array of vertices for drawing

	void BufferData(const LLNode<Triangle>* const scene);
	void DrawLoop(GLFWwindow* window, const GLuint shaderProgram, const GLuint VAO, const GLuint VBO);
	void HandleMessage(enum MESSAGE_TYPE msg, void* data);
	void InitializeShaders();
	void StartUp(MessageBus* mb);
	void ShutDown();
	Renderer();
	~Renderer();
};
