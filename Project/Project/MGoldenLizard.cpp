#include "pch.h"
#include "MGoldenLizard.h"
#include "Player.h"

MGoldenLizard::MGoldenLizard() :coin(24), exp(20)
{	
	lizardStat.name = "GoldenLizard";
	lizardStat.maxHp = 110.0;
	lizardStat.currentHp = 110.0;
	lizardStat.damage = 12;
	lizardStat.defense = 6;
	lizardStat.dropRate = 25;
	lizardStat.evasionRate = 12;
	lizardStat.skillDamage = 1.6;
	
}

MGoldenLizard::~MGoldenLizard()
{
}

void MGoldenLizard::Attack(Player& player)
{
	double damage = lizardStat.damage - player.GetDefense();

	player.GetAttack(damage);
}

double MGoldenLizard::UseSkill()
{
	return lizardStat.damage * lizardStat.skillDamage;
}

void MGoldenLizard::GetAttack(double& damage)
{
	lizardStat.currentHp -= damage;
}

const string MGoldenLizard::GetName()
{
    return string();
}

int MGoldenLizard::GetDefense()
{
	return lizardStat.defense;
}

double& MGoldenLizard::GetCurrentHP()
{
	return lizardStat.currentHp;
}

void MGoldenLizard::Heal(double heal)
{
	lizardStat.currentHp += heal;
}

