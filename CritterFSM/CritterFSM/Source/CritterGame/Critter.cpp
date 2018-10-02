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