#include <iostream>
#include "Critter.h"
#include "CritterFSM.h"

Critter::Critter()
{
	m_pCritterFSM = new CritterFSM();

	m_happiness = 5;
	m_maxHappiness = 10;
	m_hunger = 0;
	m_maxHunger = 10;
}

void Critter::RunStateMachine()
{
	m_pCritterFSM->Update(this);
}

void Critter::AddHappiness()
{
	if (m_happiness < m_maxHappiness)
		m_happiness++;
}

void Critter::RemoveHappiness()
{
	if (m_happiness != 0)
		m_happiness--;
}

void Critter::AddHunger()
{
	if (m_hunger < m_maxHunger)
		m_hunger++;
}

void Critter::RemoveHunger()
{
	if (m_hunger != 0)
		m_hunger--;
}
