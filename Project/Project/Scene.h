#pragma once

class Scene{
private:
	string SceneName; //�� �̸�

	//BATTLE_TYPE Cur_BattleType;
	int Turn_Count;
	bool bOnce;
	int CursorPos;

public:
	virtual void makeLayout() = 0; //���� �����Լ�
	virtual void begin(); 
	virtual void tick(); 

public:
	Scene(); //������
	virtual ~Scene(); //���� �Ҹ���
};

