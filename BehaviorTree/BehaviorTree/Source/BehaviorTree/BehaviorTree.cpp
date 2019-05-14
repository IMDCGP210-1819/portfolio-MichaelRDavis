#include "BehaviorTree.h"
#include "Task.h"
#include "Blackboard.h"

BehaviorTree::BehaviorTree()
	: m_blackboard(std::make_shared<Blackboard>())
{

}

BehaviorTree::~BehaviorTree()
{

}

void BehaviorTree::SetRootNode(const std::shared_ptr<Task>& newNode)
{
	m_rootNode = newNode;
}

void BehaviorTree::Tick()
{
	m_rootNode->Tick();
}

std::shared_ptr<Blackboard> BehaviorTree::GetBlackboard() const
{
	return m_blackboard;
}

