﻿#include "pch.h"
#include "Scene3F.h"
#include "ConsoleLayout.h"

void Scene3F::makeLayout() {
    // Title Layout (3층 제목 설정)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "노란 환희의 층", false, 0, TEXT_COLOR_TYPE::ORANGE, BACKGROUND_COLOR_TYPE::ORANGE_INENSITY));

    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 9, 25);

    // Map Layout
    //WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 8);
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "03 [⚔️]", false, 6, TEXT_COLOR_TYPE::ORANGE_INENSITY));

    // Story Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 13, 9, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "⚡ 이곳은 노란 환희의 층입니다.", false, 7, TEXT_COLOR_TYPE::ORANGE_INENSITY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🦗 전기사마귀가 '찌릿'거리고  있습니다.", false, 8, TEXT_COLOR_TYPE::WHITE));

    // Select Layout (전투 선택지)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 24, 5, 60);
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "1. 공격", false, 0, TEXT_COLOR_TYPE::WHITE));
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "2. 방어", false, 1, TEXT_COLOR_TYPE::WHITE));
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "3. 스킬", false, 2, TEXT_COLOR_TYPE::WHITE));
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "4. 아이템 사용", false, 3, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::DRAW, 61, 13, 16, 51);
}

void Scene3F::begin() {
	MainScene::begin();
    makeLayout();
    mantis = new EletricMantis();
}

void Scene3F::tick() {
    MainScene::tick();
}

Scene3F::Scene3F() {
}

Scene3F::~Scene3F() {
    delete mantis;
}
