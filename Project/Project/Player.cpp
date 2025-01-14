﻿#include "pch.h"
#include "Player.h"
#include "HealthPotion.h"
#include "PowerPotion.h"

shared_ptr<Player> Player::player = nullptr;

Player::Player() : stat{ 100, 100, 1, 200, 0, 17, 3, 20, "" }
{
	
}

Player::~Player()
{
	for (auto& pair : inventory) {
		for (Item* item : pair.second) {
			delete item;  // 아이템 객체 삭제
		}
		pair.second.clear();  // 벡터 초기화
	}
	inventory.clear();  // 맵 초기화
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
	cout << u8"당신이 공격합니다" << endl;
	int probability = monster.GetEvasion();
	int trigger = rand() % 100;
	if (probability < trigger) {
		
		monster.GetAttack();
		cout << u8"공격 적중!\n" << u8"적의 쳬력: " << monster.GetCurrentHP() << endl;
	}
	else { cout << u8"적이 공격을 회피했습니다."; }
	
}

void Player::gainExp(int exp) { // 경험치 획득
	stat.currentexp += exp;
	cout << stat.name << "이(가) " << " 50 " << "의 경험치를 획득했습니다!" << endl;

	while (stat.currentexp >= 100) {
		stat.currentexp = 0;
		levelUp();
	}
}

void Player::levelUp() { // 레벨업
	stat.level++;
	stat.maxHP += 20;
	stat.damage += 5;
	cout << stat.name << "이(가) 레벨 업! 현재 레벨: " << stat.level << endl;
	cout << "최대 체력과 공격력이 증가했습니다!" << endl;
}

bool Player::IsDie(double hp)
{
	if (stat.currentHP < 0) {
		return true;
	}
	else return false;
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

//----------------------------//
//          Set함수           //
//----------------------------//
void Player::SetCurrentHP(double heal)
{
	if (stat.currentHP + heal > stat.maxHP) {
		stat.currentHP = stat.maxHP;
	}
	stat.currentHP += heal;
}

void Player::SetDamage(int buff)
{
	stat.damage += buff;
}


//-----------------------------------//
//          아이템관련함수           //
//-----------------------------------//

void Player::AddItemToInventory(Item* item)
{
	inventory[item->GetType()].push_back(item);
	itemCounts[item->GetType()]++;
	cout << item->GetName() << "이 추가되었습니다." << endl;
}

void Player::ShowInventory()
{
	if (inventory.empty()) {
		cout << "인벤토리가 비어있습니다." << endl;
	}
	else {
		for (const auto& item : inventory) {
			cout << item.first << "아이템이" << item.second.size() << "개 있습니다." << endl;
		}
	}
}

void Player::UseItem(Type type)
{
	if (itemCounts[type] > 0) {
		Item* item = inventory[type].back();
		inventory[type].pop_back();  // 아이템 사용 후 제거
		itemCounts[type]--;  // 아이템 개수 감소

		cout << "아이템 사용: " << item->GetName() << endl;
		item->Use();  // 아이템 사용

		// 아이템 객체 삭제
		delete item;
		item = nullptr;
	}
	else {
		cout << "해당 아이템이 인벤토리에 없습니다.\n";
	}
}

