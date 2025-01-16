#include "pch.h"
#include "Scene4F.h"
#include "ConsoleLayout.h"

void Scene4F::makeLayout() {
    // Title Layout (4층 제목 설정)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "녹색 생명의 층", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::GREEN));

    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 9, 25);

    // Map Layout
    //WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 8);
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "04 [⚔️]", false, 5, TEXT_COLOR_TYPE::GREEN));

    // Story Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 13, 9, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🌱 이곳은 녹색 생명의 층입니다.", false, 7, TEXT_COLOR_TYPE::GREEN));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "☠️ 독덩쿠리가 독한 냄새를 풍깁니다... 우웩🤮", false, 8, TEXT_COLOR_TYPE::WHITE));

    // Select Layout (선택지)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 24, 5, 60);

	// Draw Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::DRAW, 61, 13, 16, 51);
}

void Scene4F::begin() {
	MainScene::begin();
    makeLayout();
    slime = new PoisonSlime();
}

void Scene4F::tick() {
    MainScene::tick();
}

Scene4F::Scene4F() {
}

Scene4F::~Scene4F() {
    delete slime;
}
