#include "pch.h"
#include "ScriptManager.h"

shared_ptr<ScriptManager> ScriptManager::Instance = nullptr;

void ScriptManager::SetConsoleColor(WORD color)
{
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(ConsoleHandle, color);
}

void ScriptManager::PrintScript(string Script, TEXT_COLOR_TYPE TextColor, BACKGROUND_COLOR_TYPE BackGroundColor)
{
	SetConsoleColor((WORD)TextColor | (WORD)BackGroundColor);
	cout << Script;

	SetConsoleColor((WORD)TEXT_COLOR_TYPE::WHITE | (WORD)BACKGROUND_COLOR_TYPE::BLACK);
}

void ScriptManager::PintLine(TEXT_COLOR_TYPE TextColor, BACKGROUND_COLOR_TYPE BackGroundColor)
{
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	int LineCount = 0;
	// 콘솔 정보 가져오기
	if (GetConsoleScreenBufferInfo(ConsoleHandle, &ConsoleInfo)) {
		// 콘솔 창의 가로 크기 계산
		LineCount = ConsoleInfo.srWindow.Right - ConsoleInfo.srWindow.Left + 1;
	}

	string Line;
	for (int i = 0; i < LineCount; ++i)
	{
		Line += "=";
	}

	Line += '\n';

	PrintScript(Line, TextColor, BackGroundColor);
}

void ScriptManager::PrintRoomTitle(string Title, TEXT_COLOR_TYPE TextColor, BACKGROUND_COLOR_TYPE BackGroundColor)
{
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
	int LineCount = 0;
	// 콘솔 정보 가져오기
	if (GetConsoleScreenBufferInfo(ConsoleHandle, &ConsoleInfo)) {
		// 콘솔 창의 가로 크기 계산
		LineCount = ConsoleInfo.srWindow.Right - ConsoleInfo.srWindow.Left + 1;
	}

	LineCount -= Title.length();
	string Line;
	for (int i = 0; i < LineCount / 2; ++i)
	{
		Line += "=";
	}

	string output = Line;
	output += Title;
	output += Line;

	if (0 != LineCount % 2)
	{
		output += "=";
	}

	output += '\n';

	PrintScript(output, TextColor, BackGroundColor);


}