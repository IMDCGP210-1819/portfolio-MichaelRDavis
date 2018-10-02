#include "Critter.h"
#include "CritterFinalStateMachine.h"

Critter::Critter()
{
	CFSM = new CritterFinalStateMachine();

	MaxHunger = 10;
	Hunger = MaxHunger;
}

Critter::~Critter()
{
	delete CFSM;
}

void Critter::Talk()
{
	if (CFSM->GetHappyState())
	{
		std::cout << "I am happy." << std::endl;
	}
	else if (CFSM->GetHungryState())
	{
		std::cout << "I am hungry please feed me." << std::endl;
	}
}