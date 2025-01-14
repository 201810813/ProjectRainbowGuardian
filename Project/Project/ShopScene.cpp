//ShopScene.cpp
#include "pch.h"
#include "ShopScene.h"
#include "ConsoleLayout.h"
#include "Player.h"

ShopScene::ShopScene() {}

ShopScene::~ShopScene() {}

void ShopScene::makeLayout()
{
    // Title Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "상점", false, 0, TEXT_COLOR_TYPE::BLACK, BACKGROUND_COLOR_TYPE::ORANGE));

    // Stat Layout (플레이어 정보)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2,8, 25);

    // Map Layout (상점 지도)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 9);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "02 [🏪]", false, 7, TEXT_COLOR_TYPE::ORANGE));

    // Shop Items Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 12, 9, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "구매 가능한 아이템 목록:", false, 0, TEXT_COLOR_TYPE::ORANGE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "[체력 포션] - 50 골드", false, 1, TEXT_COLOR_TYPE::WHITE));

    // 선택지 추가
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 23, 5, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[1. 체력 포션 구매하기]", false, 0, TEXT_COLOR_TYPE::WHITE));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[2. 체력 포션 판매하기]", false, 1, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[3. 상점 나가기]", false, 2, TEXT_COLOR_TYPE::WHITE));
}

void ShopScene::begin()
{
    makeLayout();
}

void ShopScene::tick()
{
    // 키 입력 처리
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1: // 구매하기
        int itemChoice;
        cout << "구매할 아이템 번호를 선택하세요: ";
        cin >> itemChoice;
   
    //    switch (itemChoice)
    //    {
    //    case 1: // 체력 포션
    //        if (PlayerManager::GetInstance()->SpendGold(50)) {
    //            cout << "체력 포션을 구매했습니다!\n";
    //            PlayerManager::GetInstance()->IncreaseHP(20); // 체력 회복
    //        }
    //        else {
    //            cout << "골드가 부족합니다.\n";
    //        }
    //        break;
    // 
    //    default:
    //        cout << "잘못된 선택입니다.\n";
    //        break;
    //    }
    //    break;

    //case 2: // 상점 나가기
    //    cout << "상점을 떠납니다.\n";
    //    break;

    //default:
    //    cout << "잘못된 입력입니다.\n";
    //    break;
    }
}
