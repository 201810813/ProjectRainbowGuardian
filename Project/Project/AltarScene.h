//altarscene.h
#pragma once
#include "MainScene.h"

class AltarScene :
    public MainScene
{
public:
	virtual void makeLayout() override;
	virtual void begin() override;
	virtual void tick() override;
public:
	AltarScene();
	virtual ~AltarScene() override;
};

