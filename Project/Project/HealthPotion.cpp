#include "pch.h"
#include "HealthPotion.h"
#include "Player.h"

HealthPotion::HealthPotion() : type(HEALTH_POTION), name("체력포션"), effect(30) {}

HealthPotion::~HealthPotion()
{
}

int HealthPotion::GetEffect()
{
    return effect;
}

string HealthPotion::GetName()
{
    return name;
}

void HealthPotion::Use()
{
    Player::getInstance()->SetCurrentHP(effect);
    cout << "현재 체력: " << Player::getInstance()->GetCurrentHP();
}

Type HealthPotion::GetType()
{
    return type;
}
