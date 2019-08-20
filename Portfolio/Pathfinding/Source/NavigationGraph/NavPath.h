#pragma once

class NavPath
{
public:
	NavPath() = default;
	~NavPath() = default;

	void AddNode(NavNode* node)
	{
		m_path.push_back(node);
	}

private:
	std::vector<NavNode*> m_path;
};