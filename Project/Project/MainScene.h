//MainScene.h
#pragma once
#include "Scene.h"

class MainScene :
    public Scene
{

public:
    virtual void makeLayout() override;

public:
    virtual void begin();
    virtual void tick();

public:
    MainScene();
    virtual ~MainScene() override;
};

