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
	bool hasShownIntro; // 인트로를 보여줬는지 여부

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
	Scene*		CurrentScene; //현재 씬을 가리키는 포인터
	int			currentFloor;

	bool		bChangeScene;
	bool     finalBossDefeated;
	bool		randomEventTriggered; // 랜덤 이벤트 트리거
	SCENE_TYPE	NextSceneType;
	int			BattleCount;
	string  randomEventIcon; // 랜덤 이벤트 아이콘

	bitset<7>	RoomColorCheck;	// bit단위로 어떤 컬러의 방들을 클리어했는지 체크해 줌.



public:
	void Initialize();
	void tick();
	void changeScene(); //씬 변경 메서드

public:
	void CheckRoomColor(SCENE_TYPE SceneType); // 어떤 컬러의 방을 클리어 했는지 체크해주는 함수.
	bool Is_AllColorClear(); // 모든 색상을 다 모았는지 확인받는 함수
	void CheckRoomColorReset(); // 색상 체크를 모두 false로 전환

	void CacheChangeScene(SCENE_TYPE SceneType);
	
	// 랜덤 함수 추가
	void RandomCreateScene();

	void updateMap(); //맵 업데이트 메서드

	TEXT_COLOR_TYPE getColorForFloor(int floor);

	void MoveToNextFloor(); // 다음 층으로 이동

	void MarkFinalBossDefeated(); // 최종 보스 클리어 처리

	void MoveToScene0F(); // 0층으로 이동

};