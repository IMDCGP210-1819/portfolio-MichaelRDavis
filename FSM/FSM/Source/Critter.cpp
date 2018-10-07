#include "Critter.h"
#include "CritterFSM.h"

#include <iostream>

Critter::Critter()
{
	critterFSM = new CritterFSM();
	happy = 5;
}

void Critter::RunStateMachine()
{
	critterFSM->Update(this);
}