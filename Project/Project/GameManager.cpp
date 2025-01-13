#include "pch.h"
#include "GameManager.h"
#include "ConsoleLayout.h"

shared_ptr<GameManager> GameManager::Instance = nullptr;

void GameManager::Initialize()
{
	WriteManager::GetInstance()->Initialize();
}

void GameManager::tick()
{
	// add call SceneManager's tick()
	WriteManager::GetInstance()->tick();
}

void GameManager::render()
{
	WriteManager::GetInstance()->render();
}