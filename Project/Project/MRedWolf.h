#pragma once
#include "Monster.h"

class MRedWolf :public Monster {
private:
	MonsterStat WolfStat;
	int coin;
	int exp;
public:
	MRedWolf();
	~MRedWolf() override;
	void Attack(Player& player) override;
	void GetAttack(double& damage) override;
	double UseSkill() override;
	void Heal(double heal) override;

public:
	const string GetName() override;
	double& GetCurrentHP();
	int	GetDefense() = 0;
	
};