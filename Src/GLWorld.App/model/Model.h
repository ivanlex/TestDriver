#pragma once
#include "../common/common_def.h"
#include "../texture/Texture.h"
#include "../shader/Shader.h"

class Model
{
private:
	std::string m_name;
	GLuint m_vao, m_vbo;
	int m_triangleCount;

	Texture* m_texture;
	Shader* m_shader;
public:
	Model(std::string name, const float* buffer, int bufferLength);
	void draw();
	void use(Texture* texture, Shader* shader);
	int getTriangleCount() const;
	~Model();
};