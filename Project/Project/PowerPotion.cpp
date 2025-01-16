#include "pch.h"
#include "PowerPotion.h"
#include "Player.h"
#include"SoundManager.h"

PowerPotion::PowerPotion() : type(POWER_POTION), name("파워 포션"),  effect(5)
{
}

PowerPotion::~PowerPotion()
{
}

int PowerPotion::GetEffect()
{
	return effect;
}

string PowerPotion::GetName()
{
	return name;
}

void PowerPotion::Use()
{
	SoundManager::GetInstance()->PlayMusic("PUsePotion", 1, 0.2, true);
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "공격력이 두 턴 동안" + to_string(effect + (2* Player::getInstance()->GetLevel())) + "오릅니다!", true, 0, TEXT_COLOR_TYPE::RED_INENSITY));
	Player::getInstance()->IncreaseChance();
	Player::getInstance()->IncreaseChance();
}

Type PowerPotion::GetType()
{
	return type;
}

