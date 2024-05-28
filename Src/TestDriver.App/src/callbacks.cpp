#include "Common_Def.h"

/// <summary>
/// 
/// </summary>
/// <param name="error_code"></param>
/// <param name="description"></param>
void error_callback(int error_code, const char* description)
{
	LOGX("ErrorCode:" << error_code << ", description:" << description);
}

/// <summary>
/// size change
/// </summary>
/// <param name="window"></param>
/// <param name="key"></param>
/// <param name="scancode"></param>
/// <param name="action"></param>
/// <param name="mods"></param>
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

/// <summary>
/// Window size changed callback
/// </summary>
/// <param name="window"></param>
/// <param name="width"></param>
/// <param name="height"></param>
void window_size_callback(GLFWwindow* window, int width, int height)
{
	LOGX("Window size changed width:" << width << ", height:" << height << ".");
}

/// <summary>
/// Set minimum supported OpenGL version.(seems not working)
/// </summary>
/// <param name="majorVersion"></param>
/// <param name="minorVersion"></param>
void SetGLVersion(int majorVersion, int minorVersion)
{
	glfwWindowHint(GL_MAJOR_VERSION, majorVersion);
	glfwWindowHint(GL_MINOR_VERSION, minorVersion);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}
