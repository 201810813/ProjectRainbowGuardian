#pragma once
#include "MainScene.h"
class ShopScene :
    public MainScene
{
public:
	virtual void makeLayout() override;
	virtual void begin() override; // ���� ���� �� ����
	virtual void tick() override;

public:
	ShopScene();
	virtual ~ShopScene() override;
};

