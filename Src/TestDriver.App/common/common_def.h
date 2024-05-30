#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <iostream>

#define LOG(x) std::cout << x << std::endl;

#define WINDOW_DEFAULT_WIDTH 640
#define WINDOW_DEFAULT_HEIGHT 480
#define APP_TITLE "My World"

void setCallbacks(GLFWwindow* window);