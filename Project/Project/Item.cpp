#include "pch.h"
#include "Item.h"

Item::Item()
{
}

Item::~Item()
{
}




//ü������
HealthPostion::HealthPostion() : type(POSTION), itemName("ü������"), itemEffect(20)
{
}

HealthPostion::~HealthPostion()
{
}
//Monster�� �׽�Ʈ. ���� Player�� ����� �����ϵ��� �ϰڽ��ϴ�.
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
