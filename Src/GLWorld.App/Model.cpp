#include "model/Model.h"

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
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
		glEnableVertexAttribArray(0);
	}
	else
	{
		LOG("Load vertex failed");
	}
}

void Model::use()
{
	glBindVertexArray(m_vao);
}

Model::~Model()
{
	glDeleteBuffers(1, &m_vbo);
	glDeleteVertexArrays(1, &m_vao);
}
