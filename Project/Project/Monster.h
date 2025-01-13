#pragma once
#include "pch.h"
#include "Player.h"
class Player;

class Monster {
public:
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
private:
	MonsterStat monsterStat = {};
	int coin;
public:
	Monster();
	virtual ~Monster();
	virtual void Attack(Player& player) = 0;
	virtual void GetAttack(double& damage) = 0;
	virtual double UseSkill() = 0;
	virtual const string GetName() = 0;
	virtual void Heal(double heal);

public:
	virtual double& GetCurrentHP() = 0;
	virtual int	GetDefense() = 0;
};
