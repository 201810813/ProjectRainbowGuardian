#pragma once
#include "Scene.h"
#include "define.h"

class ShopScene :
    public Scene
{
private:
	int CursorPos; // Ŀ�� ��ġ
	SHOP_TYPE Cur_ShopType;

public:
	virtual void makeLayout() override;
	virtual void begin() override; // ���� ���� �� ����
	virtual void tick() override;

	void handleExit();     // ���� ������

	void UpdateSelectLayout();
	void UpdatePurchaseLayout();
	void UpdateSellLayout();

public:
	ShopScene();
	virtual ~ShopScene() override;
};

