#pragma once
#include "MainScene.h"
#include "Boss.h"
#include "SceneManager.h"
class FinalScene :
    public MainScene
{
private:
	Monster* dragon;
	bool finalBossDefeated;
public:
	virtual void makeLayout() override;
	virtual void begin() override;
	virtual void tick() override;

public:
	FinalScene();
	virtual ~FinalScene() override;
};

