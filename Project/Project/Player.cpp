#include "pch.h"
#include "Player.h"

shared_ptr<Player> Player::player = nullptr;

Player::Player() : stat{ 100, 100, 1, 200, 0, 20, 3, "" }
{
	cout << "플레이어 생성" << endl;
}

Player::~Player()
{
	cout << "플레이어 삭제" << endl;
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
	double damage = stat.damage - monster.GetDefense();
	monster.GetAttack(damage);
}

bool Player::IsDie(double hp)
{
	if (stat.currentHP < 0) {
		return true;
	}
	else return false;
}

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