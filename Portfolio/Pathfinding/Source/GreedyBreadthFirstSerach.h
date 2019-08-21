#pragma once

class NavPath;
class NavNode;

class GreedyBreadthFirstSearch
{
public:
	GreedyBreadthFirstSearch();
	~GreedyBreadthFirstSearch();

	NavPath* Search(NavNode* startNode, NavNode* goalNode);

private:

};
