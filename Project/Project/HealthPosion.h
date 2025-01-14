#pragma once
#include "Item.h"
class HealthPosion :Item {
private:
	Type type;
	string name;
	int effect;
public:
	HealthPosion();
	~HealthPosion() override;
public:
	int GetEffect() override;
	string GetName() override;
};