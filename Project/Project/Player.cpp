#include "pch.h"
#include "Player.h"

shared_ptr<Player> Player::player = nullptr;

Player::Player() : stat{ 100, 100, 1, 200, 0, 17, 3, 20, "" }, invenSize(10)
{
	cout << u8"플레이어 생성" << endl;
}

Player::~Player()
{
	cout << u8"플레이어 삭제" << endl;
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
	double damage = stat.damage - monster.GetDefense();
	int probability = monster.GetEvasion();
	int trigger = rand() % 100;
	if (probability < trigger) {
		
		monster.GetAttack(damage);
		cout << u8"공격 적중!\n" << u8"적의 쳬력: " << monster.GetCurrentHP() << endl;
	}
	else { cout << u8"적이 공격을 회피했습니다."; }
	
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
double Player::GetCurrentHP()
{
	return stat.currentHP;
}

int Player::GetDefense()
{
	return stat.defense;
}

double Player::GetMaxHP()
{
	return stat.maxHP;
}

int Player::GetEvasion()
{
	return stat.evasion;
}
//-------------------------------//
//          아이템함수           //
//-------------------------------//
