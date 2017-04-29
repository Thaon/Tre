#pragma once

#include "Common.h"

#include "Display.h" 

#include "GameController.h"

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
	void processInput(float delta);
	void gameLoop();
	void drawGame(float delta);

	Display* m_gameDisplay;
	Camera* m_activeCam;
	GameState m_gameState;

	GameController m_controller;

	float oldTime, m_burnAmount, newTime;
	bool m_burning = false;
};

