#pragma once

class GraphNodeBase
{
public:
	GraphNodeBase();
	GraphNodeBase(int index);
	virtual ~GraphNodeBase();

	void SetIndex(int newIndex);

	inline int GetIndex() const { return m_Index; }

protected:
	int m_Index;
};