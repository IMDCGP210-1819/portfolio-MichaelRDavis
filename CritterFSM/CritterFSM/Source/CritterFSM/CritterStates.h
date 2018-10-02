#pragma once

#include "IState.h"

class IsHungry;
class IsFull;
class IsDead;
class Critter;

class HappyState : public IState
{
public:
	HappyState();
	~HappyState();

	void OnEnter() override;
	void OnUpdate() override;
	void OnExit() override;

	IsHungry* isHungry;
};

class HungryState : public IState
{
public:
	HungryState();
	~HungryState();

	void OnEnter() override;
	void OnUpdate() override;
	void OnExit() override;

	IsFull* isFull;
	IsDead* isDead;
};

class DeadState : public IState
{
public:
	DeadState();
	~DeadState();

	void OnEnter() override;
	void OnUpdate() override;
	void OnExit() override;
};