#include "pch.h"
#include "ConsoleLayout.h"
#include "GameManager.h"
#include "KeyManager.h"

#include "Player.h"
#include "MRedWolf.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	system("mode con | title RainbowGuardian");

	GameManager::GetInstance()->Initialize();

	bool bonce = false;
	bool is_enter = false;
	while (!GameManager::GetInstance()->IsGameEnd())
	{
		GameManager::GetInstance()->tick();

		if (IS_TAP(LEFT))
		{
			WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::STAT);
		}
		if (IS_TAP(RIGHT))
		{
			WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 6, 25);
		}

		
		if (!bonce)
		{
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "붉은 방", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::RED));
			FMessageParam MessageParam;
			MessageParam.TargetLayout = LAYOUT_TYPE::STAT;
			MessageParam.Message = "😀최강노루😀";
			MessageParam.LineIndex = 0;
			MessageParam.TextColor = TEXT_COLOR_TYPE::WHITE;
			MessageParam.BackGroundColor = BACKGROUND_COLOR_TYPE::BLACK;
			MessageParam.bDeleteLine = false;

			WriteManager::GetInstance()->AddLine(MessageParam);
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "HP       : 100  / 100", false, 1, TEXT_COLOR_TYPE::GREEN));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "EXP      : 1200 / 3000", false, 2, TEXT_COLOR_TYPE::SKY));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "ATK/SKD  : 10   /   5", false, 3, TEXT_COLOR_TYPE::RED));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "SDE/DEF  : 5%   /   8", false, 4, TEXT_COLOR_TYPE::BLUE_INENSITY));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "LUK      : 10%", false, 5, TEXT_COLOR_TYPE::ORANGE));

			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "06 [ψ]", false, 0, TEXT_COLOR_TYPE::GRAY));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "05 [δ]", false, 1, TEXT_COLOR_TYPE::GRAY));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "04 [θ]", false, 2, TEXT_COLOR_TYPE::GRAY));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "03 [ξ]", false, 3, TEXT_COLOR_TYPE::GRAY));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "02 [π]", false, 4, TEXT_COLOR_TYPE::GRAY));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "01 [χ]", false, 5, TEXT_COLOR_TYPE::RED));

			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "아.. 코딩 재밌다..", false, 0, TEXT_COLOR_TYPE::ORANGE));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "근데.. 머리 아프다...", false, 1, TEXT_COLOR_TYPE::ORANGE));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "또 새벽 늦게까지 코딩하다가 잤다..", false, 2, TEXT_COLOR_TYPE::ORANGE));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "근데, 기능 구현도 아직 다 안나왔다..", false, 3, TEXT_COLOR_TYPE::ORANGE));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "구조도 아름답지 않다..", false, 4, TEXT_COLOR_TYPE::ORANGE));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "아아아아아아ㅏ아아아아아아아아아ㅏㅇ아ㅏ아", false, 5, TEXT_COLOR_TYPE::ORANGE));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, " ", false, 6, TEXT_COLOR_TYPE::ORANGE));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "어쩌지....?", false, 7, TEXT_COLOR_TYPE::ORANGE));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "머리가 굳었ㄸ..ㅏ... 안써진다아..", false, 8, TEXT_COLOR_TYPE::ORANGE));

			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "^^ㅎㅎㅎㅎㅎㅎ", true, 8, TEXT_COLOR_TYPE::ORANGE));

			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[1. 빠르게 키 매니저를 만든다.]", false, 0, TEXT_COLOR_TYPE::ORANGE));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[2. readconsole을 사용한다.]", false, 1, TEXT_COLOR_TYPE::ORANGE));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[3. 튜터님.. 헬프미....]", false, 2, TEXT_COLOR_TYPE::ORANGE));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[4. 느아앙.. 살류...]", false, 3, TEXT_COLOR_TYPE::ORANGE));
			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[5. 그냥 악으로 버틴다.]", false, 4, TEXT_COLOR_TYPE::ORANGE));

			WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::INPUT, "입력 : ", false, 0, TEXT_COLOR_TYPE::SKY));
			bonce = true;
		}
		
		GameManager::GetInstance()->render();

		if (IS_TAP(ENTER))
		{
		GameManager::GetInstance()->EndGame();
		}
	}

	return 0;
}