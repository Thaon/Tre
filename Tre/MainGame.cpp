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
	gameLoop();
}

void MainGame::SetActiveCamera(Camera* camera)
{
	m_activeCam = camera;
}

void MainGame::initSystems()
{
	counter = 0.0f;
}

void MainGame::gameLoop()
{
	while (m_gameState != GameState::EXIT)
	{
		processInput();
		drawGame();
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
void MainGame::drawGame()
{
	m_gameDisplay->clearDisplay(0.0f, 0.0f, 0.0f, 1.0f);

	transform.SetPos(glm::vec3(sinf(counter), 0.0, 0.0));
	transform.SetRot(glm::vec3(0.0, 0.0, counter * 5));
	transform.SetScale(glm::vec3(sinf(counter), sinf(counter), sinf(counter)));

	for (auto mesh : SceneManager::GetActiveScene()->GetMeshes())
	{
		//bind shader
		mesh->GetShader()->Bind();
		mesh->GetShader()->Update(transform, *m_activeCam);
		
		//bind textures
		for (int i = 0; i < mesh->Textures().size(); i++)
		{
			mesh->Textures().at(i)->Bind(i);
		}

		//draw
		mesh->draw();
	}

	counter = counter + 0.01f;
				
	glEnableClientState(GL_COLOR_ARRAY); 
	glEnd();

	m_gameDisplay->swapBuffer();
} 