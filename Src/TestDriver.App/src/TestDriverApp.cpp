#include "Common_Def.h"
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include <iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

int main()
{
	if (!glfwInit())
	{
		std::cout << "Glfw init failed" << std::endl;
	}

	GLFWwindow* window = glfwCreateWindow(WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT, WINDOW_TITLE, NULL, NULL);

	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}