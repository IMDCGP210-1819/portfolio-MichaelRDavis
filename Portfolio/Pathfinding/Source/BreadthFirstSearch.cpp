#include "BreadthFirstSearch.h"
#include "NavigationGraph/NavPath.h"
#include "NavigationGraph/NavNode.h"

BreadthFirstSearch::BreadthFirstSearch()
{

}

BreadthFirstSearch::~BreadthFirstSearch()
{

}

NavPath* BreadthFirstSearch::Search(NavNode* start, NavNode* end)
{
	if (start == end)
	{
		return nullptr;
	}

	m_consideredNodes.emplace(start);

	while (!m_consideredNodes.empty())
	{
		NavNode* currentNode = m_consideredNodes.front();
		m_consideredNodes.pop();
		if (currentNode == end)
		{
			NavPath* path = new NavPath();
			NavNode* pathNode = currentNode;
			while (currentNode)
			{
				path->AddNode(pathNode);
			}

			return path;
		}

		std::vector<NavNode*> adjacentNodes;
		currentNode->GetNearestNodes(adjacentNodes);
		for (auto it : adjacentNodes)
		{
			NavNode* parentNode = m_map[it];
			m_map[it] = currentNode;
			m_consideredNodes.emplace(it);
		}
	}

	return nullptr;
}
