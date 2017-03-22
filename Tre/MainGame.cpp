#include "MainGame.h"
#include "Camera.h"
#include <iostream>
#include <string>



Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
					Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
					Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)) };

unsigned int indices[] = { 0, 1, 2 };

MainGame::MainGame()
{
	m_activeCam = nullptr;
	m_gameState = GameState::PLAY;
	m_gameDisplay = nullptr;
}

MainGame::~MainGame()
{
	delete m_gameDisplay;
}

void MainGame::InitDisplay(int width, int height)
{
	m_gameDisplay = new Display(width, height);
	m_gameDisplay->initDisplay();
}

void MainGame::run()
{
	initSystems();
	m_controller.Start();
	gameLoop();
}

void MainGame::SetActiveCamera(Camera* camera)
{
	m_activeCam = camera;
}

void MainGame::initSystems()
{
}

void MainGame::gameLoop()
{
	while (m_gameState != GameState::EXIT)
	{
		oldTime = newTime;
		newTime = SDL_GetPerformanceCounter();
		float deltaTime = (newTime - oldTime) / SDL_GetPerformanceFrequency();
		//std::cout << "old: " << oldTime << std::endl << "new: " << newTime << std::endl << "delta: " << deltaTime << std::endl;

		processInput();
		m_controller.Update(deltaTime);
		drawGame(deltaTime);
	}
}

void MainGame::processInput()
{
	SDL_Event evnt;

	while(SDL_PollEvent(&evnt)) //get and process events
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
				m_gameState = GameState::EXIT;
				break;
		}
	}
	
}

Transform transform;
void MainGame::drawGame(float delta)
{
	m_gameDisplay->clearDisplay(0.0f, 0.0f, 0.0f, 1.0f);

	for (auto mesh : SceneManager::GetActiveScene()->GetMeshes())
	{
		//bind shader
		mesh->GetShader()->Bind();
		mesh->GetShader()->Update(mesh->GetTransform(), *m_activeCam);
		
		//textures are bound in the Mesh's draw function

		//draw
		mesh->draw();
	}
				
	glEnableClientState(GL_COLOR_ARRAY); 
	glEnd();

	m_gameDisplay->swapBuffer();
} 