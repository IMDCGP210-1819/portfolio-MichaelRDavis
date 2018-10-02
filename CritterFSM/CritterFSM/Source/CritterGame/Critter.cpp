#include "Critter.h"

Critter::Critter()
{
	MaxHunger = 10;
	Hunger = MaxHunger;
}

Critter::~Critter()
{
	delete CFSM;
}

void Critter::Talk()
{

}