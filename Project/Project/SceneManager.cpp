//SceneManager.cpp
#include "pch.h"
#include "SceneManager.h"
#include "KeyManager.h" //Ű �Է� ó���� ���� �߰�
#include "ConsoleLayout.h"

shared_ptr<SceneManager> SceneManager::Instance = nullptr;

void SceneManager::Initialize()
{
	currentFloor = 0; // ������ 1��
	changeScene(currentFloor); // ���� ���� IntroScene �Ǵ� 1��
}

void SceneManager::tick()
{
	// Ű	�Է� ó�� (����Ű �� ������ �� �� ����)
	if (IS_TAP(UP)) 
	{
		if (currentFloor<8) {
			currentFloor++;
		}
		else {
			currentFloor = 8;
		}
		changeScene(currentFloor); //�� ����
	}

	// ���� ���� tick�� ȣ���Ͽ� ���� ������Ʈ
	if (CurrentScene != nullptr)
	{
		CurrentScene->tick();
	}
}

void SceneManager::changeScene(int floor)
{
	// ���� ���� ����
	if (CurrentScene != nullptr) //���� �����ϸ�
	{
		delete CurrentScene;
	}

	// ���ο� ���� ���� 
	switch (floor)
	{
	case 0:
		CurrentScene = new IntroScene;
		break;
	case 1:
		CurrentScene = new Scene1F; //1���� ������ ����
		break;
	case 2:
		CurrentScene = new Scene2F; //2������ 6�������� ����
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
		CurrentScene = new Scene7F; //7���� ������ ����
		break;
	case 8:
		CurrentScene = new FinalScene; //���� ���� ������ ����
		break;
	}
	// ���ο� ���� ���̾ƿ� ����
	if (CurrentScene != nullptr) {
		//�ӽ÷� �߰�
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::INPUT);
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::SELECT);
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::STORY);
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::TITLE);
		CurrentScene->makeLayout();
	}
}
