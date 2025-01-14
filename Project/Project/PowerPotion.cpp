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
	std::cout << "PowerPotion 사용: 공격력 " << effect << " 증가!" << std::endl;
	Player::getInstance()->SetDamage(effect);
}

Type PowerPotion::GetType()
{
	return type;
}

