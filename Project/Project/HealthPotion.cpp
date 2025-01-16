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
    int heal = effect + (Player::getInstance()->GetLevel() * 20);
    Player::getInstance()->SetCurrentHP(heal);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "체력을" + to_string(heal)+ "회복합니다", true, 0, TEXT_COLOR_TYPE::GREEN_INENSITY));
}

Type HealthPotion::GetType()
{
    return type;
}
