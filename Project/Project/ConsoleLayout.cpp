#include "pch.h"
#include "ConsoleLayout.h"
#include "KeyManager.h"

// ===========================================================
//                        WriteManager
// ===========================================================

shared_ptr<WriteManager> WriteManager::Instance = nullptr;

void WriteManager::MoveCursor(short x, short y)
{
    // 콘솔 출력 핸들을 가져옵니다.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Unable to get console handle.\n";
        return;
    }

    // 커서 위치 설정
    COORD coord = { x, y };  // x: 가로, y: 세로 위치
    if (!SetConsoleCursorPosition(hConsole, coord)) {
        std::cerr << "Error: Unable to set cursor position.\n";
    }
}

void WriteManager::MakeLayout(LAYOUT_TYPE LayoutType, int Left, int Top, int Height, int Width)
{
    FConsoleLayout ConsoleLayout(Left, Top, Height, Width);

    ConsoleLayoutContainer.MakeLayout(LayoutType, ConsoleLayout);
}

void WriteManager::MakeAllLayout()
{
    // Title Layout
    MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);

    // Stat Layout
    MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 6, 25);

    // Map Layout
    MakeLayout(LAYOUT_TYPE::MAP, 110, 2, 6, 7);

    // Story Layout
    MakeLayout(LAYOUT_TYPE::STORY, 0, 10, 9, 60);

    // Select Layout
    MakeLayout(LAYOUT_TYPE::SELECT, 0, 21, 5, 60);

    // Input
    MakeLayout(LAYOUT_TYPE::INPUT, 0, 28, 1, 60);
}

void WriteManager::ClearLayout(LAYOUT_TYPE TargetLayout)
{
    ConsoleLayoutContainer.clear(TargetLayout);
}

void WriteManager::ClearLayoutAllMessage(LAYOUT_TYPE TargetLayout)
{
    ConsoleLayoutContainer.ClearLayoutAllMessage(TargetLayout);
}

void WriteManager::AddLine(FMessageParam MessageParam)
{
    ConsoleLayoutContainer.AddLine(MessageParam);
}

void WriteManager::tick()
{
    ConsoleLayoutContainer.tick();
}

void WriteManager::render()
{
    ConsoleLayoutContainer.render();
}

void WriteManager::Initialize()
{
    // ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
     
    // 얘 없어도 되는데, 혹시 몰라서 남겨둠. ㅎㅎ
    //SetConsoleOutputCP(CP_UTF8);
    //SetConsoleCP(CP_UTF8);

    ConsoleLayoutContainer.Initialize();
    //MakeAllLayout();
}

void WriteManager::MoveMessageCursor(LAYOUT_TYPE TargetLayout, CURSOR_MOVE_TYPE CursorMoveType)
{
    ConsoleLayoutContainer.MoveMessageCursor(TargetLayout, CursorMoveType);
}

void WriteManager::ClearScreen()
{
    ConsoleLayoutContainer.ClearScreen();
}

void WriteManager::SwapBuffer()
{
    ConsoleLayoutContainer.SwapBuffer();
}





// ===========================================================
//                 FConsoleLayoutContainer
// ===========================================================

void FConsoleLayoutContainer::MoveCursor(short x, short y)
{
    // 콘솔 출력 핸들을 가져옵니다.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Unable to get console handle.\n";
        return;
    }

    // 커서 위치 설정
    COORD coord = { x, y };  // x: 가로, y: 세로 위치
    /*if (!SetConsoleCursorPosition(hConsole, coord)) {
        std::cerr << "Error: Unable to set cursor position.\n";
    }*/
    if (!SetConsoleCursorPosition(Console.HBuffer[Console.CurBufferIndex], coord)) {
        std::cerr << "Error: Unable to set cursor position.\n";
    }
}

void FConsoleLayoutContainer::SetConsoleColor(WORD color)
{
    //SetConsoleTextAttribute(ConsoleHandle, color);
    SetConsoleTextAttribute(Console.HBuffer[Console.CurBufferIndex], color);
}

string FConsoleLayoutContainer::OverwriteTitle(const string& Title)
{
    CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo;
    
    int LineCount = 0;
    // 콘솔 정보 가져오기
    if (GetConsoleScreenBufferInfo(Console.HConsole, &ConsoleInfo)) {
        // 콘솔 창의 가로 크기 계산
        LineCount = ConsoleInfo.srWindow.Right - ConsoleInfo.srWindow.Left + 1;
    }

    int spaceCount = 0;
    for (char ch : Title) {
        if (ch == ' ') {
            ++spaceCount;
        }
    }

    LineCount -= Title.length();
    string Line;
    for (int i = 0; i < LineCount / 2; ++i)
    {
        Line += "=";
    }

    if (spaceCount == 0)
    {
        spaceCount = 1;
    }

    for (int i = 0; i < spaceCount * 2; ++i)
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

    return output;
}

void FConsoleLayoutContainer::MakeLayoutBox(LAYOUT_TYPE LayoutType, FConsoleLayout& ConsoleLayout)
{
    SetConsoleColor((WORD) TEXT_COLOR_TYPE::GRAY | (WORD)BACKGROUND_COLOR_TYPE::BLACK);

    // ┌──────┐
    // │            │
    // │            │
    // └──────┘
    
    // LeftTop
    MoveCursor(ConsoleLayout.Left, ConsoleLayout.Top - 1);
    PrintMessage(L"┌");

    // RightTop
    MoveCursor(ConsoleLayout.Left + ConsoleLayout.Width, ConsoleLayout.Top - 1);
    PrintMessage(L"┐");

    // LeftBot
    MoveCursor(ConsoleLayout.Left, ConsoleLayout.Top + ConsoleLayout.Height);
    PrintMessage(L"└");

    // RightBot
    MoveCursor(ConsoleLayout.Left + ConsoleLayout.Width, ConsoleLayout.Top + ConsoleLayout.Height);
    PrintMessage(L"┘");

    // Up Line
    MoveCursor(ConsoleLayout.Left + 1, ConsoleLayout.Top - 1);
    
    wstring message(ConsoleLayout.Width - 1,L'─');
    PrintMessage(message);
    
    // Down Line
    MoveCursor(ConsoleLayout.Left + 1, ConsoleLayout.Top + ConsoleLayout.Height);
    PrintMessage(message);
    
    
    for (int i = 0; i < ConsoleLayout.Height; ++i)
    {
        // Left Line
        MoveCursor(ConsoleLayout.Left, ConsoleLayout.Top + i);
        std::wstring message = L"│";
        PrintMessage(message);
    
        MoveCursor(ConsoleLayout.Left + ConsoleLayout.Width, ConsoleLayout.Top + i);
        PrintMessage(message);
    }
}

void FConsoleLayoutContainer::PrintMessage(wstring message)
{
    DWORD written;
    WriteConsoleW(
        Console.HBuffer[Console.CurBufferIndex], // 현재 활성화된 버퍼 핸들
        message.c_str(),                        // 출력할 데이터
        static_cast<DWORD>(message.size()),     // 데이터 크기
        &written,                               // 실제로 출력된 크기
        NULL                                    // 비동기 처리 옵션 (동기식 처리)
    );
}

void FConsoleLayoutContainer::WriteUTF8ToConsole(const string& utf8Str)
{
    // UTF-8 -> UTF-16 변환
    int wstrSize = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, NULL, 0);
    if (wstrSize <= 0) {
        std::cerr << "Error: Failed to convert UTF-8 to UTF-16.\n";
        return;
    }

    // UTF-16 버퍼 할당
    wchar_t* wstr = new wchar_t[wstrSize];
    MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, wstr, wstrSize);

    // UTF-16 출력
    DWORD written;
    if (!WriteConsoleW(Console.HBuffer[Console.CurBufferIndex], wstr, wstrSize - 1, &written, NULL)) {
        std::cerr << "Error: Failed to write to console.\n";
    }

    // 메모리 해제
    delete[] wstr;
}

FConsoleLayoutContainer::~FConsoleLayoutContainer()
{
    if (nullptr != Console.HBuffer[0])
    {
        CloseHandle(Console.HBuffer[0]);
    }

    if (nullptr != Console.HBuffer[1])
    {
        CloseHandle(Console.HBuffer[1]);
    }
}

void FConsoleLayoutContainer::MakeLayout(LAYOUT_TYPE LayoutType, FConsoleLayout Layout)
{
    if (LayoutMap.find(LayoutType) == LayoutMap.end())
    {
        LayoutMap.insert({ LayoutType, Layout });
    }
}

void FConsoleLayoutContainer::clear(LAYOUT_TYPE TargetType)
{
    if (LayoutMap.find(TargetType) == LayoutMap.end())
        return;

    const FConsoleLayout& ConsoleLayout = LayoutMap.find(TargetType)->second;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (Console.HBuffer[Console.CurBufferIndex] == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Unable to get console handle.\n";
        return;
    }

    // 콘솔 정보 가져오기
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        std::cerr << "Error: Unable to get console buffer info.\n";
        return;
    }

    // 시작 위치 계산
    COORD startCoord = { static_cast<SHORT>(ConsoleLayout.Left), static_cast<SHORT>(ConsoleLayout.Top) };
    DWORD cellsToClear = ConsoleLayout.Width * ConsoleLayout.Height; // 지울 셀 개수
    DWORD cellsCleared;

    // 버퍼의 문자 지우기 (공백으로 채우기)
    if (!FillConsoleOutputCharacter(hConsole, ' ', cellsToClear, startCoord, &cellsCleared)) {
        std::cerr << "Error: Unable to clear console buffer.\n";
        return;
    }

    // 메세지 날리기
    LayoutMap.erase(LayoutMap.find(TargetType));
}

void FConsoleLayoutContainer::AddLine(FMessageParam MessageParam)
{
    if (LayoutMap.find(MessageParam.TargetLayout) != LayoutMap.end())
    {
         FConsoleLayout& ConsoleLayout = LayoutMap.find(MessageParam.TargetLayout)->second;
         if (MessageParam.bDeleteLine)
         {
             ConsoleLayout.Message.erase(ConsoleLayout.Message.begin());
             FStylizedString Temp;
             Temp.Message = MessageParam.Message;
             Temp.BackGroundColor = MessageParam.BackGroundColor;
             Temp.TextColor = MessageParam.TextColor;

             ConsoleLayout.Message.push_back(Temp);
         }
         else
         {
             if (MessageParam.TargetLayout == LAYOUT_TYPE::TITLE)
             {
                 ConsoleLayout.Message[MessageParam.LineIndex].Message = OverwriteTitle(MessageParam.Message);
             }
             else
             {
                 ConsoleLayout.Message[MessageParam.LineIndex].Message = MessageParam.Message;
             }
             ConsoleLayout.Message[MessageParam.LineIndex].TextColor = MessageParam.TextColor;
             ConsoleLayout.Message[MessageParam.LineIndex].BackGroundColor = MessageParam.BackGroundColor;
         }
    }
}

void FConsoleLayoutContainer::MoveMessageCursor(LAYOUT_TYPE TargetLayout, CURSOR_MOVE_TYPE CursorMoveType)
{
    // 해당 레이아웃이 없으면 리턴
    if (LayoutMap.find(TargetLayout) == LayoutMap.end())
        return;

    FConsoleLayout& ConsoleLayout = LayoutMap.find(TargetLayout)->second;
    
    switch (CursorMoveType)
    {
    case CURSOR_MOVE_TYPE::UP:
        if (ConsoleLayout.CurrentCursor + 1 > 0
            && ConsoleLayout.CurrentCursor + 1 < ConsoleLayout.Height)
        {
            ConsoleLayout.CurrentCursor++;

        }
        break;

    case CURSOR_MOVE_TYPE::DOWN:
        if (ConsoleLayout.CurrentCursor - 1 > 0
            && ConsoleLayout.CurrentCursor - 1 < ConsoleLayout.Height)
        {
            ConsoleLayout.CurrentCursor--;

        }

        break;

    default:
        break;
    }
}

void FConsoleLayoutContainer::ClearLayoutAllMessage(LAYOUT_TYPE TargetLayout)
{
    if (LayoutMap.find(TargetLayout) == LayoutMap.end())
        return;

    FConsoleLayout& ConsoleLayout = LayoutMap.find(TargetLayout)->second;

    for (int i = 0; i < ConsoleLayout.Message.size(); ++i)
    {
        ConsoleLayout.Message[i].Message.clear();
    }
   
}

void FConsoleLayoutContainer::render()
{   
    ClearScreen();

    map<LAYOUT_TYPE, FConsoleLayout>::iterator iter = LayoutMap.begin();
   
    for (; iter != LayoutMap.end(); ++iter)
    {
        if (iter->first != LAYOUT_TYPE::TITLE)
        {
            // 레이아웃 박스 그리기
            MakeLayoutBox(iter->first, iter->second);
        }

        for (int i = 0; i < iter->second.Message.size(); ++i)
        {
            if(iter->first == LAYOUT_TYPE::TITLE)
                MoveCursor(iter->second.Left, iter->second.Top + i);
            else
                MoveCursor(iter->second.Left + 1, iter->second.Top + i);

            // 색 설정
            SetConsoleColor((WORD)iter->second.Message[i].TextColor | (WORD)iter->second.Message[i].BackGroundColor);

            WriteUTF8ToConsole(iter->second.Message[i].Message);
        }
    }

    SwapBuffer();
}

void FConsoleLayoutContainer::tick()
{
    if (IS_TAP(UP))
    {
        WriteManager::GetInstance()->MoveMessageCursor(LAYOUT_TYPE::SELECT, CURSOR_MOVE_TYPE::UP);
    }
    else if (IS_TAP(DOWN))
    {
        WriteManager::GetInstance()->MoveMessageCursor(LAYOUT_TYPE::SELECT, CURSOR_MOVE_TYPE::DOWN);
    }


    // 입력 받기 임시
    //
    //
    /*static string str_Input;

    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    if (hInput == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Unable to get input handle.\n";
        return;
    }

    INPUT_RECORD inputRecord;
    DWORD eventsRead;

    if (ReadConsoleInput(hInput, &inputRecord, 1, &eventsRead)) {
        if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown) {
            if (inputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RETURN)
                str_Input.clear();
            else if (inputRecord.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
            {
                if (!str_Input.empty())
                    str_Input.pop_back();
            }
            else
                str_Input += inputRecord.Event.KeyEvent.uChar.AsciiChar;
        }
    }

    LayoutMap.find(LAYOUT_TYPE::INPUT)->second.Message[0].Message += str_Input;*/
}

void FConsoleLayoutContainer::Initialize()
{
    ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    Console.HConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Console.CurBufferIndex = 0;
    CONSOLE_CURSOR_INFO ConsoleCursorInfo{ 1, false };
    CONSOLE_SCREEN_BUFFER_INFO ConsoleScreenBufferInfo{ 0, };
    GetConsoleScreenBufferInfo(ConsoleHandle, &ConsoleScreenBufferInfo);
    Console.Rect.first = ConsoleScreenBufferInfo.dwSize.X;
    Console.Rect.second = ConsoleScreenBufferInfo.dwSize.Y;

    Console.HBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleScreenBufferSize(Console.HBuffer[0], ConsoleScreenBufferInfo.dwSize);
    SetConsoleWindowInfo(Console.HBuffer[0], TRUE, &ConsoleScreenBufferInfo.srWindow);
    SetConsoleCursorInfo(Console.HBuffer[0], &ConsoleCursorInfo);

    Console.HBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleScreenBufferSize(Console.HBuffer[1], ConsoleScreenBufferInfo.dwSize);
    SetConsoleWindowInfo(Console.HBuffer[1], TRUE, &ConsoleScreenBufferInfo.srWindow);
    SetConsoleCursorInfo(Console.HBuffer[1], &ConsoleCursorInfo);
}

void FConsoleLayoutContainer::ClearScreen()
{
    COORD pos{ 0, 0};
    DWORD dwWritten = 0;
    unsigned size = Console.Rect.second * Console.Rect.first;

    FillConsoleOutputCharacter(Console.HBuffer[Console.CurBufferIndex], ' ', size, pos, &dwWritten);
    SetConsoleCursorPosition(Console.HBuffer[Console.CurBufferIndex], pos);
}

void FConsoleLayoutContainer::SwapBuffer()
{
    SetConsoleActiveScreenBuffer(Console.HBuffer[Console.CurBufferIndex]);
    Console.CurBufferIndex = Console.CurBufferIndex ? 0 : 1;
}


// ConsoleLayout

bool FConsoleLayout::Is_CursorOutOfRange(int NewCurentCursorPos)
{
    bool ReturnValue = false;

    if (NewCurentCursorPos >= FrontCursor && NewCurentCursorPos <= BackCursor)
    {
        ReturnValue = true;
    }

    return ReturnValue;
}
