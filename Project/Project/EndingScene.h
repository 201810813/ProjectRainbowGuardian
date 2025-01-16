#pragma once
#include "Scene.h"

class EndingScene :
    public Scene
{
private:
	float AccTime;

public:
	virtual void makeLayout() override;
	virtual void begin() override;
	virtual void tick() override;

public:
    EndingScene();
    ~EndingScene();
};

