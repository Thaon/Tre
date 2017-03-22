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
	Mesh monkey;

	//Shader shader("../res/shader"); //unlit shader
	Shader shader("../res/rim"); //rim shader
	Texture texture("../res/bricks.jpg"); //load texture
	Texture texture1("../res/water.jpg"); //load texture

	monkey.loadModel("../res/monkey3.obj");
	monkey.SetShader(&shader);
	monkey.AddTexture(&texture1);

	
	//create camera
	Camera cam;
	cam.initCamera(glm::vec3(0, 0, -5), 70.0f, float(width / height), 0.01f, 1000.0f);
	mainGame.SetActiveCamera(&cam);


	//create scene and add meshes
	SceneManager::CreateScene("Scene1");
	SceneManager::GetActiveScene()->AddMesh(&monkey);
	
	//finally run game
	mainGame.run();

	return 0;
}