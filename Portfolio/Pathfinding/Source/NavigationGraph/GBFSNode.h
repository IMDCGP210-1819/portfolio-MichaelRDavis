#pragma once

class NavNode;

class GBFSNode
{
public:
	GBFSNode()
	{
		m_parentNode = nullptr;
		m_heuristic = 0.0f;
		m_isClosed = false;
	}

	inline void SetNavNode(NavNode* newParentNode) { m_parentNode = newParentNode; }
	inline void SetIsClosed(bool closed) { m_isClosed = closed; }

	inline NavNode* GetNavNode() const { return m_parentNode; }
	inline float GetHeuristic() const { return m_heuristic; }
	inline bool GetIsClosed() const { return m_isClosed; }

private:
	NavNode* m_parentNode;
	float m_heuristic;
	bool m_isClosed;
};