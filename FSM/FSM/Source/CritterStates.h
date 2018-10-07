#pragma once

#include "IState.h"

class Critter;
class IsBored;
class IsHappy;
class BoredState;
class HappyState;

class HappyState : public IState<Critter>
{
public:
	HappyState();

	void OnEnter(Critter* owner) override;
	void OnUpdate(Critter* owner) override;
	void OnExit(Critter* owner) override;

	IsBored* isBored;
};

class BoredState : public IState<Critter>
{
public:
	BoredState();

	void OnEnter(Critter* owner) override;
	void OnUpdate(Critter* owner) override;
	void OnExit(Critter* owner) override;

	IsHappy* isHappy;
};