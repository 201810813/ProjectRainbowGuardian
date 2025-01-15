#include "pch.h"
#include "SceneManager.h"
#include "KeyManager.h" // 키 입력 처리 관련 추가
#include "ConsoleLayout.h"
#include "RandomManager.h"

shared_ptr<SceneManager> SceneManager::Instance = nullptr;

void SceneManager::Initialize()
{
	if (!hasShownIntro)
	{
		CurrentScene = new IntroScene; // 처음에는 인트로 씬
		hasShownIntro = true;          // 인트로 씬 표시로 설정
	}
	else
	{
		CurrentScene = new Scene0F; // 이후에는 마을 씬으로 바로 이동
	}

    CurrentScene->makeLayout();
	currentFloor = 1; // 현재 층 초기화
	BattleCount = 0; // 배틀 횟수 초기화
	finalBossDefeated = false; // 최종 보스 전투 초기화
	randomEventTriggered = false; // 랜덤 이벤트 초기화
}

void SceneManager::tick()
{
	if (finalBossDefeated) return; // 최종 보스 클리어 시 종료

	if (IS_TAP(RIGHT)) // 오른쪽 방향키 입력 처리
	{
		//if (currentFloor == 0) // 마을에서 오른쪽 키 입력 시
		//{
		//	cout << "마을에서는 오른쪽 방향키로 이동할 수 없습니다.\n";
		//	return;
		//}

		if (randomEventTriggered) // 랜덤 이벤트 종료 처리
		{
			randomEventTriggered = false; // 랜덤 이벤트 해제
			if (currentFloor < 8)
			{
				currentFloor++; // 다음 층 이동
			}
			CacheChangeScene(static_cast<SCENE_TYPE>(currentFloor));
		}
		else if (BattleCount >= 4 && currentFloor < 8) // 전투 4회 후 랜덤 이벤트 (8층 제외)
		{
			CacheChangeScene(SCENE_TYPE::RANDOM);
			randomEventTriggered = true;
		}
		else // 일반 배틀 진행
		{
			CacheChangeScene(static_cast<SCENE_TYPE>(currentFloor));
			BattleCount++;
		}
	}

	if (IS_TAP(LEFT))
	{
		MoveToScene0F();
	}

	// 현재 씬의 tick을 호출하여 씬 업데이트
	if (CurrentScene != nullptr)
	{
		CurrentScene->tick();
	}

	// 씬 변경 처리
	changeScene();
}

void SceneManager::CacheChangeScene(SCENE_TYPE SceneType)
{
    bChangeScene = true;
	if (SceneType == SCENE_TYPE::RANDOM) // 랜덤으로 씬 변경
    {
        RandomCreateScene();
    }
	else // 특정 씬으로 변경
        NextSceneType = SceneType;
}

void SceneManager::RandomCreateScene()
{ // 배틀 카운트 초기화하고 랜덤 씬 결정!
    int randomtype;
    BattleCount = 0;
	RandomManager::GetInstance()->setRange((int)SCENE_TYPE::SHOP, (int)SCENE_TYPE::ALTAR); // 상점과 제단 사이에서 랜덤
	randomtype = RandomManager::GetInstance()->getRandom<int>();
	NextSceneType = static_cast<SCENE_TYPE>(randomtype);

	// 랜덤 씬을 맵에 표시
	if (NextSceneType == SCENE_TYPE::SHOP)
	{
		randomEventIcon = "[🛒]"; // 상점 아이콘
	}
	else if (NextSceneType == SCENE_TYPE::ALTAR)
	{
		randomEventIcon = "[⛲]"; // 제단 아이콘
	}
}

void SceneManager::changeScene()
{
	if (!bChangeScene) return;
	if (CurrentScene != nullptr) { delete CurrentScene; } // 현재 씬 삭제

	switch (NextSceneType)
	{
	case SCENE_TYPE::INTRO:
		CurrentScene = new IntroScene;
		break;
		
	case SCENE_TYPE::SCENE_0F:
		CurrentScene = new Scene0F;
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
		CurrentScene = new ShopScene;
		break;

	case SCENE_TYPE::ALTAR:
		CurrentScene = new AltarScene;
		break;

	default:
		break;
	}

	if (CurrentScene != nullptr) {
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::INPUT);
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::SELECT);
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::STORY);
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::TITLE);
		WriteManager::GetInstance()->ClearLayout(LAYOUT_TYPE::DRAW);
		CurrentScene->begin();
		updateMap();
	}

	bChangeScene = false;
}

// 맵 레이아웃 업데이트: 플레이어 위치와 아이콘 표시
void SceneManager::updateMap() 
{
	WriteManager::GetInstance()->MakeLayout(LAYOUT_TYPE::MAP, 104, 2, 9, 8);

	for (int i = 0; i <= 8; ++i)
	{
		string icon;
		TEXT_COLOR_TYPE color = TEXT_COLOR_TYPE::GRAY;

		if (i == 0) // 0층 마을!
		{
			icon = "[🏠]";
			color = TEXT_COLOR_TYPE::WHITE;
		}
		else if (i < currentFloor) // 지나간 방
		{
			icon = "[⚔️]";
			color = getColorForFloor(i); // 지나간 방의 색깔 유지
		}
		else if (i == currentFloor)
		{
			icon = randomEventTriggered ? randomEventIcon : "[🕵️]"; // 현재 층
			color = TEXT_COLOR_TYPE::WHITE;
		}
		else if (i == 8)
		{
			if (finalBossDefeated) { // 최종 보스 클리어 시
				icon = "[🌈]"; // 무지개 아이콘
				color = TEXT_COLOR_TYPE::SKY_INENSITY;
			}
			else {
				icon = "[🐉]"; // 8층 레인보우 드래곤
				color = TEXT_COLOR_TYPE::SKY_INENSITY;
			}
		}
		else
		{
			icon = "[❔]";
		}

		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::MAP, to_string(i) + "F " + icon, false, 8 - i, color));
	}
}

// 층에 따른 색상 반환
TEXT_COLOR_TYPE SceneManager::getColorForFloor(int floor)
{
	switch (floor)
	{
	case 1: return TEXT_COLOR_TYPE::RED;
	case 2: return TEXT_COLOR_TYPE::ORANGE;
	case 3: return TEXT_COLOR_TYPE::ORANGE_INENSITY;
	case 4: return TEXT_COLOR_TYPE::GREEN;
	case 5: return TEXT_COLOR_TYPE::BLUE;
	case 6: return TEXT_COLOR_TYPE::BLUE_INENSITY;
	case 7: return TEXT_COLOR_TYPE::PURPLE;
	default: return TEXT_COLOR_TYPE::GRAY;
	}
}

// 다음 층으로 이동
void SceneManager::MoveToNextFloor()
{
	if (currentFloor < 8)
	{
		randomEventTriggered = false; // 랜덤 이벤트 해제
		randomEventIcon = ""; // 랜덤 이벤트 아이콘 초기화

		currentFloor++;
		CacheChangeScene(static_cast<SCENE_TYPE>(currentFloor));
	}
	else
	{
		cout << "더 이상 이동할 층이 없습니다.\n";
	}
}

void SceneManager::MarkFinalBossDefeated()
{
	finalBossDefeated = true; // 최종 보스 클리어 상태
}

void SceneManager::MoveToScene0F()
{
	currentFloor = 0; // 0층으로 이동
	randomEventTriggered = false; // 랜덤 이벤트 해제
	randomEventIcon = ""; // 랜덤 이벤트 아이콘 초기화
	CacheChangeScene(SCENE_TYPE::SCENE_0F); // 0층으로 이동
	updateMap();
}
