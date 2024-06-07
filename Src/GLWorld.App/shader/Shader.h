#pragma once
#include "common/common_def.h"

#include <fstream>
#include <sstream>

class Shader
{
public:
	GLuint shaderProgramID;

	Shader(const char* vertexPath, const char* fragmentPath);
	void use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setFloat3(const std::string& name, float x, float y, float z) const;
	void setFloatPtr(const std::string& name, float* data) const;

	~Shader()
	{
		glDeleteProgram(shaderProgramID);
	}
};

