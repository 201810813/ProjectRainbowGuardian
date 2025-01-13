#include "pch.h"
#include "GameManager.h"
#include "ConsoleLayout.h"

shared_ptr<GameManager> GameManager::Instance = nullptr;

void GameManager::Initialize()
{
	WriteManager::GetInstance()->Initialize();
}