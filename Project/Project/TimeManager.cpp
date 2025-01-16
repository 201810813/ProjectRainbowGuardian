#include "pch.h"
#include "TimeManager.h"

shared_ptr<TimeManager> TimeManager::Instance = nullptr;

void TimeManager::Initialize()
{
}

void TimeManager::tick()
{
}

float TimeManager::GetDeltaTime()
{
	return m_Timer.Mark();
}
