﻿#pragma once
#include "pch.h"
#include "Monster.h"

class FairyFire :public Monster {
private:
	MonsterStat			FairyStat;
	map<Type, double>	dropItems;
	int					playerLevel;
	bool				bDead;
	
public:
	FairyFire();
	~FairyFire() override;

public:
	void	Attack()				override;
	void	GetAttack()				override;
	double	UseSkill()				override;
	bool	is_Die()				override;
	void	Tick()					override;
	void	DropItem()				override;
	void    Begin()					override;
	void    CreateAnimations();
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
	const bool   GetbDead()			override;
	//set
	void SetCurrentHP(double hp)	override;

public:
	void PlayAttackSound();
};