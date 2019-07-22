#pragma once

#include <cstdint>

struct Point
{
	Point(int32_t inX, int32_t inY)
		: x(inX)
		, y(inY)
	{

	}

	int32_t x;
	int32_t y;
};

struct Node
{
	Node(Node* inParent)
		: parent(inParent)
	{

	}

	Node* parent;
	Node* children[4] = { nullptr, nullptr, nullptr, nullptr };
};

class QuadTree
{
public:


private:
	Node* m_root;
};