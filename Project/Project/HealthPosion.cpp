#include "pch.h"
#include "HealthPosion.h"

HealthPosion::HealthPosion() : type(HEALTH_POSTION), name("ü������"), effect(30) {}

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
