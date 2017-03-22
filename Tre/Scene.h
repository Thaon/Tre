#pragma once

#include "Common.h"
#include "Mesh.h"

class Scene
{
public:
	Scene(std::string name);
	Scene();
	~Scene();

	void AddMesh(Mesh* mesh);
	Mesh* GetMesh(int index);
	Mesh* GetMesh(std::string m_name);
	std::string GetName() { return m_name; }
	std::vector<Mesh*> GetMeshes() { return m_meshes; }

private:
	std::vector<Mesh*> m_meshes;
	std::string m_name;
};

