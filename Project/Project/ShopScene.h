//ShopScene.h
#pragma once
#include "Scene.h"
class ShopScene :
    public Scene
{
private:
	int CursorPos; // 커서 위치

public:
	virtual void makeLayout() override;
	virtual void begin() override; // 상점 진입 시 동작
	virtual void tick() override;

	// 구매 및 판매 처리
	void handlePurchase(); // 아이템 구매
	void handleSell();     // 아이템 판매
	void handleExit();     // 상점 나가기

	void UpdateSelectLayout();

public:
	ShopScene();
	virtual ~ShopScene() override;
};

