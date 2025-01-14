#include "pch.h"
#include "GameManager.h"
#include "ConsoleLayout.h"
#include "KeyManager.h"
#include "TimeManager.h"
#include "SceneManager.h"

shared_ptr<GameManager> GameManager::Instance = nullptr;

void GameManager::Initialize()
{
	TimeManager::GetInstance()->Initialize();
	KeyManager::GetInstance()->Initialize();
	WriteManager::GetInstance()->Initialize();
	SceneManager::GetInstance()->Initialize();
}

void GameManager::tick()
{
	// add call SceneManager's tick()
	TimeManager::GetInstance()->tick();
	KeyManager::GetInstance()->tick();
	WriteManager::GetInstance()->tick();
	SceneManager::GetInstance()->tick();
}

void GameManager::render()
{
	WriteManager::GetInstance()->render();
}