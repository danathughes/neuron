// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
#include <iostream>

void key_callback(GLFWwindow* window, const int key, const int scancode, const int action, const int mode);
void key_callback(GLFWwindow* window, const int key, const int scancode, const int action, const int mode) {
    // When a user presses the escape key, we set the WindowShouldClose property to true, 
    // closing the application
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    	glfwSetWindowShouldClose(window, GL_TRUE);
}

// Shaders, bleh
const GLchar* vertex_shader_source = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
    "}\0";
const GLchar* fragment_shader_source = "#version 330 core\n"
    "out vec4 color;\n"
    "void main()\n"
    "{\n"
    "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

void manage_shader(const GLchar* const shader_source, const GLenum shader_type);
void manage_shader(const GLchar* const shader_source, const GLenum shader_type){
	// Create and compile shaders
	GLuint shader_id;
	shader_id = glCreateShader(shader_type);
	glShaderSource(shader_id, 1, &shader_source, NULL);
	glCompileShader(shader_id);
}

int main()
{
	// Initialize GLFW with correct OpenGL and window parameters
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create GLFW window object
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback); 

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	// Intialize viewport
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	// Initialize game loop
	while(!glfwWindowShouldClose(window)) {
		// Check for input / events
		glfwPollEvents();

		// Begin rendering stuff here
		// Set background color to cyan-ish
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Initialize vertices and data on the GPU
		GLfloat vertices[] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f
		};

		GLuint VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		// Handle shaders
		manage_shader(vertex_shader_source, GL_VERTEX_SHADER);
		//manage_shader(fragment_shader_source, GL_FRAGMENT_SHADER);

		// Draw backbuffer to screen
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}
