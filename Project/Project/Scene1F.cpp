//Scene1F.cpp
#include "pch.h"
#include "Scene1F.h"
#include "ConsoleLayout.h"

void Scene1F::makeLayout() {
    // Title Layout (1층 제목 설정)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "붉은 분노의 층", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::RED));

    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 8, 25);

    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "컬러", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::BLACK));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "❇️ 레벨     : 1", false, 1, TEXT_COLOR_TYPE::SKY, BACKGROUND_COLOR_TYPE::BLACK));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "⚡ EXP      : 0 / 100", false, 2, TEXT_COLOR_TYPE::SKY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🩸 HP       : 100 / 100", false, 3, TEXT_COLOR_TYPE::GREEN));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🗡️ ATK      : 10", false, 4, TEXT_COLOR_TYPE::RED));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🛡️ DEF      : 5%", false, 5, TEXT_COLOR_TYPE::BLUE_INENSITY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🍀 LUK      : 10%", false, 6, TEXT_COLOR_TYPE::ORANGE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "💰 GOLD     : 100", false, 7, TEXT_COLOR_TYPE::ORANGE_INENSITY));

    // Map Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 9);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "08 [🐉]", false, 1, TEXT_COLOR_TYPE::GRAY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "07 [❔]", false, 2, TEXT_COLOR_TYPE::GRAY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "06 [❔]", false, 3, TEXT_COLOR_TYPE::GRAY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "05 [❔]", false, 4, TEXT_COLOR_TYPE::GRAY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "04 [❔]", false, 5, TEXT_COLOR_TYPE::GRAY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "03 [❔]", false, 6, TEXT_COLOR_TYPE::GRAY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "02 [❔]", false, 7, TEXT_COLOR_TYPE::GRAY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "01 [⚔️]", false, 8, TEXT_COLOR_TYPE::RED));

    // Story Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 12, 9, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🔥 이곳은 붉은 분노의 층입니다.", false, 0, TEXT_COLOR_TYPE::RED));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🐺 화가 잔뜩 난 늑대가 당신에게 욕을 날립니다.", false, 1, TEXT_COLOR_TYPE::WHITE));

    // Select Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 23, 5, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "1. 공격", false, 0, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "2. 방어", false, 1, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "3. 스킬", false, 2, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "4. 아이템 사용", false, 3, TEXT_COLOR_TYPE::WHITE));
}

void Scene1F::begin() {
    makeLayout();
}

void Scene1F::tick() {
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
    default:
        cout << "잘못된 선택입니다. 다시 시도해주세요.\n";
        break;
    }
}

Scene1F::Scene1F() {
}

Scene1F::~Scene1F() {
}
