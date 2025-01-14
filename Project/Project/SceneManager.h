#pragma once
#include "Scene.h"

class SceneManager
{
private:
	static shared_ptr<SceneManager>	Instance;

	SceneManager() = default;
	SceneManager(const SceneManager& other) = delete;

	~SceneManager()
	{
		if(CurrentScene != nullptr)
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
	Scene* CurrentScene;


public:
	void Initialize();
	void tick();
};