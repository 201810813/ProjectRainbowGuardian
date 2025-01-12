#include "pch.h"
#include "MRedWolf.h"

MRedWolf::MRedWolf() : coin(15), exp(10)
{
	WolfStat = { "RedWolf", 100, 100, 10, 3, 1.2, 20, 20 };
}

MRedWolf::~MRedWolf()
{
}

double MRedWolf::Attack()
{
	return WolfStat.damage;
}
double MRedWolf::UseSkill() 
{
	return WolfStat.damage * WolfStat.skillDamage;
}


void MRedWolf::Hitted(double damage)
{
	WolfStat.currentHp -= damage;
}

string MRedWolf::getName()
{
	return WolfStat.name;
}

void MRedWolf::Die() 
{
}
double& MRedWolf::getHP() {
	return WolfStat.currentHp;
}