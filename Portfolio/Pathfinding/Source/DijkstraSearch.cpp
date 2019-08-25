#include "DijkstraSearch.h"
#include "NavigationGraph/NavPath.h"
#include "NavigationGraph/NavNode.h"

DijkstraSearch::DijkstraSearch()
{

}

DijkstraSearch::~DijkstraSearch()
{

}

NavPath* DijkstraSearch::Search(NavNode* startNode, NavNode* goalNode)
{
	NavNode* currentNode = startNode;
	m_queue.push(currentNode);

	while (!m_queue.empty())
	{
		currentNode = m_queue.top();
		if (currentNode == goalNode)
		{
			break;
		}

		std::vector<NavNode*> adjacentNodes;
		currentNode->GetNearestNodes(adjacentNodes);
		for (auto it : adjacentNodes)
		{

		}
	}
}

