#include "SquareGrid.h"

SquareGrid::SquareGrid(int32_t width, int32_t height)
	: m_width(width)
	, m_height(height)
{
	m_nodes = { GridNode{1, 0}, GridNode{0, -1}, GridNode{-1, 0}, GridNode{0, 1} };
}

bool SquareGrid::InBounds(GridNode node) const
{
	return 0 <= node.x && node.x < m_width && 0 <= node.y && node.y < m_height;
}

std::vector<GridNode> SquareGrid::GetNearestNodes(GridNode node)
{
	std::vector<GridNode> adjacentNodes;

	for (auto it : m_nodes)
	{
		GridNode newNode{ node.x + it.x, node.y + it.y };
		if (InBounds(newNode))
		{
			adjacentNodes.push_back(newNode);
		}
	}

	if (node.x + node.y % 2 == 0)
	{
		std::reverse(adjacentNodes.begin(), adjacentNodes.end());
	}

	return adjacentNodes;
}

void SquareGrid::DrawGrid()
{
	for (uint32_t x = 0; x < m_height; x += 10)
	{
		for (uint32_t y = 0; y < m_width; y += 10)
		{

		}
	}
}
