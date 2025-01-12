#pragma once
#include "Monster.h"
class MGoldenLizard :Monster {
private:
	MonsterStat lizardStat;
	int coin;
	int exp;
public:
	MGoldenLizard();
	~MGoldenLizard();
	double Attack() override;
	double UseSkill() override;
	void Hitted(double damage) override;
	string getName() override;
	void Die() override;
	double& getHP() override;
};