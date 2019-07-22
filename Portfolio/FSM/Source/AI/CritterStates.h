#pragma once

#include "State.h"
#include "CritterTransitions.h"
#include <iostream>

class Critter;

class HappyState : public State<Critter>
{
public:
	HappyState()
	{
		std::shared_ptr<IsBored> isBored = std::make_shared<IsBored>();
		m_transitions.emplace_back(isBored);
	}

	void OnEnter(Critter* owner) override
	{

	}

	void OnUpdate(Critter* owner) override
	{
		std::cout << "I am Happy!" << std::endl;
	}

	void OnExit(Critter* owner) override
	{

	}
};

class BoredState : public State<Critter>
{
public:
	BoredState()
	{
		std::shared_ptr<IsHappy> isHappy = std::make_shared<IsHappy>();
		m_transitions.emplace_back(isHappy);
	}

	void OnEnter(Critter* owner) override
	{

	}

	void OnUpdate(Critter* owner) override
	{
		std::cout << "I am Bored. Yawn!" << std::endl;
	}

	void OnExit(Critter* owner) override
	{

	}
};