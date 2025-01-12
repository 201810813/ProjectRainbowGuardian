#pragma once
#include "pch.h"
#include "Monster.h"
enum itemType {
	POSTION,
	EQUIPMENT
};

// Item 추상함수 
class Item {
private:
	itemType type;
	string itemName;
	double itemEffect;
public:
	Item();
	virtual ~Item();
public:
	virtual const string getItemName() = 0;
	virtual const void UseItem(Monster& monster) = 0;
	virtual const itemType getType() = 0;
};


class HealthPostion : public Item {
private:
	itemType type;
	string itemName;
	double itemEffect;
public:
	HealthPostion();
	~HealthPostion();
	const void UseItem(Monster& monster);
	const string getItemName();
	const itemType getType();
};
