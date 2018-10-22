#pragma once

class CritterFSM;

class Critter
{
public:
	Critter();

	void RunStateMachine();

	void AddHappiness();
	void RemoveHappiness();

	void AddHunger();
	void RemoveHunger();

	inline bool IsHappy() const
	{
		return m_happiness > 5;
	}

	inline bool IsBored() const
	{
		return m_happiness < 5;
	}

	inline bool IsHungry() const
	{
		return m_hunger > 7;
	}

	inline int GetHappiness() const
	{
		return m_happiness;
	}

	inline int GetHunger() const
	{
		return m_hunger;
	}

protected:
	CritterFSM* m_pCritterFSM;

	int m_happiness;
	int m_maxHappiness;
	int m_hunger;
	int m_maxHunger;
	bool m_isDead;
};