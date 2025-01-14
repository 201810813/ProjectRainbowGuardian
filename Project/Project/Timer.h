#pragma once
#include "pch.h"

class Timer
{
	friend class TimeManager;
private:
	Timer();
	~Timer();

	float Mark();
	float Peek();

private:
	std::chrono::steady_clock::time_point m_last;
};

