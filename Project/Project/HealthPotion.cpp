#include "pch.h"
#include "HealthPotion.h"
#include "Player.h"
#include "SoundManager.h"

HealthPotion::HealthPotion() : type(HEALTH_POTION), name("체력포션"), effect(10) {}

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
    SoundManager::GetInstance()->PlayMusic("HUsePotion", 1, 0.3, true);
    int heal = effect + (Player::getInstance()->GetLevel() * 20);
    Player::getInstance()->SetCurrentHP(heal);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "체력을" + to_string(heal)+ "회복합니다", true, 0, TEXT_COLOR_TYPE::GREEN_INENSITY));
}

Type HealthPotion::GetType()
{
    return type;
}
