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

	int							FrontCursor;
	int							BackCursor;
	int							CurrentCursor;

	FConsoleLayout(short _Left, short _Top, int height, int width)
		: Left(_Left)
		, Top(_Top)
		, Height(height)
		, Width(width)
		, FrontCursor(0)
		, BackCursor(0)
		, CurrentCursor(0)
	{
		Message.resize(height);
	}

	bool Is_CursorOutOfRange(int NewCurentCursorPos);
};

class FConsoleLayoutContainer
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
	void PrintMessage(wstring message);
	void WriteUTF8ToConsole(const string& utf8Str);

public:
	~FConsoleLayoutContainer();

public:
	void MakeLayout(LAYOUT_TYPE LayoutType, FConsoleLayout Layout);
	void clear(LAYOUT_TYPE TargetType);
	void AddLine(FMessageParam MessageParam);
	void MoveMessageCursor(LAYOUT_TYPE TargetLayout, CURSOR_MOVE_TYPE CursorMoveType);
	void ClearLayoutAllMessage(LAYOUT_TYPE TargetLayout);

	void render();
	void tick();

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
	void MakeAllLayout();

public:
	void MakeLayout(LAYOUT_TYPE LayoutType, int Left, int Top, int Height, int Width);
	void ClearLayout(LAYOUT_TYPE TargetLayout);
	void ClearLayoutAllMessage(LAYOUT_TYPE TargetLayout);
	void MoveLineUp(LAYOUT_TYPE TargetLayout, int LineCount) {};
	void AddLine(FMessageParam MessageParam);
	void MoveMessageCursor(LAYOUT_TYPE TargetLayout, CURSOR_MOVE_TYPE CursorMoveType);

	void Initialize();
	void tick();
	void render();


	void ClearScreen();
	void SwapBuffer();
};