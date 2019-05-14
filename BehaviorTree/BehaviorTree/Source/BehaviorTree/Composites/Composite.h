#pragma once

#include "../Task.h"
#include <vector>
#include <algorithm>

class Composite : public Task
{
public:
	Composite();
	virtual ~Composite();

	void AddChild(std::shared_ptr<Task> child);
	void RemoveChild(std::shared_ptr<Task> child);
	void ClearChildren();

protected:
	std::vector<std::shared_ptr<Task>> m_children;
	std::vector<std::shared_ptr<Task>>::iterator it;
};