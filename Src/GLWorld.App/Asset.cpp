#include "asset/Asset.h"

Asset::Asset(const char* filename)
{
	Assimp::Importer importer;

	m_filename = filename;
	m_scene = importer.ReadFile(filename,
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType);
}

const char* Asset::getFilename() const
{
	return m_filename;
}

const aiScene* Asset::getScene() const
{
	return m_scene;
}
