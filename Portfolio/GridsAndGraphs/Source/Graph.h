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
	Graph(std::vector<Link> const& links, int32_t num);
	~Graph() = default;

	void DrawGraph(Graph const& graph, int32_t num);

	void SetIsDirected(bool directed);

	inline bool GetIsDirected() const
	{
		return m_isDirected;
	}

private:
	std::vector<std::vector<int32_t>> m_adjacencyList;
	bool m_isDirected;
};