#include "pch.h"
#include "HealthPosion.h"

HealthPosion::HealthPosion() : type(HEALTH_POSTION), name("체력포션"), effect(30) {}

HealthPosion::~HealthPosion()
{
}

int HealthPosion::GetEffect()
{
    return effect;
}

string HealthPosion::GetName()
{
    return string();
}
