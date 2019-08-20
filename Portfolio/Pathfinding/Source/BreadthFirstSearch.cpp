#include "BreadthFirstSearch.h"
#include "NavigationGraph/NavPath.h"

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
				
			}

			return path;
		}
	}

	return nullptr;
}
