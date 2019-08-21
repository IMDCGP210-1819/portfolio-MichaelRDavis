#pragma once

#include <map>
#include <vector>

class NavPath;
class NavNode;
class GBFSNode;

class GreedyBreadthFirstSearch
{
public:
	GreedyBreadthFirstSearch();
	~GreedyBreadthFirstSearch();

	NavPath* Search(NavNode* startNode, NavNode* goalNode);

private:
	std::vector<NavNode*> m_closedSet;
	std::map<NavNode*, GBFSNode*> m_map;
};
