#pragma once
#include "pch.h"
#include "Monster.h"
#include <map>
#include "Item.h"
#include "define.h"
#include "ConsoleLayout.h"
//�̱��� �÷��̾�
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
		int		gold;
		int		itemCount;
		string	name;
	};
private:
	map<Type, int> itemCounts; //enum�� ���� ��������
	map<Type, vector<Item*>> inventory; //Drop()���� ���� ��ü ������ ����.
	PlayerStat stat;
	int PowerUpChance;
	bool bDead;
private:
	Player(const Player&) = delete; //���������,
	Player& operator=(const Player&) = delete;  //���Կ����� ����.
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
	void gainExp(int exp); //�߰�
	void levelUp(); //�߰�
	bool IsDie();
	void AddItemToInventory(Item* item);
	void ShowInventory();
	void UseItem(Type type);
	void IncreaseChance();

public:
	const double  GetCurrentHP();
	const int	  GetDefense();
	const double  GetMaxHP();
	const int	  GetEvasion();
	const int	  GetLevel();
	const double  GetDamage();
	const int     GetItemCount();

public:
	void SetCurrentHP(double heal);
	void SetDamage(int buff);
};