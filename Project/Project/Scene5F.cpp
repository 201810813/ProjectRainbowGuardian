#include "pch.h"
#include "Scene5F.h"
#include "ConsoleLayout.h"

void Scene5F::makeLayout() {
    // Title Layout (5층 제목 설정)
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "파란 고독의 층", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::BLUE));

    string output = "";
    if (GetFloorNumber() < 10)
    {
        output += "0";
    }
    output += to_string(GetFloorNumber());
    output += " [⚔️]";
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, output, true, 0, TEXT_COLOR_TYPE::BLUE));

    // Story Layout
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "❄️ 이곳은 파란 고독의 층입니다.", true, 1, TEXT_COLOR_TYPE::BLUE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🧊 아이스 골렘의 한기가 느껴집니다.", true, 2, TEXT_COLOR_TYPE::WHITE));
}

void Scene5F::begin() {
	MainScene::begin();
    makeLayout();
}

void Scene5F::tick() {
    MainScene::tick();
}

Scene5F::Scene5F()
{
    MainScene::ThisSceneType = SCENE_TYPE::SCENE_5F;
}

Scene5F::~Scene5F() {
}