#include "CritterTransitions.h"
#include "CritterStates.h"
#include "Critter.h"

#include <iostream>

IsBored::IsBored(HappyState* happyState)
{
	nextState = happyState;
}

bool IsBored::IsValid(Critter* owner)
{
	if (owner->happy < 5)
	{
		return true;
	}

	return false;
}

IState<Critter>* IsBored::GetNextState(Critter* owner)
{
	return nextState;
}

void IsBored::OnTransition(Critter* Owner)
{
	std::cout << "I am no longer happy" << std::endl;
}

IsHappy::IsHappy(BoredState* boredState)
{
	nextState = boredState;
}

bool IsHappy::IsValid(Critter* owner)
{
	if (owner->happy > 5)
	{
		return true;
	}

	return false;
}

IState<Critter>* IsHappy::GetNextState(Critter* owner)
{
	return nextState;
}

void IsHappy::OnTransition(Critter* Owner)
{
	std::cout << "I am no longer bored" << std::endl;
}
