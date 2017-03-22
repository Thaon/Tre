#pragma once

#include "Common.h"

#include "Display.h" 
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "transform.h"
#include "SceneManager.h"

enum class GameState{PLAY, EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void InitDisplay(int width, int height);
	void run();
	void SetActiveCamera(Camera* camera);

private:

	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();

	Display* m_gameDisplay;
	Camera* m_activeCam;
	GameState m_gameState;

	float counter;


};

