#pragma once

#include "Common.h"
#include "Shader.h"
#include "Texture.h"
#include "transform.h"

#include "obj_loader.h"

struct Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord)
	{
		this->pos = pos;
		this->texCoord = texCoord;
		this->normal = normal;
	}

	glm::vec3* GetPos() { return &pos; }
	glm::vec2* GetTexCoord() { return &texCoord; }
	glm::vec3* GetNormal() { return &normal; }

private:
	glm::vec3 pos;
	glm::vec2 texCoord;
	glm::vec3 normal;
};

class Mesh
{
public:
	Mesh(std::string name);
	Mesh();
	~Mesh();

	void draw();
	void init(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
	void loadModel(const std::string& filename);
	void initModel(const IndexedModel& model);

	Transform& GetTransform() { return m_transform; }
	std::string GetName() { return m_name; }

	void SetShader(Shader* shader) { m_shader = shader; }
	Shader* GetShader() { return m_shader; }
	std::vector<Texture*> Textures() { return m_textures; }
	void AddTexture(Texture* tex) { m_textures.push_back(tex); }

private:
	enum
	{
		POSITION_VERTEXBUFFER,
		TEXCOORD_VB,
		NORMAL_VB,
		INDEX_VB,
		NUM_BUFFERS
	};

	Transform m_transform;
	
	GLuint vertexArrayObject;
	GLuint vertexArrayBuffers[NUM_BUFFERS]; // create our array of buffers
	unsigned int drawCount; //how much of the vertexArrayObject do we want to draw
	std::string m_name;
	Shader* m_shader;
	std::vector<Texture*> m_textures;
};

