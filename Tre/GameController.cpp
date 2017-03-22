#include "GameController.h"



GameController::GameController()
{
}


GameController::~GameController()
{
}

void GameController::Start()
{
	monkey = SceneManager::GetActiveScene()->GetMesh("monkey");
}

void GameController::Update(float deltaTime)
{
	counter += 1 * deltaTime;

	//transform.SetPos(glm::vec3(sinf(counter), 0.0, 0.0));
	monkey->GetTransform().SetRot(glm::vec3(0.0, counter, 0.0));
	//transform.SetScale(glm::vec3(sinf(counter), sinf(counter), sinf(counter)));
}
