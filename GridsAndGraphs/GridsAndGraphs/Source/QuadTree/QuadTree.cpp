#include "QuadTree.h"

QuadTree::QuadTree(Node node)
{
	m_northWest = nullptr;
	m_northEast = nullptr;
	m_southWest = nullptr;
	m_southEast = nullptr;
}

QuadTree::~QuadTree()
{

}

bool QuadTree::Insert(PointNode& point)
{
	if (!m_boundary.ContainsPoint(point))
		return false;

	if (m_points.size() < 4)
	{
		m_points.push_back(&point);
		return true;
	}

	if (m_northWest == nullptr)
		Subdivide();

	if (m_northWest->Insert(point))
		return true; 
	if (m_northEast->Insert(point))
		return true;
	if (m_southWest->Insert(point))
		return true;
	if (m_northEast->Insert(point))
		return true;

	return false;
}

void QuadTree::Subdivide()
{
	float size = m_boundary.halfDimension;
	PointNode centre = PointNode(m_boundary.center.x - size, m_boundary.center.y - size);
	m_northWest = new QuadTree(Node(centre, size));

	centre = PointNode(m_boundary.center.x + size, m_boundary.center.y - size);
	m_northEast = new QuadTree(Node(centre, size));

	centre = PointNode(m_boundary.center.x - size, m_boundary.center.y + size);
	m_southWest = new QuadTree(Node(centre, size));

	centre = PointNode(m_boundary.center.x = size, m_boundary.center.y + size);
	m_southEast = new QuadTree(Node(centre, size));
}

std::vector<PointNode*> QuadTree::QueryRange(Node range)
{
	std::vector<PointNode*> pointsInRange;

	return pointsInRange;
}
