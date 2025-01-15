//altarscene.h
#pragma once
#include "Scene.h"

class AltarScene :
    public Scene
{
private:
	int CursorPos; // 커서 위치

public:
	virtual void makeLayout() override;
	virtual void begin() override;
	virtual void tick() override;

	void handleOffer(); // 골드 제물
	void handleExit();     // 나가기

public:
	AltarScene();
	virtual ~AltarScene() override;
};

