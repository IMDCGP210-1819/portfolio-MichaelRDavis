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
};

class IsFull : public ITransition
{
public:
	IsFull();
	~IsFull();

	bool IsValid() override;
	IState* GetNextState() override;
	void OnTransition() override;
};

class IsDead : public ITransition
{
public:
	IsDead();
	~IsDead();

	bool IsValid() override;
	IState* GetNextState() override;
	void OnTransition() override;
};