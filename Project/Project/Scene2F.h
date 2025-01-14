#pragma once
#include "MainScene.h"

class Scene2F : public MainScene{
public:
	virtual void makeLayout() override;
	void setupBattleRoom();
	void setupAltarRoom();
	void setupShopRoom();

	virtual void begin() override;
	virtual void tick() override;

public:
	Scene2F();
	virtual ~Scene2F() override;
};

