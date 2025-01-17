#pragma once
#include "Scene.h"
#include "define.h"

class ShopScene :
    public Scene
{
private:
	int CursorPos; // 커서 위치
	SHOP_TYPE Cur_ShopType;

public:
	virtual void makeLayout() override;
	virtual void begin() override; // 상점 진입 시 동작
	virtual void tick() override;

	void handleExit();     // 상점 나가기

	void UpdateSelectLayout();
	void UpdatePurchaseLayout();
	void UpdateSellLayout();

	void UpdateStatLayout();

public:
	void PlayGetCoinSound();

public:
	ShopScene();
	virtual ~ShopScene() override;
};

