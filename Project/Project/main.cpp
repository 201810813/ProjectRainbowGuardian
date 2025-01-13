#include <iostream>
#include "pch.h"
#include "ConsoleLayout.h"
#include "GameManager.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	GameManager::GetInstance()->Initialize();
	/*while (true)
	{
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "���� ��", 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::RED));
		WriteManager::GetInstance()->render();
		WriteManager::GetInstance()->ClearScreen();
		WriteManager::GetInstance()->SwapBuffer();
	
	}*/

	bool is_enter = false;
	while (!GameManager::GetInstance()->IsGameEnd())
	{
		GameManager::GetInstance()->tick();

		//ScriptManager::GetInstance()->ClearScreen();
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "���� ��", 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::RED));
		FMessageParam MessageParam;
		MessageParam.TargetLayout = LAYOUT_TYPE::STAT;
		MessageParam.Message = "�ְ����";
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

		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "06 [��]", 0, TEXT_COLOR_TYPE::GRAY));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "05 [��]", 1, TEXT_COLOR_TYPE::GRAY));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "04 [��]", 2, TEXT_COLOR_TYPE::GRAY));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "03 [��]", 3, TEXT_COLOR_TYPE::GRAY));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "02 [��]", 4, TEXT_COLOR_TYPE::GRAY));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "01 [��]", 5, TEXT_COLOR_TYPE::RED));

		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "��.. �ڵ� ��մ�..", 0, TEXT_COLOR_TYPE::ORANGE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "�ٵ�.. �Ӹ� ������...", 1, TEXT_COLOR_TYPE::ORANGE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "�� ���� �ʰԱ��� �ڵ��ϴٰ� ���..", 2, TEXT_COLOR_TYPE::ORANGE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "�ٵ�, ��� ������ ���� �� �ȳ��Դ�..", 3, TEXT_COLOR_TYPE::ORANGE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "������ �Ƹ����� �ʴ�..", 4, TEXT_COLOR_TYPE::ORANGE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "�ƾƾƾƾƾƤ��ƾƾƾƾƾƾƾƾƤ����Ƥ���", 5, TEXT_COLOR_TYPE::ORANGE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, " ", 6, TEXT_COLOR_TYPE::ORANGE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "��¼��....?", 7, TEXT_COLOR_TYPE::ORANGE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "�Ӹ��� ������..��... �Ƚ����پ�..", 8, TEXT_COLOR_TYPE::ORANGE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "cin�� �� �� �ȸԴ°�...", 9, TEXT_COLOR_TYPE::ORANGE));

		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[1. ������ Ű �Ŵ����� �����.]", 0, TEXT_COLOR_TYPE::ORANGE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[2. readconsole�� ����Ѵ�.]", 1, TEXT_COLOR_TYPE::ORANGE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[3. Ʃ�ʹ�.. ������....]", 2, TEXT_COLOR_TYPE::ORANGE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[4. ���ƾ�.. ���...]", 3, TEXT_COLOR_TYPE::ORANGE));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[5. �׳� ������ ��ƾ��.]", 4, TEXT_COLOR_TYPE::ORANGE));


		GameManager::GetInstance()->render();

		//string a;
		//if (!is_enter)
		//{
		//	//ScriptManager::GetInstance()->ClearScreen();
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "���� ��", 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::RED));
		//	FMessageParam MessageParam;
		//	MessageParam.TargetLayout = LAYOUT_TYPE::STAT;
		//	MessageParam.Message = "�ְ����";
		//	MessageParam.LineIndex = 0;
		//	MessageParam.TextColor = TEXT_COLOR_TYPE::WHITE;
		//	MessageParam.BackGroundColor = BACKGROUND_COLOR_TYPE::BLACK;
		//	MessageParam.bDeleteLine = false;
		//
		//	WriteManager::GetInstance()->AddLine(MessageParam);
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "HP       : 100  / 100", 1, TEXT_COLOR_TYPE::GREEN));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "EXP      : 1200 / 3000", 2, TEXT_COLOR_TYPE::SKY));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "ATK/SKD  : 10   /   5", 3, TEXT_COLOR_TYPE::RED));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "SDE/DEF  : 5%   /   8", 4, TEXT_COLOR_TYPE::BLUE_INENSITY));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "LUK      : 10%", 5, TEXT_COLOR_TYPE::ORANGE));
		//
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "06 [��]", 0, TEXT_COLOR_TYPE::GRAY));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "05 [��]", 1, TEXT_COLOR_TYPE::GRAY));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "04 [��]", 2, TEXT_COLOR_TYPE::GRAY));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "03 [��]", 3, TEXT_COLOR_TYPE::GRAY));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "02 [��]", 4, TEXT_COLOR_TYPE::GRAY));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "01 [��]", 5, TEXT_COLOR_TYPE::RED));
		//
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "=========================���丮0=========================", 0, TEXT_COLOR_TYPE::ORANGE));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "=========================���丮1=========================", 1, TEXT_COLOR_TYPE::ORANGE));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "=========================���丮2=========================", 2, TEXT_COLOR_TYPE::ORANGE));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "=========================���丮3=========================", 3, TEXT_COLOR_TYPE::ORANGE));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "=========================���丮4=========================", 4, TEXT_COLOR_TYPE::ORANGE));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "=========================���丮5=========================", 5, TEXT_COLOR_TYPE::ORANGE));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "=========================���丮6=========================", 6, TEXT_COLOR_TYPE::ORANGE));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "=========================���丮7=========================", 7, TEXT_COLOR_TYPE::ORANGE));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "=========================���丮8=========================", 8, TEXT_COLOR_TYPE::ORANGE));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STORY, "=========================���丮9=========================", 9, TEXT_COLOR_TYPE::ORANGE));
		//
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "=========================������0=========================", 0, TEXT_COLOR_TYPE::ORANGE));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "=========================������1=========================", 1, TEXT_COLOR_TYPE::ORANGE));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "=========================������2=========================", 2, TEXT_COLOR_TYPE::ORANGE));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "=========================������3=========================", 3, TEXT_COLOR_TYPE::ORANGE));
		//	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "=========================������4=========================", 4, TEXT_COLOR_TYPE::ORANGE));
		//
		//	WriteManager::GetInstance()->render();
		//
		//	fflush(stdin); // 1.
		//	std::cin.clear();
		//	cin >> a;
		//
		//	is_enter = true;
		//}
		//else
		//{
		//	fflush(stdin); // 1.
		//	std::cin.clear();
		//	cin >> a;
		//
		//	if (!a.empty())
		//	{
		//		if (a == "end")
		//		{
		//			GameManager::GetInstance()->EndGame();
		//		}
		//		is_enter = false;
		//	}
		//	
		//}
		
	}

	return 0;
}