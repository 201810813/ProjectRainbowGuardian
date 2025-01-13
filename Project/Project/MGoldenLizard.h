#include "Monster.h"

class MGoldenLizard :public Monster {
private:
	MonsterStat lizardStat;
	int coin;
	int exp;
public:
	MGoldenLizard();
	~MGoldenLizard() override;
	void Attack(Player& player) override;
	double UseSkill() override;
	void GetAttack(double& damage) override;
	void Heal(double heal) override;

public:
	double& GetCurrentHP() override;
	const string GetName() override;
	int	GetDefense() override; // 
};
