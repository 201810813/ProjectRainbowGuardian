#include "pch.h"
#include "FinalScene.h"
#include "ConsoleLayout.h"

void FinalScene::makeLayout() {
    // Title Layout (8층 제목 설정)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "옥탑: 레인보우 드래곤의 층", false, 0, TEXT_COLOR_TYPE::GREEN, BACKGROUND_COLOR_TYPE::SKY_INENSITY));

    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 9, 25);

    // Map Layout
    //WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 8);
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "08 [🐉]", false, 1, TEXT_COLOR_TYPE::GREEN));

    // Story Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 13, 9, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🌈 레인보우 드래곤이 나타났습니다!", false, 1, TEXT_COLOR_TYPE::SKY_INENSITY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "⚔️ 드래곤을 쓰러트리고, 흑백 저주를 풀어야 합니다.", false, 2, TEXT_COLOR_TYPE::SKY_INENSITY));

    // Select Layout (선택지)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 24, 5, 60);
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "1. 공격", false, 0, TEXT_COLOR_TYPE::WHITE));
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "2. 방어", false, 1, TEXT_COLOR_TYPE::WHITE));
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "3. 스킬", false, 2, TEXT_COLOR_TYPE::WHITE));
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "4. 아이템 사용", false, 3, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::DRAW, 61, 13, 16, 51);

    // Input Layout (사용자 입력)
    //WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::INPUT, 0, 28, 1, 60);
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::INPUT, "선택: ", true, 0, TEXT_COLOR_TYPE::WHITE));
}

void FinalScene::begin() {
    makeLayout();
}

void FinalScene::tick() {
    // 사용자 입력 처리
    MainScene::tick();
}

FinalScene::FinalScene() {
}

FinalScene::~FinalScene() {
}
