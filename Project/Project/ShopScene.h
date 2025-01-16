//ShopScene.h
#pragma once
#include "Scene.h"
class ShopScene :
    public Scene
{
private:
	int CursorPos; // Ŀ�� ��ġ

public:
	virtual void makeLayout() override;
	virtual void begin() override; // ���� ���� �� ����
	virtual void tick() override;

	// ���� �� �Ǹ� ó��
	void handlePurchase(); // ������ ����
	void handleSell();     // ������ �Ǹ�
	void handleExit();     // ���� ������

	void UpdateSelectLayout();

public:
	ShopScene();
	virtual ~ShopScene() override;
};

