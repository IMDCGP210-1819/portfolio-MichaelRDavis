#include "Graph.h"
#include "Graph.h"

Graph::Graph(std::vector<Link> const& links)
	: m_isDirected(true)
{
	int32_t size = links.size();
	m_adjacencyList.resize(size);

	for (auto& link : links)
	{
		if(m_isDirected)
		{
			
		}
	}
}

void Graph::SetIsDirected(bool directed)
{
	m_isDirected = directed;
}
