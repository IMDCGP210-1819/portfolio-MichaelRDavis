#include "CritterStates.h"
#include "CritterTransitions.h"

#include <iostream>

HappyState::HappyState()
{
	isBored = new IsBored(this);
}

void HappyState::OnEnter(Critter* owner)
{
	std::cout << "I am now happy" << std::endl;
}

void HappyState::OnUpdate(Critter* owner)
{
	std::cout << "Happy" << std::endl;
}

void HappyState::OnExit(Critter* owner)
{
	std::cout << "I am getting bored now" << std::endl;
}

BoredState::BoredState()
{
	isHappy = new IsHappy(this);
}

void BoredState::OnEnter(Critter* owner)
{
	std::cout << "Bored" << std::endl;
}

void BoredState::OnUpdate(Critter* owner)
{
	std::cout << "Yawn!" << std::endl;
}

void BoredState::OnExit(Critter* owner)
{

}
