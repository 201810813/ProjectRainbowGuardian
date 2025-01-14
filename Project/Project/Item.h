#pragma once
#include "pch.h"
enum Type {
	HEALTH_POSTION		= 0,
	RED_CRISTAL			= 1,
	ORANGE_CRISTAL		= 2,
	YELLO_CRISTAL		= 3
};

class Item {
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
};