#include "pch.h"
#include "FinalScene.h"
#include "ConsoleLayout.h"

void FinalScene::makeLayout() {
    // Title Layout (8층 제목 설정)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "옥탑: 레인보우 드래곤의 층", false, 0, TEXT_COLOR_TYPE::GREEN, BACKGROUND_COLOR_TYPE::SKY_INENSITY));

    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 7, 25);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "컬러", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::BLACK));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "❇️ 레벨     : 10", false, 1, TEXT_COLOR_TYPE::SKY, BACKGROUND_COLOR_TYPE::BLACK));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "⚡ EXP      : 99 / 100", false, 2, TEXT_COLOR_TYPE::SKY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🩸 HP       : 1000 / 1000", false, 3, TEXT_COLOR_TYPE::GREEN));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🗡️ ATK      : 500", false, 4, TEXT_COLOR_TYPE::RED));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🛡️ DEF      : 30%", false, 5, TEXT_COLOR_TYPE::BLUE_INENSITY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🍀 LUK      : 50%", false, 6, TEXT_COLOR_TYPE::ORANGE));

    // Map Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 9);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "08 [🐉]", false, 1, TEXT_COLOR_TYPE::GREEN));

    // Story Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 11, 8, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🌈 레인보우 드래곤이 나타났습니다!", false, 0, TEXT_COLOR_TYPE::SKY_INENSITY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "⚔️ 드래곤을 쓰러트리고, 흑백 저주를 풀어야 합니다.", false, 1, TEXT_COLOR_TYPE::SKY_INENSITY));

    // Select Layout (선택지)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 21, 5, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "1. 공격", false, 0, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "2. 방어", false, 1, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "3. 스킬 사용", false, 2, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "4. 아이템 사용", false, 3, TEXT_COLOR_TYPE::WHITE));

    // Input Layout (사용자 입력)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::INPUT, 0, 28, 1, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::INPUT, "선택: ", true, 0, TEXT_COLOR_TYPE::WHITE));
}

void FinalScene::begin() {
    makeLayout();
}

void FinalScene::tick() {
    // 사용자 입력 처리
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "레인보우 드래곤을 공격했습니다!\n";
        break;
    case 2:
        cout << "드래곤의 공격을 방어했습니다!\n";
        break;
    case 3:
        cout << "강력한 스킬을 사용했습니다!\n";
        break;
    case 4:
        cout << "아이템을 사용했습니다.\n";
        break;
    default:
        cout << "잘못된 선택입니다. 다시 시도해주세요.\n";
        break;
    }
}

FinalScene::FinalScene() {
}

FinalScene::~FinalScene() {
}
