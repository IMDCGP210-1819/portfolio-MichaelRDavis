#include "Critter.h"
#include "CritterFSM.h"

Critter::Critter()
{
	m_stateMachine = std::make_unique<CritterFSM>();
	m_stateMachine->SetOwner(this);

	m_maxHappiness = 10;
	m_happiness = m_maxHappiness;
}

Critter::~Critter()
{
}

void Critter::Update()
{
	m_stateMachine->Update();
}

void Critter::Talk()
{

}

void Critter::SetHappiness(int32_t val)
{
	if (val < m_maxHappiness)
	{
		m_happiness = val;
	}
}
