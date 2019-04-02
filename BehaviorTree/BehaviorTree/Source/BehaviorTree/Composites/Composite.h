#pragma once

#include "../Task.h"
#include <vector>
#include <algorithm>

class Composite : public Task
{
public:
	void AddChild(Task* child);
	void RemoveChild(Task* child);
	void ClearChildren();

protected:
	std::vector<Task*> m_children;
};