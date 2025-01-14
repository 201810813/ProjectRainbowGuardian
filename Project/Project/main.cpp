#include "pch.h"
#include "ConsoleLayout.h"
#include "GameManager.h"
#include "KeyManager.h"
#include "SceneManager.h"

BOOL WINAPI ConsoleHandler(DWORD signal) {
	if (signal == CTRL_CLOSE_EVENT) {
		
		GameManager::GetInstance()->EndGame();

		return TRUE; // 시스템에 신호를 처리했음을 알림
	}
	return FALSE;
}

int main()
{
	if (!SetConsoleCtrlHandler(ConsoleHandler, TRUE))

	SetConsoleOutputCP(CP_UTF8);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	system("mode con | title RainbowGuardian");

	GameManager::GetInstance()->Initialize();

	bool bonce = false;
	bool is_enter = false;

	while (!GameManager::GetInstance()->IsGameEnd()){
		GameManager::GetInstance()->tick();

		//테스트용 코드
		//if (IS_TAP(LEFT)){WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::STAT);	}
		//if (IS_TAP(RIGHT)){WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 6, 25);}

		if (IS_TAP(ENTER)) { GameManager::GetInstance()->EndGame(); } //게임 종료
		GameManager::GetInstance()->render();
	}
	return 0;
}