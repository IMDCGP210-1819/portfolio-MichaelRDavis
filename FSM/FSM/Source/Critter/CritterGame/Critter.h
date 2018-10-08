#pragma once

class CritterFSM;

class Critter
{
public:
	Critter();

	void RunStateMachine();

	void AddHappy() { happy++; }
	void RemoveHappy() { happy--; }

	int happy;
	int maxHappy;

	CritterFSM* critterFSM;
};