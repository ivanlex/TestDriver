#include "texture/Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "common/stb_image.h"

Texture::Texture(const char* textureFile)
{
	unsigned char* data = stbi_load(textureFile, &width, &height, &nrChannels, 0);

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

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		LOG("Load texture file failed");
		return;
	}

	STBI_FREE(data);
}
