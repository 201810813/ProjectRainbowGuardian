//AltarScene.cpp
#include "pch.h"
#include "AltarScene.h"
#include "ConsoleLayout.h" // 콘솔 레이아웃 관련
#include "Player.h" // 플레이어 정보 관리
#include "SceneManager.h"
#include "KeyManager.h" // 키 입력 처리 관련 추가

AltarScene::AltarScene() {
	CursorPos = 0;
}

AltarScene::~AltarScene() {
}

void AltarScene::makeLayout(){

    // Title Layout (제단 제목 설정)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "제단", false, 0, TEXT_COLOR_TYPE::BLACK, BACKGROUND_COLOR_TYPE::WHITE));

    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 9, 25);
   /* Player* player = Player::GetInstance();
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "HP: " + to_string(player->GetHP()) + "/" + to_string(player->GetMaxHP()), false, 0, TEXT_COLOR_TYPE::GREEN));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "골드: " + to_string(player->GetGold()), false, 1, TEXT_COLOR_TYPE::ORANGE));*/

    // Map Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 8);

    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 13, 9, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "어디선가 성스러운 기운이 느껴집니다...", false, 1, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "골드 100을 봉양하면 최대 체력으로 회복됩니다.", false, 2, TEXT_COLOR_TYPE::WHITE));

    // 선택지 추가
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 24, 5, 60);
    if (CursorPos == 0)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [1. 봉양하기]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [2. 나가기]", false, 1, TEXT_COLOR_TYPE::WHITE));
    }
    else if (CursorPos == 1)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [1. 봉양하기]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [2. 나가기]", false, 1, TEXT_COLOR_TYPE::WHITE));
    }

    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::DRAW, 61, 13, 16, 51);

}

void AltarScene::begin() {
    makeLayout();
}

void AltarScene::tick()
{
    if (IS_TAP(UP)) // 커서를 위로 이동
    {
        CursorPos = (CursorPos > 0) ? CursorPos - 1 : 1; // 0에서 1로 순환
        WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
        makeLayout();
    }
    else if (IS_TAP(DOWN)) // 커서를 아래로 이동
    {
        CursorPos = (CursorPos < 1) ? CursorPos + 1 : 0; // 1에서 0으로 순환
        WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
        makeLayout();
    }

    if (IS_TAP(ENTER)) // 선택 확정
    {
        if (CursorPos == 0) // 봉양
        {
            handleOffer();
        }
        else if (CursorPos == 1) // 나가기
        {
            handleExit();
        }
    }
}

void AltarScene::handleOffer()
{
	//Player* player = Player::GetInstance();
	//if (player->SpendGold(100)) // 100골드 소모
	//{
	//	player->SetCurrentHP(player->GetMaxHP());
	//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "성스러운 기운이 당신을 감싸 체력이 모두 회복되었습니다.", false, 3, TEXT_COLOR_TYPE::WHITE));
	//}
	//else
	//{
	//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "골드가 부족합니다.", false, 3, TEXT_COLOR_TYPE::WHITE));
	//}
	makeLayout();
}

void AltarScene::handleExit() // 나가기
{
    SceneManager::GetInstance()->MoveToNextFloor();
}