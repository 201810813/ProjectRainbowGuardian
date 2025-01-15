//MainScene.cpp
#include "pch.h"
#include "MainScene.h"
#include "ConsoleLayout.h"
#include "KeyManager.h"
#include "MRedWolf.h"
#include "HealthPotion.h"
#include "PowerPotion.h"

void MainScene::makeLayout()
{
	// WriteManager::GetInstance()->MakeLayout();

    // Title Layout
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
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "💰 GOLD     : 0", false, 7, TEXT_COLOR_TYPE::ORANGE_INENSITY));

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

    // Select Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 23, 5, 60);

    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::DRAW, 61, 12, 17, 58);
}

void MainScene::begin()
{
    Cur_BattleType = BATTLE_TYPE::TURN_COUNT;
    Turn_Count = 0;
    bOnce = false;
    CursorPos = 0;
    makeLayout();
    
}

void MainScene::tick()
{
    string output;

    // !!!! 각각 턴이 진행될 때마다 한번씩만 함수가 호출되고, 메세지를 출력해주도록 해야함.

    // 현재 턴이 무엇이냐에 따라 다른 행동들을 수행한다.
    switch (Cur_BattleType)
    {
        // 턴 카운트 : 단순히 몇번 턴이 흘렀는지를 확인해준다.
        // 이후에 플레이어 버프 효과 지속시간에 사용할 턴 수
    case BATTLE_TYPE::TURN_COUNT:

        if (!bOnce)
        {
            Turn_Count++;
            output = "현재 턴 : " + to_string(Turn_Count);
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, output));
            bOnce = true;
        }

        if (IS_TAP(ENTER))
        {
            Cur_BattleType = BATTLE_TYPE::PLAYER_TURN;
            bOnce = false;
        }

        break;


        // 플레이어의 행동 선택
    case BATTLE_TYPE::PLAYER_TURN:

        if (!bOnce)
        {
            output = "플레이어의 턴!!";
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, output));
            bOnce = true;
        }

        if (IS_TAP(ENTER))
        {
            Cur_BattleType = BATTLE_TYPE::SELECT;
            bOnce = false;
        }

        break;


        // 플레이어의 행동 선택
    case BATTLE_TYPE::SELECT:

        if (!bOnce)
        {
            output = "행동을 선택해 주세요.";
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, output));

            CursorPos = 0;
            bOnce = true;
        }

        /*
        선택 기능 추가
        커서
        bOnce false 처리 해주어야함.
        다음 스테이지 이동 해주어야 함.
        */

        if (IS_TAP(UP))
        {
            CursorPos = 0;
        }
        else if (IS_TAP(DOWN))
        {
            CursorPos = 1;
        }

        if (0 == CursorPos)
        {
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  >    [ 공격 ]", false, 0));
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "       [아이템]", false, 1));
        }
        else if (1 == CursorPos)
        {
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "       [ 공격 ]", false, 0));
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  >    [아이템]", false, 1));
        }

        if (IS_TAP(ENTER))
        {
            if (0 == CursorPos)
            {
                Cur_BattleType = BATTLE_TYPE::PLAYER_ATTACK;
            }
            else if (1 == CursorPos)
            {
                Cur_BattleType = BATTLE_TYPE::ITEM;
            }

            /* 셀렉 레이아웃 문자만 삭제할 수 있는 기능 추가해야함.*/
            WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
            bOnce = false;
        }

        break;

        // 플레이어의 공격 진행
    case BATTLE_TYPE::PLAYER_ATTACK:

        if (!bOnce)
        {
            output = "당신은 몬스터를 공격했습니다!";
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, output));
            Player::getInstance()->Attack(*monster);
            bOnce = true;
        }
        if (IS_TAP(ENTER))
        {
            Cur_BattleType = BATTLE_TYPE::MONSTER_TURN;
            bOnce = false;
        }

        break;

        // 플레이어 가방 열기
        /* 이 부분 동적으로 구현할 수 있도록 해야함.*/
    case BATTLE_TYPE::ITEM:

        if (!bOnce)
        {
            output = "당신은 가방을 열었습니다!";
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, output));
            output = "어느 아이템을 사용하실 건가요?";
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, output));
            CursorPos = 0;
            bOnce = true;
        }

        /*
        선택 기능 추가
        커서
        bOnce = false 처리 해주어야함.
        스테이트 이동 처리 해주어야 함.
        */

        if (IS_TAP(UP))
        {
            CursorPos = 0;
        }
        else if (IS_TAP(DOWN))
        {
            CursorPos = 1;
        }

        if (0 == CursorPos)
        {
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  >    [회복 포션]", false, 0));
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "       [강화 포션]", false, 1));
        }
        else if (1 == CursorPos)
        {
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "       [회복 포션]", false, 0));
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  >    [강화 포션]", false, 1));
        }

        if (IS_TAP(ENTER))
        {
            if (0 == CursorPos)
            {
                HealthPotion healthPotion; // 회복 포션 객체 생성
                healthPotion.Use(); // 회복 포션 사용
                WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "회복포션을 사용하여 30을 회복함.", true, 0));
            }
            else if (1 == CursorPos)
            {
                PowerPotion powerPotion; // 강화 포션 객체 생성
                powerPotion.Use(); // 강화 포션 사용
                WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "강화포션을 사용하여 데미지를 5를 강화함.", true, 0));
            }

            Cur_BattleType = BATTLE_TYPE::MONSTER_TURN;

            /* 셀렉 레이아웃 문자만 삭제할 수 있는 기능 추가해야함.*/
            WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
            bOnce = false;
        }

        break;

        // 플레이어 가방에서 아이템 사용하기
    case BATTLE_TYPE::ITEM_SELECT:

        // 필요 없는 것 같음.

        break;

        // 몬스터 턴 진행
    case BATTLE_TYPE::MONSTER_TURN:

        if (!bOnce)
        {
            // 몬스터 행동 선택 (랜덤 일반 공격/ 스킬 공격)
            // 행동 실행
            // 결과 출력
            // 몬스터가 공격을 했다.
            // 몬스터가 "화염구!!"을 사용했다.
            

            output = "몬스터가 플레이어를 공격합니다..!";
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, output));
            monster->Attack();
            
            CursorPos = 0;
            bOnce = true;
        }
        if (IS_TAP(ENTER))
        {
            Cur_BattleType = BATTLE_TYPE::MONSTER_DEAD_CHECK;
            bOnce = false;
        }

        break;

        // 몬스터 죽었는지 체크 메세지는 불필요
    case BATTLE_TYPE::MONSTER_DEAD_CHECK:

        monster->is_Die();
        Cur_BattleType = BATTLE_TYPE::TURN_COUNT;
        break;


    default:
        break;
    }
    
}

MainScene::MainScene()
    : Cur_BattleType(BATTLE_TYPE::TURN_COUNT)
    , Turn_Count(0)
    , bOnce(false)
    , CursorPos(0)
{
    monster = new MRedWolf();
}

MainScene::~MainScene()
{
    if (monster != nullptr) {
        delete monster;
    }
}