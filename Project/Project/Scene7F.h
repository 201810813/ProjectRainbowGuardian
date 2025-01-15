#pragma once
#include "MainScene.h"

class Scene7F :
    public MainScene
{
public:
	virtual void makeLayout() override;
	virtual void begin() override;
	virtual void tick() override;

public:
	Scene7F();
	virtual ~Scene7F() override;
};

