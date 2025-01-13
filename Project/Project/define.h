#pragma once
#include "pch.h"

enum class TEXT_COLOR_TYPE
{
	BLACK = 0,
	GRAY = FOREGROUND_INTENSITY,
	RED = FOREGROUND_RED,
	RED_INENSITY = FOREGROUND_RED | FOREGROUND_INTENSITY,
	ORANGE = FOREGROUND_RED | FOREGROUND_GREEN,
	ORANGE_INENSITY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	GREEN = FOREGROUND_GREEN,
	GREEN_INENSITY = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	SKY = FOREGROUND_GREEN | FOREGROUND_BLUE,
	SKY_INENSITY = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	BLUE = FOREGROUND_BLUE,
	BLUE_INENSITY = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	PURPLE = FOREGROUND_BLUE | FOREGROUND_RED,
	PURPLE_INENSITY = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY,

	WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,

	END
};

enum class BACKGROUND_COLOR_TYPE
{
	BLACK = 0,
	GRAY = BACKGROUND_INTENSITY,
	RED = BACKGROUND_RED,
	RED_INENSITY = BACKGROUND_RED | BACKGROUND_INTENSITY,
	ORANGE = BACKGROUND_RED | BACKGROUND_GREEN,
	ORANGE_INENSITY = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY,
	GREEN = BACKGROUND_GREEN,
	GREEN_INENSITY = BACKGROUND_GREEN | BACKGROUND_INTENSITY,
	SKY = BACKGROUND_GREEN | BACKGROUND_BLUE,
	SKY_INENSITY = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY,
	BLUE = BACKGROUND_BLUE,
	BLUE_INENSITY = BACKGROUND_BLUE | BACKGROUND_INTENSITY,
	PURPLE = BACKGROUND_BLUE | BACKGROUND_RED,
	PURPLE_INENSITY = BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY,

	WHITE = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,

	END
};

enum class LAYOUT_TYPE
{
	TITLE,
	STAT,
	MAP,
	STORY,
	SELECT,
	INPUT,

	END
};

struct FMessageParam
{
	LAYOUT_TYPE				TargetLayout = LAYOUT_TYPE::TITLE;
	std::string				Message = "";
	int						LineIndex = 0;
	bool					bDeleteLine = true;
	TEXT_COLOR_TYPE			TextColor = TEXT_COLOR_TYPE::WHITE;
	BACKGROUND_COLOR_TYPE	BackGroundColor = BACKGROUND_COLOR_TYPE::BLACK;

	FMessageParam() = default;
	FMessageParam(LAYOUT_TYPE LayoutType, std::string Msg, int idx = 0, TEXT_COLOR_TYPE TColorType = TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE BColorType = BACKGROUND_COLOR_TYPE::BLACK, bool DLine = true)
		: TargetLayout(LayoutType)
		, Message(Msg)
		, LineIndex(idx)
		, bDeleteLine(DLine)
		, TextColor(TColorType)
		, BackGroundColor(BColorType)
	{

	}
};

// ==================
// ==    KeyMgr    ==
// ==================

enum class KEY_TYPE
{
	W,
	A,
	S,
	D,

	O,
	T,

	UP,
	LEFT,
	DOWN,
	RIGHT,

	NUM_0,
	NUM_1,
	NUM_2,
	NUM_3,

	LBTN,

	SPACE,
	ESC,
	ENTER,

	END,
};

enum class KEY_STATE
{
	TAP,
	PRESS,
	RELEASE,
	NONE,
};

#define IS_TAP(key_type) CKeyMgr::CreateMgr()->GetKeyState(KEY_TYPE::key_type) == KEY_STATE::TAP
#define IS_PRESS(key_type) CKeyMgr::CreateMgr()->GetKeyState(KEY_TYPE::key_type) == KEY_STATE::PRESS
#define IS_RELEASE(key_type) CKeyMgr::CreateMgr()->GetKeyState(KEY_TYPE::key_type) == KEY_STATE::RELEASE
#define IS_NONE(key_type) CKeyMgr::CreateMgr()->GetKeyState(KEY_TYPE::key_type) == KEY_STATE::NONE

struct Key_Info
{
	KEY_TYPE		_KType;
	KEY_STATE		_KState;
	bool			PrevPress;
};