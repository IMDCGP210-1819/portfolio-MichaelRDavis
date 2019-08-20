#pragma once

#include <cstdint>

template<typename T>
class Vector
{
public:
	Vector(T inX, T inY)
		: x(inX)
		, y(inY)
	{

	}

	inline T GetPointX() const { return x; }
	inline T GetPointY() const { return y; }

private:
	T x;
	T y;
};


template<typename T>
class Node
{
public:
	Node(Vector<int32_t> inPoint, T inData)
		: point(inPoint)
		, data(inData)
	{

	}

	inline Vector<int32_t> GetPoint() const { return point; }
	inline T GetData() const { return data; }

private:
	Vector<int32_t> point;
	T data;
};

template<typename T>
class QuadTree
{
public:
	QuadTree()
	{
		m_topLeft = Vector<int32_t>(0, 0);
		m_bottomRight = Vector<int32_t>(0, 0);
		m_root = nullptr;
		m_children = nullptr;
	}

	QuadTree(Point top, Point bottom)
	{
		m_topLeft = top;
		m_bottomRight = bottom;
		m_root = nullptr;
		m_children = nullptr;
	}

	void Insert(Node<T>* newNode)
	{
		if (m_root == nullptr)
		{
			return;
		}

		if (!InBoundary(newNode->GetPoint()))
		{
			return;
		}

		if (abs(m_topLeft.GetPointX() - m_bottomRight.GetPointX() <= 1 &&
			abs(m_topLeft.GetPointY() - m_bottomRight.GetPointY() <= 1)))
		{
			if (m_root == nullptr)
			{
				m_root = newNode;
			}

			return;
		}

		if (m_topLeft.GetPointX() + m_bottomRight.GetPointX() / 2 >= newNode->GetPoint().GetPointX())
		{
			if (m_children[0] == nullptr)
			{
				m_children[0] = new QuadTree<T>(Point(m_topLeft.GetPointX(), m_bottomRight.GetPointY()), );
			}
		}
	}

	Node* Search(Vector<int32_t> point)
	{

	}

	bool InBoundary(Vector<int32_t> point)
	{

	}

private:
	Vector<int32_t> m_topLeft;
	Vector<int32_t> m_bottomRight;
	Node<T>* m_root;
	QuadTree<T>* m_children[4];
};