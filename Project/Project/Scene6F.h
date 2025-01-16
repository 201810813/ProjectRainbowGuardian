#pragma once
#include "MainScene.h"
#include "MistWitch.h"
class Scene6F : public MainScene{
private:
	Monster* witch;
public:
	virtual void makeLayout() override;
	virtual void begin() override;
	virtual void tick() override;

	Scene6F();
	virtual ~Scene6F() override;
};

