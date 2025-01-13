#pragma once

struct FConsole
{
	HANDLE			HConsole;
	pair<int, int>	Rect;
	HANDLE			HBuffer[2];
	int				CurBufferIndex;

	FConsole()
		: HConsole(nullptr)
		, HBuffer{nullptr, }
		, CurBufferIndex(0)
	{

	}
};

struct FStylizedString
{
	string					Message;
	TEXT_COLOR_TYPE			TextColor = TEXT_COLOR_TYPE::WHITE;
	BACKGROUND_COLOR_TYPE	BackGroundColor = BACKGROUND_COLOR_TYPE::BLACK;
};

struct FConsoleLayout
{
	vector<FStylizedString>		Message;
	short						Left;
	short						Top;
	int							Height;
	int							Width;

	FConsoleLayout(short _Left, short _Top, int height, int width)
		: Left(_Left)
		, Top(_Top)
		, Height(height)
		, Width(width)
	{
		Message.resize(height);
	}
};

struct FConsoleLayoutContainer
{
private:
	map<LAYOUT_TYPE, FConsoleLayout>	LayoutMap;
	HANDLE								ConsoleHandle;
	FConsole							Console;

private:
	void MoveCursor(short x, short y);
	void SetConsoleColor(WORD color);
	
	string OverwriteTitle(const string& Title);
	void MakeLayoutBox(LAYOUT_TYPE LayoutType, FConsoleLayout& ConsoleLayout);
	void PrintMessage(string message);
	void PrintMessage(wstring message);

public:
	~FConsoleLayoutContainer();

public:
	void MakeLayout(LAYOUT_TYPE LayoutType, FConsoleLayout Layout);
	void clear(LAYOUT_TYPE TargetType);
	void AddLine(FMessageParam MessageParam);
	void render();
	void Initialize();


	void ClearScreen();
	void SwapBuffer();
};

class WriteManager
{
private:
	static shared_ptr<WriteManager>	Instance;
	FConsoleLayoutContainer			ConsoleLayoutContainer;

	WriteManager() = default;
	WriteManager(const WriteManager& other) = delete;

	~WriteManager()
	{

	}

	WriteManager& operator = (const WriteManager& other) = delete;

	static void Destroy(WriteManager* InstancePtr)
	{
		delete InstancePtr;
	}

public:
	static shared_ptr<WriteManager> GetInstance()
	{
		if (nullptr == Instance)
		{
			Instance = shared_ptr<WriteManager>(new WriteManager(), Destroy);
		}

		return Instance;
	}

private:
	void MoveCursor(short x, short y);

	void MakeLayout(LAYOUT_TYPE LayoutType, int Left, int Top, int Height, int Width);

	void MakeAllLayout();

public:

	void ClearLayout(LAYOUT_TYPE TargetLayout);

	void MoveLineUp(LAYOUT_TYPE TargetLayout, int LineCount) {};

	void AddLine(FMessageParam MessageParam);

	void render();

	void Initialize();


	void ClearScreen();
	void SwapBuffer();
};