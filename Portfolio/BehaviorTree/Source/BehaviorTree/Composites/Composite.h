#pragma once

#include "Behavior.h"
#include <memory>
#include <vector>

class Composite : public Behavior
{
public:
	Composite();
	~Composite() = default;

	void AddChildren(std::shared_ptr<Behavior> behavior);
	inline bool HasChildren() const { return !m_children.empty(); }

protected:
	std::vector<std::shared_ptr<Behavior>> m_children;
	std::vector<std::shared_ptr<Behavior>>::iterator m_iterator;
};