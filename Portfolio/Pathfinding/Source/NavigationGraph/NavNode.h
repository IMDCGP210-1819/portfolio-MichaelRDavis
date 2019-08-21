#pragma once

#include <vmath.h>

class NavLink;

class NavNode
{
public:
	NavNode(Vector2f inData)
	{
		m_data = inData;
	}

	NavNode(Vector2f inData, float inWeight = 5.0f)
	{
		m_data = inData;
		m_weight = inWeight;
	}

	void GetNearestNodes(std::vector<NavNode*> outNodes)
	{
		for (auto it = m_links.begin(); it != m_links.end(); ++it)
		{
			NavLink* link = *it;
		}
	}

	NavLink* GetLink(NavNode node)
	{
		for (auto it = m_links.begin(); it != m_links.end(); ++it)
		{

		}
	}

private:
	std::vector<NavLink*> m_links;
	float m_weight;
	Vector2f m_data;
};