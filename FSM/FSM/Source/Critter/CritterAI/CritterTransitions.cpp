#include "CritterTransitions.h"
#include "CritterStates.h"
#include "Critter.h"

#include <iostream>

IsBored::IsBored()
{
	m_pNextState = nullptr;
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
	return m_pNextState;
}

void IsBored::OnTransition(Critter* Owner)
{
	
}

IsHappy::IsHappy()
{
	m_pNextState = nullptr;
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
	return m_pNextState;
}

void IsHappy::OnTransition(Critter* Owner)
{
	
}
