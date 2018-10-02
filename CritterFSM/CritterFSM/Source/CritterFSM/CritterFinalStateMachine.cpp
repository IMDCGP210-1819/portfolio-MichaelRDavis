#include "CritterFinalStateMachine.h"
#include "CritterStates.h"

CritterFinalStateMachine::CritterFinalStateMachine()
{
	happyState = new HappyState();
	hungryState = new HungryState();
	deadState = new DeadState();

	ActiveState = happyState;
	InitialState = happyState;
}

CritterFinalStateMachine::~CritterFinalStateMachine()
{

}

void CritterFinalStateMachine::Update()
{
	ActiveState->OnUpdate();
}

void CritterFinalStateMachine::SetState(IState* NewState)
{
	ActiveState = NewState;
}
