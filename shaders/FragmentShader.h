const GLchar* fragmentShaderSource = "#version 330 core	\n"
"out vec4 color;										\n"
"uniform vec4 ourColor;									\n"	// We set this variable in the OpenGL code.
"void main()											\n"
"{														\n"
"	color = vec4(1.0f, 0.5f, 0.2f, 1.0f);				\n"
"}														\n\0";
