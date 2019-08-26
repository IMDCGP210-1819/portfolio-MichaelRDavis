#pragma once

#include <cstdint>
#include <vector>
#include <array>

struct GridNode
{
	int32_t x;
	int32_t y;
};

class SquareGrid
{
public:
	SquareGrid(int32_t width, int32_t height);

	inline int32_t GetWidth() const { return m_width; }
	inline int32_t GetHeight() const { return m_height; }

	bool InBounds(GridNode node) const;

	std::vector<GridNode> GetNearestNodes(GridNode node);

	void DrawGrid();

private:
	int32_t m_width;
	int32_t m_height;
	std::array<GridNode, 4> m_nodes;
};