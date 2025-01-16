#include "pch.h"
#include "Scene6F.h"
#include "ConsoleLayout.h"

void Scene6F::makeLayout() {
    // Title Layout (6층 제목 설정)
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "남색 슬픔의 층", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::BLUE_INENSITY));

    string output = "";
    if (GetFloorNumber() < 10)
    {
        output += "0";
    }
    output += to_string(GetFloorNumber());
    output += " [⚔️]";
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, output, true, 0, TEXT_COLOR_TYPE::BLUE_INENSITY));

    // Story Layout
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "😭 이곳은 남색 슬픔의 층입니다.", true, 1, TEXT_COLOR_TYPE::BLUE_INENSITY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "👻 눈물 망령의 대성통곡이 귀를 찌릅니다.", true, 2, TEXT_COLOR_TYPE::WHITE));
}

void Scene6F::begin() {
    MainScene::begin();
    makeLayout();
}

void Scene6F::tick() {
    MainScene::tick();
}

Scene6F::Scene6F()
{
    MainScene::ThisSceneType = SCENE_TYPE::SCENE_6F;
}

Scene6F::~Scene6F() {
}
