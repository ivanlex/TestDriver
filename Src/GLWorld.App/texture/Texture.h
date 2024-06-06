#pragma once
#include "../common/common_def.h"

class Texture
{
private:
	int width, height, nrChannels;
public:
	GLuint textureID;
	Texture(const char* textureFile);

	/// <summary>
	/// Active and bind texture for textureNo(GL_TEXTURE0, GL_TEXTURE1 ... GL_TEXTURE15)
	/// </summary>
	/// <param name="textureNo">from GL_TEXTURE0 up to GLTEXTURE15</param>
	void use(GLenum textureNo);
};