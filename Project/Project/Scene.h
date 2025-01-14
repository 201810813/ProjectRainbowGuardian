#pragma once

class Scene
{
private:
	string SceneName; //�� �̸�

public:
	virtual void makeLayout() = 0; //���� �����Լ�
	virtual void begin(); 
	virtual void tick(); 

public:
	Scene(); //������
	virtual ~Scene(); //���� �Ҹ���
};

