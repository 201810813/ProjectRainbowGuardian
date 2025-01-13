#include "pch.h"
#include "ConsoleLayout.h"
#include "GameManager.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	GameManager::GetInstance()->Initialize();

	bool is_enter = false;
	while (!GameManager::GetInstance()->IsGameEnd())
	{
		 //GameManager::GetInstance()->tick();
	
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
		 
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[1. ������ Ű �Ŵ����� �����.]", 0, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[2. readconsole�� ����Ѵ�.]", 1, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[3. Ʃ�ʹ�.. ������....]", 2, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[4. ���ƾ�.. ���...]", 3, TEXT_COLOR_TYPE::ORANGE));
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "[5. �׳� ������ ��ƾ��.]", 4, TEXT_COLOR_TYPE::ORANGE));
		 
		 WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::INPUT, "�Է� : ", 0, TEXT_COLOR_TYPE::SKY));
		 
		 GameManager::GetInstance()->tick();
		 
		 GameManager::GetInstance()->render();
	}

	return 0;
}