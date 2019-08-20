#pragma once

class NavPath;
class NavNode;
class NavNodePath;

#include <map>
#include <queue>

class BreadthFirstSearch
{
public:
	BreadthFirstSearch();
	~BreadthFirstSearch();

	NavPath* Search(NavNode* start, NavNode* end);

private:
	std::queue<NavNode*> m_consideredNodes;
	std::map<NavNode*, NavNode*> m_map;
};