#pragma once

#include <map>
#include <queue>

class NavNode;
class NavPath;
class DijkstraNode;

class DijkstraSearch
{
public:
	DijkstraSearch();
	~DijkstraSearch();

	NavPath* Search(NavNode* startNode, NavNode* goalNode);

private:
	std::priority_queue<NavNode*> m_queue;
	std::map<NavNode*, DijkstraNode*> m_map;
};