#include "GameController.h"



GameController::GameController()
{
}


GameController::~GameController()
{
}

void GameController::Start()
{
	m1 = SceneManager::GetActiveScene()->GetModel("monkey");
	m1->GetTransform().SetPos(glm::vec3(0.0, 2.0, 0.0));
	m1->GetTransform().SetScale(glm::vec3(.2f, .2f, .2f));
	m1->GetTransform().SetRot(glm::vec3(90.0, 0.0, 0.0));

	/*m2 = SceneManager::GetActiveScene()->GetMesh("monkey2");
	m3 = SceneManager::GetActiveScene()->GetMesh("monkey3");*/


	/*m2->GetTransform().SetPos(glm::vec3(-3, 0.0, 0.0));
	m3->GetTransform().SetPos(glm::vec3(3, 0.0, 0.0));*/

}

void GameController::Update(float deltaTime)
{
	counter += 1 * deltaTime;

	//m1->GetTransform().SetScale(glm::vec3(sinf(counter * deltaTime), sinf(counter * deltaTime), sinf(counter * deltaTime)));
	m1->GetTransform().SetRot(glm::vec3(90.0, 0.0, counter));
	/*m2->GetTransform().SetRot(glm::vec3(0.0, counter, 0.0));
	m3->GetTransform().SetRot(glm::vec3(0.0, counter, 0.0));*/
	//transform.SetPos(glm::vec3(sinf(counter), 0.0, 0.0));
}
