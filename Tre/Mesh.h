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

class Mesh {
public:
	/*  Mesh Data  */
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;
	/*  Functions  */
	Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
	void Draw(Shader shader);
	void OnlyDrawMesh(Shader shader);
private:
	/*  Render data  */
	GLuint VAO, VBO, EBO;
	/*  Functions    */
	void SetupMesh();
};

