#pragma once

#include "../Behavior.h"
#include <vector>
#include <algorithm>

class Composite : public Behavior
{
public:
	void AddChild(Behavior* child);
	void RemoveChild(Behavior* child);
	void ClearChildren();

protected:
	std::vector<Behavior*> m_children;
};