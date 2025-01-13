#include "pch.h"
#include "MRedWolf.h"

MRedWolf::MRedWolf() : coin(15), exp(13)
{
	WolfStat = { "RedWolf", 100, 100, 10, 3, 1.2, 20, 20 };
}

MRedWolf::~MRedWolf()
{
}

double MRedWolf::UseSkill() 
{
	return WolfStat.damage * WolfStat.skillDamage;
}

void MRedWolf::Attack(Player& player) {
	double damage = WolfStat.damage - player.GetDefense();

	player.GetAttack(damage);
}

void MRedWolf::GetAttack(double& damage)
{
	WolfStat.currentHp -= damage;
}

const string MRedWolf::GetName()
{
	return WolfStat.name;
}

double& MRedWolf::GetCurrentHP() {
	return WolfStat.currentHp;
}

void MRedWolf::Heal(double heal)
{
	WolfStat.currentHp += heal;
}


