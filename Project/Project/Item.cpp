#include "pch.h"
#include "Item.h"

Item::Item()
{
}

Item::~Item()
{
}




//체력포션
HealthPostion::HealthPostion() : type(POSTION), itemName("체력포션"), itemEffect(20)
{
}

HealthPostion::~HealthPostion()
{
}
//Monster로 테스트. 이후 Player가 생기면 수정하도록 하겠습니다.
const void HealthPostion::UseItem(Monster& monster)
{
	monster.Heal(itemEffect);
}

const string HealthPostion::getItemName()
{
	return string();
}

const itemType HealthPostion::getType() 
{
	return type;
}
