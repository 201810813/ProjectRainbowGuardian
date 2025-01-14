﻿#pragma once

class GameManager
{
private:
	static shared_ptr<GameManager>	Instance;
	bool							GameEnd;
	
	GameManager() = default;
	GameManager(const GameManager& other) = delete;
	
	~GameManager()
	{

	}

	GameManager& operator = (const GameManager& other) = delete;

	static void Destroy(GameManager* InstancePtr)
	{
		delete InstancePtr;
	}

public:
	static shared_ptr<GameManager> GetInstance()
	{
		if (nullptr == Instance)
		{
			Instance = shared_ptr<GameManager>(new GameManager(), Destroy);
		}

		return Instance;
	}

	void Initialize();

	void tick();
	void render();

	void EndGame()
	{
		GameEnd = true;
	}

	bool IsGameEnd()
	{
		return GameEnd;
	}
};