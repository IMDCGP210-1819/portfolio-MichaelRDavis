#pragma once

#include "ITransition.h"

class Critter;

class IsBored : public ITransition<Critter>
{
public:
	IsBored();

	bool IsValid(Critter* owner) override;
	IState<Critter>* GetNextState(Critter* owner) override;
	void OnTransition(Critter* Owner) override;

	IState<Critter>* m_pNextState;
};

class IsHappy : public ITransition<Critter>
{
public:
	IsHappy();

	bool IsValid(Critter* owner) override;
	IState<Critter>* GetNextState(Critter* owner) override;
	void OnTransition(Critter* owner) override;

	IState<Critter>* m_pNextState;
};