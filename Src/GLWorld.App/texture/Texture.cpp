#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../common/stb_image.h"

Texture::Texture(const char* textureFile)
{
	stbi_set_flip_vertically_on_load(GL_TRUE);
	unsigned char* data = stbi_load(textureFile, &width, &height, &nrChannels, 4);

	if (data != NULL)
	{
		float borderColor[] = { 1.f, 1.f, 1.f, 1.f };

		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		switch (nrChannels)
		{
			case 1 :
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
			case 3:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			case 4:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			default:
				break;
		}

		
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		LOG("Load texture file failed");
		return;
	}

	stbi_image_free(data);
}

void Texture::use(GLenum textureNo)
{
	if (textureID != NULL)
	{
		glActiveTexture(textureNo);
		glBindTexture(GL_TEXTURE_2D, textureID);
	}
}

Texture::~Texture()
{
	glDeleteTextures(1, &textureID);
}
