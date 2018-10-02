#include "CritterStates.h"
#include "CritterTransitions.h"

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

}

void HungryState::OnUpdate()
{
	if (isFull->IsValid())
	{
		isFull->GetNextState();
	}
	else if (isDead->IsValid())
	{

	}
}

void HungryState::OnExit()
{

}

DeadState::DeadState()
{

}

DeadState::~DeadState()
{

}

void DeadState::OnEnter()
{

}

void DeadState::OnUpdate()
{

}

void DeadState::OnExit()
{

}
