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
    int idx = 8 - (GetFloorNumber() % 9);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, output, false, idx, TEXT_COLOR_TYPE::RED));


    // Story Layout
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🔴 이곳은 붉은 분노의 층입니다.", false, 7, TEXT_COLOR_TYPE::RED));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🔥 불도깨비가 당신에게 불똥을 날립니다.", false, 8, TEXT_COLOR_TYPE::WHITE));

    // BACKGROUND
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⢲⣲⣲⣲⡲⡲⡢        ⠀⢨⢳⢰⡄⡝⡆⠀          ⠀⢠⠋⠉⡹⡱⡄       ⠀ ⢨⢳⢰⡄⡝⡆⠀             ⢲⣲⣲⣲⡲⡲⡢", false, 0));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⢀⢗⢵⡱⣝⠥⠀        ⠀⢘⡎⢪⠇⣳⠁           ⠀⡯⣒⡆⢜⣒⢵         ⢘⡎⢪⠇⣳⠁              ⢀⢗⢵⡱⣝⠥ ", false, 1));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⢀⢯⡺⣜⢎⡇⠀        ⠀⠀⣇⣸⣁⣸⠀⠀          ⠀⢳⢤⣐⡢⣰⠜⠀        ⠀⣇⣸⣁⣸               ⢀⢯⡺⣜⢎⡇ ", false, 2));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⠐⣝⢞⡎⣗⡕⠀⠀  ⠰⠙⡆⠀⠀   ⢸⠀             ⠀⠘⢜⣐⣊⡱⠁⠀          ⢸⠀                ⠐⣝⢞⡎⣗⡕", false, 3));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⢈⢾⢵⢝⢮⡪⠀⠀  ⠀⣷⠀             ⠄⠄⠄⠄⢄⢐⠀                                    ⢈⢾⢵⢝⢮⡪", false, 4));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⠠⡫⡮⡳⡳⡱⠀   ⠀⣿⠀           ⠠⢑⣟⡽⡽⡽⣝⡷⡐⠀                                   ⠠⡫⡮⡳⡳⡱", false, 5));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⢀⢯⡪⣎⢯⠪  ⠀⠂⠙⡙⠑⠈⡀        ⠨⢸⢮⢯⢯⡻⡮⠋⢄⢦⡡⢀⠀                                 ⢀⢯⡪⣎⢯⠪", false, 6));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⠠⣳⡣⣗⢵⡋⠀⠀   ⣿⠀⠀⠀        ⠨⢸⢯⢯⡳⣯⣻⢃⣰⢼⠍⠐                                  ⠠⣳⡣⣗⢵⡋", false, 7));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⣠⣛⢕⡫⡫⡣⡄    ⣿⠀⠀⠀         ⠌⡯⣗⡯⡷⣕⣗⠯⠃⠌⠀⠀                                 ⣠⣛⢕⡫⡫⡣⡄", false, 8));
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
    MainScene::monster = new FairyFire();
}

Scene1F::~Scene1F() {
}
