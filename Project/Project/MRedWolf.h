#pragma once

#include "Monster.h"

class MRedWolf :public Monster {
private:
	MonsterStat WolfStat;
public:
	MRedWolf();
	~MRedWolf() override;
	void Attack(Player& player) override;
	void GetAttack(double& damage) override;
	double UseSkill() override;

public:
	const string GetName() override;
	double& GetCurrentHP() override;
	int	GetDefense() override;
	int GetExp() override;
	int GetEvasion() override;
	void Die() override;
	void Tick();
};