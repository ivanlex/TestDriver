#include "common/common_def.h"

float vertices[] = {
	-0.5f, -0.5f, 0,
	0.5f, -0.5f, 0,
	0, 0.5f, 0,
};

const char* defaultVertexShaderSource =
"#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"\n"
"void main()\n"
"{\n"
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\n";

const char* defaultFragmentShaderSource =
"#version 330 core\n"
"out vec4 FragColor;\n"
"\n"
"void main()\n"
"{\n"
"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
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

	return 0;
}

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
	setCallbacks(window);
	glClearColor(0.2f, .7f, .1f, 1.f);

	GLuint vao; // vertex array object
	glGenBuffers(1, &vao);
	glBindBuffer(GL_ARRAY_BUFFER, vao);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)NULL);
	glEnableVertexAttribArray(0);

	glUseProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glBindVertexArray(vao);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);	

		
		
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}