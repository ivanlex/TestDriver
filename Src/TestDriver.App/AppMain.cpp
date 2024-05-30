#include "common/common_def.h"

float vertex[] = {
	-0.5f, -0.5f, 0,
	0.5f, -0.5f, 0,
	0, 0.5f, 0,
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
	setCallbacks(window);
	glClearColor(0.2f, .7f, .1f, 1.f);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}