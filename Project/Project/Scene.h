#pragma once

class Scene
{
private:
	string SceneName; //씬 이름

public:
	virtual void makeLayout() = 0; //순수 가상함수
	virtual void begin(); 
	virtual void tick(); 

public:
	Scene(); //생성자
	virtual ~Scene(); //가상 소멸자
};

