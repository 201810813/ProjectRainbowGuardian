#pragma once
#include "pch.h"
#include "Player.h"
#include "Item.h"
#include <utility>
#include "define.h"
#include "ConsoleLayout.h"
#include "HealthPotion.h"
#include "PowerPotion.h"
#include "RandomManager.h"
#
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
	MonsterStat monsterStat;
	map<Type,double> dropItems;
	int playerLevel;
	bool bDead;
public:
	Monster();
	virtual ~Monster();
public:
	virtual void	Attack()		= 0;
	virtual void	GetAttack()		= 0;
	virtual double	UseSkill()		= 0;
	virtual void	is_Die()		= 0;
	virtual void	Tick()			= 0;
	virtual void	DropItem()		= 0;
public:
	//get fuc
	virtual const double GetSkillDamage() = 0;
	virtual const double GetDamage()	  = 0;
	virtual const double GetCurrentHP()   = 0;
	virtual const double GetMaxHP()		  = 0;
	virtual const double GetDropRate()    = 0;
	virtual const int	 GetDefense()	  = 0;
	virtual const int	 GetExp()		  = 0;
	virtual const int	 GetCoin()		  = 0;
	virtual const int    GetEvasion()	  = 0;
	virtual const bool   GetbDead()		  = 0;
	virtual const string GetName()		  = 0;
	//set fuc
	virtual void SetCurrentHP(double hp)  = 0;
	
};
