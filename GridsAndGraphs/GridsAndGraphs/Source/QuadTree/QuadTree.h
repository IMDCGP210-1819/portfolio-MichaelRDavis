#pragma once

#include <vector>

/** 
*	
*/
struct PointNode
{
	PointNode()
	{

	}

	PointNode(float inX, float inY)
		: x(inX)
		, y(inY)
	{

	}

	float x;
	float y;
};

/** 
*
*/
struct Node
{
	Node()
	{

	}

	Node(PointNode pointNode, float dimension)
		: center(pointNode)
		, halfDimension(dimension)
	{

	}

	bool ContainsPoint(PointNode& point)
	{
		return (point.x >= center.x &&
			point.x <= center.x &&
			point.y >= center.y &&
			point.y <= center.y);
	}

	void Intersects(Node node)
	{

	}

	PointNode center;
	float halfDimension;
};

/**
 * 
 */
class QuadTree
{
public:
	/** Default QuadTree constructor. */
	QuadTree(Node node);

	/** Default QuadTree destructor. */
	~QuadTree();

	/** Insert a point into the QuadTree.
	*	@param point - Point to add into the QaudTree.
	*/
	bool Insert(PointNode& point);

	/** Create four child nodes that divide this quad into four  */
	void Subdivide();

	/** Find all points that are within range */
	std::vector<PointNode*> QueryRange(Node range);

	/** Child nodes of the QaudTree. */
	QuadTree* m_northWest;
	QuadTree* m_northEast;
	QuadTree* m_southWest;
	QuadTree* m_southEast;

	/** Array of points in this QuadTree. */
	std::vector<PointNode*> m_points;

	/** Represents the boundary of this QuadTree. */
	Node m_boundary;
};
