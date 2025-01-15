#include "pch.h"
#include "ShopScene.h"
#include "ConsoleLayout.h"
#include "Player.h" // 플레이어 정보 관리
#include "KeyManager.h" // 키 입력 처리 관련 추가
#include "SceneManager.h"

ShopScene::ShopScene() : CursorPos(0) {}

ShopScene::~ShopScene() {}

void ShopScene::makeLayout()
{
    // Title Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "상점", false, 0, TEXT_COLOR_TYPE::BLACK, BACKGROUND_COLOR_TYPE::ORANGE));

    // Stat Layout (플레이어 정보)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 9, 25);
    /*Player* player = Player::GetInstance();
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "골드: " + std::to_string(player->GetGold()), false, 0, TEXT_COLOR_TYPE::WHITE));*/

    //Map Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 8);

    // Shop Items Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 13, 9, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "구매 가능한 아이템 목록:", false, 0, TEXT_COLOR_TYPE::ORANGE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "1. 체력 포션 (10 골드)", false, 1, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "2. 공격력 강화 (15 골드)", false, 2, TEXT_COLOR_TYPE::WHITE));

    // 선택지 추가
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 24, 5, 60);
    if (CursorPos == 0)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [1. 아이템 구매]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [2. 아이템 판매]", false, 1, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [3. 상점 나가기]", false, 2, TEXT_COLOR_TYPE::WHITE));
    }
    else if (CursorPos == 1)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [1. 아이템 구매]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [2. 아이템 판매]", false, 1, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [3. 상점 나가기]", false, 2, TEXT_COLOR_TYPE::WHITE));
    }
    else if (CursorPos == 2)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [1. 아이템 구매]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [2. 아이템 판매]", false, 1, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [3. 상점 나가기]", false, 2, TEXT_COLOR_TYPE::WHITE));
    }

	WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::DRAW, 61, 13, 16, 51);
}

void ShopScene::begin()
{
    makeLayout();
}

void ShopScene::tick()
{
    if (IS_TAP(UP)) // 커서를 위로 이동
    {
        CursorPos = (CursorPos > 0) ? CursorPos - 1 : 2; // 0에서 2로 이동
        WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
        makeLayout();
    }
    else if (IS_TAP(DOWN)) // 커서를 아래로 이동
    {
        CursorPos = (CursorPos < 2) ? CursorPos + 1 : 0; // 2에서 0으로 이동
        WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
        makeLayout();
    }

    if (IS_TAP(ENTER)) // 선택지 확정
    {
        switch (CursorPos)
        {
        case 0: // 아이템 구매
            handlePurchase();
            break;
        case 1: // 아이템 판매
            handleSell();
            break;
        case 2: // 상점 나가기
            handleExit();
            break;
        }
    }
}

void ShopScene::handlePurchase()
{
    cout << "구매할 아이템 번호를 선택하세요 (1: 체력 포션, 2: 공격력 강화): ";
    int itemChoice;
    cin >> itemChoice;
//
//    Player* player = Player::GetInstance();
//    switch (itemChoice)
//    {
//   case 1: // 체력 포션
//        if (player->SpendGold(10))
//        {
//            player->AddToInventory("체력 포션");
//            cout << "체력 포션을 구매했습니다!\n";
//        }
//        else
//        {
//            cout << "골드가 부족합니다.\n";
//        }
//        break;
//
//    case 2: // 공격력 강화
//        if (player->SpendGold(15))
//        {
//            player->AddToInventory("공격력 강화");
//            cout << "공격력 강화 아이템을 구매했습니다!\n";
//        }
//        else
//        {
//            cout << "골드가 부족합니다.\n";
//        }
//        break;
//
//    default:
//        cout << "잘못된 선택입니다.\n";
//        break;
//    }
//
    makeLayout();
}

void ShopScene::handleSell()
{
//    Player* player = Player::GetInstance();
//
//    if (player->IsInventoryEmpty())
//    {
//        cout << "판매할 아이템이 없습니다.\n";
//        return;
//    }
//
//    player->DisplayInventory();
//    cout << "판매할 아이템 번호를 선택하세요: ";
//    int itemIndex;
//    cin >> itemIndex;
//
//    if (player->SellItem(itemIndex))
//    {
//        cout << "아이템을 성공적으로 판매했습니다!\n";
//    }
//    else
//    {
//        cout << "잘못된 선택입니다.\n";
//    }
//
    makeLayout();
}

void ShopScene::handleExit() // 상점 나가기
{
    SceneManager::GetInstance()->MoveToNextFloor();
}
