﻿#include "pch.h"
#include "Scene0F.h"
#include "ConsoleLayout.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "Player.h"

void Scene0F::makeLayout()
{
    // Title Layout (0층 제목 설정)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "마을: 안전한 피난처", false, 0, TEXT_COLOR_TYPE::BLACK, BACKGROUND_COLOR_TYPE::WHITE));

    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 9, 25);

    // Map Layout
     WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 8);

    // Story Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 13, 9, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "당신은 마을에 왔습니다.", false, 8));

    // Select Layout (선택지)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 24, 5, 60);
    if (CursorPos == 0) {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [1. 탑으로!!!]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [2. 게임 종료]", false, 1, TEXT_COLOR_TYPE::WHITE));
    }
    else {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [1. 탑으로!!!]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [2. 게임 종료]", false, 1, TEXT_COLOR_TYPE::WHITE));
    }


    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::DRAW, 61, 13, 16, 51);
}

void Scene0F::begin()
{
	Player::getInstance()->GetMaxHP(); // 최대 체력
	CursorPos = 0;
    makeLayout();
}

void Scene0F::tick()
{
    if (IS_TAP(UP))
    {
        CursorPos = (CursorPos > 0) ? CursorPos - 1 : 1; // 위로 이동
        WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
        makeLayout();
    }
    else if (IS_TAP(DOWN))
    {
        CursorPos = (CursorPos < 1) ? CursorPos + 1 : 0; // 아래로 이동
        WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
        makeLayout();
    }

    if (IS_TAP(ENTER))
    {
        if (CursorPos == 0) // 다시 도전
        {
            GoTo1F();
        }
        else if (CursorPos == 1) // 게임 종료
        {
            Exit();
        }
    }
}

Scene0F::Scene0F() : CursorPos(0) {}

Scene0F::~Scene0F() {}

void Scene0F::GoTo1F()
{
    SceneManager::GetInstance()->CacheChangeScene(SCENE_TYPE::SCENE_1F); // 1층으로 이동
	
   
}

void Scene0F::Exit()
{
    exit(0); // 프로그램 종료
}