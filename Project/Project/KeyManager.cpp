#include "pch.h"
#include "KeyManager.h"
#include <conio.h>

shared_ptr<KeyManager> KeyManager::Instance = nullptr;

int KeyArray[(UINT)KEY_TYPE::END] =
{
	VK_UP,
	VK_LEFT,
	VK_DOWN,
	VK_RIGHT,

	VK_RETURN,
};


void KeyManager::Initialize()
{
	for (int i = 0; i < (UINT)KEY_TYPE::END; ++i)
	{
		m_KeyInfo.push_back(Key_Info{ (KEY_TYPE)i, KEY_STATE::NONE, false });
	}
}

void KeyManager::tick()
{
	if (_kbhit())
	{
		for (int i = 0; i < (UINT)KEY_TYPE::END; ++i)
		{
			if (GetAsyncKeyState(KeyArray[i]) & 0x8000)
			{
				if (m_KeyInfo[i].PrevPress)
				{
					m_KeyInfo[i]._KState = KEY_STATE::PRESS;
				}
				else
				{
					m_KeyInfo[i]._KState = KEY_STATE::TAP;
				}
				m_KeyInfo[i].PrevPress = true;
			}
			else
			{
				if (m_KeyInfo[i].PrevPress)
				{
					m_KeyInfo[i]._KState = KEY_STATE::RELEASE;
				}
				else
				{
					m_KeyInfo[i]._KState = KEY_STATE::NONE;
				}
				m_KeyInfo[i].PrevPress = false;
			}
		}
	}

	else
	{
		for (UINT i = 0; i < (UINT)KEY_TYPE::END; ++i)
		{
			if (KEY_STATE::TAP == m_KeyInfo[i]._KState || KEY_STATE::PRESS == m_KeyInfo[i]._KState)
				m_KeyInfo[i]._KState = KEY_STATE::RELEASE;
			else if (KEY_STATE::RELEASE == m_KeyInfo[i]._KState)
				m_KeyInfo[i]._KState = KEY_STATE::NONE;

			m_KeyInfo[i].PrevPress = false;
		}
	}

	/*HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	if (hInput == INVALID_HANDLE_VALUE) {
		std::cerr << "Error: Unable to get input handle.\n";
		return;
	}

	INPUT_RECORD inputRecord;
	DWORD eventsRead;

	if (ReadConsoleInput(hInput, &inputRecord, 1, &eventsRead)) {
		if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown)
		{
			for (int i = 0; i < (UINT)KEY_TYPE::END; ++i)
			{
				if (GetAsyncKeyState(KeyArray[i]) & 0x8000)
				{
					if (m_KeyInfo[i].PrevPress)
					{
						m_KeyInfo[i]._KState = KEY_STATE::PRESS;
					}
					else
					{
						m_KeyInfo[i]._KState = KEY_STATE::TAP;
					}
					m_KeyInfo[i].PrevPress = true;
				}
				else
				{
					if (m_KeyInfo[i].PrevPress)
					{
						m_KeyInfo[i]._KState = KEY_STATE::RELEASE;
					}
					else
					{
						m_KeyInfo[i]._KState = KEY_STATE::NONE;
					}
					m_KeyInfo[i].PrevPress = false;
				}
			}
		}

		else
		{
			for (UINT i = 0; i < (UINT)KEY_TYPE::END; ++i)
			{
				if (KEY_STATE::TAP == m_KeyInfo[i]._KState || KEY_STATE::PRESS == m_KeyInfo[i]._KState)
					m_KeyInfo[i]._KState = KEY_STATE::RELEASE;
				else if (KEY_STATE::RELEASE == m_KeyInfo[i]._KState)
					m_KeyInfo[i]._KState = KEY_STATE::NONE;

				m_KeyInfo[i].PrevPress = false;
			}
		}
	}*/
}
