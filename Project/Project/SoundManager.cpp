#include "pch.h"
#include "SoundManager.h"
#include "PathManager.h"

shared_ptr<SoundManager> SoundManager::Instance = nullptr;

SoundManager::~SoundManager()
{
	map<string, Sound*>::iterator iter;
	for (iter = m_mapSound.begin(); iter != m_mapSound.end(); ++iter)
	{
		delete iter->second;
	}
	m_mapSound.clear();
}

void SoundManager::Initialize()
{
	FMOD::System_Create(&Sound::g_pFMOD);

	// 32개 채널 생성
	Sound::g_pFMOD->init(32, FMOD_DEFAULT, nullptr);



	// 사용 가능한 음악들 로드
	Sound* sound = new Sound();
	wstring path = PathManager::GetInstance()->GetContentPath();
	path += L"BGM.mp3";
	sound->LoadSound(path);
	m_mapSound.insert({ "Main_BGM", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Ending.mp3";
	sound->LoadSound(path);
	m_mapSound.insert({ "Ending_BGM", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Hover_Cilck_Sound.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "MoveCursor", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Select_Cilck_Sound.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "SelectCursor", sound });
}

void SoundManager::tick()
{
	Sound::g_pFMOD->update();
}

void SoundManager::PlayMusic(const string& SoundName, int _iRoopCount, float _fVolume, bool _bOverlap)
{
	if (m_mapSound.end() == m_mapSound.find(SoundName))
		return;

	m_mapSound.find(SoundName)->second->Play(_iRoopCount, _fVolume, _bOverlap);
}

void SoundManager::StopMusic(const string& SoundName)
{
	if (m_mapSound.end() == m_mapSound.find(SoundName))
		return;

	m_mapSound.find(SoundName)->second->Stop();
}

void SoundManager::SetVolume(const string& SoundName, float _f, int _iChannelIdx)
{
	if (m_mapSound.end() == m_mapSound.find(SoundName))
		return;

	m_mapSound.find(SoundName)->second->SetVolume(_f, _iChannelIdx);
}
