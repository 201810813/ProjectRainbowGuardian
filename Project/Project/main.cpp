#include "pch.h"
#include "ConsoleLayout.h"
#include "GameManager.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	string test = "string";
	wcout << u8"😀" << endl;
	wcout << u8"으아아아" << endl;
	wcout << L"느앙?" << endl;
	cout << test << endl;

	GameManager::GetInstance()->Initialize();

	bool is_enter = false;
	while (!GameManager::GetInstance()->IsGameEnd())
	{
		 //GameManager::GetInstance()->tick();
	
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "붉은 방", 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::RED));
		 FMessageParam MessageParam;
		 MessageParam.TargetLayout = LAYOUT_TYPE::STAT;
		 MessageParam.Message = "최강노루";
		 MessageParam.LineIndex = 0;
		 MessageParam.TextColor = TEXT_COLOR_TYPE::WHITE;
		 MessageParam.BackGroundColor = BACKGROUND_COLOR_TYPE::BLACK;
		 MessageParam.bDeleteLine = false;
		 
		 WriteManager::GetInstance()->AddLine(MessageParam);
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "HP       : 100  / 100", 1, TEXT_COLOR_TYPE::GREEN));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "EXP      : 1200 / 3000", 2, TEXT_COLOR_TYPE::SKY));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "ATK/SKD  : 10   /   5", 3, TEXT_COLOR_TYPE::RED));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "SDE/DEF  : 5%   /   8", 4, TEXT_COLOR_TYPE::BLUE_INENSITY));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "LUK      : 10%", 5, TEXT_COLOR_TYPE::ORANGE));
		 
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "06 [ψ]", 0, TEXT_COLOR_TYPE::GRAY));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "05 [δ]", 1, TEXT_COLOR_TYPE::GRAY));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "04 [θ]", 2, TEXT_COLOR_TYPE::GRAY));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "03 [ξ]", 3, TEXT_COLOR_TYPE::GRAY));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "02 [π]", 4, TEXT_COLOR_TYPE::GRAY));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "01 [χ]", 5, TEXT_COLOR_TYPE::RED));
		 
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "아.. 코딩 재밌다..", 0, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "근데.. 머리 아프다...", 1, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "또 새벽 늦게까지 코딩하다가 잤다..", 2, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "근데, 기능 구현도 아직 다 안나왔다..", 3, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "구조도 아름답지 않다..", 4, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "아아아아아아ㅏ아아아아아아아아아ㅏㅇ아ㅏ아", 5, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, " ", 6, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "어쩌지....?", 7, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "머리가 굳었ㄸ..ㅏ... 안써진다아..", 8, TEXT_COLOR_TYPE::ORANGE));
		 
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[1. 빠르게 키 매니저를 만든다.]", 0, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[2. readconsole을 사용한다.]", 1, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[3. 튜터님.. 헬프미....]", 2, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[4. 느아앙.. 살류...]", 3, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[5. 그냥 악으로 버틴다.]", 4, TEXT_COLOR_TYPE::ORANGE));
		 
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::INPUT, "입력 : ", 0, TEXT_COLOR_TYPE::SKY));
		 
		 GameManager::GetInstance()->tick();
		 
		 GameManager::GetInstance()->render();
	}

	return 0;
}