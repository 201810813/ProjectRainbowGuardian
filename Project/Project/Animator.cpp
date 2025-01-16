#include "pch.h"
#include "Animator.h"
#include "Animation.h"



Animator::Animator()
	: AnimationMap{}
	, CurrentAnimation(nullptr)
	, bRepeat(false)
{
}

Animator::~Animator()
{
	map<string, Animation*>::iterator iter = AnimationMap.begin();
	for (;iter != AnimationMap.end(); ++iter)
	{
		if (nullptr != iter->second)
		{
			delete iter->second;
		}
	}
}

void Animator::tick()
{
	if (nullptr != CurrentAnimation)
	{
		CurrentAnimation->tick();

		if (bRepeat && CurrentAnimation->IsFinish())
		{
			CurrentAnimation->Reset();
		}
	}
}

bool Animator::isCurAnimEnd()
{
	return CurrentAnimation->IsFinish();
}

void Animator::CreateAnimation(const string& _strName, const vector<vector<string>>& PAnimationInfo, UINT PFrameCount, float PDuration)
{
	Animation* pAnimation = FindAnimation(_strName);

	if (nullptr != pAnimation)
	{
		return;
	}

	pAnimation = new Animation;
	pAnimation->Create(PAnimationInfo, PFrameCount, PDuration);
	pAnimation->pAnimator = this;

	AnimationMap.insert(make_pair(_strName, pAnimation));
}

Animation* Animator::FindAnimation(const string& _strKey)
{
	if (AnimationMap.find(_strKey) == AnimationMap.end())
		return nullptr;

	return AnimationMap.find(_strKey)->second;
}

void Animator::Play(const string& _strName, bool _bRepeat)
{
	CurrentAnimation = FindAnimation(_strName);
	CurrentAnimation->Reset();

	bRepeat = _bRepeat;
}

void Animator::CuntinuePlay(const string& _strName, bool _bRepeat)
{
	CurrentAnimation = FindAnimation(_strName);
	bRepeat = _bRepeat;
}
