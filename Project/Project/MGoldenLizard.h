#include "Monster.h"

class MGoldenLizard :public Monster {
private:
	MonsterStat lizardStat;
	int coin;
	int exp;
public:
	MGoldenLizard();
	~MGoldenLizard() override;
	double Attack() override;
	double UseSkill() override;
	void Hitted(double& damage) override;
	const string getName() override;
	double& getHP() override;
	void Heal(double heal) override;
};
