#pragma once
#include "Scene.h"

class IntroScene :
    public Scene
{
private:
    float   AccTime;
    int     MoveIndex;
    bool    bMovereverse;
    int     CursorPos;

public:
    virtual void makeLayout() override;

private:
    void ActionSelect();
    void MoveSymbol();
    void MakeIntro();
    void MakeSelect();
    void MoveCursor();

public:
    virtual void begin();
    virtual void tick();

public:
    IntroScene();
    virtual ~IntroScene() override;
};

