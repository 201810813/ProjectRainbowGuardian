//Scene1F.cpp
#include "pch.h"
#include "Scene1F.h"
#include "ConsoleLayout.h"

void Scene1F::makeLayout() {
    // Title Layout (1층 제목 설정)
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "붉은 분노의 층", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::RED));

    string output = "";
    if (GetFloorNumber() < 10)
    {
        output += "0";
    }
    output += to_string(GetFloorNumber());
    output += " [⚔️]";
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, output, true, 0, TEXT_COLOR_TYPE::RED));


    // Story Layout
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🔥 이곳은 붉은 분노의 층입니다.", true, 1, TEXT_COLOR_TYPE::RED));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🐺 화가 잔뜩 난 늑대가 당신에게 욕을 날립니다.", true, 2, TEXT_COLOR_TYPE::WHITE));
}


void Scene1F::begin() {
	MainScene::begin();
    makeLayout();
}

void Scene1F::tick() {
    // 사용자 입력 처리
	MainScene::tick();
}


Scene1F::Scene1F() {
    MainScene::ThisSceneType = SCENE_TYPE::SCENE_1F;
}

Scene1F::~Scene1F() {
}
