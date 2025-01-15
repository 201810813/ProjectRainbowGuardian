#pragma once
#include "Monster.h"
class Boss :public Monster {
private:
	MonsterStat			BossStat;
	map<Type, double>	dropItems;
	int					playerLevel;
	bool				bDead;

public:
	Boss();
	~Boss() override;

public:
	void	Attack()				override;
	void	GetAttack()				override;
	double	UseSkill()				override;
	bool	is_Die()				override;
	void	Tick()					override;
	void	DropItem()				override;
	void	CreateAnimations();
	void    Begin()					override;

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
};

