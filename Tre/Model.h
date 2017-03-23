#pragma once

#include "Mesh.h"

//taken from: https://learnopengl.com/#!Model-Loading/Model

class Model
{
public:
	/*  Functions   */
	Model(std::string name, GLchar* path)
	{
		m_name = name;
		loadModel(path);
	}
	~Model();
	void Draw();
	std::string GetName() { return m_name; }
	void SetShader(Shader* shader);
	Shader* GetShader() { return m_shader; }
	Transform& GetTransform() { return m_transform; }
private:
	/*  Model Data  */
	std::string m_name;
	std::vector<Mesh*> meshes;
	std::string directory;
	std::vector<Texture> textures_loaded;
	Shader* m_shader;
	Transform m_transform;
	/*  Functions   */
	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh* processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	GLint TextureFromFile(const char * path, std::string directory);
};

