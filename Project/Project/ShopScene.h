#pragma once
#include "MainScene.h"
class ShopScene :
    public MainScene
{
public:
	virtual void makeLayout() override;
	virtual void begin() override; // 상점 진입 시 동작
	virtual void tick() override;

public:
	ShopScene();
	virtual ~ShopScene() override;
};

