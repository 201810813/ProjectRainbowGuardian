//MainScene.cpp
#include "pch.h"
#include "MainScene.h"
#include "ConsoleLayout.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "FairyFire.h"
#include "HealthPotion.h"
#include "PowerPotion.h"
#include "SoundManager.h"

#include <sstream>

void MainScene::makeLayout()
{
    // Title Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
	
    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 9, 25);
    UpdateStatLayout();

    // Map Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 111, 2, 9, 8);

    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "08 [❔]", false, 1, TEXT_COLOR_TYPE::GRAY));
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "07 [❔]", false, 2, TEXT_COLOR_TYPE::GRAY));
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "06 [❔]", false, 3, TEXT_COLOR_TYPE::GRAY));
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "05 [❔]", false, 4, TEXT_COLOR_TYPE::GRAY));
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "04 [❔]", false, 5, TEXT_COLOR_TYPE::GRAY));
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "03 [❔]", false, 6, TEXT_COLOR_TYPE::GRAY));
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "02 [❔]", false, 7, TEXT_COLOR_TYPE::GRAY));
    //WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "01 [⚔️]", false, 8, TEXT_COLOR_TYPE::RED));

    // Story Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 13, 9, 60);

    // Select Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 24, 5, 60);

	//Draw Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::DRAW, 61, 13, 16, 58);

    //Backgound Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::BACKGROUND, 27, 2, 9, 82);

	//PROGRESS_BAR Layout
    UpdateProgressBarLayout();

    //MONSTER_STAT_UI Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MONSTER_STAT_UI, 63, 14, 2, 20);
    UpdateMonsterStatLayout();
}

void MainScene::UpdateStatLayout()
{
    std::ostringstream oss;
    Player::getInstance()->GetDamage();
    Player::getInstance()->GetCurrentHP();
    
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "컬러", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::BLACK));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "========================", false, 1, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::BLACK));
    
    oss.str("");
    oss.clear();
    oss << "❇️ 레벨     : " << Player::getInstance()->GetLevel();
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, oss.str(), false, 2, TEXT_COLOR_TYPE::SKY, BACKGROUND_COLOR_TYPE::BLACK));

    oss.str("");
    oss.clear();
    oss << "⚡ EXP      : " << Player::getInstance()->GetCurrentExp() << " / " << Player::getInstance()->GetMaxExp();
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, oss.str(), false, 3, TEXT_COLOR_TYPE::SKY));

    oss.str("");
    oss.clear();
    oss << "🩸 HP       : " << (int)floor(Player::getInstance()->GetCurrentHP()) << " / " << (int)floor(Player::getInstance()->GetMaxHP());
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, oss.str(), false, 4, TEXT_COLOR_TYPE::GREEN));

    oss.str("");
    oss.clear();
    oss << "🗡️ ATK      : " << (int)floor(Player::getInstance()->GetDamage());

    if (Player::getInstance()->Is_PowerUp())
    {
        oss << " + " << Player::getInstance()->GetAddDamage();
    }

    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, oss.str(), false, 5, TEXT_COLOR_TYPE::RED));

    oss.str("");
    oss.clear();
    oss << "🛡️ DEF      : " << (int)floor(Player::getInstance()->GetDefense());
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, oss.str(), false, 6, TEXT_COLOR_TYPE::BLUE_INENSITY));

    oss.str("");
    oss.clear();
    oss << "🍀 LUK      : " << (int)floor(Player::getInstance()->GetEvasion()) << "%";
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, oss.str(), false, 7, TEXT_COLOR_TYPE::ORANGE));

    oss.str("");
    oss.clear();
    oss << "💰 GOLD     : " << (int)floor(Player::getInstance()->GetCoin());
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, oss.str(), false, 8, TEXT_COLOR_TYPE::ORANGE_INENSITY));
}

void MainScene::UpdateMonsterStatLayout()
{
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MONSTER_STAT_UI, monster->GetName(), false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::BLACK));

    std::ostringstream oss;
    oss.str("");
    oss.clear();
    oss << "🩸 HP   : " << (int)floor(monster->GetCurrentHP()) << " / " << (int)floor(monster->GetMaxHP());
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MONSTER_STAT_UI, oss.str(), false, 1, TEXT_COLOR_TYPE::GREEN));

    /*oss.str("");
    oss.clear();
    oss << "❇️ 레벨     : " << monster->GetName();
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MONSTER_STAT_UI, oss.str(), false, 2, TEXT_COLOR_TYPE::SKY, BACKGROUND_COLOR_TYPE::BLACK));*/
}

void MainScene::UpdateProgressBarLayout()
{
    //PROGRESS_BAR Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::PROGRESS_BAR, 105, 3, 7, 3);
	string bitcheck = SceneManager::GetInstance()->GetRoomColorCheck().to_string();
    WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::PROGRESS_BAR);
	
    for (int i = 0; i < 7; ++i)
    {
		BACKGROUND_COLOR_TYPE ColorType = BACKGROUND_COLOR_TYPE::BLACK;
        
        if (bitcheck[6 - i] == '1')
        {
            switch (i)
            {
            case 0:
                ColorType = BACKGROUND_COLOR_TYPE::RED;
                break;

            case 1:
                ColorType = BACKGROUND_COLOR_TYPE::ORANGE;
                break;

            case 2:
                ColorType = BACKGROUND_COLOR_TYPE::ORANGE_INENSITY;
                break;

            case 3:
                ColorType = BACKGROUND_COLOR_TYPE::GREEN;
                break;

            case 4:
                ColorType = BACKGROUND_COLOR_TYPE::BLUE;
                break;

            case 5:
                ColorType = BACKGROUND_COLOR_TYPE::BLUE_INENSITY;
                break;

            case 6:
                ColorType = BACKGROUND_COLOR_TYPE::PURPLE;
                break;

            default:
                break;
            }
        }
        else
        {
            ColorType = BACKGROUND_COLOR_TYPE::BLACK;
        }

        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::PROGRESS_BAR, "  ", false, i, TEXT_COLOR_TYPE::WHITE, ColorType));
    }
}

void MainScene::begin()
{
    Cur_BattleType = BATTLE_TYPE::TURN_COUNT;
    Turn_Count = 0; //
	bOnce = false; // 한번만 출력되도록 하는 플래그
	CursorPos = 0; // 커서 위치 초기화
    monster->Begin();
    MainScene::makeLayout();
}

void MainScene::tick()
{
    UpdateStatLayout();
    UpdateProgressBarLayout();
    UpdateMonsterStatLayout();
    string output;
    monster->Tick();
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
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, output, true, 0, TEXT_COLOR_TYPE::SKY));
            bOnce = true;
        }

        if (IS_TAP(ENTER))
        {
            SoundManager::GetInstance()->PlayMusic("MoveCursor", 1, 0.06f, true);
            Cur_BattleType = BATTLE_TYPE::PLAYER_TURN;
            bOnce = false;
        }

        break;


        // 플레이어의 행동 선택
    case BATTLE_TYPE::PLAYER_TURN:

        if (!bOnce)
        {
            output = "플레이어의 턴!!";
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, output, true, 0, TEXT_COLOR_TYPE::SKY_INENSITY));
            bOnce = true;
        }

        if (IS_TAP(ENTER))
        {
            SoundManager::GetInstance()->PlayMusic("MoveCursor", 1, 0.06f, true);
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
            SoundManager::GetInstance()->PlayMusic("SelectCursor", 1, 1.f, true);
            CursorPos = 0;
        }
        else if (IS_TAP(DOWN))
        {
            SoundManager::GetInstance()->PlayMusic("SelectCursor", 1, 1.f, true);
            CursorPos = 1;
        }

        if (0 == CursorPos)
        {
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  >  [ 공격 ]  ", false, 0));
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "       [아이템]", false, 1));
        }
        else if (1 == CursorPos)
        {
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "       [ 공격 ]", false, 0));
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  >  [아이템]  ", false, 1));
        }

        if (IS_TAP(ENTER))
        {
            SoundManager::GetInstance()->PlayMusic("MoveCursor", 1, 0.06f, true);
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
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, output, true, 0, TEXT_COLOR_TYPE::RED));
            Player::getInstance()->Attack(*monster);
            bOnce = true;
        }
        if (IS_TAP(ENTER))
        {
            SoundManager::GetInstance()->PlayMusic("MoveCursor", 1, 0.06f, true);
            Cur_BattleType = BATTLE_TYPE::MONSTER_DEAD_CHECK;
            bOnce = false;
        }

        break;

        // 플레이어 가방 열기
        /* 이 부분 동적으로 구현할 수 있도록 해야함.*/
    case BATTLE_TYPE::ITEM:
        
        if (!bOnce)
        {
            output = "당신은 가방을 열었습니다!";
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, output, true, 0, TEXT_COLOR_TYPE::ORANGE));
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
            SoundManager::GetInstance()->PlayMusic("SelectCursor", 1, 1.f, true);
            CursorPos = 0;
        }
        else if (IS_TAP(DOWN))
        {
            SoundManager::GetInstance()->PlayMusic("SelectCursor", 1, 1.f, true);
            CursorPos = 1;
        }

        if (0 == CursorPos)
        {
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  >  [회복 포션]  ", false, 0));
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "       [강화 포션]", false, 1));
        }
        else if (1 == CursorPos)
        {
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "       [회복 포션]", false, 0));
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  >  [강화 포션]  ", false, 1));
        }

        if (IS_TAP(ENTER))
        {   // 회복 포션 사용
            SoundManager::GetInstance()->PlayMusic("MoveCursor", 1, 0.06f, true);
            if (0 == CursorPos)
            {
                if (Player::getInstance()->UseItem(HEALTH_POTION)) {
                    Cur_BattleType = BATTLE_TYPE::MONSTER_DEAD_CHECK;
                }
                else {
                    Cur_BattleType = BATTLE_TYPE::SELECT;
                }
                
            }
            // 강화 포션 사용
            else if (1 == CursorPos)
            {
                if (Player::getInstance()->UseItem(POWER_POTION)) {
                    Cur_BattleType = BATTLE_TYPE::MONSTER_DEAD_CHECK;
                }
                else {
                    Cur_BattleType = BATTLE_TYPE::SELECT;
                }
            }
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
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, output, true, 0, TEXT_COLOR_TYPE::RED_INENSITY));
            monster->Attack();
            
            CursorPos = 0;
            bOnce = true;
        }
        if (IS_TAP(ENTER))
        {
            SoundManager::GetInstance()->PlayMusic("MoveCursor", 1, 0.06f, true);
            Cur_BattleType = BATTLE_TYPE::PLAYER_DEAD_CHECK;
            bOnce = false;
        }

        break;

        // 몬스터 죽었는지 체크 메세지는 불필요
    case BATTLE_TYPE::MONSTER_DEAD_CHECK:
        
        if (monster->is_Die()) {
            Cur_BattleType = BATTLE_TYPE::REWARD;
        }
        else { Cur_BattleType = BATTLE_TYPE::MONSTER_TURN; }

        break;
        

    case BATTLE_TYPE::PLAYER_DEAD_CHECK:
        //플레이어 죽었는지?
        if (!bOnce)
        {
            bOnce = true;
            if (Player::getInstance()->IsDie())
            {
                WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "당신은 세상의 색을 되찾지 못하고, 사망하셨습니다.", true, 0));
            }
            else
            {
                Cur_BattleType = BATTLE_TYPE::TURN_COUNT;
                bOnce = false;
            }
        }
        
        if (IS_TAP(ENTER))
        {
            SoundManager::GetInstance()->PlayMusic("MoveCursor", 1, 0.06f, true);
            bOnce = false;
            Cur_BattleType = BATTLE_TYPE::TOWN_CHANGER;
        }

        break;

    case BATTLE_TYPE::REWARD:
 
        if (!bOnce) {//플레이어 보상(경험치, 돈)
            // 현제방이 보스방인지 아닌지 확인
            if (ThisSceneType == SCENE_TYPE::FINAL)
            {
                WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "🌈레인보우 드래곤이 쓰러졌습니다🐉", true, 5, TEXT_COLOR_TYPE::SKY_INENSITY));
                WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "드래곤은 주인공에게 색을 돌려주었습니다. ", true, 6, TEXT_COLOR_TYPE::WHITE));
                WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "주인공은 마을로 돌아가 색을 되찾았습니다! ", true, 7, TEXT_COLOR_TYPE::WHITE));
                WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "게임을 클리어했습니다. 감사합니다!", true, 8, TEXT_COLOR_TYPE::SKY_INENSITY));
            }
            else
            {
                Player::getInstance()->gainExp(monster->GetExp());
                Player::getInstance()->gainCoin(monster->GetCoin());
            }
            bOnce = true;
        }
        
        if (IS_TAP(ENTER)) {
            SoundManager::GetInstance()->PlayMusic("MoveCursor", 1, 0.06f, true);
            bOnce = false;
            Cur_BattleType = BATTLE_TYPE::SCENE_CHANGER;
        }
        //다음씬 이동?;
        break;

    case BATTLE_TYPE::SCENE_CHANGER:
       
        //색 다 모았는지 확인
            //ture: 보스방 이동
            //false: 랜덤방
        if (!bOnce) {
            if (ThisSceneType != SCENE_TYPE::FINAL)
            {
                output = "다음 층으로 이동합니다.";
                WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, output));
            }
            bOnce = true;
        }

        if (IS_TAP(ENTER)) {
            SoundManager::GetInstance()->PlayMusic("MoveCursor", 1, 0.06f, true);
            bOnce = false;
            if (ThisSceneType == SCENE_TYPE::FINAL)
            {
                SoundManager::GetInstance()->StopMusic("Main_BGM");
                SceneManager::GetInstance()->CacheChangeScene(SCENE_TYPE::ENDINGCREDIT);
            }
            else
            {
                SceneManager::GetInstance()->CheckRoomColor(ThisSceneType);
                if (SceneManager::GetInstance()->Is_AllColorClear())
                {
                    SceneManager::GetInstance()->CacheChangeScene(SCENE_TYPE::FINAL);
                }
                else
                {
                    SceneManager::GetInstance()->CacheChangeScene(SCENE_TYPE::RANDOM);
                }
            }
        }
        break;

    case BATTLE_TYPE::TOWN_CHANGER:

        if (!bOnce) {
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "다시 마을에서 환생합니다.", true, 1));
            bOnce = true;
        }
        if (IS_TAP(ENTER)) {
            SoundManager::GetInstance()->PlayMusic("MoveCursor", 1, 0.06f, true);
            bOnce = false;
            SceneManager::GetInstance()->CheckRoomColorReset();
            SceneManager::GetInstance()->RessetFloorNumber();
            WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::MAP);
            Player::getInstance()->PlayerRecovery();
            SceneManager::GetInstance()->CacheChangeScene(SCENE_TYPE::SCENE_0F);
        }
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
}

MainScene::~MainScene()
{
    if (monster != nullptr) {
        delete monster;
    }
}