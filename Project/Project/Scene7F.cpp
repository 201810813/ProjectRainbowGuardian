#include "pch.h"
#include "Scene7F.h"
#include "ConsoleLayout.h"

void Scene7F::makeLayout() {
    // Title Layout (7층 제목 설정)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "7층: 보라색 환영의 층", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::PURPLE));

    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 9, 25);

    // Map Layout
    //WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 8);
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "07 [⚔️]", false, 2, TEXT_COLOR_TYPE::PURPLE));

    // Story Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 13, 9, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🔮 이곳은 보라색 환영의 층입니다.", false, 7, TEXT_COLOR_TYPE::PURPLE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🪞 르탄이와 똑닮은 환영이 나타났습니다.", false, 8, TEXT_COLOR_TYPE::WHITE));

    // Select Layout (선택지)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 24, 5, 60);

	// Draw Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::DRAW, 61, 13, 16, 51);
}

void Scene7F::begin() {
    makeLayout();
    rtan = new Rtan();
}

void Scene7F::tick() {
    MainScene::tick();
}

Scene7F::Scene7F() {
}

Scene7F::~Scene7F() {
    delete rtan;
}
