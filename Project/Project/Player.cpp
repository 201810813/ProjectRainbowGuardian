#include "pch.h"
#include "Player.h"
#include "HealthPotion.h"
#include "PowerPotion.h"
#include "SoundManager.h"
#include "RandomManager.h"

shared_ptr<Player> Player::player = nullptr;

Player::Player() : stat{ 100, 100, 1, 100, 0, 10, 3, 20, 0, 0, ""}, AddDamage(1), bPowerUp(false), PowerUpChance(0), bDead(false)
{
	this->HealthPotion = new class HealthPotion();
	this->PowerPotion = new class PowerPotion();
}

Player::~Player()
{
	delete HealthPotion;
	delete PowerPotion;
}

shared_ptr<Player> Player::getInstance() {
	if (!player) {
		player = shared_ptr<Player>(new Player());
	}
	return player;
}

void Player::SetName(const string name)
{
	stat.name = name;
}
string& Player::getName() {
	return stat.name;
}

void Player::GetAttack(double& damage)
{
	stat.currentHP -= damage;
	if (stat.currentHP < 0) {
		stat.currentHP = 0;
	}

}

void Player::Attack(Monster& monster)
{
	RandomManager::GetInstance()->setRange(0.f, 100.f);
	int probability = RandomManager::GetInstance()->getRandom<double>();
	int trigger = monster.GetEvasion();
	// 공격 성공
	if (trigger <= probability) {
		PlayAttackSound();
		if (PowerUpChance > 0) {
			int damage = GetDamage() + AddDamage;        // 플레이어 데미지 가져오기
			PowerUpChance--;
			monster.GetAttack();         // 몬스터 체력 감소
			// 성공 메시지 출력
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "공격 적중!", true, 0, TEXT_COLOR_TYPE::ORANGE));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "데미지 " + to_string(damage - monster.GetDefense()) + "가 들어갔습니다.", true, 0,TEXT_COLOR_TYPE::ORANGE));
		}
		else {
			bPowerUp = false;
			int damage = GetDamage();        // 플레이어 데미지 가져오기
			monster.GetAttack();         // 몬스터 체력 감소

			// 성공 메시지 출력
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "공격 적중!", true, 0, TEXT_COLOR_TYPE::ORANGE));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "데미지 " + to_string(damage - monster.GetDefense()) + "가 들어갔습니다.", true, 0, TEXT_COLOR_TYPE::ORANGE));
		}
	}
	else
	{
		SoundManager::GetInstance()->PlayMusic("Herb3", 1, 0.5, true);
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "적이 공격을 회피했습니다.....", true, 0, TEXT_COLOR_TYPE::WHITE));
	}
	
}

void Player::gainExp(int exp) { // 경험치 획득
	stat.currentexp += exp;

	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, ("플레이어가 " + to_string(exp) + "의 경험치를 획득했습니다!"), true, 0));
	if (stat.currentexp >= 100) {
		stat.currentexp = 0;
		levelUp();
	}
}

void Player::gainCoin(int coin)
{
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, to_string(coin) + "만큼의 골드를 얻었습니다.", true, 0, TEXT_COLOR_TYPE::ORANGE_INENSITY));
	stat.coin += coin;
}

bool Player::SpendGold(int Coin)
{
	if (stat.coin < Coin)
	{
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "지갑에 돈이 충분하지 않습니다.", true, 0, TEXT_COLOR_TYPE::ORANGE_INENSITY));
		return false;
	}
	else
	{
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, to_string(Coin) + "만큼의 골드를 사용했습니다.", false, 2, TEXT_COLOR_TYPE::ORANGE_INENSITY));
		stat.coin -= Coin;
		return true;
	}
}

void Player::levelUp() { // 레벨업
	stat.level++;
	stat.maxHP += 30;
	stat.currentHP = stat.maxHP;
	stat.damage += 7;
	stat.defense += 2;
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "레벨 업! 현재 레벨: " + to_string(stat.level), true, 0,TEXT_COLOR_TYPE::SKY));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "최대 체력과 공격력, 방여력이 증가했습니다!" ,true, 0, TEXT_COLOR_TYPE::SKY));
}

bool Player::IsDie()
{
	if (stat.currentHP <= 0) {
		bDead = true;
		return bDead;
	}
	else return bDead;
}

//----------------------------//
//          Get함수           //
//----------------------------//
const double Player::GetCurrentHP()
{
	return stat.currentHP;
}

const int Player::GetDefense()
{
	return stat.defense;
}

const double Player::GetMaxHP()
{
	return stat.maxHP;
}

const int Player::GetEvasion()
{
	return stat.evasion;
}

const int Player::GetLevel()
{
	return stat.level;
}

const double Player::GetDamage()
{
	return stat.damage;
}

const int Player::GetItemCount()
{
	return stat.itemCount;
}


const int Player::GetCoin()
{
	return stat.coin;
}

const int Player::GetCurrentExp()
{
	return stat.currentexp;
}

const int Player::GetMaxExp()
{
	return stat.maxExp;
}

const int Player::GetAddDamage()
{
	return AddDamage;
}


bool Player::Is_PowerUp()
{
	return bPowerUp;
}

const int Player::GetItemCount(Type type)
{
	return inventory[type];
}


void Player::PlayerRecovery()
{
	stat.currentHP = stat.maxHP;
	bDead = false;
}

//----------------------------//
//          Set함수           //
//----------------------------//
void Player::SetCurrentHP(double heal)
{
	if (stat.currentHP + heal > stat.maxHP) {
		stat.currentHP = stat.maxHP;
	}
	else
	{
		stat.currentHP += heal;
	}
}

void Player::SetDamage(int buff)
{
	stat.damage += buff;
}

void Player::SetCoin(int coin)
{
	stat.coin += coin;
}

void Player::PlayAttackSound()
{
	RandomManager::GetInstance()->setRange(1, 4);
	int rand = RandomManager::GetInstance()->getRandom<int>();

	switch (rand)
	{
	case 1:
		SoundManager::GetInstance()->PlayMusic("Sword_Hit_Flesh_1", 1, 0.3f, true);
		break;

	case 2:
		SoundManager::GetInstance()->PlayMusic("Sword_Hit_Flesh_2", 1, 0.3f, true);
		break;

	case 3:
		SoundManager::GetInstance()->PlayMusic("Sword_Hit_Flesh_3", 1, 0.3f, true);
		break;

	case 4:
		SoundManager::GetInstance()->PlayMusic("Sword_Hit_Flesh_4", 1, 0.3f, true);
		break;

	default:
		break;
	}
}


//-----------------------------------//
//          아이템관련함수           //
//-----------------------------------//

void Player::AddItemToInventory(Type type)
{
	inventory[type]++;
	if (type == HEALTH_POTION) {
		//WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "체력 포션이 추가되었습니다.", false, 4, TEXT_COLOR_TYPE::GREEN));
	}
	else if (type == POWER_POTION) {
		//WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "파워 포션이 추가되었습니다.", false, 4, TEXT_COLOR_TYPE::GREEN));
	}
	
}

void Player::ShowInventory()
{
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "체력 포션: " + to_string(inventory[HEALTH_POTION]), true, 0, TEXT_COLOR_TYPE::GREEN));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "파워 포션: " + to_string(inventory[POWER_POTION]), true, 0, TEXT_COLOR_TYPE::GREEN));
}



bool Player::UseItem(Type type)
{
	if(type == HEALTH_POTION){
		if (inventory[type] > 0) {
				HealthPotion->Use();
				inventory[HEALTH_POTION]--;
				return true;
			
		}
		else {
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "해당 아이템이 인벤토리에 없습니다.", true, 0, TEXT_COLOR_TYPE::GREEN));
			return false;
		}
	}
	else if (type == POWER_POTION) {
		if (inventory[type] > 0)
		{
			PowerPotion->Use();
			AddDamage = 5 + (2 * stat.level);
			inventory[POWER_POTION]--;
			bPowerUp = true;
			return true;
		}
		else {
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "해당 아이템이 인벤토리에 없습니다.", true, 0, TEXT_COLOR_TYPE::GREEN));
			return false;
		}
		
	}
	return false;
}

void Player::IncreaseChance()
{
	PowerUpChance++;
}

void Player::SellItem(Type type)
{
	inventory[type]--;
}

