#include "pch.h"
#include "IronGolem.h"


IronGolem::IronGolem()
{
	playerLevel = Player::getInstance()->GetLevel();
	RandomManager::GetInstance()->setRange(20, 30);
	double  Hp = double(playerLevel * RandomManager::GetInstance()->getRandom<int>())+(3*playerLevel);
	RandomManager::GetInstance()->setRange(5, 7);
	double  damage = double(playerLevel * RandomManager::GetInstance()->getRandom<int>())+ (1* playerLevel);
	int		def = playerLevel * 2;
	//이름    hp  maxhp  damage   def  skd   eva drop exp  coin
	GolemStat = { "아이언 골렘", Hp, Hp, damage, def, 1.4, 20, 30, 13, 20 };
	dropItems[HEALTH_POTION] = GolemStat.dropRate;
	dropItems[POWER_POTION] = GolemStat.dropRate;
	bDead = false;
}

IronGolem::~IronGolem() {}


double IronGolem::UseSkill()
{
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, GetName() + "가 스킬을 사용합니다!!!!", true, 0));
	return GetDamage() * GetSkillDamage();
}

void IronGolem::Attack()
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

void IronGolem::GetAttack()
{
	double damage = Player::getInstance()->GetDamage() - GetDefense();
	SetCurrentHP(GetCurrentHP() - damage);
	if (GetCurrentHP() <= 0) {
		SetCurrentHP(0);
	}
}

void IronGolem::DropItem() {
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

void IronGolem::is_Die()
{
	if (GetCurrentHP() <= 0) {
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "당신이 붉은 늑대를 쓰러트렸습니다!", true, 0));
		DropItem();
		bDead = true;
	}
	bDead = false;
}

void IronGolem::Tick()
{
}


//---------------------------------
//           Get함수
//---------------------------------
const string IronGolem::GetName()
{
	return GolemStat.name;
}
const double IronGolem::GetCurrentHP()
{
	return GolemStat.currentHp;
}
const double IronGolem::GetMaxHP()
{
	return GolemStat.maxHp;
}
const double IronGolem::GetDropRate()
{
	return GolemStat.dropRate;
}

const bool IronGolem::GetbDead()
{
	return bDead;
}

const int IronGolem::GetCoin()
{
	return GolemStat.coin;
}
const int IronGolem::GetDefense()
{
	return GolemStat.defense;
}
const int IronGolem::GetExp()
{
	return GolemStat.exp;
}
const int IronGolem::GetEvasion()
{
	return GolemStat.evasion;
}

const double IronGolem::GetSkillDamage()
{
	return GolemStat.skillDamage;
}

const double IronGolem::GetDamage()
{
	return GolemStat.damage;
}
//-----------------------------//
//          Set함수            //
//-----------------------------//

void IronGolem::SetCurrentHP(double hp)
{
	GolemStat.currentHp = hp;
}


