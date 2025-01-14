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
		double evasion;
		double dropRate;
		int exp;
		int coin;
	};
private:
	MonsterStat monsterStat = {};
public:
	Monster();
	virtual ~Monster();
	virtual void Attack(Player& player) = 0;
	virtual void GetAttack(double& damage) = 0;
	virtual double UseSkill() = 0;
	virtual const string GetName() = 0;
	virtual void Die() = 0;
	virtual void Tick() = 0;

public:
	virtual double& GetCurrentHP() = 0;
	virtual int	GetDefense() = 0;
	virtual int GetExp() = 0;
	virtual int GetEvasion() = 0;
};
