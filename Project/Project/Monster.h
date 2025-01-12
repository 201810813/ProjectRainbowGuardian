#pragma once
#include "pch.h"
struct MonsterStat
{
	string name;
	double maxHp;
	double currentHp;
	double damage;
	int defense;
	double skillDamage;
	double evasionRate;
	double dropRate;
	int exp;
};


class Monster {
private:
	MonsterStat monsterStat = {};
	int coin;
public:
	Monster();
	virtual ~Monster();
	virtual double Attack() = 0;
	virtual double UseSkill() = 0;
	virtual void Hitted(double& damage) = 0;
	virtual const string getName() = 0;
	virtual double& getHP() = 0;
	virtual void Heal(double heal);
};
