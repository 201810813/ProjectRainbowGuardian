#pragma once
#include "MainScene.h"
#include "SceneManager.h"

#include "Boss.h"
class FinalScene :
    public MainScene
{
private:
	bool finalBossDefeated;

	Monster* dragon;
public:
	virtual void makeLayout() override;
	virtual void begin() override;
	virtual void tick() override;

public:
	FinalScene();
	virtual ~FinalScene() override;
};

