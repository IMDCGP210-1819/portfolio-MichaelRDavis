#include "../Graphs/GraphEdge.h"

GraphEdge::GraphEdge()
	: m_From(0)
	, m_To(0)
	, m_Cost(1.0f)
{

}

GraphEdge::GraphEdge(int from, int to, float cost)
	: m_From(from)
	, m_To(to)
	, m_Cost(cost)
{

}

GraphEdge::GraphEdge(int from, int to)
	: m_From(from)
	, m_To(to)
	, m_Cost(1.0f)
{

}

GraphEdge::~GraphEdge()
{

}

void GraphEdge::SetFrom(int newFrom)
{
	m_From = newFrom;
}

void GraphEdge::SetTo(int newTo)
{
	m_To = newTo;
}

void GraphEdge::SetCost(float newCost)
{
	m_Cost = newCost;
}
