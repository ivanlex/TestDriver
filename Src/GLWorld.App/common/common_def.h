#pragma once
#define GLFW_INCLUDE_NONE

#pragma region gl
#include <GLFW/glfw3.h>
#include <glad/gl.h>
#pragma endregion

#pragma region glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#pragma endregion

#pragma region assimp
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#pragma endregion



#include <iostream>
#include <filesystem>

//#define DEBUG
#define LOG(x) std::cout << x << std::endl;

#define WINDOW_DEFAULT_WIDTH 640
#define WINDOW_DEFAULT_HEIGHT 480
#define APP_TITLE "My World"

#define APP_ERROR_CREATE_SHADER_FAIL -1;
#define APP_ERROR_CREATE_SHADER_PROGRAM_FAIL -2;

#define DEFAULT_VERTEX "./glsl/default_vertex.glsl"
#define DEFAULT_FRAGMENT "./glsl/default_fragment.glsl"
#define DEFAULT_TEXTURE "./images/default_texture.jpeg"
#define SECOND_TEXTURE "./images/second_texture.jpg"

#define SCROLL_STRIDE 5.f
#define FIELD_OF_VIEW_MINIMUM 5
#define FIELD_OF_VIEW_MAXIMUM 120
#define MOVE_STRIDE 0.1f
#define ROTATE_STRIDE 10.f

void setCallbacks(GLFWwindow* window);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);