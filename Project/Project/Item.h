#pragma once
#include "pch.h"
#include "define.h"
class Player;

enum Type {
	HEALTH_POTION,
	POWER_POTION,
	RED_CRISTAL,
	ORANGE_CRISTAL,
	YELLO_CRISTAL,
};

class Item {
public:
	
private:
	Type type;
	string name;
	int Effect;
public:
	Item();
	virtual ~Item();
public:
	virtual int GetEffect() = 0;
	virtual string GetName() = 0;
	virtual void Use() = 0;
	virtual Type GetType() = 0;
};
