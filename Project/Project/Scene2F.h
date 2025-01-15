#pragma once
#include "MainScene.h"
#include "IronGolem.h"

class Scene2F : public MainScene{
private:
	Monster* golem;
public:
	virtual void makeLayout() override;
	virtual void begin() override;
	virtual void tick() override;

public:
	Scene2F();
	virtual ~Scene2F() override;
};

