#pragma once
#include "MainScene.h"
#include "EletricMantis.h"

class Scene3F : public MainScene{
private:
    Monster* mantis;
public:
    virtual void makeLayout() override;
    virtual void begin() override;
    virtual void tick() override;

public:
    Scene3F();
    virtual ~Scene3F() override;
};

