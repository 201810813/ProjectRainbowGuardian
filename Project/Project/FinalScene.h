#pragma once
#include "MainScene.h"
class FinalScene :
    public MainScene
{
public:
	virtual void makeLayout() override;
	virtual void begin() override;
	virtual void tick() override;

public:
	FinalScene();
	virtual ~FinalScene() override;
};

