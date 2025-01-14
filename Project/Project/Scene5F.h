#pragma once
#include "MainScene.h"

class Scene5F : public MainScene{
public:
	virtual void makeLayout() override;
	virtual void begin() override;
	virtual void tick() override;

	virtual void setupBattleRoom();
	virtual void setupAltarRoom();
	virtual void setupShopRoom();

public:
	Scene5F();
	virtual ~Scene5F() override;
};

