#pragma once
#include "Scene.h"
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
#include "AltarScene.h"
#include "ShopScene.h"

class SceneManager
{
private:
	static shared_ptr<SceneManager>	Instance;

	SceneManager() = default;
	SceneManager(const SceneManager& other) = delete;

	~SceneManager()
	{
		//delete CurrentScene;
		if(CurrentScene != nullptr) //
			delete CurrentScene;
	}

	SceneManager& operator = (const SceneManager& other) = delete; 

	static void Destroy(SceneManager* InstancePtr)
	{
		delete InstancePtr;
	}

public:
	static shared_ptr<SceneManager> GetInstance()
	{
		if (nullptr == Instance)
		{
			Instance = shared_ptr<SceneManager>(new SceneManager(), Destroy);
		}

		return Instance;
	}

private:
	Scene* CurrentScene; //현재 씬을 가리키는 포인터
	int currentFloor;

public:
	void Initialize();
	void tick();
	void changeScene(int floor); //씬 변경 메서드
};