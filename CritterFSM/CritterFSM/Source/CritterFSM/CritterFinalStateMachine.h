#pragma once

#include "IFinalStateMachine.h"

class HappyState;
class HungryState;
class DeadState;

class CritterFinalStateMachine : public IFinalStateMachine
{
public:
	CritterFinalStateMachine();
	~CritterFinalStateMachine();

	void Update();
	void SetState(IState* NewState);

	inline HappyState* GetHappyState() const { return happyState; }
	inline HungryState* GetHungryState() const { return hungryState; }
	inline DeadState* GetDeadState() const { return deadState; }

	inline IState* GetActiveState() { return ActiveState; }
	inline IState* GetInitialState() { return InitialState; }

	HappyState* happyState;
	HungryState* hungryState;
	DeadState* deadState;
};
