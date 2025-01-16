#pragma once
#include "MainScene.h"
#include "IceHedgehog.h"
class Scene5F : public MainScene{
private:
	Monster* hedgehog;
public:
	virtual void makeLayout() override;
	virtual void begin() override;
	virtual void tick() override;

public:
	Scene5F();
	virtual ~Scene5F() override;
};

