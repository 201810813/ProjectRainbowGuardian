#pragma once
#include "MainScene.h"

class Scene0F : public MainScene{
private:
	int CursorPos; // Ŀ��

public:
    virtual void makeLayout() override;
    virtual void begin() override;
    virtual void tick() override;

	void GoTo1F(); // 1������ �̵�
    void Exit();    // ���� ����

public:
    Scene0F();
    virtual ~Scene0F() override;
};
