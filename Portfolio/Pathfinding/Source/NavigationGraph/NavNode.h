#pragma once

template<typename T>
class NavNode
{
public:
	NavNode(T inData)
	{
		m_data = inData;
	}

	NavNode(T inData, float inWeight = 5.0f)
	{
		m_data = inData;
		m_weight = inWeight;
	}

	void GetNearestNodes(std::vector<NavNode<T>> outNodes)
	{
		for (auto it = m_links.begin(); it != m_links.end(); ++it)
		{
			NavLink<T>* link = *it;
		}
	}

	NavLink<T>* GetLink(NavNode<T> node)
	{
		for (auto it = m_links.begin(); it != m_links.end(); ++it)
		{

		}
	}

private:
	std::vector<NavLink<T>> m_links;
	float m_weight;
	T m_data;
};