#pragma once

#include "Common.h"
#include "Shader.h"
#include "Texture.h"
#include "transform.h"


struct Vertex
{
public:
	glm::vec3* GetPos() { return &pos; }
	glm::vec2* GetTexCoord() { return &texCoord; }
	glm::vec3* GetNormal() { return &normal; }

	glm::vec3 pos;
	glm::vec2 texCoord;
	glm::vec3 normal;
};

class Mesh
{
public:
	Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
	Mesh();
	~Mesh();

	void draw();
	void SetupMesh();

	std::string GetName() { return m_name; }

	void SetShader(Shader* shader) { m_shader = shader; }
	Shader* GetShader() { return m_shader; }
	std::vector<Texture> Textures() { return m_textures; }
	void AddTexture(Texture tex) { m_textures.push_back(tex); }

private:
	enum
	{
		POSITION_VERTEXBUFFER,
		TEXCOORD_VB,
		NORMAL_VB,
		INDEX_VB,
		NUM_BUFFERS
	};

	
	
	GLuint vertexArrayObject, vertexBufferObject, elementBufferObject;
	GLuint vertexArrayBuffers[NUM_BUFFERS]; // create our array of buffers
	unsigned int drawCount; //how much of the vertexArrayObject do we want to draw
	std::string m_name, m_path;
	Shader* m_shader;
	std::vector<Vertex> m_vertices;
	std::vector<GLuint> m_indices;
	std::vector<Texture> m_textures;
};

