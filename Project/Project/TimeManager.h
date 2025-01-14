#pragma once
#include "Timer.h"

class TimeManager
{
private:
	static shared_ptr<TimeManager>	Instance;
	float m_DeltaTime;
	Timer m_Timer;

	TimeManager() = default;
	TimeManager(const TimeManager& other) = delete;

	~TimeManager() {}

	TimeManager& operator = (const TimeManager& other) = delete;

	static void Destroy(TimeManager* InstancePtr)
	{
		delete InstancePtr;
	}

public:
	static shared_ptr<TimeManager> GetInstance()
	{
		if (nullptr == Instance)
		{
			Instance = shared_ptr<TimeManager>(new TimeManager(), Destroy);
		}

		return Instance;
	}

	void Initialize();

	void tick();
	float GetDeltaTime();
};

