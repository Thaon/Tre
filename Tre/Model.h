#pragma once

#include "Mesh.h"

//mostly taken from: https://learnopengl.com/#!Model-Loading/Model

/***
	The Model class encapsulates the core functionality when it comes to draw and manipulate meshes.
	
	The methods and members are self descriptive, to be noted, the methods that handle mesh loading and processing are mostly taken from the aforementioned tutorial on the Assimp library.
	
	To be noted, the vector of Textures (m_loadedTextures) is only used if the flag m_useInternalTextures is set to false during the loading of the external Mesh.
	Such textures can only be added after the model is created and only by using the appropriate method: AddExternalTexture.
*/

class Model
{
public:
	/*  Functions   */
	Model(std::string name, GLchar* path, bool loadInternalTextures)
	{
		this->m_name = name;
		this->m_useInternalTextures = loadInternalTextures;
		this->loadModel(path);
	}
	void Draw(Shader shader);
	std::string GetName() { return m_name; }
	void SetShader(Shader* shader);
	Shader* GetShader() { return m_shader; }
	Transform& GetTransform() { return m_transform; }
	GLint TextureFromFile(const char * path, std::string directory);
	void AddExternalTexture(std::string dir);

private:
	/*  Model Data  */
	Shader* m_shader;
	std::string m_name;
	std::vector<Mesh> meshes;
	std::string directory;
	std::vector<Texture> m_loadedTextures;
	bool m_useInternalTextures;
	Transform m_transform;

	/*  Functions   */
	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
};

