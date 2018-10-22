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
	if (owner->IsBored())
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
	if (owner->IsHappy())
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

IsHungry::IsHungry()
{
	m_pNextState = nullptr;
}

bool IsHungry::IsValid(Critter* owner)
{
	if (owner->IsHungry())
	{
		return true;
	}

	return false;
}

IState<Critter>* IsHungry::GetNextState(Critter* owner)
{
	return m_pNextState;
}

void IsHungry::OnTransition(Critter* owner)
{

}
