#include "pch.h"
#include "EndingScene.h"
#include "ConsoleLayout.h"
#include "TimeManager.h"

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
    // 씬 전환 시, 사용 중인 레이아웃 클리어
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::TITLE);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::STAT);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::MAP);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::STORY);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::DRAW);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::SELECT);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::INPUT);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::BACKGROUND);
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
        "   - SetupEnvironment() -> ConsoleLayout, KeyManager, Animator, FMOD",
        "   - AnimeScene(ASCIIArt, IntroScene, 몬스터 애니메이션)",
        "",
        "> Game Designer & Scene Architect : 차정민",
        "   - SceneClass(SceneManager, Shop, Altar, 0F ~ 8F Scene, EndingScene)",
        "   - Concept(세계관 기획, 문서화), Design(아이콘, 컬러)", 
        "   - GameSound(BGM, 효과음)",
        "",
        "> Monster & Item Engineer : 지승현",
        "   - MosterClass(), ItemClass()",
        "   - BattleLogic()",
        "   - ImplementSystem(인벤토리 시스템, 회복 시스템)",
        "",
        ">  Player Logic & ASCII Artist : 김동근",
        "   - PlayerClass()",
        "   - DrawBackground(ASCIIStyle)",
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
