#pragma once

#include "ITransition.h"

class Critter;
class BoredState;
class HappyState;

class IsBored : public ITransition<Critter>
{
public:
	IsBored();

	bool IsValid(Critter* owner) override;
	IState<Critter>* GetNextState(Critter* owner) override;
	void OnTransition(Critter* Owner) override;

	BoredState* nextState;
};

class IsHappy : public ITransition<Critter>
{
public:
	IsHappy();

	bool IsValid(Critter* owner) override;
	IState<Critter>* GetNextState(Critter* owner) override;
	void OnTransition(Critter* Owner) override;

	HappyState* nextState;
};