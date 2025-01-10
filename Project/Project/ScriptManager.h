#pragma once

class ScriptManager
{
private:
	static ScriptManager*	instance;
	WORD					ConsoleColor;

	ScriptManager()
		: ConsoleColor(0)
	{
		cout << "call";
	}

	~ScriptManager()
	{

	}

public:
	static ScriptManager* GetInstance()
	{
		if (nullptr == instance)
		{
			instance = new ScriptManager();
		}

		return instance;
	}

	static void Destroy()
	{
		if (nullptr != instance)
		{
			delete instance;
			instance = nullptr;
		}
	}

private:
	void SetConsoleColor(WORD color);

public:
	void PrintScript(string Script, TEXT_COLOR_TYPE TextColor = TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE BackGroundColor = BACKGROUND_COLOR_TYPE::BLACK);
};