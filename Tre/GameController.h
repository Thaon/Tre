#pragma once

#include "Common.h"

#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "transform.h"
#include "SceneManager.h"


///this class will be the only access point to the engine, alongside the main function
class GameController
{
public:
	GameController();
	~GameController();

	void Start();
	void Update(float deltaTime);

private:
	float counter;
	Mesh* m1, *m2, *m3;
};

