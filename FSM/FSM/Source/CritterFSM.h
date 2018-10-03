#pragma once

#include "IFSM.h"

class Critter;
class HappyState;
class BoredState;

class CritterFSM : public IFSM<Critter>
{
public:
	CritterFSM();

	void Update(Critter* owner) override;

	HappyState* happyState;
	BoredState* boredState;
};