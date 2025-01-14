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
	void Attack() override;
	void GetAttack(double& damage) override;
	double UseSkill() override;

public:
	const string GetName() override;
	double& GetCurrentHP() override;
	int	GetDefense() override;
	int GetExp() override;
	int GetEvasion() override;
	void Die() override;
	void Tick() override;
	void DropItem() override;
};