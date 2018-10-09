#include <iostream>
#include "Critter.h"
#include "CritterFSM.h"

Critter::Critter()
{
	m_pCritterFSM = new CritterFSM();

	m_happy = 5;
	m_maxHappy = 10;
}

void Critter::RunStateMachine()
{
	m_pCritterFSM->Update(this);
}

void Critter::AddHappy()
{
	if (m_happy < m_maxHappy)
		m_happy++;
}

void Critter::RemoveHappy()
{
	if (m_happy != 0)
		m_happy--;
}
