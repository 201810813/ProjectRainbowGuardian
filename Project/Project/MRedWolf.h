#pragma once
#include "Monster.h"
class MRedWolf:Monster {
private:
	MonsterStat WolfStat;
	int coin;
	int exp;
public:
	MRedWolf();
	~MRedWolf() override;
	double Attack() override;
	double UseSkill() override;
	void Hitted(double damage) override;
	string getName() override;
	void Die() override;
	double& getHP() override;
};