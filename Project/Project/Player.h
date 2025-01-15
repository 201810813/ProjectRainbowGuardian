#pragma once
#include "pch.h"
#include "Monster.h"
#include <map>
#include "Item.h"
#include "define.h"
#include "ConsoleLayout.h"
//싱글톤 플레이어
class Monster;

class Player {
public:
	struct PlayerStat {
		double	maxHP;
		double	currentHP;
		int		level;
		int		maxExp;
		int		currentexp;
		double	damage;
		int		defense;
		int		evasion;
		string	name;
	};
private:
	map<Type, int> itemCounts; //enum에 따라 갯수증가
	map<Type, vector<Item*>> inventory; //Drop()에서 받은 객체 포인터 저장.
	PlayerStat stat;
	

private:
	Player(const Player&) = delete; //복사생성자,
	Player& operator=(const Player&) = delete;  //대입연산자 제거.
	static shared_ptr<Player> player;

public:
	Player();
	~Player();
	static shared_ptr<Player> getInstance();

public:
	void SetName(const string name);
	string& getName();
	void GetAttack(double& damage);
	void Attack(Monster& monster);
	void gainExp(int exp); //추가
	void levelUp(); //추가
	bool IsDie(double hp);
	void AddItemToInventory(Item* item);
	void ShowInventory();
	void UseItem(Type type);

public:
	const double  GetCurrentHP();
	const int	  GetDefense();
	const double  GetMaxHP();
	const int	  GetEvasion();
	const int	  GetLevel();
	const double  GetDamage();

public:
	void SetCurrentHP(double heal);
	void SetDamage(int buff);
};