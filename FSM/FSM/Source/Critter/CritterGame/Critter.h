#pragma once

class CritterFSM;

class Critter
{
public:
	Critter();

	void RunStateMachine();

	void AddHappy();
	void RemoveHappy();

	inline bool IsHappy() const
	{
		return m_happy > 5;
	}

	inline bool IsBored() const
	{
		return m_happy < 5;
	}

	inline int GetHappy() const
	{
		return m_happy;
	}

protected:
	CritterFSM* m_pCritterFSM;

	int m_happy;
	int m_maxHappy;
};