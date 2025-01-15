#pragma once

class Animation;

class Animator
{
private:
    map<string, Animation*> AnimationMap;  // �ش� �ִϸ����Ϳ��� ���� ������ �ִϸ��̼ǵ�
    Animation*              CurrentAnimation;     // ���� �ִϸ��̼�

    bool                    bRepeat;        // �ݺ���� ����

public:
    virtual void tick();

public:
    void CreateAnimation(const string& _strName, const vector<vector<string>>& PAnimationInfo, UINT PFrameCount, float PDuration);

    Animation* FindAnimation(const string& _strKey);

    void Play(const string& _strName, bool _bRepeat);

    // ���ϸ��̼��� �̾ �������ִ� �Լ�
    void CuntinuePlay(const string& _strName, bool _bRepeat);

    void ReSetCurAnim() { CurrentAnimation = nullptr; }

public:
    Animator();
    ~Animator();

};