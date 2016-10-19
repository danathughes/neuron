// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <glfw3.h>


class Windower
{
public:
	GLFWwindow* window;
	void StartUp();
	void ShutDown();
	Windower();
	~Windower();
};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
