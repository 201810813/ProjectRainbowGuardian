#pragma once
#include "MainScene.h"

class Scene0F : public MainScene{
private:
	int CursorPos; // 커서

public:
    virtual void makeLayout() override;
    virtual void begin() override;
    virtual void tick() override;

	void GoTo1F(); // 1층으로 이동
    void Exit();    // 게임 종료

	void UpdateSelectLayout(); // 선택지 업데이트

public:
    Scene0F();
    virtual ~Scene0F() override;
};
