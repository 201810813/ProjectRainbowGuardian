#include "pch.h"
#include "EndingScene.h"
#include "ConsoleLayout.h"
#include "TimeManager.h"
#include "SoundManager.h"

EndingScene::EndingScene()
    : AccTime(0.f)
    , currentLineIndex(0)
{
}

EndingScene::~EndingScene()
{
}

void EndingScene::makeLayout()
{
    // 엔딩씬 전용 레이아웃 생성
    // 좌표(0,1), 크기(28, 119)는 팀 내 콘솔 레이아웃 규칙에 맞춰 사용
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::DRAW, 0, 1, 28, 119);
}

void EndingScene::begin()
{
    SoundManager::GetInstance()->PlayMusic("Ending_BGM", 0, 0.05f, true);
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

    AccTime = 0.f;
    currentLineIndex = 0;  // 첫 번째 라인부터 시작
}

void EndingScene::tick()
{
    static bool isFirstCalled = false; // 첫 번째 호출 상태
    static bool isSecondCalled = false; // 두 번째 호출 상태
    static bool isThirdCalled = false;

    // 첫 1초 동안
    if (AccTime <= 1.f && !isFirstCalled)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::DRAW, "===============================", true, 0, TEXT_COLOR_TYPE::SKY));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::DRAW, "      🌈RAINBOW GUARDIAN", true, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::DRAW, "        - END CREDITS -", true, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::DRAW, "===============================", true, 0, TEXT_COLOR_TYPE::SKY));
        isFirstCalled = true;
    }

    // 콘솔에 표시할 엔딩 크레딧 텍스트 목록
    static vector<string> credits = {
        "",
        "[ 팀원 및 역할 ]",
        "> Lead Programmer : 지성현",
        "   - 프로젝트 일정 관리 (Schedule Management)",
        "   - 기술적 이슈 해결 및 지원 (Technical Issue Resolution & Support)",
        "   - 게임 구조 설계 및 구현 (Game Engine Design & Implementation)",
        "   - 씬 구조 설계 (Scene Progression Configuration)",
        "   - 애니메이션 시스템 구현 (Animation System Development)",
        "   - 사운드 추가 및 관리 (Sound Integration & Management)",
        "",
        "> Game Designer & Developer : 차정민",
        "   - 프로젝트 컨셉 설계 및 스토리 개발 (Game Concept & Story Design, including dialogues)",
        "   - 맵 시스템 구현 (Map System Implementation)", 
        "   - 씬(맵) 클래스 개발: 배틀 씬 (1F ~ 7F, Final) (Battle Scene Classes), 상점 씬, 제단 씬 (Shop and Altar Scenes)",
        "   - 맵 아이콘 시각화 및 표현 (Map Icon Visualization)",
        "   - 게임 BGM 작편곡 (Game BGM Composition)",
        "   - 효과음 제작 (Sound Effect Creation)",
        "",
        "> Game Systems Developer : 지승현",
        "   - 몬스터 설계 및 구현 (Monster Design & Implementation)",
        "   - 몬스터 드랍아이템 구현 (Monster Drop Item System)",
        "   - 전투 상호작용 설계 및 구현 (Battle Logic Design & Implementation)",
        "   - 아이템 및 인벤토리 시스템 구현 (Item & Inventory System)",
        "   - 상점 기능 구현 (Shop Logic)",
        "",
        ">  Gameplay Developer & ASCII Artist : 김동근",
        "   - 플레이어 클래스 설계 및 구현 (Player Class Design & Implementation)",
        "   - 컬러 텍스트 출력 구현 (Color Text Output)",
        "   - 아스키 코드 활용한 배경 제작 (Background Design Using ASCII Art)",
        "",
        "[ 개발 환경 ]",
        "C++ / Visual Studio 2022 / FMOD",
        "개발 기간 : 2025.01.10 ~ 2025.01.16",
        "일정 관리 : 노션, 슬랙",
        "",
        "모든 색을 되찾아 주셔서 감사합니다!",
        "게임이 종료되었습니다..."
    };

    // 1) 매 프레임마다 시간 누적
    AccTime += TimeManager::GetInstance()->GetDeltaTime();

    // 2) 한 줄씩 출력할 시간 간격
    float lineDelay = 1.0f;

    // 3) currentLineIndex가 전체 라인 수를 넘어가지 않으면, 일정 간격마다 새로운 줄을 출력
    if (currentLineIndex < credits.size())
    {
        if (AccTime >= lineDelay)
        {
            // 현재 라인 출력
            WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::DRAW, credits[currentLineIndex], true));
            // 인덱스 & 시간 갱신
            currentLineIndex++;
            AccTime = 0.f;
        }
    }
    else
    {
        // 모든 줄을 다 출력한 상태...
        // 필요하다면 이후 로직(씬 전환, 자동 종료 등)을 작성
        // 예) 특정 시간이 지나면 타이틀로 돌아간다던가, 프로그램 종료 메시지 등
    }
}
