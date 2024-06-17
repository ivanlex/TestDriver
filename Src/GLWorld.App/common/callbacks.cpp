#include "common_def.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

void mouse_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		double xPos= 0.0, yPos = 0.0;

		glfwGetCursorPos(window, &xPos, &yPos);

		LOG("Current mouse pos, xPos:" << xPos << ", yPos:" << yPos);
	}
}

void windowSizeChanged_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	LOG("Window " << glfwGetWindowTitle(window) << " size changed width:" << width << ",height" << height);
}

void setCallbacks(GLFWwindow* window)
{
	glfwSetMouseButtonCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetWindowSizeCallback(window, windowSizeChanged_callback);
}