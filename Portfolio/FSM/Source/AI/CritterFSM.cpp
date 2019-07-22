#include "CritterFSM.h"
#include "CritterStates.h"

CritterFSM::CritterFSM()
{
	std::shared_ptr<HappyState> happyState = std::make_shared<HappyState>();
	m_states.emplace_back(happyState);
	std::shared_ptr<BoredState> boredState = std::make_shared<BoredState>();
	m_states.emplace_back(boredState);
}

void CritterFSM::Update()
{

}
