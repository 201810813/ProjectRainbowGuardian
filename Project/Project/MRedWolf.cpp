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
		cout << "공격 적중!\n" << "당신의 쳬력: " << Player::getInstance()->GetCurrentHP() << endl;
	}
	else { cout << "적의 공격을 회피했습니다."; }
}

void MRedWolf::Tick() {
}

void MRedWolf::DropItem() {
	RandomManager::GetInstance()->setRange(0.f, 1.f);  // 0.0 ~ 1.0 사이의 랜덤 값
	double randomChance = RandomManager::GetInstance()->getRandom<double>();
    for (const auto& item : dropItems) {
        if (randomChance <= item.second) {  // 확률에 맞는 아이템 드롭
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
                Player::getInstance()->AddItemToInventory(droppedItem);  // 플레이어 인벤토리에 아이템 추가
                std::cout << droppedItem->GetName() << "이(가) 드롭되었습니다.\n";
            }
            break;  // 첫 번째 드롭 아이템을 처리한 후 종료
        }
    }
}

void MRedWolf::Die()
{
	cout << "당신이 붉은 늑대를 쓰러트렸습니다!" << endl;
	DropItem();
	delete this;
}

//---------------------------------
//           Get함수
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

