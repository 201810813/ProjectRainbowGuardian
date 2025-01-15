﻿#include "pch.h"
#include "IceHedgehog.h"


IceHedgehog::IceHedgehog()
{
	playerLevel = Player::getInstance()->GetLevel();
	RandomManager::GetInstance()->setRange(20, 30);
	double  Hp = double(playerLevel * RandomManager::GetInstance()->getRandom<int>()) + (9 * playerLevel);
	RandomManager::GetInstance()->setRange(5, 7);
	double  damage = double(playerLevel * RandomManager::GetInstance()->getRandom<int>()) + (3 * playerLevel);
	int		def = playerLevel * 2;
	//이름    hp  maxhp  damage   def  skd   eva drop exp  coin
	HedgehogeStat = { "고드름치", Hp, Hp, damage, def, 1.4, 20, 30, 13, 20 };
	dropItems[HEALTH_POTION] = HedgehogeStat.dropRate;
	dropItems[POWER_POTION] = HedgehogeStat.dropRate;
	bDead = false;
}

IceHedgehog::~IceHedgehog() {}


double IceHedgehog::UseSkill()
{
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, GetName() + "가 스킬을 사용합니다!!!!", true, 0));
	return GetDamage() * GetSkillDamage();
}

void IceHedgehog::Attack()
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

void IceHedgehog::GetAttack()
{
	double damage = Player::getInstance()->GetDamage() - GetDefense();
	SetCurrentHP(GetCurrentHP() - damage);
	if (GetCurrentHP() <= 0) {
		SetCurrentHP(0);
	}
}

void IceHedgehog::DropItem() {
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

void IceHedgehog::is_Die()
{
	if (GetCurrentHP() <= 0) {
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "당신이 고드름치를 쓰러트렸습니다!", true, 0));
		DropItem();
		bDead = true;
	}
	bDead = false;
}

void IceHedgehog::Tick()
{
}


//---------------------------------
//           Get함수
//---------------------------------
const string IceHedgehog::GetName()
{
	return HedgehogeStat.name;
}
const double IceHedgehog::GetCurrentHP()
{
	return HedgehogeStat.currentHp;
}
const double IceHedgehog::GetMaxHP()
{
	return HedgehogeStat.maxHp;
}
const double IceHedgehog::GetDropRate()
{
	return HedgehogeStat.dropRate;
}

const bool IceHedgehog::GetbDead()
{
	return bDead;
}

const int IceHedgehog::GetCoin()
{
	return HedgehogeStat.coin;
}
const int IceHedgehog::GetDefense()
{
	return HedgehogeStat.defense;
}
const int IceHedgehog::GetExp()
{
	return HedgehogeStat.exp;
}
const int IceHedgehog::GetEvasion()
{
	return HedgehogeStat.evasion;
}

const double IceHedgehog::GetSkillDamage()
{
	return HedgehogeStat.skillDamage;
}

const double IceHedgehog::GetDamage()
{
	return HedgehogeStat.damage;
}
//-----------------------------//
//          Set함수            //
//-----------------------------//

void IceHedgehog::SetCurrentHP(double hp)
{
	HedgehogeStat.currentHp = hp;
}