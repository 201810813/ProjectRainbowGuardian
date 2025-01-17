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
    int idx = 8 - (GetFloorNumber() % 9);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, output, false, idx, TEXT_COLOR_TYPE::BLUE_INENSITY));

    // Story Layout
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "😭 이곳은 남색 슬픔의 층입니다.", false, 7, TEXT_COLOR_TYPE::BLUE_INENSITY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🧞‍♀️안개마녀의 대성통곡이 귀를 찌릅니다.", false, 8, TEXT_COLOR_TYPE::WHITE));

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
    MainScene::monster = new MistWitch();
}

Scene6F::~Scene6F() {
}
