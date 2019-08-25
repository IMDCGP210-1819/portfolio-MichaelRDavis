#include "GreedyBreadthFirstSerach.h"
#include "NavigationGraph/GBFSNode.h"
#include "NavigationGraph/NavNode.h"
#include "NavigationGraph/NavLink.h"
#include "NavigationGraph/NavPath.h"
#include <algorithm>

GreedyBreadthFirstSearch::GreedyBreadthFirstSearch()
{

}

GreedyBreadthFirstSearch::~GreedyBreadthFirstSearch()
{

}

NavPath* GreedyBreadthFirstSearch::Search(NavNode* startNode, NavNode* goalNode)
{
	NavNode* currentNode = startNode;
	m_map[currentNode]->SetIsClosed(true);

	do
	{
		std::vector<NavNode*> adjacentNodes;
		currentNode->GetNearestNodes(adjacentNodes);
		for (auto it : adjacentNodes)
		{
			GBFSNode* pathNode = m_map[it->GetLink(it)->GetToNode()];
			if (!pathNode->GetIsClosed())
			{
				pathNode->SetNavNode(it);
				if (pathNode->GetIsClosed())
				{
					pathNode->ComputeHeuristic();
					m_closedSet.emplace_back(it->GetLink(it)->GetToNode());

					NavPath* path = new NavPath();
					NavNode* pathNode = it;
					while (it)
					{
						path->AddNode(pathNode);
					}

					return path;
				}
			}
		}

		if (m_closedSet.empty())
		{
			return nullptr;
		}

	} while (currentNode != goalNode);
}
