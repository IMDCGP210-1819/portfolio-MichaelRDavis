#include <iostream>
#include "Critter.h"
#include "CritterFSM.h"

Critter::Critter()
{
	critterFSM = new CritterFSM();
	happy = 5;
}

void Critter::RunStateMachine()
{
	critterFSM->Update(this);
}