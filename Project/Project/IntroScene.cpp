﻿#include "pch.h"
#include "IntroScene.h"
#include "ConsoleLayout.h"
#include "TimeManager.h"
#include "KeyManager.h"
#include "GameManager.h"

void IntroScene::makeLayout()
{
	MakeIntro();
	MakeSelect();
}

void IntroScene::MakeIntro()
{
	WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 1, 28, 119);
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"    ⠀⠀   ⠀⠀⠀⠀⠀⠀⠀⢸⣿⠙⢻⣶⠀⢴⣟⠊⢳⡧⠀⣿⡂⢵⣟⠊⢳⡧⠀⣿⡎⠓⣷⣶⣿⠎⢳⣷⢼⣾⡄⢸⣾⡂⢰⣿⡀⠀⠀⠀⣾⡞⠑⠛⠎⣾⡧⠀⣷⡇⢰⣷⠋⢺⣷⠀⢷⡟⠘⣷⡇⠀⣿⡎⢓⣿⡆⣳⡇⢠⣷⠋⢚⣷⠀⣳⡟⠘⣳⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, 2));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"    ⠀⠀   ⠀⠀⠀⠀⠀⠀⠀⢸⣿⠴⣾⡛⠀⢸⡷⠤⢼⡯⠀⣿⡂⢽⣗⠀⢸⡯⠀⣿⡖⠦⣿⣹⣿⠅⢸⣿⣪⣿⠆⢸⣿⡂⢸⣿⡀⠀⠀⠀⣿⡏⠀⣤⡄⣿⣗⠀⣿⡏⢸⣿⠥⢴⣿⠀⣿⡷⢢⣿⠃⢀⣿⡇⠠⣿⡇⢾⡇⢨⣿⠤⠴⣿⠀⣽⡇⠀⢾⡧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, 3));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"    ⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⢸⣿⠀⢻⣿⣄⢸⣟⠀⢸⡯⢀⣿⡂⢽⣗⠀⢸⡯⢀⣿⣂⣠⢿⢽⣿⣅⣸⡿⢜⣿⣃⣸⢿⣂⡸⣿⡀⠀⠀⠀⣿⣏⣀⣿⡇⣿⣗⣀⣿⡇⢸⣿⠂⢨⣿⠀⣿⡇⠈⢿⣧⠀⣿⣇⣐⣿⡇⣻⡇⢰⣿⠀⠨⣿⡀⢾⡇⠀⣻⣗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, 4));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⢤⢔⠖⢰⢰⢢⢤⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 6));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡔⡎⠇⡃⡅⣆⣕⢼⢠⣕⢬⣘⠸⢹⢢⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 7));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢦⠃⣊⢔⡵⣫⠯⠓⣝⡸⣘⠎⠟⣮⡻⣦⣑⠜⢵⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 8));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠹⢐⡸⣎⠯⠊⠀⠀⢨⣯⡷⣷⣳⠀⠀⠉⢞⡵⣗⢅⢫⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 9));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠳⢁⢮⢞⠎⠀⠀⠀⠀⢸⡩⣻⡛⣭⠀⠀⠀⠀⠘⣽⣳⢅⢏⡦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 10));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡎⠇⡜⣵⡋⠀⣀⣴⣟⣿⣼⡫⣮⣗⡽⡽⣿⣤⡀⠀⠸⣺⣳⠨⣺⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 11));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡝⠄⢽⢮⠂⣠⣾⣿⣿⣷⣿⣝⣜⣕⣯⣾⣿⣿⣿⡀⠀⣟⡾⡌⣞⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 12));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢯⢈⠮⢏⣾⣻⣾⢿⣿⢿⣿⣷⣷⣿⣿⣿⣿⣟⣾⣯⣧⢳⣻⠠⣳⠅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 13));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢱⢑⣨⣾⣷⡿⣟⣧⣛⣿⣷⣟⢿⣻⢷⣷⡯⣾⣽⢿⢽⣾⡬⡸⠺⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 14));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣶⣶⣷⢶⣦⣤⣠⣀⡀⡀⣤⣰⣮⣗⢿⣿⣗⣿⣿⣻⡯⣶⢟⣿⣹⣿⣟⣾⣯⣿⢿⣿⣻⣿⣟⣧⢷⣦⣠⢀⣀⣀⣠⣤⣦⡶⣾⣶⡶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 15));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣷⣿⣿⣿⡿⣷⣿⣽⣷⣿⣿⡿⣯⣯⣿⡯⣾⣿⣻⣿⣿⢻⣿⣟⣟⢾⣻⡽⣿⣫⢿⣿⣽⣿⣾⢾⣿⣟⣟⣿⣿⣷⣿⣽⣿⣾⣿⣿⣿⣿⡿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 16));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⣿⢽⣿⣿⣿⣟⣯⣷⣿⣿⣯⣿⣫⣾⣿⣿⣿⣯⢿⣽⣾⢿⣽⣽⣽⢽⣽⣽⣯⢿⣿⣿⢷⣳⢻⢿⡻⣿⣾⣿⣽⣻⣿⣿⣷⣟⣿⣿⣟⣾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 17));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡾⣿⣿⠟⠛⠻⠑⠉⠟⠹⠛⣻⡎⣗⠑⠻⠟⠀⠘⠙⣻⣟⣿⣫⣟⣿⢿⣟⣯⣟⣾⠏⠁⠈⠺⠏⠛⣝⡻⢞⠛⠉⠫⠁⠙⠟⠙⢿⣽⣿⢯⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 18));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⢿⣯⣟⡁⠀⠀⠀⠀⠀⣀⡔⠊⠈⠀⠀⠀⠀⠀⠀⠀⠉⢹⠛⠛⠺⠿⠝⠚⢻⢿⡟⠓⠀⠀⠀⠀⠀⠈⠈⠸⢢⡄⡀⠀⠀⠀⠀⡘⣝⣾⡿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 19));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⣀⣤⡶⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠓⡶⣄⡀⠀⠈⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 20));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡳⠟⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠹⣷⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 21));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, MoveIndex + 22));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT,
		"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠂⠀⠂⠐⠀⠈⠠⠈⠀⡁⠈⠀⠂⠐⠀⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
		, false, 26));
}

void IntroScene::MakeSelect()
{
	WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 90, 13, 6, 20);
	if (0 == CursorPos)
	{
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  >    [시 작]", false, 1));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "       [종 료]", false, 4));
	}
	else if(1 == CursorPos)
	{
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "       [시 작]", false, 1));
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::SELECT, "  >    [종 료]", false, 4));
	}
}

void IntroScene::MoveCursor()
{
	if (IS_TAP(UP))
	{
		CursorPos = 0;
	}
	else if (IS_TAP(DOWN))
	{
		CursorPos = 1;
	}
}

void IntroScene::ActionSelect()
{
	if (0 == CursorPos)
	{
		// MainScene 전환 추가해주어야 한다.
	}
	else if (1 == CursorPos)
	{
		GameManager::GetInstance()->EndGame();
	}
}

void IntroScene::MoveSymbol()
{
	AccTime += TimeManager::GetInstance()->GetDeltaTime();

	if (!(AccTime >= 0.3f))
	{
		return;
	}
	else
	{
		if (!bMovereverse)
		{
			MoveIndex++;
			if (MoveIndex >= 3)
				bMovereverse = true;
		}
		else if (bMovereverse)
		{
			MoveIndex--;
			if (MoveIndex <= 0)
				bMovereverse = false;
		}

		AccTime = 0.f;
	}
}

void IntroScene::begin()
{
	makeLayout();
}

void IntroScene::tick()
{
	MoveCursor();
	if (IS_TAP(ENTER))
	{
		ActionSelect();
	}

	WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::STAT);
	MoveSymbol();
	makeLayout();

}

IntroScene::IntroScene()
	: AccTime(0.f)
	, MoveIndex(0)
	, bMovereverse(false)
	, CursorPos(0)
{
}

IntroScene::~IntroScene()
{
}