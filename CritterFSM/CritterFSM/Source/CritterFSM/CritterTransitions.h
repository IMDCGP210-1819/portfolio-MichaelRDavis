#pragma once

#include "ITransition.h"

class HappyState;
class HungryState;
class DeadState;

class IsHungry : public ITransition
{
public:
	IsHungry();
	~IsHungry();

	bool IsValid() override;
	IState* GetNextState() override;
	void OnTransition() override;

	HungryState* hungryState;
};

class IsFull : public ITransition
{
public:
	IsFull();
	~IsFull();

	bool IsValid() override;
	IState* GetNextState() override;
	void OnTransition() override;

	HappyState* happyState;
};

class IsDead : public ITransition
{
public:
	IsDead();
	~IsDead();

	bool IsValid() override;
	IState* GetNextState() override;
	void OnTransition() override;

	DeadState* deadState;
};