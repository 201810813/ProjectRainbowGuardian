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
	double Attack() override;
	double UseSkill() override;
	void Hitted(double& damage) override;
	const string getName() override;
	double& getHP() override;
	void Heal(double heal) override;
};