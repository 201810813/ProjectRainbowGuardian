#include "pch.h"
#include "Monster.h"

Monster::Monster() : coin(0) {
	monsterStat = {};
}

Monster::~Monster()
{
}
//�÷��̾� ��� ���ͷ� Item�׽�Ʈ.
void Monster::Heal(double heal)
{
	monsterStat.currentHp += heal;
}