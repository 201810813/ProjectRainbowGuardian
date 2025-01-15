#pragma once
#include "Scene.h"
#include "Monster.h"
class MRedWolf;

class MainScene :
    public Scene
{
private:
    BATTLE_TYPE Cur_BattleType;
    int Turn_Count;
    bool bOnce;
    int CursorPos;
    
protected:
    Monster* monster;

public:
    virtual void makeLayout() override;

public:
    virtual void begin();
    virtual void tick();

public:
    MainScene();
    virtual ~MainScene() override;
};

