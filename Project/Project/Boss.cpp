#include "pch.h"
#include "Boss.h"


Boss::Boss()
{
	playerLevel = Player::getInstance()->GetLevel();
	RandomManager::GetInstance()->setRange(30, 45);
	double  Hp = double(playerLevel * RandomManager::GetInstance()->getRandom<int>());
	RandomManager::GetInstance()->setRange(7, 9);
	double  damage = double(playerLevel * RandomManager::GetInstance()->getRandom<int>());
	int		def = playerLevel * 2;
	//이름    hp  maxhp  damage   def  skd   eva drop exp  coin
	BossStat = { "무지개 드래고니당", Hp, Hp, damage, def, 1.4, 20, 30, 13, 20};
	dropItems[HEALTH_POTION] = BossStat.dropRate;
	dropItems[POWER_POTION] = BossStat.dropRate;
	bDead = false;
}

Boss::~Boss() {}


double Boss::UseSkill()
{
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, GetName() + "가 스킬을 사용합니다!!!!", true, 0));
	return GetDamage() * GetSkillDamage();
}

void Boss::Attack()
{
	//스킬 쓸확률
	int skillProbability = 10;
	RandomManager::GetInstance()->setRange(0, 100);
	double Trigger = double(playerLevel * RandomManager::GetInstance()->getRandom<int>());

	//스킬을 쓰면
	if (Trigger < skillProbability) {
		double	damage = UseSkill() - Player::getInstance()->GetDefense();
		int		probability = Player::getInstance()->GetEvasion();
		int		trigger = rand() % 100;
		if (probability < trigger) {
			Player::getInstance()->GetAttack(damage);
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "스킬 공격 히트! 데미지: " + to_string(int(damage)), true, 0));
		}
		else {
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "적의 스킬 공격을 회피했습니다.", true, 0));
		}
	}
	//스킬을 아니 쓰면
	else {
		double	damage = GetDamage() - Player::getInstance()->GetDefense();
		int		probability = Player::getInstance()->GetEvasion();
		int		trigger = rand() % 100;
		if (probability < trigger) {
			Player::getInstance()->GetAttack(damage);
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "일반 공격 히트! 데미지: " + to_string(int(damage)), true, 0));
		}
		else { WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "적의 일반 공격을 회피했습니다.", true, 0)); }
	}
}

void Boss::GetAttack()
{
	double damage = Player::getInstance()->GetDamage() - GetDefense();
	SetCurrentHP(GetCurrentHP() - damage);
	if (GetCurrentHP() <= 0) {
		SetCurrentHP(0);
	}
}

void Boss::DropItem() {
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
				WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, droppedItem->GetName() + "이(가) 드롭되었습니다."));
			}
			delete droppedItem;
		}
	}
}

void Boss::is_Die()
{
	if (GetCurrentHP() <= 0) {
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "당신이 " + GetName() + "를 쓰러트렸습니다!", true, 0));
		DropItem();
		bDead = true;
	}
	bDead = false;
}

void Boss::Tick()
{
}


//---------------------------------
//           Get함수
//---------------------------------
const string Boss::GetName()
{
	return BossStat.name;
}
const double Boss::GetCurrentHP()
{
	return BossStat.currentHp;
}
const double Boss::GetMaxHP()
{
	return BossStat.maxHp;
}
const double Boss::GetDropRate()
{
	return BossStat.dropRate;
}

const bool Boss::GetbDead()
{
	return bDead;
}

const int Boss::GetCoin()
{
	return BossStat.coin;
}
const int Boss::GetDefense()
{
	return BossStat.defense;
}
const int Boss::GetExp()
{
	return BossStat.exp;
}
const int Boss::GetEvasion()
{
	return BossStat.evasion;
}

const double Boss::GetSkillDamage()
{
	return BossStat.skillDamage;
}

const double Boss::GetDamage()
{
	return BossStat.damage;
}
//-----------------------------//
//          Set함수            //
//-----------------------------//

void Boss::SetCurrentHP(double hp)
{
	BossStat.currentHp = hp;
}



