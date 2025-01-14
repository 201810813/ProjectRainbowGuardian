//SceneManager.cpp
#include "pch.h"
#include "SceneManager.h"
#include "KeyManager.h" //Ű �Է� ó���� ���� �߰�
#include "ConsoleLayout.h"

shared_ptr<SceneManager> SceneManager::Instance = nullptr;

void SceneManager::Initialize()
{
	CurrentScene = new MainScene;
	CurrentScene->makeLayout();
	/*CurrentScene = new IntroScene;
	CurrentScene->makeLayout();*/
}

void SceneManager::tick()
{
	// Ű	�Է� ó�� (����Ű �� ������ �� �� ����)
	//if (IS_TAP(UP)) 
	//{
	//	if (currentFloor<8) {
	//		currentFloor++;
	//	}
	//	else {
	//		currentFloor = 8;
	//	}
	//	CacheChangeScene(SCENE_TYPE::SCENE_1F); //�� ����
	//}

	// ���� ���� tick�� ȣ���Ͽ� ���� ������Ʈ
	if (CurrentScene != nullptr)
	{
		CurrentScene->tick();
	}
}

void SceneManager::CacheChangeScene(SCENE_TYPE SceneType)
{
	bChangeScene = true;
	NextSceneType = SceneType;
}

void SceneManager::RandomCreateScene()
{
	if (BattleCount > 4)
	{
		// 너는 쉬어야만해
		// 난 못 쉬지만.
		
		//제단 or 상점

		BattleCount = 0;
	}
	else
	{
		BattleCount++;

		// 배틀 씬중 랜덤!
	}

}

void SceneManager::changeScene()
{
	if (!bChangeScene)
		return;


	if (CurrentScene != nullptr)
	{
		delete CurrentScene;
	}

	switch (NextSceneType)
	{
	case SCENE_TYPE::INTRO:
		CurrentScene = new IntroScene;
		break;

	case SCENE_TYPE::SCENE_1F:
		CurrentScene = new Scene1F;
		break;

	case SCENE_TYPE::SCENE_2F:
		CurrentScene = new Scene2F;
		break;

	case SCENE_TYPE::SCENE_3F:
		CurrentScene = new Scene3F;
		break;

	case SCENE_TYPE::SCENE_4F:
		CurrentScene = new Scene4F;
		break;

	case SCENE_TYPE::SCENE_5F:
		CurrentScene = new Scene5F;
		break;

	case SCENE_TYPE::SCENE_6F:
		CurrentScene = new Scene6F;
		break;

	case SCENE_TYPE::SCENE_7F:
		CurrentScene = new Scene7F;
		break;

	case SCENE_TYPE::FINAL:
		CurrentScene = new FinalScene;
		break;

	case SCENE_TYPE::SHOP:
		// 상정
		break;

	case SCENE_TYPE::ALTAR:
		// 제단
		break;

	case SCENE_TYPE::RANDOM:
		// 랜덤 함수 만들어서 랜덤한 방 생성후 지정
		break;

	default:
		break;
	}

	if (CurrentScene != nullptr) {
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::STAT);
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::INPUT);
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::SELECT);
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::STORY);
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::TITLE);
		CurrentScene->makeLayout();
	}

	bChangeScene = false;
}
