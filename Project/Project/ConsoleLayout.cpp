#include "pch.h"
#include "ConsoleLayout.h"

// ===========================================================
//                        WriteManager
// ===========================================================

shared_ptr<WriteManager> WriteManager::Instance = nullptr;

void WriteManager::MoveCursor(short x, short y)
{
    // �ܼ� ��� �ڵ��� �����ɴϴ�.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Unable to get console handle.\n";
        return;
    }

    // Ŀ�� ��ġ ����
    COORD coord = { x, y };  // x: ����, y: ���� ��ġ
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
    MakeLayout(LAYOUT_TYPE::STORY, 0, 10, 10, 60);

    // Select Layout
    MakeLayout(LAYOUT_TYPE::SELECT, 0, 22, 5, 60);
}

void WriteManager::ClearLayout(LAYOUT_TYPE TargetLayout)
{
    ConsoleLayoutContainer.clear(TargetLayout);
}

void WriteManager::AddLine(FMessageParam MessageParam)
{
    ConsoleLayoutContainer.AddLine(MessageParam);
}

void WriteManager::render()
{
    ConsoleLayoutContainer.render();
}

void WriteManager::Initialize()
{
    // ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleLayoutContainer.Initialize();
    MakeAllLayout();
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
    // �ܼ� ��� �ڵ��� �����ɴϴ�.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Unable to get console handle.\n";
        return;
    }

    // Ŀ�� ��ġ ����
    COORD coord = { x, y };  // x: ����, y: ���� ��ġ
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
    // �ܼ� ���� ��������
    if (GetConsoleScreenBufferInfo(ConsoleHandle, &ConsoleInfo)) {
        // �ܼ� â�� ���� ũ�� ���
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

    return output;
}

void FConsoleLayoutContainer::MakeLayoutBox(LAYOUT_TYPE LayoutType, FConsoleLayout& ConsoleLayout)
{
    SetConsoleColor((WORD) TEXT_COLOR_TYPE::GRAY | (WORD)BACKGROUND_COLOR_TYPE::BLACK);

    // ����������������
    // ��            ��
    // ��            ��
    // ����������������
    
    // LeftTop
    MoveCursor(ConsoleLayout.Left, ConsoleLayout.Top - 1);
    PrintMessage(L"��");

    // RightTop
    MoveCursor(ConsoleLayout.Left + ConsoleLayout.Width, ConsoleLayout.Top - 1);
    PrintMessage(L"��");

    // LeftBot
    MoveCursor(ConsoleLayout.Left, ConsoleLayout.Top + ConsoleLayout.Height);
    PrintMessage(L"��");

    // RightBot
    MoveCursor(ConsoleLayout.Left + ConsoleLayout.Width, ConsoleLayout.Top + ConsoleLayout.Height);
    PrintMessage(L"��");

    // Up Line
    MoveCursor(ConsoleLayout.Left + 1, ConsoleLayout.Top - 1);
    
    wstring message(ConsoleLayout.Width - 1,L'��');
    PrintMessage(message);
    
    // Down Line
    MoveCursor(ConsoleLayout.Left + 1, ConsoleLayout.Top + ConsoleLayout.Height);
    PrintMessage(message);
    
    
    for (int i = 0; i < ConsoleLayout.Height; ++i)
    {
        // Left Line
        MoveCursor(ConsoleLayout.Left, ConsoleLayout.Top + i);
        std::wstring message = L"��";
        PrintMessage(message);
    
        MoveCursor(ConsoleLayout.Left + ConsoleLayout.Width, ConsoleLayout.Top + i);
        PrintMessage(message);
    }
}

void FConsoleLayoutContainer::PrintMessage(string message)
{
    DWORD written;

    WriteConsole(
        Console.HBuffer[Console.CurBufferIndex], // ���� Ȱ��ȭ�� ���� �ڵ�
        message.c_str(),                        // ����� ������
        static_cast<DWORD>(message.size()),     // ������ ũ��
        &written,                               // ������ ��µ� ũ��
        NULL                                    // �񵿱� ó�� �ɼ� (����� ó��)
    );
}

void FConsoleLayoutContainer::PrintMessage(wstring message)
{
    DWORD written;

    WriteConsoleW(
        Console.HBuffer[Console.CurBufferIndex], // ���� Ȱ��ȭ�� ���� �ڵ�
        message.c_str(),                        // ����� ������
        static_cast<DWORD>(message.size()),     // ������ ũ��
        &written,                               // ������ ��µ� ũ��
        NULL                                    // �񵿱� ó�� �ɼ� (����� ó��)
    );
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
    const FConsoleLayout& ConsoleLayout = LayoutMap.find(TargetType)->second;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (Console.HBuffer[Console.CurBufferIndex] == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Unable to get console handle.\n";
        return;
    }

    // �ܼ� ���� ��������
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        std::cerr << "Error: Unable to get console buffer info.\n";
        return;
    }

    // ���� ��ġ ���
    COORD startCoord = { static_cast<SHORT>(ConsoleLayout.Left), static_cast<SHORT>(ConsoleLayout.Top) };
    DWORD cellsToClear = ConsoleLayout.Width * ConsoleLayout.Height; // ���� �� ����
    DWORD cellsCleared;

    // ������ ���� ����� (�������� ä���)
    if (!FillConsoleOutputCharacter(hConsole, ' ', cellsToClear, startCoord, &cellsCleared)) {
        std::cerr << "Error: Unable to clear console buffer.\n";
        return;
    }

    // ������ �Ӽ� �ʱ�ȭ (���� �ʱ�ȭ)
    //if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellsToClear, startCoord, &cellsCleared)) {
    //    std::cerr << "Error: Unable to reset console attributes.\n";
    //    return;
    //}

    // Ŀ���� ���� ��ġ�� �̵�
}

void FConsoleLayoutContainer::AddLine(FMessageParam MessageParam)
{
    if (LayoutMap.find(MessageParam.TargetLayout) != LayoutMap.end())
    {
        if (MessageParam.TargetLayout == LAYOUT_TYPE::TITLE)
        {
            LayoutMap.find(MessageParam.TargetLayout)->second.Message[MessageParam.LineIndex].Message = OverwriteTitle(MessageParam.Message);
        }
        else
        {
            LayoutMap.find(MessageParam.TargetLayout)->second.Message[MessageParam.LineIndex].Message = MessageParam.Message;
        }
        LayoutMap.find(MessageParam.TargetLayout)->second.Message[MessageParam.LineIndex].TextColor = MessageParam.TextColor;
        LayoutMap.find(MessageParam.TargetLayout)->second.Message[MessageParam.LineIndex].BackGroundColor = MessageParam.BackGroundColor;
    }
}

void FConsoleLayoutContainer::render()
{   
    ClearScreen();
    string a;
    cout << "�Է�";
    fflush(stdin);
    //cin.ignore();
    cin.clear();
    cin >> a;

    map<LAYOUT_TYPE, FConsoleLayout>::iterator iter = LayoutMap.begin();
   
    for (; iter != LayoutMap.end(); ++iter)
    {
        if (iter->first != LAYOUT_TYPE::TITLE)
        {
            // ���̾ƿ� �ڽ� �׸���
            MakeLayoutBox(iter->first, iter->second);
        }

        for (int i = 0; i < iter->second.Message.size(); ++i)
        {
            if(iter->first == LAYOUT_TYPE::TITLE)
                MoveCursor(iter->second.Left, iter->second.Top + i);
            else
                MoveCursor(iter->second.Left + 1, iter->second.Top + i);

            // �� ����
            SetConsoleColor((WORD)iter->second.Message[i].TextColor | (WORD)iter->second.Message[i].BackGroundColor);

            // ���� Ȱ��ȭ�� ���ۿ� ���
            DWORD written;
            std::string message = iter->second.Message[i].Message;

            WriteFile(
                Console.HBuffer[Console.CurBufferIndex], // ���� Ȱ��ȭ�� ���� �ڵ�
                message.c_str(),                        // ����� ������
                static_cast<DWORD>(message.size()),     // ������ ũ��
                &written,                               // ������ ��µ� ũ��
                NULL                                    // �񵿱� ó�� �ɼ� (����� ó��)
            );
        }
    }

    SwapBuffer();
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

    //GENERIC_READ
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

    // �ܼ� ȭ�� ��ü�� ���⸦ �־� �� ȭ��ó�� ����ϴ�.
    //FillConsoleOutputCharacter(Console.HConsole, '*', size, pos, &dwWritten);
    //SetConsoleCursorPosition(Console.HConsole, pos);

    FillConsoleOutputCharacter(Console.HBuffer[Console.CurBufferIndex], ' ', size, pos, &dwWritten);
    SetConsoleCursorPosition(Console.HBuffer[Console.CurBufferIndex], pos);
}

void FConsoleLayoutContainer::SwapBuffer()
{
    SetConsoleActiveScreenBuffer(Console.HBuffer[Console.CurBufferIndex]);
    Console.CurBufferIndex = Console.CurBufferIndex ? 0 : 1;
}