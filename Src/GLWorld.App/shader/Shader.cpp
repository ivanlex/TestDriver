#include "../shader/Shader.h"

void CreateVertexShader(const char* vertexShaderCode, GLuint* vertexShader)
{
	*vertexShader = glCreateShader(GL_VERTEX_SHADER);

	if (*vertexShader == NULL)
	{
		LOG("Create vertex shader failed");
		return;
	}

#ifdef DEBUG
	LOG(vertexShaderCode);
#endif

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

#ifdef DEBUG
	LOG(fragmentShaderCode);
#endif

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

	shaderProgramID = glCreateProgram();

	glAttachShader(shaderProgramID, vertexShader);
	glAttachShader(shaderProgramID, fragmentShader);
	glLinkProgram(shaderProgramID);

	GLint success;

	glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);

	if (success)
	{
		LOG("Link successfully!");
	}
	else
	{
		char* info = new char[512];
		glGetProgramInfoLog(shaderProgramID, 512, NULL, info);
		LOG(info);

		delete[]info;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::use()
{
	glUseProgram(shaderProgramID);
}

void Shader::setBool(const std::string& name, bool value) const
{
	GLuint location = glGetUniformLocation(shaderProgramID, name.c_str());
	glUniform1i(location, value);
}

void Shader::setInt(const std::string& name, int value) const
{
	GLuint location = glGetUniformLocation(shaderProgramID, name.c_str());
	glUniform1i(location, value);
}

void Shader::setFloat(const std::string& name, float value) const
{
	GLuint location = glGetUniformLocation(shaderProgramID, name.c_str());
	glUniform1f(location, value);
}

void Shader::setFloat3(const std::string& name, float x, float y, float z) const
{
	GLuint location = glGetUniformLocation(shaderProgramID, name.c_str());
	glUniform3f(location, x, y, z);
}

void Shader::setFloat3Ptr(const std::string& name, float* data) const
{
	GLuint location = glGetUniformLocation(shaderProgramID, name.c_str());
	glUniform3fv(location, 1, data);
}

void Shader::setFloatPtr(const std::string& name, float* data) const
{
	GLuint location = glGetUniformLocation(shaderProgramID, name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, data);
}
