#pragma once
#include "MainScene.h"
#include "SceneManager.h"

class FinalScene :
    public MainScene
{
private:
	bool finalBossDefeated;

public:
	virtual void makeLayout() override;
	virtual void begin() override;
	virtual void tick() override;

public:
	FinalScene();
	virtual ~FinalScene() override;
};

