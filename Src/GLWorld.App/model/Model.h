#pragma once
#include "../common/common_def.h"

class Model
{
private:
	std::string m_name;
	GLuint m_vao, m_vbo;
public:
	Model(std::string name, const float* buffer, int bufferLength);
	void use();
	~Model();
};