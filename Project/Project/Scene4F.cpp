#include "pch.h"
#include "Scene4F.h"
#include "ConsoleLayout.h"

void Scene4F::makeLayout() {
    // Title Layout (4층 제목 설정)
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "녹색 생명의 층", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::GREEN));

    string output = "";
    if (GetFloorNumber() < 10)
    {
        output += "0";
    }
    output += to_string(GetFloorNumber());
    output += " [⚔️]";
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, output, true, 0, TEXT_COLOR_TYPE::GREEN));

    // Story Layout
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🌱 이곳은 녹색 생명의 층입니다.", true, 1, TEXT_COLOR_TYPE::GREEN));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "☠️ 독 덩굴 괴물이 나타났습니다.", true, 2, TEXT_COLOR_TYPE::WHITE));
}

void Scene4F::begin() {
	MainScene::begin();
    makeLayout();
}

void Scene4F::tick() {
    MainScene::tick();
}

Scene4F::Scene4F()
{
    MainScene::ThisSceneType = SCENE_TYPE::SCENE_4F;
}

Scene4F::~Scene4F() {
}
