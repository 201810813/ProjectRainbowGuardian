//AltarScene.cpp
#include "pch.h"
#include "AltarScene.h"
#include "ConsoleLayout.h" // 콘솔 레이아웃 관련

void AltarScene::makeLayout(){
    // Title Layout (제단 제목 설정)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "제단", false, 0, TEXT_COLOR_TYPE::BLACK, BACKGROUND_COLOR_TYPE::WHITE));

    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 7, 25);

    // Map Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 9);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "02 [⛲]", false, 7, TEXT_COLOR_TYPE::ORANGE));

    // 제단에 대한 스토리 추가
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 11, 8, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "어디선가 성스러운 기운이 느껴집니다...", false, 0, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "제단 앞에서 선 당신은 선택을 해야 합니다.", false, 1, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "골드를 봉양하고 회복을 하시겠습니까?", false, 2, TEXT_COLOR_TYPE::WHITE));

    // 선택지 추가 (예: 아이템 선택)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 21, 5, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[1. 네]", false, 0, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[2. 아니요]", false, 1, TEXT_COLOR_TYPE::WHITE));
}

void AltarScene::begin() {
    makeLayout();
}

void AltarScene::tick()
{
   // 사용자 입력 처리
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "성스러운 기운이 당신을 감싸고 있습니다.\n";
        break;
    case 2:
        cout << "다음 장소로 이동합니다.\n";
        break;
    default:
        cout << "잘못된 선택입니다. 다시 시도해주세요.\n";
        break;
    }
}

AltarScene::AltarScene() {
}

AltarScene::~AltarScene() {
}
