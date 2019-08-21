#pragma once

class NavNode;

class NavLink
{
public:
	NavLink(float inWeight = 1.0f)
	{
		m_weight = inWeight;
		m_to = nullptr;
		m_from = nullptr;
	}

	NavNode* GetNearestNode(NavNode* node)
	{
		if (m_to == node)
		{
			return m_from;
		}
		else
		{
			return m_to;
		}
	}

	inline NavNode* GetToNode() const { return m_to; }
	inline NavNode* GetFromNode() const { return m_from; }

private:
	NavNode* m_to;
	NavNode* m_from;
	float m_weight;
};