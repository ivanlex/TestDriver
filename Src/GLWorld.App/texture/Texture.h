#pragma once
#include "../common/common_def.h"

class Texture
{
private:
	int width, height, nrChannels;
public:
	GLuint textureID;
	Texture(const char* textureFile);
};