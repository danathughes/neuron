#pragma once

#define GLEW_STATIC // FIXME: Linker errors happen if this constant isn't defined here, not sure why.
#include <GL/glew.h>
#include <glfw3.h>

#include <Subsystem.h>
#include <LLNode.h>
#include <Triangle.h>

class MessageBus; // Fwd declaration to avoid compiler error, see MessageBus.h/.cpp

class Renderer : public Subsystem
{
public:
	Renderer();
	~Renderer();
	void StartUp(MessageBus* const mb);
	void ShutDown();
	void HandleMessage(const enum MESSAGE_TYPE msg, const void* const data);

	void DrawLoop(GLFWwindow* window, const GLuint shaderProgram, const GLuint VAO, const GLuint VBO);
	void InitializeData(const LLNode<Triangle>* const scene);
	void InitializeShaders();
	void RebufferData(const LLNode<Triangle>* const scene);

	GLuint shaderProgram;
	GLuint VAO;
	GLuint VBO;
	GLuint texture;
};
