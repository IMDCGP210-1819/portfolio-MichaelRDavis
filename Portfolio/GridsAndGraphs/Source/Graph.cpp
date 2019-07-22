#include "Graph.h"

Graph::Graph(std::vector<Link> const& links, int32_t num)
	: m_isDirected(true)
{
	m_adjacencyList.resize(num);
}

void Graph::DrawGraph(Graph const& graph, int32_t num)
{

}

void Graph::SetIsDirected(bool directed)
{
	m_isDirected = directed;
}