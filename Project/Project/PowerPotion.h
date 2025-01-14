#pragma once
#include "Item.h"
class PowerPotion : public Item {
private:
	Type type;
	string name;
	int effect;
public:
	PowerPotion();
	~PowerPotion() override;
public:
	int GetEffect() override;
	string GetName() override;
	void Use() override;
	Type GetType() override;
};