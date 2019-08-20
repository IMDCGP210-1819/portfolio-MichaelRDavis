#pragma once

#include <queue>

class NavNode;
class NavNodePath;

class DijkstraSearch
{
public:
	DijkstraSearch();
	~DijkstraSearch();

private:
	std::priority_queue<NavNode, NavNodePath> m_queue;
};