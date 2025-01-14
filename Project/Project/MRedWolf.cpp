#include "pch.h"
#include "MRedWolf.h"
#include "HealthPotion.h"
#include "PowerPotion.h"
#include "RandomManager.h"

MRedWolf::MRedWolf()
{
	playerLevel = Player::getInstance()->GetLevel();
	RandomManager::GetInstance()->setRange(20, 30);
	double  Hp = double(playerLevel * RandomManager::GetInstance()->getRandom<int>());
	RandomManager::GetInstance()->setRange(5, 10);
	double  damage = double(playerLevel * RandomManager::GetInstance()->getRandom<int>()); 
	int		def = playerLevel * 2;
 	     		  //이름    hp  maxhp  damage   def  skd   eva drop exp  coin
	WolfStat = { "RedWolf", Hp,  Hp,   damage,  def,  1.4,  20,  30, 13,   20};
	dropItems[HEALTH_POTION] = WolfStat.dropRate;
	dropItems[POWER_POTION] = WolfStat.dropRate;
}

MRedWolf::~MRedWolf() {}


double MRedWolf::UseSkill()
{
	cout << GetName() + "가 스킬을 사용합니다!!!!";
	return GetDamage() * GetSkillDamage();
}

void MRedWolf::Attack()
{	
	//스킬 쓸확률
	int skillProbability = 10;
	RandomManager::GetInstance()->setRange(0, 100);
	double Trigger = double(playerLevel * RandomManager::GetInstance()->getRandom<int>());
	//스킬을 쓰면
	if (Trigger < skillProbability) {
		double	damage		= UseSkill() - Player::getInstance()->GetDefense();
		int		probability = Player::getInstance()->GetEvasion();
		int		trigger		= rand() % 100;
		if (probability < trigger) {
			Player::getInstance()->GetAttack(damage);
			cout << u8"스킬 공격 히트!\n" << u8"당신의 쳬력: " << Player::getInstance()->GetCurrentHP() << endl;
		}
		else { cout << u8"적의 스킬 공격을 회피했습니다."; }
	}
	//스킬을 아니 쓰면
	else {
		double	damage = GetDamage() - Player::getInstance()->GetDefense();
		int		probability = Player::getInstance()->GetEvasion();
		int		trigger		= rand() % 100;
		if (probability < trigger) {
			Player::getInstance()->GetAttack(damage);
			cout << u8"공격 적중!\n" << u8"당신의 쳬력: " << Player::getInstance()->GetCurrentHP() << endl;
		}
		else { cout << u8"적의 공격을 회피했습니다."; }
	}
}

void MRedWolf::GetAttack()
{
	double damage = Player::getInstance()->GetDamage();
	if (GetCurrentHP() <= 0) {
		SetCurrentHP(0);
	}
	else {
		SetCurrentHP(damage);
	}
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
			delete droppedItem;
		}
	}
}

void MRedWolf::Die()
{
	cout << "당신이 붉은 늑대를 쓰러트렸습니다!" << endl;
	DropItem();
	delete this;
}

void MRedWolf::Tick()
{
}


//---------------------------------
//           Get함수
//---------------------------------
const string MRedWolf::GetName()
{
	return WolfStat.name;
}
const double MRedWolf::GetCurrentHP() 
{
	return WolfStat.currentHp;
}
const double MRedWolf::GetMaxHP()
{
	return WolfStat.maxHp;
}
const double MRedWolf::GetDropRate()
{
	return WolfStat.dropRate;
}

const int MRedWolf::GetCoin()
{
	return WolfStat.coin;
}
const int MRedWolf::GetDefense()
{
	return WolfStat.defense;
}
const int MRedWolf::GetExp()
{
	return WolfStat.exp;
}
const int MRedWolf::GetEvasion()
{
	return WolfStat.evasion;
}

const double MRedWolf::GetSkillDamage()
{
	return WolfStat.skillDamage;
}

const double MRedWolf::GetDamage()
{
	return WolfStat.damage;
}
//-----------------------------//
//          Set함수            //
//-----------------------------//

void MRedWolf::SetCurrentHP(double hp)
{
	WolfStat.currentHp = hp;
}

