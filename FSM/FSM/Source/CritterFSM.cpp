#include "CritterFSM.h"
#include "CritterStates.h"
#include "CritterTransitions.h"

CritterFSM::CritterFSM()
{
	happyState = new HappyState(boredState);
	boredState = new BoredState(happyState);

	initialState = happyState;
	activeState = happyState;
}

void CritterFSM::Update(Critter* owner)
{
	if (happyState->isBored->IsValid(owner))
	{
		if (activeState != nullptr)
		{
			activeState->OnExit(owner);
		}

		activeState = happyState->isBored->GetNextState(owner);
		if (activeState != nullptr)
		{
			activeState->OnUpdate(owner);
		}
	}
	else if(boredState->isHappy->IsValid(owner))
	{
		if (activeState != nullptr)
		{
			activeState->OnExit(owner);
		}

		activeState = boredState->isHappy->GetNextState(owner);
		if (activeState != nullptr)
		{
			activeState->OnUpdate(owner);
		}
	}
	else
	{
		if (activeState != nullptr)
		{
			activeState->OnUpdate(owner);
		}
	}
}
