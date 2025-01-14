#pragma once
#include "pch.h"
#include "Monster.h"

class MRedWolf :public Monster {
private:
	MonsterStat WolfStat;
	map<Type, double> dropItems;
	int playerLevel;
	
public:
	MRedWolf();
	~MRedWolf() override;

public:
	void	Attack()					override;
	void	GetAttack()					override;
	double	UseSkill()					override;
	void	Die()						override;
	void	Tick()						override;
	void	DropItem()					override;

public:
	//get
	const string GetName()			override;
	const int	 GetDefense()		override;
	const int	 GetExp()			override;
	const int	 GetEvasion()		override;
	const int	 GetCoin()			override;
	const double GetSkillDamage()	override;
	const double GetDamage()		override;
	const double GetCurrentHP()		override;
	const double GetMaxHP()			override;
	const double GetDropRate()		override;
	//set
	void SetCurrentHP(double hp)	override;
};