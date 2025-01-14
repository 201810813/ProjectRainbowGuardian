#include "pch.h"
#include "KeyManager.h"

int Keyarr[(UINT)KEY_TYPE::END] =
{
	'W',
	'A',
	'S',
	'D',

	'O',
	'T',

	VK_UP,
	VK_LEFT,
	VK_DOWN,
	VK_RIGHT,

	VK_NUMPAD0,
	VK_NUMPAD1,
	VK_NUMPAD2,
	VK_NUMPAD3,

	VK_LBUTTON,

	VK_SPACE,
	VK_ESCAPE,
	VK_RETURN,
};


void KeyManager::Initialize()
{
}

void KeyManager::tick()
{
}
