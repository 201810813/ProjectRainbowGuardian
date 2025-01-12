#pragma once

class ScriptManager
{
private:
	static shared_ptr<ScriptManager>	Instance;
	HANDLE								ConsoleHandle;
	WORD								ConsoleColor;

	ScriptManager() = default;
	ScriptManager(const ScriptManager& other) = delete;

	~ScriptManager()
	{

	}

	ScriptManager& operator = (const ScriptManager& other) = delete;

	static void Destroy(ScriptManager* InstancePtr)
	{
		delete InstancePtr;
	}

public:
	static shared_ptr<ScriptManager> GetInstance()
	{
		if (nullptr == Instance)
		{
			Instance = shared_ptr<ScriptManager>(new ScriptManager(), Destroy);
		}

		return Instance;
	}

	void Initialize()
	{
		ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	}

private:
	void SetConsoleColor(WORD color);

public:
	void PrintScript(string Script, TEXT_COLOR_TYPE TextColor = TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE BackGroundColor = BACKGROUND_COLOR_TYPE::BLACK);
	void ClearScreen() { system("cls"); }
	void PintLine(TEXT_COLOR_TYPE TextColor = TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE BackGroundColor = BACKGROUND_COLOR_TYPE::BLACK);
	void PrintRoomTitle(string Title, TEXT_COLOR_TYPE TextColor = TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE BackGroundColor = BACKGROUND_COLOR_TYPE::BLACK);
};