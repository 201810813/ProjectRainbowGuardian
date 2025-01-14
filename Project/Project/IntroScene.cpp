#include "pch.h"
#include "IntroScene.h"
#include "ConsoleLayout.h"

void IntroScene::makeLayout()
{
	// WriteManager::GetInstance()->MakeLayout();
	WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::SELECT, 0, 1, 20, 100);
}

void IntroScene::begin()
{
	makeLayout();
}

void IntroScene::tick()
{
}

IntroScene::IntroScene()
{
}

IntroScene::~IntroScene()
{
}