//altarscene.h
#pragma once
#include "Scene.h"

class AltarScene :
    public Scene
{
private:
	int CursorPos; // Ŀ�� ��ġ

public:
	virtual void makeLayout() override;
	virtual void begin() override;
	virtual void tick() override;

	void handleOffer(); // ��� ����
	void handleExit();     // ������

public:
	AltarScene();
	virtual ~AltarScene() override;
};

