#include "common_def.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

void windowSizeChanged_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	LOG("Window " << glfwGetWindowTitle(window) << " size changed width:" << width << ",height" << height);
}

void setCallbacks(GLFWwindow* window)
{
	glfwSetKeyCallback(window, key_callback);
	glfwSetWindowSizeCallback(window, windowSizeChanged_callback);
}