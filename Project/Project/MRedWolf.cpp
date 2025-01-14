#include "pch.h"
#include "MRedWolf.h"
#include "HealthPotion.h"
#include "PowerPotion.h"
#include "RandomManager.h"

MRedWolf::MRedWolf()
{
	playerLevel = Player::getInstance()->GetLevel();
	WolfStat = { "RedWolf", 100, 100, 10, 3, 1.2, 20, 20, 13 };
	dropItems[HEALTH_POTION] = 1.0;
	dropItems[POWER_POTION] = 0.5;
}

MRedWolf::~MRedWolf() {}


double MRedWolf::UseSkill()
{
	return WolfStat.damage * WolfStat.skillDamage;
}

void MRedWolf::Attack()
{
	double damage = WolfStat.damage - Player::getInstance()->GetDefense();
	int probability = Player::getInstance()->GetEvasion();
	int trigger = rand() % 100;
	if (probability < trigger) {
		Player::getInstance()->GetAttack(damage);
		cout << "���� ����!\n" << "����� �Ƿ�: " << Player::getInstance()->GetCurrentHP() << endl;
	}
	else { cout << "���� ������ ȸ���߽��ϴ�."; }
}

void MRedWolf::Tick() {
}

void MRedWolf::DropItem() {
	RandomManager::GetInstance()->setRange(0.f, 1.f);  // 0.0 ~ 1.0 ������ ���� ��
	double randomChance = RandomManager::GetInstance()->getRandom<double>();
    for (const auto& item : dropItems) {
        if (randomChance <= item.second) {  // Ȯ���� �´� ������ ���
            Item* droppedItem = nullptr;

            switch (item.first) {
            case HEALTH_POTION:
                droppedItem = new HealthPotion();
                break;
            case POWER_POTION:
				droppedItem = new PowerPotion();
				break;
            default:
                break;
            }

            if (droppedItem) {
                Player::getInstance()->AddItemToInventory(droppedItem);  // �÷��̾� �κ��丮�� ������ �߰�
                std::cout << droppedItem->GetName() << "��(��) ��ӵǾ����ϴ�.\n";
            }
            break;  // ù ��° ��� �������� ó���� �� ����
        }
    }
}

void MRedWolf::Die()
{
	cout << "����� ���� ���븦 ����Ʈ�Ƚ��ϴ�!" << endl;
	DropItem();
	delete this;
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

