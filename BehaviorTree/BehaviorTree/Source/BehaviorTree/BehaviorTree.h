#pragma once

class Behavior;

/** Base class for a behavior tree */
class BehaviorTree
{
public:
	/** Update the behavior tree, called once per frame */
	virtual void Tick() = 0;

protected:
	/** The root of the behavior tree */
	Behavior* m_pRoot;
};