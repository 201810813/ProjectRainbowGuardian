#include "pch.h"
#include "ScriptManager.h"
#include "GameManager.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	GameManager::GetInstance()->Initialize();

	bool is_enter = false;
	while (!GameManager::GetInstance()->IsGameEnd())
	{
		if (!is_enter)
		{
			ScriptManager::GetInstance()->ClearScreen();
			ScriptManager::GetInstance()->PrintRoomTitle("���� ��", TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::RED);
			ScriptManager::GetInstance()->PrintScript("���� !!! �����̴�!", TEXT_COLOR_TYPE::RED, BACKGROUND_COLOR_TYPE::WHITE);
			cout << "\n";
			ScriptManager::GetInstance()->PintLine(TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::BLUE);
			cout << "\n�Է� >";
			cin.ignore();
			is_enter = true;
		}
		else
		{
			string a;
			cin >> a;

			if (!a.empty())
			{
				if (a == "end")
				{
					GameManager::GetInstance()->EndGame();
				}
				is_enter = false;
			}
			
		}
		
	}

	return 0;
}