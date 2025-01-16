#include "pch.h"
#include "EndingScene.h"
#include "ConsoleLayout.h"
#include "TimeManager.h"
#include "SoundManager.h"


// 누가  어떤 거 맡아서 했고,
// 개발 환경은 어떤거썼는지
// C++, Viusal Sturio 2022, FMOD
// 개발 기간
// 일정관리
// 노션, 슬랙 등등..

void EndingScene::makeLayout()
{
	WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::DRAW, 0, 1, 28, 119);
}

void EndingScene::begin()
{
    SoundManager::GetInstance()->PlayMusic("Ending_BGM", 0, 0.05, true);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::TITLE);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::STAT);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::MAP);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::STORY);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::DRAW);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::SELECT);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::INPUT);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::BACKGROUND);

    for (int i = 0; i < 7; ++i)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::PROGRESS_BAR, "   ", false, i, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::BLACK));
    }
    WriteManager::GetInstance()->render();
    WriteManager::GetInstance()->render();

    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::PROGRESS_BAR);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::MONSTER_STAT_UI);
	makeLayout();
}

void EndingScene::tick()
{
    static bool isFirstCalled = false; // 첫 번째 호출 상태
    static bool isSecondCalled = false; // 두 번째 호출 상태

    AccTime += TimeManager::GetInstance()->GetDeltaTime();

    if (AccTime <= 1.f && !isFirstCalled)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::DRAW, "", true));
        isFirstCalled = true; // 호출된 상태로 설정
    }
    else if (AccTime > 1.f && AccTime <= 2.f && !isSecondCalled)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::DRAW, "", true));
        isSecondCalled = true; // 호출된 상태로 설정
    }
}

EndingScene::EndingScene()
	: AccTime(0.f)
{
}

EndingScene::~EndingScene()
{
}