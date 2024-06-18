#include "Model.h"
#include "../texture/Texture.h"

#define WITH_TEXTURE_POS 5
#define VERTEX_ONLY_POS 3

Model::Model(std::string name, const float* buffer, int bufferLength)
{
	m_name = name;

	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);

	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * bufferLength, buffer, GL_STATIC_DRAW);

	if (bufferLength % WITH_TEXTURE_POS == 0)
	{
		int stride[] = { 3, 2 };
		m_triangleCount = bufferLength / WITH_TEXTURE_POS;

		for (int i = 0; i < 2; i++)
		{
			glVertexAttribPointer(
				i,
				stride[i],
				GL_FLOAT,
				GL_FALSE,
				5 * sizeof(GL_FLOAT),
				(void*)(i * (i > 0 ? stride[i - 1] : 0) * sizeof(float))
			);
			glEnableVertexAttribArray(i);
		}
	}
	else if (bufferLength % VERTEX_ONLY_POS == 0)
	{
		m_triangleCount = bufferLength / VERTEX_ONLY_POS;

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
		glEnableVertexAttribArray(0);
	}
	else
	{
		LOG("Load vertex failed");
	}
}

void Model::draw()
{
	if (!m_texture)
	{
		LOG("Texture should be applied before draw, " << m_name.c_str());
		return;
	}

	if (!m_shader)
	{
		LOG("Shader should be applied before draw, " << m_name.c_str());
		return;
	}

	use(m_texture, m_shader);
	glDrawArrays(GL_TRIANGLES, 0, m_triangleCount);
}

void Model::use(Texture* texture, Shader* shader)
{
	glBindVertexArray(m_vao);

	shader->use();
	texture->use(GL_TEXTURE0);
	shader->setInt("userTex", 0);

	m_texture = texture;
	m_shader = shader;
}

int Model::getTriangleCount() const
{
	return m_triangleCount;
}

Model::~Model()
{
	glDeleteBuffers(1, &m_vbo);
	glDeleteVertexArrays(1, &m_vao);
}
