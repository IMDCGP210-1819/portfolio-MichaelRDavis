#include "CritterFSM.h"
#include "CritterStates.h"
#include "CritterTransitions.h"

CritterFSM::CritterFSM()
{
	m_pHappyState = new HappyState();
	m_pBoredState = new BoredState();
	m_pHungryState = new HungryState();

	m_pInitialState = m_pHappyState;
	m_pActiveState = m_pHappyState;
}

void CritterFSM::SetNextState(IState<Critter>* NewState)
{
	m_pActiveState = NewState;
}

void CritterFSM::Update(Critter* owner)
{
	if (m_pHappyState->m_pIsBored->IsValid(owner))
	{
		if (m_pActiveState != nullptr)
		{
			m_pActiveState->OnExit(owner);
		}

		SetNextState(m_pBoredState);
		if (m_pActiveState != nullptr)
		{
			m_pActiveState->OnUpdate(owner);
		}
	}

	if (m_pBoredState->m_pIsHappy->IsValid(owner))
	{
		if (m_pActiveState != nullptr)
		{
			m_pActiveState->OnExit(owner);
		}

		SetNextState(m_pHappyState);
		if (m_pActiveState != nullptr)
		{
			m_pActiveState->OnUpdate(owner);
		}
	}

	if (m_pHungryState->m_pIsHungry->IsValid(owner))
	{
		if (m_pActiveState != nullptr)
		{
			m_pActiveState->OnExit(owner);
		}

		SetNextState(m_pHungryState);
		if (m_pActiveState != nullptr)
		{
			m_pActiveState->OnUpdate(owner);
		}
	}
}
