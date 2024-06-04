#include "Shader.h"

void CreateVertexShader(const char* vertexShaderCode, GLuint* vertexShader)
{
	*vertexShader = glCreateShader(GL_VERTEX_SHADER);

	if (*vertexShader == NULL)
	{
		LOG("Create vertex shader failed");
		return;
	}

	glShaderSource(*vertexShader, 1, &vertexShaderCode, NULL);
	glCompileShader(*vertexShader);
}

void CreateFragmentShader(const char* fragmentShaderCode, GLuint* fragmentShader)
{
	*fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	if (*fragmentShader == NULL)
	{
		LOG("Create fragment shader failed");
		return;
	}

	glShaderSource(*fragmentShader, 1, &fragmentShaderCode, NULL);
	glCompileShader(*fragmentShader);
}

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;

	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	fShaderFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	try
	{
		 vShaderFile.open(vertexPath);
		 fShaderFile.open(fragmentPath);

		 std::stringstream vShaderStream, fShaderStream;

		 vShaderStream << vShaderFile.rdbuf();
		 fShaderStream << fShaderFile.rdbuf();

		 vShaderFile.close();
		 fShaderFile.close();

		 vertexCode = vShaderStream.str();
		 fragmentCode = fShaderStream.str();
	}
	catch (const std::exception& e)
	{
		LOG(e.what());
	}

	const char* vertexShaderCode = vertexCode.c_str();
	const char* fragmentShaderCode = fragmentCode.c_str();

	GLuint vertexShader, fragmentShader;

	CreateVertexShader(vertexShaderCode, &vertexShader);
	CreateFragmentShader(fragmentShaderCode, &fragmentShader);

	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	GLuint success;

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (success)
	{
		LOG("Link successfully!");
	}
	else
	{
		char* info = new char[512];
		glGetProgramInfoLog(shaderProgram, 512, NULL, info);
		LOG(info);

		delete[]info;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}