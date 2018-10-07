#include "CritterStates.h"
#include "CritterTransitions.h"

#include <iostream>

HappyState::HappyState()
{
	isBored = new IsBored();
}

void HappyState::OnEnter(Critter* owner)
{
	
}

void HappyState::OnUpdate(Critter* owner)
{
	std::cout << "Happy" << std::endl;
}

void HappyState::OnExit(Critter* owner)
{
	
}

BoredState::BoredState()
{
	isHappy = new IsHappy();
}

void BoredState::OnEnter(Critter* owner)
{
	
}

void BoredState::OnUpdate(Critter* owner)
{
	std::cout << "Yawn!" << std::endl;
}

void BoredState::OnExit(Critter* owner)
{

}
