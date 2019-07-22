#pragma once

#include "Critter.h"
#include "FSM.h"

class CritterFSM : public FSM<Critter>
{
public:
	CritterFSM();
	~CritterFSM() = default;

	void Update() override;
};