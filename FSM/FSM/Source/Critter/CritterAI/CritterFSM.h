#pragma once

#include "IFSM.h"

class Critter;
class HappyState;
class BoredState;

class CritterFSM : public IFSM<Critter>
{
public:
	CritterFSM();

	void SetNextState(IState<Critter>* newState);
	void Update(Critter* owner) override;

	HappyState* m_pHappyState;
	BoredState* m_pBoredState;
};