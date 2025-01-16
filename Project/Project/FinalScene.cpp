#include "pch.h"
#include "FinalScene.h"
#include "ConsoleLayout.h"
#include "KeyManager.h"
#include "Boss.h"
#include "SoundManager.h"



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

    if (!finalBossDefeated) {
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🌈레인보우 드래곤이 나타났습니다🐉", false, 5, TEXT_COLOR_TYPE::SKY_INENSITY));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "주인공은 드래곤에게 색을 돌려달라는 소원을 빌었습니다. ", false, 6, TEXT_COLOR_TYPE::WHITE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "아니 근데...모든 색을 먹어 치운 게 드래곤이라고 하네요?! ", false, 7, TEXT_COLOR_TYPE::WHITE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "⚔️ 드래곤을 쓰러트리고, 흑백 저주를 풀어야 합니다.", false, 8, TEXT_COLOR_TYPE::SKY_INENSITY));
	}
	else {
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🌈레인보우 드래곤이 쓰러졌습니다🐉", false, 5, TEXT_COLOR_TYPE::SKY_INENSITY));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "드래곤은 주인공에게 색을 돌려주었습니다. ", false, 6, TEXT_COLOR_TYPE::WHITE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "주인공은 마을로 돌아가 색을 되찾았습니다! ", false, 7, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "게임을 클리어했습니다. 감사합니다!", false, 8, TEXT_COLOR_TYPE::SKY_INENSITY));
    }
}

void FinalScene::begin() {
    SoundManager::GetInstance()->PlayMusic("EnterBossRoom", 1, 0.2f, true);
    MainScene::begin();
    makeLayout();
}

void FinalScene::tick() {
    // 사용자 입력 처리
    MainScene::tick();
}

FinalScene::FinalScene() : finalBossDefeated(false)
{
    MainScene::ThisSceneType = SCENE_TYPE::FINAL;
    MainScene::monster = new Boss;
}

FinalScene::~FinalScene() {
}
