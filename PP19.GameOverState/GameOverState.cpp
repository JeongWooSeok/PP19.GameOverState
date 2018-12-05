#include "GameOverState.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"
#include "Game.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
	std::cout << "GoToMain button clicked\n";
}

void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(PlayState::Instance());
	std::cout << "Restart button clicked\n";
}

bool GameOverState::onEnter()
{
	if (!TheTextureManager::Instance()->load("Assets/gameover.png", "gameovertext",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/main.png", "mainbutton",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/restart.png", "restartbutton",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* gameOverText = new AnimatedGraphic(new LoaderParams
	(200, 100, 190, 30, "gameovertext"), 2);

	GameObject* button1 = new MenuButton(new LoaderParams
	(200, 200, 200, 80, "mainbutton"), s_gameOverToMain);

	GameObject* button2 = new MenuButton(new LoaderParams
	(200, 300, 200, 80, "restartbutton"), s_restartPlay);

	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering GameOverState\n";
	return true;
}

bool GameOverState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("gameovertext");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	TheTextureManager::Instance()->clearFromTextureMap("restartbutton");
	std::cout << "exiting MenuState\n";
	return true;
}

void GameOverState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void GameOverState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}