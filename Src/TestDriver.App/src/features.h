#pragma once
#include "common_def.h"

void SetGLVersion(int majorVersion, int minorVersion);
void error_callback(int error_code, const char* description);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void window_size_callback(GLFWwindow* window, int width, int height);