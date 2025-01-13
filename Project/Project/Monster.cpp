#include "pch.h"
#include "Monster.h"

Monster::Monster() : coin(0) {
	monsterStat = {};
}

Monster::~Monster()
{
}
//플레이어 대신 몬스터로 Item테스트.
void Monster::Heal(double heal)
{
	monsterStat.currentHp += heal;
}