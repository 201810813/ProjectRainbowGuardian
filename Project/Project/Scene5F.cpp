﻿#include "pch.h"
#include "Scene5F.h"
#include "ConsoleLayout.h"
#include "RandomManager.h"

void Scene5F::makeLayout() {
    // Title Layout (5층 제목 설정)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "파란 고독의 층", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::BLUE));

    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 8, 25);

    //랜덤 방 종류 결정
    RandomManager::GetInstance()->setRange(1.f, 100.f);
    double randomValue = RandomManager::GetInstance()->getRandom<double>(); // 1~100 사이의 랜덤 값

    if (randomValue <= 60) {
        setupBattleRoom(); // 전투 방 설정
    }
    else if (randomValue <= 80) {
        setupAltarRoom(); // 제단 방 설정
    }
    else {
        setupShopRoom(); // 상점 방 설정
    }
}

void Scene5F::setupBattleRoom() {
    // Map Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 9);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "05 [⚔️]", false, 4, TEXT_COLOR_TYPE::BLUE));

    // Story Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 12, 9, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "❄️ 이곳은 파란 고독의 층입니다.", false, 0, TEXT_COLOR_TYPE::BLUE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🧊 아이스 골렘의 한기가 느껴집니다.", false, 1, TEXT_COLOR_TYPE::WHITE));

    // Select Layout (선택지)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 23, 5, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "1. 공격", false, 0, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "2. 방어", false, 1, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "3. 스킬", false, 2, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "4. 아이템 사용", false, 3, TEXT_COLOR_TYPE::WHITE));
}

void Scene5F::setupAltarRoom() {
	// Map Layout
	WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 9);
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "05 [⛲]", false, 4, TEXT_COLOR_TYPE::BLUE));
	// Story Layout
	WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 12, 9, 60);
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🟦 신성한 기운이 느껴집니다.", false, 0, TEXT_COLOR_TYPE::BLUE));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🙏 제단에서 선택을 해야 합니다.", false, 1, TEXT_COLOR_TYPE::WHITE));
	// Select Layout (제단 선택지)
	WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 23, 5, 60);
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "1. 골드 봉헌", false, 0, TEXT_COLOR_TYPE::WHITE));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "2. 제단 떠나기", false, 1, TEXT_COLOR_TYPE::WHITE));
}

void Scene5F::setupShopRoom() {
    // Map Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 9);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "05 [🏪]", false, 4, TEXT_COLOR_TYPE::ORANGE));

    // Story Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 12, 9, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🟠 이곳은 상점입니다.", false, 0, TEXT_COLOR_TYPE::ORANGE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🛒 필요한 아이템을 구매하세요.", false, 1, TEXT_COLOR_TYPE::WHITE));

    // Select Layout (상점 선택지)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 23, 5, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "1. 아이템 구매", false, 0, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "2. 상점 나가기", false, 1, TEXT_COLOR_TYPE::WHITE));
}

void Scene5F::begin() {
    makeLayout();
}

void Scene5F::tick() {
    // 사용자 입력 처리
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "몬스터를 공격했습니다!\n";
        break;
    case 2:
        cout << "방어했습니다.\n";
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

Scene5F::Scene5F() {
}

Scene5F::~Scene5F() {
}