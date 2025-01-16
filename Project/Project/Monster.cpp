#include "pch.h"
#include "Monster.h"

Monster::Monster()
{
	animator = new Animator();
}

Monster::~Monster()
{
	delete animator;
}

void Monster::Tick()
{
	animator->tick();
}
