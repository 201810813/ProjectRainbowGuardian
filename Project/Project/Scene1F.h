// Scene1F.h
#pragma once
#include "MainScene.h"
#include "FairyFire.h"

class Scene1F : public MainScene{
public:
    virtual void makeLayout() override;
    virtual void begin() override;
    virtual void tick() override;

public:
    Scene1F();
    virtual ~Scene1F() override;
};
