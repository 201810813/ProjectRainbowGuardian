#pragma once
#include "MainScene.h"

class Scene4F : public MainScene {
public:
    virtual void makeLayout() override;
    virtual void begin() override;
    virtual void tick() override;

public:
    Scene4F();
    virtual ~Scene4F() override;
};

