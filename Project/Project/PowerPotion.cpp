#include "pch.h"
#include "PowerPotion.h"
#include "Player.h"
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
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "공격력이 두 턴 동안" + to_string(effect * Player::getInstance()->GetLevel()) + "오릅니다!", true, 0, TEXT_COLOR_TYPE::RED_INENSITY));
	Player::getInstance()->IncreaseChance();
	Player::getInstance()->IncreaseChance();
}

Type PowerPotion::GetType()
{
	return type;
}

