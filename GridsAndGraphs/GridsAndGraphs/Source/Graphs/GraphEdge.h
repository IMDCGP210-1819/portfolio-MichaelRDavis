#pragma once

class GraphEdge
{
public:
	GraphEdge();
	GraphEdge(int from, int to, float cost);
	GraphEdge(int from, int to);
	virtual ~GraphEdge();

	inline int GetFrom() const { return m_From; }
	void SetFrom(int newFrom);

	inline int GetTo() const { return m_To; }
	void SetTo(int newTo);

	inline float GetCost() const { return m_Cost; }
	void SetCost(float newCost);

protected:
	int m_To;
	int m_From;
	float m_Cost;
};