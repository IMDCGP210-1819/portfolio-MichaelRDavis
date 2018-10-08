#include "CritterStates.h"
#include "CritterTransitions.h"

#include <iostream>

HappyState::HappyState()
{
	m_pIsBored = new IsBored();
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
	m_pIsHappy = new IsHappy();
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
