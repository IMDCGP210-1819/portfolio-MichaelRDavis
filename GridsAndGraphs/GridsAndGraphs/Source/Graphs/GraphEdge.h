#pragma once

class GraphEdge
{
public:
	GraphEdge(int from, int to, float cost);
	GraphEdge(int from, int to);
	virtual ~GraphEdge();

protected:
	int m_To;
	int m_From;
	float m_Cost;
};