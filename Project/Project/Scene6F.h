#pragma once
#include "MainScene.h"

class Scene6F : public MainScene{
public:
	virtual void makeLayout() override;
	virtual void begin() override;
	virtual void tick() override;

	virtual void setupBattleRoom();
	virtual void setupAltarRoom();
	virtual void setupShopRoom();

	Scene6F();
	virtual ~Scene6F() override;
};

