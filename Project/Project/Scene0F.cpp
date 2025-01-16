#include "pch.h"
#include "Scene0F.h"
#include "ConsoleLayout.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "Player.h"
#include "Rtan.h"
#include "SoundManager.h"

void Scene0F::makeLayout()
{
    // Title Layout (0층 제목 설정)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "마을: 안전한 피난처", false, 0, TEXT_COLOR_TYPE::BLACK, BACKGROUND_COLOR_TYPE::WHITE));

    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 9, 25);

    // Map Layout
     WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 8);
	 string output = "";
     /*if (GetFloorNumber() < 10)
     {
         output += "0";
     }
     output += to_string(GetFloorNumber());
     output += " [🏠]";*/
     output = "00 [🏠]";
     WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, output, true, 0, TEXT_COLOR_TYPE::GRAY));

    // Story Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 13, 9, 60);
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "당신은 마을에 왔습니다.", false, 8));

    // BACKGROUND
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "                 ⠀⣠⢃⠢⠨⠱⡁⡀⠀      ⣇⠤⣸", false, 0));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀    ⠀⡘⡘⡐⡨⠨⠨⡐⠱⢄⠀      ⣇⠤⣸", false, 1));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⠀⠀⠀⠀⠀⠀⠀⠀⢐⠁⠢⠀   ⠈⠆⢆⢢⢡⣑⢨⢨⠜⠀    ⠀⠀ ⣇⠤⣸", false, 2));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⠀⠀⠀⠀⣄⡀⠀⠀⡐⢠⠁           	    ⣇⠤⣸", false, 3));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⠀⠀⠀⡜⠀⠀⠑⠄⡴⡂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	 ⠀  ⣇⠤⣸                ⡠⡤⠤⠤⠤⢄", false, 4));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⠀⠀⠀⠉⢩⠭⠍⠭⣛⠎⠍⡉⠉⠅⠀⠀⠀⠀⠀⠀⠀	    ⡇⣀⢸              ⣠⣊⣀⣈⣢⣀⡤⠤⠵⠤⢄", false, 5));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⣀⣀⣀⣀⣸⢨⠁⠌⡹⡀⣀⣈⣂⣇⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣏⣀⣹⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡇⢠⠤⣠⣊⣀⣈⣢⣀⣀⣀⣑⣄⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀", false, 6));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⠀⠀⠀⠀⢸⡀⣐⢁⣐⡈⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀          ⡔⠁⠈⢢             ⣇⣸⣀⡇⢠⠤⡄⢸ ⡤⠤⢤⢸", false, 7));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::BACKGROUND, "⡀⠄⠂⠢⠐⠑⠘⠂⠪⠊⠂⠂⠢⢄⢀⢀⢀⡀⣀⢀⢀⢀        ⡜      ⢣              ⣇⣸⣀⣇⣸⣀⣓⣒⣚⣸", false, 8));

    // Select Layout (선택지)
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 24, 5, 60);
    UpdateSelectLayout();


    //WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::DRAW);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::MONSTER_STAT_UI);


}

void Scene0F::begin()
{
    MainScene::begin();
	Player::getInstance()->GetMaxHP(); // 최대 체력
	CursorPos = 0;
    makeLayout();
}

void Scene0F::tick()
{
    if (IS_TAP(UP))
    {
        SoundManager::GetInstance()->PlayMusic("SelectCursor", 1, 1.f, true);
        CursorPos = (CursorPos > 0) ? CursorPos - 1 : 1; // 위로 이동
        WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
        UpdateSelectLayout();
    }
    else if (IS_TAP(DOWN))
    {
        SoundManager::GetInstance()->PlayMusic("SelectCursor", 1, 1.f, true);
        CursorPos = (CursorPos < 1) ? CursorPos + 1 : 0; // 아래로 이동
        WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::SELECT);
        UpdateSelectLayout();
    }

    if (IS_TAP(ENTER))
    {
        SoundManager::GetInstance()->PlayMusic("MoveCursor", 1, 0.06f, true);
        if (CursorPos == 0) // 다시 도전
        {
            GoTo1F();
        }
        else if (CursorPos == 1) // 게임 종료
        {
            Exit();
        }
    }
}

Scene0F::Scene0F() : CursorPos(0)
{
    MainScene::monster = new Rtan;
}

Scene0F::~Scene0F() {}

void Scene0F::GoTo1F()
{
    SceneManager::GetInstance()->CacheChangeScene(SCENE_TYPE::SCENE_1F); // 1층으로 이동
}

void Scene0F::Exit()
{
    exit(0); // 프로그램 종료
}

void Scene0F::UpdateSelectLayout()
{
    if (CursorPos == 0) {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [1. 탑으로!!!]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [2. 게임 종료]", false, 1, TEXT_COLOR_TYPE::WHITE));
    }
    else {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "     [1. 탑으로!!!]", false, 0, TEXT_COLOR_TYPE::WHITE));
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  > [2. 게임 종료]", false, 1, TEXT_COLOR_TYPE::WHITE));
    }
}