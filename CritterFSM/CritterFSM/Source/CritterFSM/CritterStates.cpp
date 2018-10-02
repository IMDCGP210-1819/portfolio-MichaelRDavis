#include "CritterStates.h"
#include "CritterTransitions.h"
#include <iostream>

HappyState::HappyState()
{
	isHungry = new IsHungry();
}

HappyState::~HappyState()
{
	delete isHungry;
}

void HappyState::OnEnter()
{
	std::cout << "I am Happy." << std::endl;
}

void HappyState::OnUpdate()
{
	if (isHungry->IsValid())
	{
		isHungry->GetNextState();
	}
}

void HappyState::OnExit()
{
	std::cout << "I am no longer Happy." << std::endl;
}

HungryState::HungryState()
{
	isFull = new IsFull();
	isDead = new IsDead();
}

HungryState::~HungryState()
{
	delete isDead;
	delete isFull;
}

void HungryState::OnEnter()
{
	std::cout << "I am Hungry please feed me" << std::endl;
}

void HungryState::OnUpdate()
{
	if (isFull->IsValid())
	{
		isFull->GetNextState();
	}
	else if (isDead->IsValid())
	{
		isDead->GetNextState();
	}
}

void HungryState::OnExit()
{
	std::cout << "I am no longer Hungry" << std::endl;
}

DeadState::DeadState()
{

}

DeadState::~DeadState()
{

}

void DeadState::OnEnter()
{
	std::cout << "Dead" << std::endl;
}

void DeadState::OnUpdate()
{

}

void DeadState::OnExit()
{

}
