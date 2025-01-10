#include "pch.h"
#include "ScriptManager.h"

ScriptManager* ScriptManager::instance = nullptr;

void ScriptManager::SetConsoleColor(WORD color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void ScriptManager::PrintScript(string Script, TEXT_COLOR_TYPE TextColor, BACKGROUND_COLOR_TYPE BackGroundColor)
{
	SetConsoleColor((WORD)TextColor | (WORD)BackGroundColor);
	cout << Script;

}