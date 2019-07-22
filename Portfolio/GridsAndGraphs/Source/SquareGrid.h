#pragma once

#include <cstdint>

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

private:
	int32_t m_width;
	int32_t m_height;
};