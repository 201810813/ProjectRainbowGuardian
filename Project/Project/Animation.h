#pragma once

class Animator;

struct FAnimFrame
{
    vector<string>  ImageVector;    // �����Ӵ� ����� ���ڿ�
    float           Duration;      // �ش� ������ �����ð�
};

class Animation
{
private:
    Animator*          pAnimator;

    vector<FAnimFrame>  AnimFrameVector;   // ��� ������ ����

    int                 CurrentFrameIndex;  // ���� ���� ��ų ������ �ε���
    float               AccTime; // �����ð�

    bool                bFinish;  // ��� �Ϸ�


public:
    void tick();
    void render();

public:
    void Create(const vector<vector<string>>& PAnimationInfo, UINT PFrameCount, float PDuration);

    void Reset()
    {
        CurrentFrameIndex = 0;
        bFinish = false;
        AccTime = 0.f;
    }

    bool IsFinish() { return bFinish; }

public:
    Animation();
    ~Animation();

    friend class Animator;
};

