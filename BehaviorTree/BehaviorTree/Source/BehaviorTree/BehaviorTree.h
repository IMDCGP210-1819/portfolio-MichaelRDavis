#pragma once

#include <memory>

class Task;
class Blackboard;

/** Base class for a behavior tree */
class BehaviorTree
{
public:
	/** Constructor. */
	BehaviorTree();

	/** Destructor. */
	~BehaviorTree();

	/** Set the root node of this behavior tree. */
	void SetRootNode(const std::shared_ptr<Task>& newNode);

	/** Update the behavior tree, called once per frame */
	virtual void Tick();

	/** Returns the blackboard object. */
	std::shared_ptr<Blackboard> GetBlackboard() const;

protected:
	/** The root of the behavior tree */
	std::shared_ptr<Task> m_rootNode;

	/** The behavior trees blackboard. */
	std::shared_ptr<Blackboard> m_blackboard;
};