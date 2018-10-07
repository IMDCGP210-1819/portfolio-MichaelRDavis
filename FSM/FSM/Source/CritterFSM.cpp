#include "CritterFSM.h"
#include "CritterStates.h"
#include "CritterTransitions.h"

CritterFSM::CritterFSM()
{
	happyState = new HappyState();
	boredState = new BoredState();

	initialState = happyState;
	activeState = happyState;
}

void CritterFSM::SetNextState(IState<Critter>* NewState)
{
	activeState = NewState;
}

void CritterFSM::Update(Critter* owner)
{
	if (happyState->isBored->IsValid(owner))
	{
		if (activeState != nullptr)
		{
			activeState->OnExit(owner);
		}

		SetNextState(boredState);
		if (activeState != nullptr)
		{
			activeState->OnUpdate(owner);
		}
	}

	if (boredState->isHappy->IsValid(owner))
	{
		if (activeState != nullptr)
		{
			activeState->OnExit(owner);
		}

		SetNextState(happyState);
		if (activeState != nullptr)
		{
			activeState->OnUpdate(owner);
		}
	}
}
