#include "pch.h"
#include "Scene7F.h"
#include "ConsoleLayout.h"

void Scene7F::makeLayout() {
    // Title Layout (7층 제목 설정)
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "7층: 보라색 환영의 층", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::PURPLE));

    string output = "";
    if (GetFloorNumber() < 10)
    {
        output += "0";
    }
    output += to_string(GetFloorNumber());
    output += " [⚔️]";
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, output, true, 0, TEXT_COLOR_TYPE::PURPLE));

    // Story Layout
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🔮 이곳은 보라색 환영의 층입니다.", true, 1, TEXT_COLOR_TYPE::PURPLE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🪞 당신과 똑닮은 환영이 나타났습니다.", true, 2, TEXT_COLOR_TYPE::WHITE));
}

void Scene7F::begin() {
    MainScene::begin();
    makeLayout();
}

void Scene7F::tick() {
    MainScene::tick();
}

Scene7F::Scene7F() 
{
    MainScene::ThisSceneType = SCENE_TYPE::SCENE_7F;
}

Scene7F::~Scene7F() {
}
