#include "Mesh.h"
#include <vector>
#include <sstream>


void Mesh::SetupMesh()
{
	glGenVertexArrays(1, &vertexArrayObject);
	glGenBuffers(1, &vertexBufferObject);
	glGenBuffers(1, &elementBufferObject);

	glBindVertexArray(vertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);

	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), &m_vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(GLuint), &m_indices[0], GL_STATIC_DRAW);

	// Vertex Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(GLvoid*)0);
	// Vertex Normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(GLvoid*)offsetof(Vertex, normal));
	// Vertex Texture Coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(GLvoid*)offsetof(Vertex, texCoord));

	glBindVertexArray(0);
}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures)
{
	drawCount = NULL;
	m_shader = nullptr;

	this->m_vertices = vertices;
	this->m_indices = indices;
	this->m_textures = textures;

	this->SetupMesh();
}

Mesh::Mesh()
{
	drawCount = NULL;
	m_shader = nullptr;
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vertexArrayObject); // delete arrays
}

void Mesh::draw()
{
	//bind textures and pass them to shader
	for (GLuint i = 0; i < this->m_textures.size(); i++)
	{
		std::string texName = "texture";
		texName += (int)i + '1'; //int to char conversion

		GLuint loc = glGetUniformLocation(m_shader->GetProgram(), (texName).c_str());
		glUseProgram(m_shader->GetProgram());
		glUniform1i(loc, i);
		glActiveTexture(GL_TEXTURE0 + i); // Activate proper texture unit before binding
		glBindTexture(GL_TEXTURE_2D, m_textures[i].GetHandler());
	}

	glBindVertexArray(vertexArrayObject);
	glDrawElements(GL_TRIANGLES, drawCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

