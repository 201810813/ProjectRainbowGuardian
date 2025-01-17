#include "pch.h"
#include "Animation.h"
#include "Animator.h"
#include "TimeManager.h"
#include "ConsoleLayout.h"

Animation::Animation()
	: pAnimator(nullptr)
	, AnimFrameVector{}
	, CurrentFrameIndex(0)
	, AccTime(0.f)
	, bFinish(false)
{
}

Animation::~Animation()
{
}

void Animation::tick()
{
	if (bFinish)
		return;

	AccTime += TimeManager::GetInstance()->GetDeltaTime();

	if (AnimFrameVector[CurrentFrameIndex].Duration < AccTime)
	{
		AccTime -= AnimFrameVector[CurrentFrameIndex].Duration;

		// 벡터의 인덱스를 초과한 경우 ==> Animation 재생 완료
		if (AnimFrameVector.size() <= CurrentFrameIndex + 1)
		{
			bFinish = true;
		}
		else
		{
			++CurrentFrameIndex;
		}
	}

	render();
}

void Animation::render()
{
	WriteManager::GetInstance()->ClearLayoutAllMessage(LAYOUT_TYPE::DRAW);

	for (int i = 0; i < AnimFrameVector[CurrentFrameIndex].ImageVector.size(); ++i)
	{
		WriteManager::GetInstance()->AddLine(FMessageParam(LAYOUT_TYPE::DRAW
			, AnimFrameVector[CurrentFrameIndex].ImageVector[i]
			, false
			, i));
	}
}

void Animation::Create(const vector<vector<string>>& PAnimationInfo, UINT PFrameCount, float PDuration)
{
	for (UINT i = 0; i < PFrameCount; ++i)
	{
		FAnimFrame frm = {};

		for (int index = 0; index < PAnimationInfo[i].size(); ++index)
		{
			frm.ImageVector.push_back(PAnimationInfo[i][index]);
		}

		frm.Duration = PDuration;

		AnimFrameVector.push_back(frm);
	}

}
