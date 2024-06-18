#pragma once
#include "../common/common_def.h"

class Asset
{
private:
	const char* m_filename;
	const aiScene* m_scene;
public:
	Asset(const char* filename);
	const char* getFilename() const;
	const aiScene* getScene() const;
};