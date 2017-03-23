#pragma once

#include "Common.h"
#include "Model.h"

class Scene
{
public:
	Scene(std::string name);
	Scene();
	~Scene();

	void AddModel(Model* mesh);
	Model* GetModel(int index);
	Model* GetModel(std::string m_name);
	std::string GetName() { return m_name; }
	std::vector<Model*> GetModels() { return m_models; }

private:
	std::vector<Model*> m_models;
	std::string m_name;
};

