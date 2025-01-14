﻿#include "pch.h"
#include "Scene7F.h"
#include "ConsoleLayout.h"

void Scene7F::makeLayout() {
    // Title Layout (7층 제목 설정)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "7층: 보라색 환영의 층", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::PURPLE));

    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 7, 25);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "컬러", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::BLACK));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "❇️ 레벨     : 1", false, 1, TEXT_COLOR_TYPE::SKY, BACKGROUND_COLOR_TYPE::BLACK));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "⚡ EXP      : 0 / 100", false, 2, TEXT_COLOR_TYPE::SKY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🩸 HP       : 100 / 100", false, 3, TEXT_COLOR_TYPE::GREEN));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🗡️ ATK      : 10", false, 4, TEXT_COLOR_TYPE::RED));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🛡️ DEF      : 5%", false, 5, TEXT_COLOR_TYPE::BLUE_INENSITY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🍀 LUK      : 10%", false, 6, TEXT_COLOR_TYPE::ORANGE));

    // Map Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 9);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "07 [⚔️]", false, 2, TEXT_COLOR_TYPE::PURPLE));

    // Story Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 11, 8, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🔮 이곳은 보라색 환영의 층입니다.", false, 0, TEXT_COLOR_TYPE::PURPLE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🪞 당신과 똑닮은 환영이 나타났습니다.", false, 1, TEXT_COLOR_TYPE::WHITE));

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

void Scene7F::begin() {
    makeLayout();
}

void Scene7F::tick() {
    // 사용자 입력 처리
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "공격했습니다!\n";
        break;
    case 2:
        cout << "방어 자세를 취했습니다.\n";
        break;
    case 3:
        cout << "강력한 스킬을 사용했습니다!!\n";
        break;
    case 4:
        cout << "아이템을 사용했습니다.\n";
        break;
    default:
        cout << "잘못된 선택입니다. 다시 시도해주세요.\n";
        break;
    }
}

Scene7F::Scene7F() {
}

Scene7F::~Scene7F() {
}