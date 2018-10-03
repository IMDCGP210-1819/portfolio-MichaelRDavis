#include "CritterFSM.h"
#include "CritterStates.h"
#include "CritterTransitions.h"

CritterFSM::CritterFSM()
{
	happyState = new HappyState();

	initialState = happyState;
	activeState = happyState;
}

void CritterFSM::Update(Critter* owner)
{
	if (happyState->isBored->IsValid(owner))
	{
		activeState->OnExit(owner);
		activeState = happyState->isBored->GetNextState(owner);
		activeState->OnEnter(owner);
	}
	else
	{
		activeState->OnUpdate(owner);
	}
}
