#pragma once
#include "Scene.h"

class IntroScene :
    public Scene
{

public:
    virtual void makeLayout() override;

public:
    virtual void begin();
    virtual void tick();

public:
    IntroScene();
    virtual ~IntroScene() override;
};

