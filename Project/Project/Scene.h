#pragma once

class Scene{
private:
	string SceneName; //씬 이름

	//BATTLE_TYPE Cur_BattleType;
	int Floor_Num;
	int Turn_Count;
	bool bOnce;
	int CursorPos;

public:
	virtual void makeLayout() = 0; //순수 가상함수
	virtual void begin(); 
	virtual void tick(); 

public:
	void SetFloorNumber(int FloorNumber) { Floor_Num = FloorNumber; }
	int GetFloorNumber() { return Floor_Num; }

public:
	Scene(); //생성자
	virtual ~Scene(); //가상 소멸자
};

