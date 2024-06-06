#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>

#include <iostream>
#include <filesystem>

//#define DEBUG
#define LOG(x) std::cout << x << std::endl;

#define WINDOW_DEFAULT_WIDTH 640
#define WINDOW_DEFAULT_HEIGHT 480
#define APP_TITLE "My World"

#define APP_ERROR_CREATE_SHADER_FAIL -1;
#define APP_ERROR_CREATE_SHADER_PROGRAM_FAIL -2;

#define DEFAULT_VERTEX "D:/References/GLWorld/Src/GLWorld.App/glsl/default_vertex.glsl"
#define DEFAULT_FRAGMENT "D:/References/GLWorld/Src/GLWorld.App/glsl/default_fragment.glsl"
#define DEFAULT_TEXTURE "D:/References/GLWorld/Src/GLWorld.App/images/default_texture.jpeg"
#define SECOND_TEXTURE "D:/References/GLWorld/Src/GLWorld.App/images/second_texture.jpg"

void setCallbacks(GLFWwindow* window);