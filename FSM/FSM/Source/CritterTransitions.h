#pragma once

#include "ITransition.h"

class Critter;
class BoredState;
class HappyState;

class IsBored : public ITransition<Critter>
{
public:
	IsBored(HappyState* happyState);

	bool IsValid(Critter* owner) override;
	IState<Critter>* GetNextState(Critter* owner) override;
	void OnTransition(Critter* Owner) override;

	IState<Critter>* nextState;
};

class IsHappy : public ITransition<Critter>
{
public:
	IsHappy(BoredState* boredState);

	bool IsValid(Critter* owner) override;
	IState<Critter>* GetNextState(Critter* owner) override;
	void OnTransition(Critter* Owner) override;

	IState<Critter>* nextState;
};