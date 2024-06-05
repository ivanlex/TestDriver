#include "common/common_def.h"
#include "shader/Shader.h"

float vertices[] = {
	// first triangle   //color
	0.5f, 0.5f, 0.0f,   1.f, 0,  0,
	0.5f, -0.5f, 0.0f,  0,  1.f, 0,
	-0.5f, 0.5f, 0.0f,  0,   0, 1.f
};

float params[] = {
	1.2f, 2.3f
};

GLuint indices[] = {
	0,1,2,
	0,1,3
};

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

	Shader defaultShader(DEFAULT_VERTEX, DEFAULT_FRAGMENT);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), (void*)NULL);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), (void*)(3 * sizeof(float)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	defaultShader.use();

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		double time = glfwGetTime();
		float xValue = cos(time) / 0.2f;
		float yValue = cos(time) / 0.3f;
		float zValue = cos(time) / 0.4f;
		defaultShader.setFloat3("vertexColorParam", xValue, yValue, zValue);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}