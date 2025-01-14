#pragma once
#include "MainScene.h"

class Scene3F : public MainScene{
    public:
        virtual void makeLayout() override;
        virtual void begin() override;
        virtual void tick() override;

        void setupBattleRoom();
        void setupAltarRoom();
        void setupShopRoom();

    public:
        Scene3F();
        virtual ~Scene3F() override;
};

