#pragma once

class Scene{
private:
	string SceneName; //�� �̸�

	//BATTLE_TYPE Cur_BattleType;
	int Floor_Num;
	int Turn_Count;
	bool bOnce;
	int CursorPos;

public:
	virtual void makeLayout() = 0; //���� �����Լ�
	virtual void begin(); 
	virtual void tick(); 

public:
	void SetFloorNumber(int FloorNumber) { Floor_Num = FloorNumber; }
	int GetFloorNumber() { return Floor_Num; }

public:
	Scene(); //������
	virtual ~Scene(); //���� �Ҹ���
};

