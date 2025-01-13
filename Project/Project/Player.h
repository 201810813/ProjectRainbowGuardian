#pragma once
#include "pch.h"
#include "Monster.h"
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
		string name;
	};
private:
	PlayerStat stat;
	//복사생성자, 대입연산자 제거.

	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;
	static std::shared_ptr<Player> player;

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
};