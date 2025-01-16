#include "pch.h"
#include "ShopScene.h"
#include "ConsoleLayout.h"
#include "Player.h" // 플레이어 정보 관리
#include "KeyManager.h" // 키 입력 처리 관련 추가
#include "SceneManager.h"
#include "HealthPotion.h"

ShopScene::ShopScene() : CursorPos(0) {}

ShopScene::~ShopScene() {}

void ShopScene::makeLayout()
{
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "상점", false, 0, TEXT_COLOR_TYPE::BLACK, BACKGROUND_COLOR_TYPE::ORANGE));

    string output = "";
    if (GetFloorNumber() < 10)
    {
        output += "0";
    }

    output += to_string(GetFloorNumber());
    output += " [🛒]";
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, output, true, 0, TEXT_COLOR_TYPE::GRAY));

    // Stat Layout (플레이어 정보)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 9, 25);

    //Map Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 8);




    // Shop Items Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 13, 9, 60);


    // 선택지 추가
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 24, 5, 60);
    //UpdateSelectLayout();

    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::DRAW, 61, 13, 16, 51);
}

void ShopScene::begin()
{
    Cur_ShopType = SHOP_TYPE::MAIN;
    makeLayout();
    // Title Layout
    
}

void ShopScene::tick()
{
    
    switch (Cur_ShopType)
    {
        //상점 메인.
    case SHOP_TYPE::MAIN:
        UpdateSelectLayout();
        if (IS_TAP(UP)) // 커서를 위로 이동
        {
            CursorPos = (CursorPos > 0) ? CursorPos - 1 : 2; // 0에서 2로 이동
            WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
        }
        else if (IS_TAP(DOWN)) // 커서를 아래로 이동
        {
            CursorPos = (CursorPos < 2) ? CursorPos + 1 : 0; // 2에서 0으로 이동
            WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
        }

        if (IS_TAP(ENTER)) // 선택지 확정
        {
            switch (CursorPos)
            {
            case 0: // 아이템 구매
                Cur_ShopType = SHOP_TYPE::PURCHASE;
                break;
            case 1: // 아이템 판매
                Cur_ShopType = SHOP_TYPE::SELL;
                break;
            case 2: // 상점 나가기
                handleExit();
                break;
            }
        }
        break;
        //구매 화면
    case SHOP_TYPE::PURCHASE:
        UpdatePurchaseLayout();
        if (IS_TAP(UP)) // 커서를 위로 이동
        {
            CursorPos = (CursorPos > 0) ? CursorPos - 1 : 2; // 0에서 2로 이동
            WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
        }
        else if (IS_TAP(DOWN)) // 커서를 아래로 이동
        {
            CursorPos = (CursorPos < 2) ? CursorPos + 1 : 0; // 2에서 0으로 이동
            WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
        }
        if (IS_TAP(ENTER)) // 선택지 확정
        {
            switch (CursorPos)
            {
                
            case 0: // 체력포션 구매
                makeLayout();
                if (Player::getInstance()->GetCoin() >= 30) {
                    Player::getInstance()->SpendGold(10);
                    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "체력 포션을 구매했습니다.", false, 0, TEXT_COLOR_TYPE::ORANGE));
                    Player::getInstance()->AddItemToInventory(HEALTH_POTION);
                }
                else {
                    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "돈이 부족합니다", false, 0, TEXT_COLOR_TYPE::ORANGE));
                }
                break;
            case 1: // 파워포션 구매
                makeLayout();
                if (Player::getInstance()->GetCoin() >= 20) {
                    Player::getInstance()->SpendGold(15);
                    Player::getInstance()->AddItemToInventory(POWER_POTION);
                    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "파워 포션을 구매했습니다.", false, 0, TEXT_COLOR_TYPE::ORANGE));
                }
                else {
                    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "돈이 부족합니다", false, 0, TEXT_COLOR_TYPE::ORANGE));
                }
                break;
            case 2: // 이전 메뉴로
                WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::STORY);
                Cur_ShopType = SHOP_TYPE::MAIN;
                CursorPos = 0;
                break;
            }
        }
        break;
        //판매 화면
    case SHOP_TYPE::SELL:
        UpdateSellLayout();
        if (IS_TAP(UP)) // 커서를 위로 이동
        {
            CursorPos = (CursorPos > 0) ? CursorPos - 1 : 2; // 0에서 2로 이동
            WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
        }
        else if (IS_TAP(DOWN)) // 커서를 아래로 이동
        {
            CursorPos = (CursorPos < 2) ? CursorPos + 1 : 0; // 2에서 0으로 이동
            WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
        }
        if (IS_TAP(ENTER)) // 선택지 확정
        {
            switch (CursorPos)
            {
                makeLayout();
            case 0: // 체력포션 판매
                
                if (Player::getInstance()->GetItemCount(HEALTH_POTION) > 0) { // 체력포션 판매
                    Player::getInstance()->SellItem(HEALTH_POTION);
                    Player::getInstance()->gainCoin(18);
                    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "체력 포션을 판매했습니다", false, 0, TEXT_COLOR_TYPE::ORANGE));
                }
                else {
                    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "체력 포션이 없습니다.", false, 0, TEXT_COLOR_TYPE::ORANGE));
                }
                break;
            case 1: // 파워포션 판매
                
                if (Player::getInstance()->GetItemCount(POWER_POTION) > 0) { // 파워포션 판매
                    Player::getInstance()->SellItem(POWER_POTION);
                    Player::getInstance()->gainCoin(12);
                    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "파워 포션을 판매했습니다", false, 0, TEXT_COLOR_TYPE::ORANGE));
                }
                else {
                    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "파워 포션이 없습니다.", false, 0, TEXT_COLOR_TYPE::ORANGE));
                }
                break;
            case 2: // 이전 메뉴로
                WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::STORY);
                Cur_ShopType = SHOP_TYPE::MAIN;
                CursorPos = 0;
                break;
            }
            break;

    default:
        break;
        }
    }
}




void ShopScene::handleExit() // 상점 나가기
{
    //SceneManager::GetInstance()->MoveToNextFloor();
    SceneManager::GetInstance()->CacheChangeScene(SCENE_TYPE::RANDOM);
}

void ShopScene::UpdateSelectLayout()
{
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "구매 가능한 아이템 목록:", false, 6, TEXT_COLOR_TYPE::ORANGE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "1. 체력 포션 (10 골드)", false, 7, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "2. 공격력 강화 (15 골드)", false, 8, TEXT_COLOR_TYPE::WHITE));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "판매 가격 : 60 % ", false, 5, TEXT_COLOR_TYPE::ORANGE));

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

}void ShopScene::UpdatePurchaseLayout() {
     
    if (CursorPos == 0)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [1. 체력 포션 ]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [2. 파워 포션 ]", false, 1, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [3. 이전 메뉴 ]", false, 2, TEXT_COLOR_TYPE::WHITE));
    }
    else if (CursorPos == 1)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [1. 체력 포션 ]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [2. 파워 포션 ]", false, 1, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [3. 이전 메뉴 ]", false, 2, TEXT_COLOR_TYPE::WHITE));
    }
    else if (CursorPos == 2)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [1. 체력 포션 ]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [2. 파워 포션 ]", false, 1, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [3. 이전 메뉴 ]", false, 2, TEXT_COLOR_TYPE::WHITE));
    }
}

void ShopScene::UpdateSellLayout()
{
    
    if (CursorPos == 0)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [1. 체력 포션 ]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [2. 파워 포션 ]", false, 1, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [3. 이전 메뉴 ]", false, 2, TEXT_COLOR_TYPE::WHITE));
    }
    else if (CursorPos == 1)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [1. 체력 포션 ]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [2. 파워 포션 ]", false, 1, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [3. 이전 메뉴 ]", false, 2, TEXT_COLOR_TYPE::WHITE));
    }
    else if (CursorPos == 2)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [1. 체력 포션 ]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [2. 파워 포션 ]", false, 1, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [3. 이전 메뉴 ]", false, 2, TEXT_COLOR_TYPE::WHITE));
    }
}
