#pragma once

#include "fmod.h"
#include "fmod.hpp"
#include "fmod_codec.h"

#ifdef _DEBUG
#pragma comment(lib, "fmodL_vc.lib")
#else
#pragma comment(lib, "fmod_vc.lib")
#endif

class Sound
{
public:
	static FMOD::System* g_pFMOD;

private:
	FMOD::Sound*			m_pSound;
	list<FMOD::Channel*>	m_listChannel;

public:
	//  0 ~ 1(Volume)
	int Play(int _iRoopCount, float _fVolume = 1.f, bool _bOverlap = false);
	void Stop();

	// 0 ~ 1
	void SetVolume(float _f, int _iChannelIdx);

private:
	void RemoveChannel(FMOD::Channel* _pTargetChannel);
	friend FMOD_RESULT CHANNEL_CALLBACK(FMOD_CHANNELCONTROL* channelcontrol, FMOD_CHANNELCONTROL_TYPE controltype
		, FMOD_CHANNELCONTROL_CALLBACK_TYPE callbacktype
		, void* commanddata1, void* commanddata2);

public:
	//virtual void UpdateData() {}
	void LoadSound(const wstring& _strFilePath);

public:
	Sound();
	~Sound();
};
