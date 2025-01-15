#pragma once

class Animation;

class Animator
{
private:
    map<string, Animation*> AnimationMap;  // 해당 애니메이터에서 실행 가능한 애니메이션들
    Animation*              CurrentAnimation;     // 현재 애니메이션

    bool                    bRepeat;        // 반복재생 여부

public:
    virtual void tick();

public:
    void CreateAnimation(const string& _strName, const vector<vector<string>>& PAnimationInfo, UINT PFrameCount, float PDuration);

    Animation* FindAnimation(const string& _strKey);

    void Play(const string& _strName, bool _bRepeat);

    // 에니메이션을 이어서 실행해주는 함수
    void CuntinuePlay(const string& _strName, bool _bRepeat);

    void ReSetCurAnim() { CurrentAnimation = nullptr; }

public:
    Animator();
    ~Animator();

};