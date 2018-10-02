#include "CritterTransitions.h"
#include "CritterStates.h"

#include <iostream>

IsHungry::IsHungry()
{

}

IsHungry::~IsHungry()
{

}

bool IsHungry::IsValid()
{
	return true;
}

IState* IsHungry::GetNextState()
{
	return nullptr;
}

void IsHungry::OnTransition()
{
	std::cout << "I am hungry" << std::endl;
}

IsFull::IsFull()
{
	
}

IsFull::~IsFull()
{
	
}

bool IsFull::IsValid()
{
	return true;
}

IState* IsFull::GetNextState()
{
	return nullptr;
}

void IsFull::OnTransition()
{
	std::cout << "I am full up" << std::endl;
}

IsDead::IsDead()
{
	
}

IsDead::~IsDead()
{
	
}

bool IsDead::IsValid()
{
	return true;
}

IState* IsDead::GetNextState()
{
	return nullptr;
}

void IsDead::OnTransition()
{
	std::cout << "DEAD" << std::endl;
}
