#pragma once
#include "Scene.h"
#include "MainScene.h"
#include "IntroScene.h"
#include "Scene0F.h"
#include "Scene1F.h"
#include "Scene2F.h"
#include "Scene3F.h"
#include "Scene4F.h"
#include "Scene5F.h"
#include "Scene6F.h"
#include "Scene7F.h"
#include "FinalScene.h"
#include "AltarScene.h"
#include "ShopScene.h"

#include <bitset>

class SceneManager
{
private:
	static shared_ptr<SceneManager>	Instance;
	bool hasShownIntro; // ��Ʈ�θ� ��������� ����

	SceneManager() = default;
	SceneManager(const SceneManager& other) = delete;

	~SceneManager()
	{
		//delete CurrentScene;
		if(CurrentScene != nullptr) //
			delete CurrentScene;
	}

	SceneManager& operator = (const SceneManager& other) = delete; 

	static void Destroy(SceneManager* InstancePtr)
	{
		delete InstancePtr;
	}

public:
	static shared_ptr<SceneManager> GetInstance()
	{
		if (nullptr == Instance)
		{
			Instance = shared_ptr<SceneManager>(new SceneManager(), Destroy);
		}

		return Instance;
	}

private:
	Scene*		CurrentScene; //���� ���� ����Ű�� ������
	int			currentFloor;

	bool		bChangeScene;
	bool     finalBossDefeated;
	bool		randomEventTriggered; // ���� �̺�Ʈ Ʈ����
	SCENE_TYPE	NextSceneType;
	int			BattleCount;
	string  randomEventIcon; // ���� �̺�Ʈ ������

	bitset<7>	RoomColorCheck;	// bit������ � �÷��� ����� Ŭ�����ߴ��� üũ�� ��.



public:
	void Initialize();
	void tick();
	void changeScene(); //�� ���� �޼���

public:
	void CheckRoomColor(SCENE_TYPE SceneType); // � �÷��� ���� Ŭ���� �ߴ��� üũ���ִ� �Լ�.
	bool Is_AllColorClear(); // ��� ������ �� ��Ҵ��� Ȯ�ι޴� �Լ�
	void CheckRoomColorReset(); // ���� üũ�� ��� false�� ��ȯ

	void CacheChangeScene(SCENE_TYPE SceneType);
	
	// ���� �Լ� �߰�
	void RandomCreateScene();

	void updateMap(); //�� ������Ʈ �޼���

	TEXT_COLOR_TYPE getColorForFloor(int floor);

	void MoveToNextFloor(); // ���� ������ �̵�

	void MarkFinalBossDefeated(); // ���� ���� Ŭ���� ó��

	void MoveToScene0F(); // 0������ �̵�

};