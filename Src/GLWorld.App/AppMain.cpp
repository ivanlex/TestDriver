#include "common/common_def.h"

float vertices[] = {
	// first triangle
	0.5f, 0.5f, 0.0f, 
	0.5f, -0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f,
	-0.5f, 0.5f, 0.1f,
};

float params[] = {
	1.2f, 2.3f
};

GLuint indices[] = {
	0,1,2,
	0,1,3
};

const char* defaultVertexShaderSource =
"#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"\n"
"out vec4 vertexColor;\n"
"\n"
"void main()\n"
"{\n"
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"	vertexColor = vec4(aPos.x + 0.5f, aPos.y + 0.3f, aPos.z + 0.3f, 0);\n"
"}\n";

const char* defaultFragmentShaderSource =
"#version 330 core\n"
"out vec4 FragColor;\n"
"\n"
"in vec4 vertexColor;\n"
"uniform vec4 vertexColorLocation;\n"
"\n"
"void main()\n"
"{\n"
"	FragColor = vec4(vertexColor.x * vertexColorLocation.x, vertexColor.y * vertexColorLocation.y, vertexColor.z * vertexColorLocation.z, 1);\n"
"}\n";

/// <summary>
/// Create default vertex and fragment shader
/// </summary>
/// <param name="vertexShader">output vertex shader</param>
int createShader(GLuint* vertexShader, GLuint* fragmentShader)
{
	*vertexShader = glCreateShader(GL_VERTEX_SHADER);

	if (vertexShader == NULL)
	{
		LOG("CreateVertex shader failed");
		return 1;
	}

	glShaderSource(*vertexShader, 1, &defaultVertexShaderSource, NULL);
	glCompileShader(*vertexShader);

	*fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	if (fragmentShader == NULL)
	{
		LOG("CreateFragment shader failed");
		return 2;
	}

	glShaderSource(*fragmentShader, 1, &defaultFragmentShaderSource, NULL);
	glCompileShader(*fragmentShader);

	return 0;
}

/// <summary>
/// Link shader program
/// </summary>
/// <param name="vertexShader"></param>
/// <param name="fragmentShader"></param>
/// <returns></returns>
int createShaderProgram(GLuint vertexShader, GLuint fragmentShader, GLuint* shaderProgram)
{	
	if (!(*shaderProgram = glCreateProgram()))
	{
		LOG("Create shader program failed");
		return 1;
	}

	glAttachShader(*shaderProgram, vertexShader);
	glAttachShader(*shaderProgram, fragmentShader);
	glLinkProgram(*shaderProgram);

	GLint success;

	glGetProgramiv(*shaderProgram, GL_LINK_STATUS, &success);

	if (success)
	{
		LOG("Link Program successfully");
	}
	else
	{
		char* info = new char[512];
		glGetProgramInfoLog(*shaderProgram, 512, NULL, info);
		LOG(info);

		delete []info;

		return 1;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return 0;
}

int tick = 0;

int main()
{
	if (!glfwInit())
	{
		LOG("Glfw init failed");
	}

	GLFWwindow* window = glfwCreateWindow(
		WINDOW_DEFAULT_WIDTH,
		WINDOW_DEFAULT_HEIGHT,
		APP_TITLE,
		NULL,
		NULL
	);

	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);
	glfwSwapInterval(1);
	setCallbacks(window);
	glClearColor(0.f, 0.f, 0.f, 1.f);

	GLuint vertexShader, fragmentShader, shaderProgram;
	
	if (createShader(&vertexShader, &fragmentShader))
	{
		LOG("Since create shader failed. exit app");
		glfwTerminate();
		return APP_ERROR_CREATE_SHADER_FAIL;
	}

	if (createShaderProgram(vertexShader, fragmentShader, &shaderProgram))
	{
		LOG("Since create shader program failed. exit app");
		glfwTerminate();
		return APP_ERROR_CREATE_SHADER_PROGRAM_FAIL;
	}

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 4 * sizeof(GL_FLOAT), (void*)NULL);

	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	
	glEnableVertexAttribArray(0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glUseProgram(shaderProgram);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		float timeValue = glfwGetTime();
		float redValue = atan(timeValue) / 2.0f + 0.3f;
		float greenValue = sin(timeValue) / 2.0f + 0.5f;
		float blueValue = cos(timeValue) / 2.0f + 0.8f;
		int vertexColorLocation = glGetUniformLocation(shaderProgram, "vertexColorLocation");
		glUniform4f(vertexColorLocation, redValue, greenValue, blueValue, 1.f);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)NULL);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}