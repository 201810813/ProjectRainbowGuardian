#include "pch.h"
#include "GameManager.h"
#include "ConsoleLayout.h"
#include "KeyManager.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "PathManager.h"

shared_ptr<GameManager> GameManager::Instance = nullptr;

void GameManager::Initialize()
{
	PathManager::GetInstance()->Initialize();
	SoundManager::GetInstance()->Initialize();
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

	// 이번tick에서 할거 다하고 최종적으로 씬 전환
	// 위치 애매함..
	SceneManager::GetInstance()->changeScene();

	SoundManager::GetInstance()->tick();
}

void GameManager::render()
{
	WriteManager::GetInstance()->render();
}