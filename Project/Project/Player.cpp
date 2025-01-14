#include "pch.h"
#include "Player.h"

shared_ptr<Player> Player::player = nullptr;

Player::Player() : stat{ 100, 100, 1, 200, 0, 17, 3, 20, "" }, invenSize(10)
{
	cout << "�÷��̾� ����" << endl;
}

Player::~Player()
{
	cout << "�÷��̾� ����" << endl;
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
	cout << "����� �����մϴ�" << endl;
	double damage = stat.damage - monster.GetDefense();
	int probability = monster.GetEvasion();
	int trigger = rand() % 100;
	if (probability < trigger) {
		
		monster.GetAttack(damage);
		cout << "���� ����!\n" << "���� �Ƿ�: " << monster.GetCurrentHP() << endl;
	}
	else { cout << "���� ������ ȸ���߽��ϴ�."; }
	
}

bool Player::IsDie(double hp)
{
	if (stat.currentHP < 0) {
		return true;
	}
	else return false;
}

//----------------------------//
//          Get�Լ�           //
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
//          �������Լ�           //
//-------------------------------//
