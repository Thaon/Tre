#include "MainGame.h"
#include "Camera.h"
#include <iostream>
#include <string>


MainGame::MainGame()
{
	m_activeCam = nullptr;
	m_gameState = GameState::PLAY;
	m_gameDisplay = nullptr;
	m_backgroundColour = glm::vec4(0, 0, 0, 0);
}

MainGame::~MainGame()
{
	delete m_gameDisplay;
}

void MainGame::InitDisplay(int width, int height, glm::vec4 clearColour)
{
	m_gameDisplay = new Display(width, height);
	m_gameDisplay->initDisplay();
	m_backgroundColour = clearColour;
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
	oldTime = newTime = m_burnAmount = 0;
}

void MainGame::gameLoop()
{
	while (m_gameState != GameState::EXIT)
	{
		oldTime = newTime;
		newTime = SDL_GetPerformanceCounter();
		float deltaTime = (newTime - oldTime) / SDL_GetPerformanceFrequency();
		//std::cout << "old: " << oldTime << std::endl << "new: " << newTime << std::endl << "delta: " << deltaTime << std::endl;

		processInput(deltaTime);
		m_controller.Update(deltaTime);
		drawGame(deltaTime);
	}
}

void MainGame::processInput(float delta)
{
	SDL_Event evnt;

	while(SDL_PollEvent(&evnt)) //get and process events
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
				m_gameState = GameState::EXIT;
				break;

			case SDL_KEYDOWN:
				/* Check the SDLKey values and move change the coords */
				switch (evnt.key.keysym.sym)
				{
				case SDLK_LEFT:
					m_burning = false;
					break;
				case SDLK_RIGHT:
					m_burning = true;
					break;
				case SDLK_SPACE:
					m_burning = !m_burning;
					break;
				case SDLK_ESCAPE:
					m_gameState = GameState::EXIT;
					break;
				}
		}
	}
	
	if (m_burning)
	{
		if (m_burnAmount < 1)
			m_burnAmount += .5f * delta;
	}
	else
	{
		if (m_burnAmount > 0)
			m_burnAmount -= .5f * delta;
	}
}

Transform transform;
void MainGame::drawGame(float delta)
{
	m_gameDisplay->clearDisplay(m_backgroundColour.r, m_backgroundColour.g, m_backgroundColour.b, m_backgroundColour.a);

	for (auto model : SceneManager::GetActiveScene()->GetModels())
	{
		//bind shader
		model->GetShader()->Bind();
		model->GetTransform().Update();
		model->GetShader()->Update(model->GetTransform(), *m_activeCam, delta, m_burnAmount);
		
		//textures are bound in the Mesh's draw function

		//draw
		model->Draw(*model->GetShader());
	}
				
	glEnableClientState(GL_COLOR_ARRAY); 
	glEnd();

	m_gameDisplay->swapBuffer();
} 