#pragma once

#include <memory>

class Behavior;
class Blackboard;

class BehaviorTree
{
public:
	BehaviorTree();
	~BehaviorTree() = default;

	virtual void OnTick();

	void SetRootNode(const std::shared_ptr<Behavior>& node);

	inline std::shared_ptr<Behavior> GetRootNode() const
	{
		return m_root;
	}

	inline std::shared_ptr<Blackboard> GetBlakcboard() const
	{
		return m_blackboard;
	}

private:
	std::shared_ptr<Behavior> m_root;
	std::shared_ptr<Blackboard> m_blackboard;
};