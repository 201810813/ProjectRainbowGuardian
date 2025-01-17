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
    int idx = 8 - (GetFloorNumber() % 9);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, output, false, idx, TEXT_COLOR_TYPE::PURPLE));

    // Story Layout
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🔮 이곳은 보라색 환영의 층입니다.", false, 7, TEXT_COLOR_TYPE::PURPLE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🪞 르탄이와 똑닮은 환영이 나타났습니다.", false, 8, TEXT_COLOR_TYPE::WHITE));

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
    MainScene::monster = new Rtan();
}

Scene7F::~Scene7F() {
}
