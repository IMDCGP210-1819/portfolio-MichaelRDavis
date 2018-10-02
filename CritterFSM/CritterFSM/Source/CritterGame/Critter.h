#pragma once

#include <iostream>

class CritterFinalStateMachine;

class Critter
{
public:
	Critter();
	~Critter();

	inline void ReduceHunger() { Hunger++; }
	inline void IncreaseHunger() { Hunger--; }

	inline int GetHunger() const { return Hunger; }
	inline int GetMaxHunger() const { return MaxHunger; }

	inline CritterFinalStateMachine* GetStateMachine() const { return CFSM; }

private:
	CritterFinalStateMachine* CFSM;

	int Hunger;
	int MaxHunger;
};