#include "GameController.h"



GameController::GameController()
{
}


GameController::~GameController()
{
}

void GameController::Start()
{
	m1 = SceneManager::GetActiveScene()->GetMesh("monkey");
	m2 = SceneManager::GetActiveScene()->GetMesh("monkey2");
	m3 = SceneManager::GetActiveScene()->GetMesh("monkey3");


	m2->GetTransform().SetPos(glm::vec3(-3, 0.0, 0.0));
	m3->GetTransform().SetPos(glm::vec3(3, 0.0, 0.0));

}

void GameController::Update(float deltaTime)
{
	counter += 1 * deltaTime;

	//m1->GetTransform().SetScale(glm::vec3(1, 1, 1));
	m1->GetTransform().SetRot(glm::vec3(0.0, counter, 0.0));
	m2->GetTransform().SetRot(glm::vec3(0.0, counter, 0.0));
	m3->GetTransform().SetRot(glm::vec3(0.0, counter, 0.0));
	//transform.SetPos(glm::vec3(sinf(counter), 0.0, 0.0));
}
