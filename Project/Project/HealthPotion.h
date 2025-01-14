#pragma once
#include "Item.h"
class HealthPotion : public Item {
private:
	Type type;
	string name;
	int effect;
public:
	HealthPotion();
	~HealthPotion() override;
public:
	int GetEffect() override;
	string GetName() override;
	void Use() override;
	Type GetType() override;
};