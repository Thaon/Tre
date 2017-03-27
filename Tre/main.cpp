#include <iostream>
#include "MainGame.h"


int main(int argc, char** argv) //argument used to call SDL main
{
	//create and configure game
	MainGame mainGame;
	int width = 800;
	int height = 600;
	mainGame.InitDisplay(width, height);

	
	//create monkey object
	Model dragon("car", "../res/Car/Car.3ds", false);
	dragon.AddExternalTexture("../res/Water.jpg");
	dragon.AddExternalTexture("../res/bricks.jpg");
	
	
	//Mesh monkey2 = Mesh("monkey2");
	//Mesh monkey3 = Mesh("monkey3");


	//Shader shader("../res/shader"); //unlit shader
	Shader unlitshader("../res/shader"); //rim shader
	Shader rimshader("../res/rim"); //rim shader
	Shader blendshader("../res/blend"); //rim shader
	
	//Texture texture("../res/bricks.jpg"); //load texture
	//Texture texture1("../res/water.jpg"); //load texture

	dragon.SetShader(&rimshader);

	/*monkey2.loadModel("../res/monkey3.obj");
	monkey2.SetShader(&rimshader);
	monkey2.AddTexture(&texture1);
	monkey2.AddTexture(&texture);

	monkey3.loadModel("../res/monkey3.obj");
	monkey3.SetShader(&blendshader);
	monkey3.AddTexture(&texture1);
	monkey3.AddTexture(&texture);*/
	
	//create camera
	Camera cam;
	cam.initCamera(glm::vec3(0, 0, -5), 70.0f, float(width / height), 0.01f, 1000.0f);
	mainGame.SetActiveCamera(&cam);


	//create scene and add meshes
	SceneManager::CreateScene("Scene1");
	SceneManager::GetActiveScene()->AddModel(&dragon);
	/*SceneManager::GetActiveScene()->AddMesh(&monkey2);
	SceneManager::GetActiveScene()->AddMesh(&monkey3);*/

	
	//finally run game
	mainGame.run();

	return 0;
}