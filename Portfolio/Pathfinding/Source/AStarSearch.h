#pragma once

#include <vector>
#include <map>

class NavPath;
class NavNode;
class AStarNode;

class AStarSearch
{
public:
	AStarSearch();
	~AStarSearch();

	NavPath* Search(NavNode* startNode, NavNode* goalNode);

private:
	std::vector<AStarNode> m_openSet;
	std::map<NavNode*, AStarNode*> m_map;
};