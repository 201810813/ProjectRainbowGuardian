
#pragma once
#include "pch.h"
#include "Monster.h"
#include <map>
#include "Item.h"
//싱글톤 플레이어
class Monster;

class Player {
public:
	struct PlayerStat {
		double maxHP;
		double currentHP;
		int level;
		int maxExp;
		int currentexp;
		double damage;
		int defense;
		int evasion;
		string name;
	};
private:
	int invenSize;
	map<Type, int> inventory;
	PlayerStat stat;
	

private:
	Player(const Player&) = delete; //복사생성자,
	Player& operator=(const Player&) = delete;  //대입연산자 제거.
	static shared_ptr<Player> player;

public:
	Player();
	~Player();
	static shared_ptr<Player> getInstance();
	void SetName(const string name);
	string& getName();
	void GetAttack(double& damage);
	void Attack(Monster& monster);
	bool IsDie(double hp);

public:
	double GetCurrentHP();
	int	GetDefense();
	double GetMaxHP();
	int GetEvasion();	
};