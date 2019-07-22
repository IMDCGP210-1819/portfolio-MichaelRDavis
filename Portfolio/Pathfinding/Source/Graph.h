#pragma once

#include <cstdint>
#include <vector>

struct Link
{
	int32_t sourceIndex;
	int32_t destinationIndex;
};

class Graph
{
public:
	Graph(std::vector<Link> const& links);

	std::vector<std::vector<Link>> m_adjacencyList;

	void SetIsDirected(bool directed);

	inline bool GetIsDirected() const
	{
		return m_isDirected;
	}

private:
	bool m_isDirected;
};