#pragma once

class Behavior;

class BehaviorTree
{
public:
	virtual void Tick() = 0;

protected:
	Behavior* m_pRoot;
};