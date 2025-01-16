#include "pch.h"
#include "Scene3F.h"
#include "ConsoleLayout.h"

void Scene3F::makeLayout() {
    // Title Layout (3층 제목 설정)
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "노란 환희의 층", false, 0, TEXT_COLOR_TYPE::ORANGE, BACKGROUND_COLOR_TYPE::ORANGE_INENSITY));

    string output = "";
    if (GetFloorNumber() < 10)
    {
        output += "0";
    }
    output += to_string(GetFloorNumber());
    output += " [⚔️]";
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, output, true, 0, TEXT_COLOR_TYPE::ORANGE_INENSITY));

    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "⚡ 이곳은 노란 환희의 층입니다.", false, 7, TEXT_COLOR_TYPE::ORANGE_INENSITY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🦗 전기사마귀가 '찌릿'거리고  있습니다.", false, 8, TEXT_COLOR_TYPE::WHITE));
}

void Scene3F::begin() {
	MainScene::begin();
    makeLayout();
    mantis = new EletricMantis();
}

void Scene3F::tick() {
    MainScene::tick();
}

Scene3F::Scene3F()
{
    MainScene::ThisSceneType = SCENE_TYPE::SCENE_3F;
}

Scene3F::~Scene3F() {
    delete mantis;
}
