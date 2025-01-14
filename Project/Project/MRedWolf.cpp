#include "pch.h"
#include "MRedWolf.h"

MRedWolf::MRedWolf()
{
	WolfStat = { "RedWolf", 100, 100, 10, 3, 1.2, 20, 20, 13 };
}

MRedWolf::~MRedWolf()
{

}

double MRedWolf::UseSkill()
{
	return WolfStat.damage * WolfStat.skillDamage;
}

void MRedWolf::Attack(Player& player) 
{
	double damage = WolfStat.damage - player.GetDefense();
	int probability = player.GetEvasion();
	int trigger = rand() % 100;
	if (probability < trigger) {
		player.GetAttack(damage);
		cout << "���� ����!\n" << "����� �Ƿ�: " << player.GetCurrentHP() << endl;
	}
	else { cout << "���� ������ ȸ���߽��ϴ�."; }
}

void MRedWolf::Die() 
{

	delete this;
}

void MRedWolf::Tick() {
	if (WolfStat.currentHp <= 0) {
		Die();
	}
}

//---------------------------------
//           Get�Լ�
//---------------------------------
void MRedWolf::GetAttack(double& damage)
{
	WolfStat.currentHp -= damage;
	if (WolfStat.currentHp <= 0) {
		WolfStat.currentHp = 0;
	}
}

const string MRedWolf::GetName()
{
	return WolfStat.name;
}

double& MRedWolf::GetCurrentHP() 
{
	return WolfStat.currentHp;
}
int MRedWolf::GetDefense()
{
	return WolfStat.defense;
}
int MRedWolf::GetExp()
{
	return WolfStat.exp;
}

int MRedWolf::GetEvasion()
{
	return WolfStat.evasion;
}

