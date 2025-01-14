#pragma once
#include "MainScene.h"

class Scene4F : public MainScene {
public:
    virtual void makeLayout() override;
    virtual void begin() override;
    virtual void tick() override;
    void setupBattleRoom();
    void setupAltarRoom();
    void setupShopRoom();

public:
    Scene4F();
    virtual ~Scene4F() override;
};

