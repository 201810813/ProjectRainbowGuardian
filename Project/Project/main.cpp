#include "pch.h"
#include "ScriptManager.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ScriptManager::GetInstance();

	ScriptManager::GetInstance()->PrintScript("나는 !!! 빨강이다!", TEXT_COLOR_TYPE::RED, BACKGROUND_COLOR_TYPE::WHITE);
	
	ScriptManager::Destroy();

	return 0;
}