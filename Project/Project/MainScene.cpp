//MainScene.cpp
#include "pch.h"
#include "MainScene.h"
#include "ConsoleLayout.h"

void MainScene::makeLayout()
{
	// WriteManager::GetInstance()->MakeLayout();

    // Title Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::TITLE, 0, 0, 1, 100);
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::TITLE, "붉은 분노의 층", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::RED));

    // Stat Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STAT, 0, 2, 8, 25);
    
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "컬러", false, 0, TEXT_COLOR_TYPE::WHITE, BACKGROUND_COLOR_TYPE::BLACK));  
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "❇️ 레벨     : 1", false, 1, TEXT_COLOR_TYPE::SKY, BACKGROUND_COLOR_TYPE::BLACK));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "⚡ EXP      : 0 / 100", false, 2, TEXT_COLOR_TYPE::SKY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🩸 HP       : 100 / 100", false, 3, TEXT_COLOR_TYPE::GREEN));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🗡️ ATK      : 10", false, 4, TEXT_COLOR_TYPE::RED));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🛡️ DEF      : 5%", false, 5, TEXT_COLOR_TYPE::BLUE_INENSITY));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "🍀 LUK      : 10%", false, 6, TEXT_COLOR_TYPE::ORANGE));
	WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::STAT, "💰 GOLD     : 0", false, 7, TEXT_COLOR_TYPE::ORANGE_INENSITY));

    // Map Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 9);

    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "08 [🐉]", false, 1, TEXT_COLOR_TYPE::GRAY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "07 [❔]", false, 2, TEXT_COLOR_TYPE::GRAY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "06 [❔]", false, 3, TEXT_COLOR_TYPE::GRAY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "05 [❔]", false, 4, TEXT_COLOR_TYPE::GRAY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "04 [❔]", false, 5, TEXT_COLOR_TYPE::GRAY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "03 [❔]", false, 6, TEXT_COLOR_TYPE::GRAY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "02 [❔]", false, 7, TEXT_COLOR_TYPE::GRAY));
    WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, "01 [⚔️]", false, 8, TEXT_COLOR_TYPE::RED));

    // Story Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::STORY, 0, 12, 9, 60);

    // Select Layout
    WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 23, 5, 60);
}

void MainScene::begin()
{
    makeLayout();
}

void MainScene::tick()
{
}

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}