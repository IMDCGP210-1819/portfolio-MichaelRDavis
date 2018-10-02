#pragma once

class IState;

class IFinalStateMachine
{
public:
	virtual void Update() = 0;
	IState* InitialState;
	IState* ActiveState;
};