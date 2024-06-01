#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <iostream>

#define LOG(x) std::cout << x << std::endl;

#define WINDOW_DEFAULT_WIDTH 640
#define WINDOW_DEFAULT_HEIGHT 480
#define APP_TITLE "My World"

#define APP_ERROR_CREATE_SHADER_FAIL -1;
#define APP_ERROR_CREATE_SHADER_PROGRAM_FAIL -2;

void setCallbacks(GLFWwindow* window);