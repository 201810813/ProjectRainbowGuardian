//SceneManager.cpp
#include "pch.h"
#include "SceneManager.h"
#include "KeyManager.h" //키 입력 처리를 위해 추가
#include "ConsoleLayout.h"

shared_ptr<SceneManager> SceneManager::Instance = nullptr;

void SceneManager::Initialize()
{
	currentFloor = 0; // 시작은 1층
	changeScene(currentFloor); // 시작 씬은 IntroScene 또는 1층
}

void SceneManager::tick()
{
	// 키	입력 처리 (방향키 위 눌렀을 때 씬 변경)
	if (IS_TAP(UP)) 
	{
		if (currentFloor<8) {
			currentFloor++;
		}
		else {
			currentFloor = 8;
		}
		changeScene(currentFloor); //씬 변경
	}

	// 현재 씬의 tick을 호출하여 씬을 업데이트
	if (CurrentScene != nullptr)
	{
		CurrentScene->tick();
	}
}

void SceneManager::changeScene(int floor)
{
	// 이전 씬을 삭제
	if (CurrentScene != nullptr) //씬이 존재하면
	{
		delete CurrentScene;
	}

	// 새로운 씬을 생성 
	switch (floor)
	{
	case 0:
		CurrentScene = new IntroScene;
		break;
	case 1:
		CurrentScene = new Scene1F; //1층은 무조건 전투
		break;
	case 2:
		CurrentScene = new Scene2F; //2층부터 6층까지는 랜덤
		break;
	case 3:
		CurrentScene = new Scene3F;
		break;
	case 4:
		CurrentScene = new Scene4F;
		break;
	case 5:
		CurrentScene = new Scene5F;
		break;
	case 6:
		CurrentScene = new Scene6F;
		break;
	case 7:
		CurrentScene = new Scene7F; //7층은 무조건 전투
		break;
	case 8:
		CurrentScene = new FinalScene; //최종 층은 무조건 전투
		break;
	}
	// 새로운 씬의 레이아웃 생성
	if (CurrentScene != nullptr) {
		//임시로 추가
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::INPUT);
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::SELECT);
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::STORY);
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::TITLE);
		CurrentScene->makeLayout();
	}
}
