#include "pch.h"
#include "EndingScene.h"
#include "ConsoleLayout.h"
#include "TimeManager.h"


// ����  � �� �þƼ� �߰�,
// ���� ȯ���� ��Ž����
// C++, Viusal Sturio 2022, FMOD
// ���� �Ⱓ
// ��������
// ���, ���� ���..

void EndingScene::makeLayout()
{
	WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::DRAW, 0, 1, 28, 119);
}

void EndingScene::begin()
{
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::TITLE);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::STAT);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::MAP);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::STORY);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::DRAW);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::SELECT);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::INPUT);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::BACKGROUND);

    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::PROGRESS_BAR);
    WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::MONSTER_STAT_UI);
	makeLayout();
}

void EndingScene::tick()
{
    static bool isFirstCalled = false; // ù ��° ȣ�� ����
    static bool isSecondCalled = false; // �� ��° ȣ�� ����

    AccTime += TimeManager::GetInstance()->GetDeltaTime();

    if (AccTime <= 1.f && !isFirstCalled)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::DRAW, "", true));
        isFirstCalled = true; // ȣ��� ���·� ����
    }
    else if (AccTime > 1.f && AccTime <= 2.f && !isSecondCalled)
    {
        WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::DRAW, "", true));
        isSecondCalled = true; // ȣ��� ���·� ����
    }
}

EndingScene::EndingScene()
	: AccTime(0.f)
{
}

EndingScene::~EndingScene()
{
}