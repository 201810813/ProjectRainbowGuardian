#include "pch.h"
#include "SceneManager.h"
#include "MainScene.h"
#include "IntroScene.h"
#include "Scene1F.h"
#include "Scene2F.h"
#include "Scene3F.h"
#include "Scene4F.h"
#include "Scene5F.h"
#include "Scene6F.h"
#include "Scene7F.h"
#include "FinalScene.h"

shared_ptr<SceneManager> SceneManager::Instance = nullptr;

void SceneManager::Initialize()
{
	//CurrentScene = new IntroScene;
	CurrentScene = new MainScene;
	//CurrentScene = new Scene1F;
	//CurrentScene = new Scene2F;
	//CurrentScene = new Scene3F;
	//CurrentScene = new Scene4F;
	//CurrentScene = new Scene5F;
	//CurrentScene = new Scene6F;
	//CurrentScene = new Scene7F;
	//CurrentScene = new FinalScene;

	CurrentScene->makeLayout(); //레이아웃 생성
}

void SceneManager::tick()
{
	CurrentScene->tick();
}