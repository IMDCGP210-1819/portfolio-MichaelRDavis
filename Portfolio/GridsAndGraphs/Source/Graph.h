#pragma once

#include <cstdint>
#include <vector>

template<typename T>
class Node
{
	Node(T inData, Graph& graph)
	{
		m_data = std::move(inData);
		m_graph = graph;
	}

private:
	T m_data;
	Graph& m_graph;
	std::array<Node, 2> m_nodes;
	std::vector<Link*> m_links;
};

template<typename T>
class Link
{
public:
	Link(Node<T>* to, Node<T>* from)
	{
		m_nodes[0] = to;
		m_nodes[1] = from;
	}

private:
	std::array<Node, 2> m_nodes;
	std::vector<Link*> m_links;
};

template<typename T>
class Graph
{
public:
	Graph()
	{

	}

	~Graph()
	{

	}

	Node<T>* AddNode(T inData)
	{
		return new Node<T>(inData, *this);
	}

	Link<T>* AddLink(T inData, Node<T>* to, Node<T>* from)
	{

	}

private:
	std::array<Node<T>*, 2> m_nodes;
	std::array<Node<T>*, 2> m_links;
};