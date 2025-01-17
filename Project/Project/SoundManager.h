#pragma once

#include "Sound.h"

class SoundManager
{
private:
	static shared_ptr<SoundManager>	Instance;
	map<string, Sound*>				m_mapSound;

	SoundManager() = default;
	SoundManager(const SoundManager& other) = delete;

	~SoundManager();

	SoundManager& operator = (const SoundManager& other) = delete;

	static void Destroy(SoundManager* InstancePtr)
	{
		delete InstancePtr;
	}

public:
	static shared_ptr<SoundManager> GetInstance()
	{
		if (nullptr == Instance)
		{
			Instance = shared_ptr<SoundManager>(new SoundManager(), Destroy);
		}

		return Instance;
	}

	void Initialize();

	void tick();
	void PlayMusic(const string& SoundName, int _iRoopCount, float _fVolume = 1.f, bool _bOverlap = false);
	void StopMusic(const string& SoundName);
	void SetVolume(const string& SoundName, float _f, int _iChannelIdx);
};

