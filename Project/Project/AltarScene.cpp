//AltarScene.cpp
#include "pch.h"
#include "AltarScene.h"
#include "ConsoleLayout.h" // 콘솔 레이아웃 관련
#include "Player.h" // 플레이어 정보 관리
#include "SceneManager.h"
#include "KeyManager.h" // 키 입력 처리 관련 추가
#include "SoundManager.h"

#include <sstream>

AltarScene::AltarScene()
    :RecurveryOnce(false)
{
	CursorPos = 0;
}

AltarScene::~AltarScene() {
}

void AltarScene::makeLayout(){
    
    // Title Layout (제단 제목 설정)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 119);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "제단", false, 0, TEXT_COLOR_TYPE::BLACK, BACKGROUND_COLOR_TYPE::WHITE));

    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 9, 25);

    // Map Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 8);
    string output = "";
    if (GetFloorNumber() < 10)
    {
        output += "0";
    }
    output += to_string(GetFloorNumber());
    output += " [⛲]";
    int idx = 8 - (GetFloorNumber() % 9);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, output, false, idx, TEXT_COLOR_TYPE::GRAY));


    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 13, 9, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "어디선가 성스러운 기운이 느껴집니다...", true, 1, TEXT_COLOR_TYPE::SKY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "골드 100을 봉양하면 최대 체력으로 회복됩니다.", true, 2, TEXT_COLOR_TYPE::SKY_INENSITY));

    // BACKGROUND
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⢿⣿⣿⣿⡿      ⢿⣿⣿⣿⡿                                             ⢿⣿⣿⣿⡿      ⢿⣿⣿⣿⡿", false, 0));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, " ⣿⣿⣿        ⣿⣿⣿ ⠀⠀     ⠀  ⠀  ⠀⠀⠀⠀⠀⡴⠋⠳⡄⠀⠀⠀	                  ⣿⣿⣿        ⣿⣿⣿", false, 1));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, " ⣿⣿⣿        ⣿⣿⣿⠀⠀      ⠀ ⠀   ⠀⠀⢀⣤⣤⣹⣤⣴⣣⣤⣄⡀⠀                    ⣿⣿⣿        ⣿⣿⣿", false, 2));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, " ⣿⣿⣿        ⣿⣿⣿⠀⠀           ⠀⣠⠞⢉⡄⠀⣟⠀⠈⡧⠀⣀⠙⢦⡀                   ⣿⣿⣿        ⣿⣿⣿", false, 3));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, " ⣿⣿⣿        ⣿⣿⣿⠀          ⠀⠀⠀⠙⠶⢯⣤⠄⣗⠀⠀⡯⢠⣬⠷⠞⠃⠀⠀                 ⣿⣿⣿        ⣿⣿⣿", false, 4));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, " ⣿⣿⣿        ⣿⣿⣿⠀⠀        ⠀  ⠀⠀⠀⠀⠈⠳⡗⠀⠀⢿⠚⠁⠀⠀                    ⣿⣿⣿        ⣿⣿⣿", false, 5));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, " ⣿⣿⣿        ⣿⣿⣿⠀⠀     ⠀  ⠀⠀    ⠀⠀⣸⠁⠀⠀⠸⡆⠀⠀ 	                  ⣿⣿⣿        ⣿⣿⣿", false, 6));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, " ⣿⣿⣿        ⣿⣿⣿⠀     ⠀⠀ ⠀    ⠀⠀⠀⢀⣏⢘⢛⢛⢛⢷⠀⠀                    ⠀⣿⣿⣿        ⣿⣿⣿", false, 7));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⣾⣿⣿⣿⣷      ⣾⣿⣿⣿⣷⠀     ⠀⠀⠀⠀    ⠀⠀⣏⣉⣉⣉⣉⣉⣉⡇                     ⣾⣿⣿⣿⣷      ⣾⣿⣿⣿⣷", false, 8));

    // 선택지 추가
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 24, 5, 60);
    UpdateSelectLayout();

    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::DRAW, 61, 13, 16, 58);

}

void AltarScene::begin() {
    SoundManager::GetInstance()->PlayMusic("AltarEnter", 1, 0.5, true);
    WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::MONSTER_STAT_UI);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::MONSTER_STAT_UI);
    makeLayout();
}

void AltarScene::tick()
{
    UpdateStatLayout();

    if (IS_TAP(UP)) // 커서를 위로 이동
    {
        SoundManager::GetInstance()->PlayMusic("SelectCursor", 1, 1.f, true);
        CursorPos = (CursorPos > 0) ? CursorPos - 1 : 1; // 0에서 1로 순환
        WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
    }
    else if (IS_TAP(DOWN)) // 커서를 아래로 이동
    {
        SoundManager::GetInstance()->PlayMusic("SelectCursor", 1, 1.f, true);
        CursorPos = (CursorPos < 1) ? CursorPos + 1 : 0; // 1에서 0으로 순환
        WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
    }

    if (IS_TAP(ENTER)) // 선택 확정
    {
        SoundManager::GetInstance()->PlayMusic("MoveCursor", 1, 0.06f, true);
        if (CursorPos == 0) // 봉양
        {
            handleOffer();
        }
        else if (CursorPos == 1) // 나가기
        {
            handleExit();
        }
    }

    UpdateSelectLayout();
}

void AltarScene::handleOffer()
{
	if (!RecurveryOnce) // 100골드 소모
	{
        if (Player::getInstance()->SpendGold(100))
        {
			SoundManager::GetInstance()->PlayMusic("UseCoin_0", 1, 0.6f, true);
            SoundManager::GetInstance()->PlayMusic("Holy_Spell", 1, 0.1f, true);
            Player::getInstance()->SetCurrentHP(Player::getInstance()->GetMaxHP()); // 최대 체력으로 회복
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "성스러운 기운이 당신을 감싸 체력이 모두 회복되었습니다.", true, 3, TEXT_COLOR_TYPE::WHITE));
        }
        else
        {
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "어디선가 안타까워하는 시선이 느껴지는 것만 같군요..", true, 3, TEXT_COLOR_TYPE::WHITE));
        }
		RecurveryOnce = true;
	}
	else
	{
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "더 이상 여신상이 반응하지 않습니다.", true, 3, TEXT_COLOR_TYPE::WHITE));
	}
}

void AltarScene::handleExit() // 나가기
{
    SceneManager::GetInstance()->CacheChangeScene(SCENE_TYPE::RANDOM);
}

void AltarScene::UpdateSelectLayout()
{
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
}

void AltarScene::UpdateStatLayout()
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