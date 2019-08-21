#include "GreedyBreadthFirstSerach.h"
#include "NavigationGraph/GBFSNode.h"
#include "NavigationGraph/NavNode.h"

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
			GBFSNode* pathNode = 
		}

	} while (currentNode != goalNode);
}
