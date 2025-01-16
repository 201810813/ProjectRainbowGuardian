#pragma once
#include "Scene.h"
#include "Monster.h"
class FairyFire;

class MainScene :
    public Scene
{
private:
    BATTLE_TYPE Cur_BattleType;
    int Turn_Count;
    bool bOnce;
    int CursorPos;

protected:
    SCENE_TYPE ThisSceneType;
    
protected:
    Monster* monster;

public:
    virtual void makeLayout() override;
    void UpdateStatLayout();
	void UpdateMonsterStatLayout();
	void UpdateProgressBarLayout();

public:
    virtual void begin();
    virtual void tick();

public:
    MainScene();
    virtual ~MainScene() override;
};

