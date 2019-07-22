#include "BehaviorTree.h"
#include "Behavior.h"
#include "Blackboard.h"

BehaviorTree::BehaviorTree()
	: m_blackboard(std::make_shared<Blackboard>())
{

}

void BehaviorTree::OnTick()
{
	m_root->Tick();
}

void BehaviorTree::SetRootNode(const std::shared_ptr<Behavior>& node)
{
	m_root = node;
}

