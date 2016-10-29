#include <iostream>

#include <Subsystem.h>
#include <Renderer.h>
#include <Messages.h>
#include <MessageBus.h>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <glfw3.h>

// Shaders
#include <VertexShader.h>
#include <FragmentShader.h>

// ctors/dtors/Startup/Shutdown
Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

void Renderer::StartUp(MessageBus* const mb)
{
	std::cout << "Starting rendering subsystem.\n";
	this->msgBus = mb;
	this->InitializeShaders();
}

void Renderer::ShutDown()
{
	std::cout << "Shutting down rendering subsystem.\n";
}

// public
void Renderer::DrawLoop(GLFWwindow* window, const GLuint shaderProgram, const GLuint VAO, const GLuint VBO) {
	// Game loop
	std::cout << "Starting draw loop.\n";
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.6f, 0.2f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw our first triangle
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 4);
		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
}

void Renderer::HandleMessage(const enum MESSAGE_TYPE msg, const void* const data) {
	if (data != nullptr) {
		std::cout << "Renderer: I received a " << msg << " message! It contains data: " << *(int*)data << "\n";
	}
	else {
		std::cout << "Renderer: I received a message! The data was a null pointer. \n";
	}
	switch (msg) {
		case REBUFFER_DATA:
			this->RebufferData((LLNode<Triangle>*)data);
			break;
		case INITIALIZE_DATA:
			this->InitializeData((LLNode<Triangle>*)data);
			break;
		default:
			break;
	}
}

void Renderer::InitializeData(const LLNode<Triangle>* const scene) {
	GLfloat* vertices = (GLfloat*)(scene->data->BufferData());

	std::cout << "Renderer::InitializeData()\n";
	for (int i = 0; i < 9; i++){
		std::cout << vertices[i] << ", ";
	}
	std::cout << "\n";

	// Allocate reference for our Vertex Array/Attribute Object
	glGenVertexArrays(1, &this->VAO);

	// Allocate reference for our Vertex Buffer Object
	glGenBuffers(1, &this->VBO);

	// Bind the Vertex Array Object so that it's associated with the VBO for this context
	glBindVertexArray(this->VAO);
	// Bind the vertex for the context
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	// Copy vertices into the allocated buffer in GPU memory
	glBufferData(GL_ARRAY_BUFFER, 36, vertices, GL_DYNAMIC_DRAW);
	// Set up data about our VBO; this function _only_ works if a VBO is bound to GL_ARRAY_BUFFER
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	// Enable the vertex array created above;
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	delete(vertices);
}

void Renderer::InitializeShaders()
{
	// Build and compile our shader program
	// Vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// Check for compile time errors
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// Fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// Check for compile time errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// Link shaders
	this->shaderProgram = glCreateProgram();
	glAttachShader(this->shaderProgram, vertexShader);
	glAttachShader(this->shaderProgram, fragmentShader);
	glLinkProgram(this->shaderProgram);
	// Check for linking errors
	glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(this->shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Renderer::RebufferData(const LLNode<Triangle>* const scene) {
	GLfloat* vertices = (GLfloat*)(scene->data->BufferData());
	std::cout << "Renderer::RebufferData()\n";
	for (int i = 0; i < 9; i++){
		std::cout << vertices[i] << ", ";
	}
	std::cout << "\n";
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferSubData(GL_ARRAY_BUFFER, NULL, 36, vertices);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	delete(vertices);
}
