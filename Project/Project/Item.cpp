#include "pch.h"
#include "Item.h"
#include "Player.h"
Item::Item() : type(Type::HEALTH_POTION), name("아이템"), Effect(0) {}

Item::~Item()
{
}
