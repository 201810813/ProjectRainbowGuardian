#pragma once
#include "pch.h"
#include "Monster.h"
#include <map>
#include "Item.h"
#include "define.h"
#include "ConsoleLayout.h"
//�̱��� �÷��̾�
class Monster;
class HealthPotion;
class PowerPotion;

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
		int		coin;
		int		itemCount;
		string	name;
	};
private:
	map<Type, int> inventory; //enum�� ���� ��������
	PlayerStat stat;
	int PowerUpChance;
	bool bPowerUp;
	int AddDamage;
	bool bDead;
	HealthPotion* HealthPotion;
	PowerPotion* PowerPotion;
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
	void gainCoin(int coin);
	bool SpendGold(int Coin);
	void levelUp(); //�߰�
	bool IsDie();
	void AddItemToInventory(Type type);
	void ShowInventory();
	bool UseItem(Type type);
	void IncreaseChance();
	void SellItem(Type type);

public:
	const double  GetCurrentHP();
	const int	  GetDefense();
	const double  GetMaxHP();
	const int	  GetEvasion();
	const int	  GetLevel();
	const double  GetDamage();
	const int	  GetCoin();
	const int     GetItemCount();
	const int	  GetCurrentExp();
	const int     GetMaxExp();
	const int	  GetAddDamage();
	const int	  GetItemCount(Type type);
	bool Is_PowerUp();

public:
	void PlayerRecovery();
	void SetCurrentHP(double heal);
	void SetDamage(int buff);
	void SetCoin(int coin);

public:
	void PlayAttackSound();
};