#include "pch.h"
#include "MGoldenLizard.h"

MGoldenLizard::MGoldenLizard()
{	
	lizardStat.name = "GoldenLizard";
	lizardStat.maxHp = 110.0;
	lizardStat.currentHp = 110.0;
	lizardStat.damage = 12;
	lizardStat.defense = 6;
	lizardStat.dropRate = 25;
	lizardStat.evasionRate = 12;
	lizardStat.skillDamage = 1.6;
	coin = 20;
}

MGoldenLizard::~MGoldenLizard()
{
}

double MGoldenLizard::Attack()
{
	return lizardStat.damage;
}

double MGoldenLizard::UseSkill()
{
	return lizardStat.damage * lizardStat.skillDamage;
}

void MGoldenLizard::Hitted(double damage)
{
	lizardStat.currentHp -= damage;
}

string MGoldenLizard::getName()
{
    return string();
}

double& MGoldenLizard::getHP()
{
	return lizardStat.currentHp;
}

void MGoldenLizard::Die() {}
