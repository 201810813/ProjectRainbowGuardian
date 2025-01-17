#pragma once

class Animator;

struct FAnimFrame
{
    vector<string>  ImageVector;    // 프레임당 출력할 문자열
    float           Duration;      // 해당 프레임 유지시간
};

class Animation
{
private:
    Animator*          pAnimator;

    vector<FAnimFrame>  AnimFrameVector;   // 모든 프레임 정보

    int                 CurrentFrameIndex;  // 현재 노출 시킬 프레임 인덱스
    float               AccTime; // 누적시간

    bool                bFinish;  // 재생 완료


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

