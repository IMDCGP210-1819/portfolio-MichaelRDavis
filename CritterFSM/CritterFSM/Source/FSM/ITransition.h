#pragma once

class IState;

class ITransition
{
public:
	virtual bool IsValid() = 0;
	virtual IState* GetNextState() = 0;
	virtual void OnTransition() = 0;
};