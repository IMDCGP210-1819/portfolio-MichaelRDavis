#pragma once

#include "Transition.h"

class IsHappy : public Transition<Critter>
{
public:
	bool IsValid() const override
	{

	}

	std::shared_ptr<State<Critter>> GetNextState() override
	{

	}

	void OnTransition() override
	{

	}
};

class IsBored : public Transition<Critter>
{
public:
	bool IsValid() const override
	{

	}

	std::shared_ptr<State<Critter>> GetNextState() override
	{

	}

	void OnTransition() override
	{

	}
};