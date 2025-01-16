#include "pch.h"
#include "Scene2F.h"
#include "ConsoleLayout.h"

void Scene2F::makeLayout() {
    // Title Layout (2층 제목 설정)
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "주황 욕망의 층", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::ORANGE));

    // Map Layout
    string output = "";
    if (GetFloorNumber() < 10)
    {
        output += "0";
    }
    output += to_string(GetFloorNumber());
    output += " [⚔️]";
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, output, true, 0, TEXT_COLOR_TYPE::ORANGE));

    // Story Layout
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🟠 이곳은 주황 욕망의 층입니다.", true, 1, TEXT_COLOR_TYPE::ORANGE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🦎 황금 도마뱀이 당신의 장비를 탐내고 있습니다.", true, 2, TEXT_COLOR_TYPE::WHITE));
}

void Scene2F::begin() {
	MainScene::begin();
    makeLayout();
}

void Scene2F::tick() {
    MainScene::tick();
}

Scene2F::Scene2F()
{
    MainScene::ThisSceneType = SCENE_TYPE::SCENE_2F;
}

Scene2F::~Scene2F() {}
