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

	// ===== 상점 =====

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Chest(Close).wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "CloseDoor", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Chest(Open).wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "OpenDoor", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"GetCoin_0.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "GetCoin_0", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"GetCoin_1.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "GetCoin_1", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"GetCoin_2.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "GetCoin_2", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"UseCoin_0.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "UseCoin_0", sound });

	// ===== 제단 =====
	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Holy_Spell.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "Holy_Spell", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"AltarEnter.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "AltarEnter", sound });

	// ===== 포션 =====
	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"HUsePotion.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "HUsePotion", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"PUsePotion.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "PUsePotion", sound });

	// ===== 플레이어 =====
	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Sword_Hit_Flesh_1.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "Sword_Hit_Flesh_1", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Sword_Hit_Flesh_2.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "Sword_Hit_Flesh_2", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Sword_Hit_Flesh_3.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "Sword_Hit_Flesh_3", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Sword_Hit_Flesh_4.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "Sword_Hit_Flesh_4", sound });

	// ==== 회피 =====
	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Herb3.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "Herb3", sound });


	// ==== 아이언 골램 =====
	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Injured_Bash_0.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "Injured_Bash_0", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Injured_Bash_1.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "Injured_Bash_1", sound });

	// ==== 고드름치 =====

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"ice_blast_projectile_spell_01.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "ice_blast_projectile_spell_01", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"ice_spell_impact_shatter_01.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "ice_spell_impact_shatter_01", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"ice_spell_impact_shatter_02.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "ice_spell_impact_shatter_02", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"ice_spell_impact_shatter_03.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "ice_spell_impact_shatter_03", sound });

	// ==== 독덩쿠리 =====
	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Punch_1.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "Punch_1", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"Punch_4.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "Punch_4", sound });

	// ==== 보스씬 =====
	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"EnterBossRoom.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "EnterBossRoom", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"BossDie.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "BossDie", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"BossSkill.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "BossSkill", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"punch_heavy_huge_distorted_04.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "punch_heavy_huge_distorted_04", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"punch_heavy_huge_distorted_03.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "punch_heavy_huge_distorted_03", sound });

	// ==== 플레임 몹 =====
	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"fireball_impact_burn_01.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "fireball_impact_burn_01", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"fireball_impact_burn_03.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "fireball_impact_burn_03", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"fireball_impact_burn_04.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "fireball_impact_burn_04", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"fireball_blast_projectile_spell_06.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "fireball_blast_projectile_spell_06", sound });

	// ==== 전기 사마구 =====
	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"elec_lightning_magic_spell_04.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "elec_lightning_magic_spell_04", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"electric_lightning_blast_01.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "electric_lightning_blast_01", sound });

	// ==== 안개 마녀 =====
	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"water_blast_projectile_spell_03.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "water_blast_projectile_spell_03", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"water_blast_projectile_spell_04.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "water_blast_projectile_spell_04", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"water_spell_impact_hit_03.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "water_spell_impact_hit_03", sound });

	sound = new Sound();
	path = PathManager::GetInstance()->GetContentPath();
	path += L"water_spell_impact_hit_04.wav";
	sound->LoadSound(path);
	m_mapSound.insert({ "water_spell_impact_hit_04", sound });

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
