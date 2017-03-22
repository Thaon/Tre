#include "Scene.h"



Scene::Scene(std::string name)
{
	m_name = name;
	m_meshes = std::vector<Mesh*>();
}

Scene::Scene()
{
	m_name = "default name";
	m_meshes = std::vector<Mesh*>();
}


Scene::~Scene()
{
}

void Scene::AddMesh(Mesh * mesh)
{
	m_meshes.push_back(mesh);
}

Mesh* Scene::GetMesh(int index)
{
	if (m_meshes.size() > index)
		return m_meshes.at(index);
	else
	{
		std::cout << "not enough meshes in the scene!" << std::endl;
		return nullptr;
	}
}

Mesh* Scene::GetMesh(std::string name)
{
	for (auto mesh : m_meshes)
	{
		if (mesh->GetName() == name)
			return mesh;
	}
	std::cout << "could not find mesh named: " << name << std::endl;
	return nullptr;
}
